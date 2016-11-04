using IBApi;
using NLog;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using TradeBot.Events;
using TradeBot.Extensions;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.Gui;
using TradeBot.MenuFramework;
using TradeBot.TwsAbstractions;
using TradeBot.Utils;
using static TradeBot.Gui.Window;
using static TradeBot.Properties;

namespace TradeBot
{
    public class Program
    {
        public static void Main()
        {
            Program console = new Program();
            console.Start();
        }

        private TradeBotClient client;
        private Menu menu;

        private bool shouldExitApplication;

        public Program()
        {
            InitClient();
            InitConsole();
            InitMenu();
            InitEventHandlers();
        }

        #region Initialization
        private void InitClient()
        {
            client = new TradeBotClient(Preferences.ClientId);
            client.IgnoredDebugMessages = new string[] {
                nameof(EWrapper.error),
                nameof(EWrapper.connectAck),
                nameof(EWrapper.connectionClosed),
                nameof(EWrapper.managedAccounts),
                nameof(EWrapper.nextValidId),
                nameof(EWrapper.tickPrice),
                nameof(EWrapper.tickSize),
                nameof(EWrapper.tickString),
                nameof(EWrapper.tickGeneric),
                nameof(EWrapper.updateAccountValue),
                nameof(EWrapper.updateAccountTime),
                nameof(EWrapper.accountDownloadEnd),
                nameof(EWrapper.updatePortfolio),
                nameof(EWrapper.position),
                nameof(EWrapper.positionEnd),
                nameof(EWrapper.openOrder),
                nameof(EWrapper.openOrderEnd),
                nameof(EWrapper.orderStatus),
                nameof(EWrapper.execDetails),
                nameof(EWrapper.commissionReport)
            };
        }

        private void InitEventHandlers()
        {
            Window.SetWindowCloseHandler(OnWindowClose);

            client.PropertyChanged += OnPropertyChanged;
            client.Error += OnError;
        }

        private void InitConsole()
        {
            UpdateConsoleTitle();

            // The following settings are only supported on Windows.
            if (OS.IsWindows())
            {
                // Set the console buffer height to the maximum allowed value.
                Console.BufferHeight = Int16.MaxValue - 1;
                if (Preferences.CenterWindow)
                {
                    Window.SetWindowSizeAndCenter(
                        Preferences.WindowWidth,
                        Preferences.WindowHeight);
                }
            }
        }

        private void InitMenu()
        {
            menu = new Menu();

            Action<IList<string>, Action> addMenuOption = (entry, command)
                => menu.AddMenuOption(entry[0], entry[1], command);

            MenuOptionEntries entries = Messages.MenuOptionEntries;
            addMenuOption(entries.ReloadSavedState, ReloadSavedStateCommand);
            addMenuOption(entries.SetTickerSymbol, SetTickerSymbolDataCommand);
            addMenuOption(entries.ClearTickerSymbol, ClearTickerSymbolCommand);
            addMenuOption(entries.SetStepSize, SetStepSizeCommand);
            addMenuOption(entries.SetStepSizeFromCash, SetStepSizeFromCashCommand);
            addMenuOption(entries.Buy, BuyCommand);
            addMenuOption(entries.Sell, SellCommand);
            addMenuOption(entries.ReversePosition, ReversePositionCommand);
            addMenuOption(entries.ClosePosition, ClosePositionCommand);
            addMenuOption(entries.ListPositions, ListPositionsCommand);
            addMenuOption(entries.ListAllPositions, ListAllPositionsCommand);
            addMenuOption(entries.ClearScreen, ClearScreenCommand);
            addMenuOption(entries.Help, HelpCommand);
            addMenuOption(entries.ExitApplication, ExitApplicationCommand);
        }
        #endregion

        #region Public methods
        public void Start()
        {
            IO.ShowMessage(Messages.WelcomeMessage);

            try
            {
                client.Connect(Preferences.ClientUrl, Preferences.ClientPort);
                LoadState();
                while (!shouldExitApplication)
                {
                    menu.PromptForMenuOption().Command();
                }
            }
            catch (Exception e)
            {
                IO.ShowMessage(Messages.ExceptionFormat, LogLevel.Fatal, e.Message, e.StackTrace);
            }
            finally
            {
                Shutdown();
                if (OS.IsWindows())
                {
                    IO.PromptForChar(Messages.PressAnyKeyToExit);
                }
            }
        }
        #endregion

        #region Menu commands
        private void ReloadSavedStateCommand()
        {
            LoadState();
        }

        private void SetTickerSymbolDataCommand()
        {
            string tickerSymbol = IO.PromptForInput(Messages.SelectTickerPrompt);
            IfNotNullOrWhiteSpace(tickerSymbol)(() =>
            {
                client.TickerSymbol = tickerSymbol;
            });
        }

        private void ClearTickerSymbolCommand()
        {
            client.TickerSymbol = null;
        }

        private void SetStepSizeCommand()
        {
            string stepSizeString = IO.PromptForInput(Messages.StepSizePrompt);
            int? stepSize = stepSizeString.ToInt();
            IfHasValue(stepSize)(() =>
            {
                client.StepSize = stepSize.Value;
            });
        }

        private void SetStepSizeFromCashCommand()
        {
            Validator[] validators = { IfTickerSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                string cashString = IO.PromptForInput(Messages.StepSizeFromCashPrompt);
                double? cash = cashString.ToDouble();
                IfHasValue(cash)(() =>
                {
                    double sharePrice = client.GetTick(TickType.LAST);
                    client.StepSize = StockMath.CalculateStepSizeFromCashValue(cash.Value, sharePrice);
                });
            });
        }

        private void BuyCommand()
        {
            Validator[] validators = { IfTickerSet(), IfStepSizeSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                client.PlaceBuyOrder(client.StepSize);
            });
        }

        private void SellCommand()
        {
            Validator[] validators = { IfTickerSet(), IfStepSizeSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                client.PlaceSellOrder(client.StepSize);
            });
        }

        private void ReversePositionCommand()
        {
            Validator[] validators = { IfTickerSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                PortfolioInfo position = client.Portfolio?.Get(client.TickerSymbol);
                IfPositionExists(position)(() =>
                {
                    int positionSize = (int)position.Position;
                    int orderSize = Math.Abs(positionSize) * 2;

                    if (positionSize > 0)
                    {
                        client.PlaceSellOrder(orderSize);

                    }
                    else if (positionSize < 0)
                    {
                        client.PlaceBuyOrder(orderSize);
                    }
                });
            });
        }

        private void ClosePositionCommand()
        {
            Validator[] validators = { IfTickerSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                PortfolioInfo position = client.Portfolio?.Get(client.TickerSymbol);
                IfPositionExists(position)(() =>
                {
                    int positionSize = (int)position.Position;
                    int orderSize = Math.Abs(positionSize);

                    if (positionSize > 0)
                    {
                        client.PlaceSellOrder(orderSize);

                    }
                    else if (positionSize < 0)
                    {
                        client.PlaceBuyOrder(orderSize);
                    }
                });
            });
        }

        private void ListPositionsCommand()
        {
            Portfolio portfolio = client.Portfolio;
            if (portfolio != null)
            {
                foreach (var portfolioEntry in portfolio)
                {
                    string tickerSymbol = portfolioEntry.Key;
                    PortfolioInfo position = portfolioEntry.Value;
                    IO.ShowMessage(Messages.ListPositionsFormat,
                        position.Position,
                        position.Contract.Symbol,
                        position.AverageCost.ToCurrencyString(),
                        position.MarketPrice.ToCurrencyString(),
                        position.UnrealisedPNL.ToCurrencyString(),
                        position.MarketValue.ToCurrencyString());
                }
            }
            else
            {
                IO.ShowMessage(Messages.PortfolioNotFound, LogLevel.Error);
            }
        }

        private void ListAllPositionsCommand()
        {
            IList<PositionInfo> positions = client.RequestAllPositionsForAllAccountsAsync().Result;
            foreach (var position in positions)
            {
                IO.ShowMessage(Messages.ListAllPositionsFormat,
                    position.PositionSize,
                    position.Contract.Symbol,
                    position.Account);
            }
        }

        private void ClearScreenCommand()
        {
            Console.Clear();
        }

        private void HelpCommand()
        {
            IO.ShowMessage(menu.ToString());
        }

        private void ExitApplicationCommand()
        {
            shouldExitApplication = true;
        }
        #endregion

        #region Event handlers
        private void OnError(int id, int errorCode, string errorMessage, Exception e)
        {
            // Ignore common error codes
            switch (errorCode)
            {
                case ErrorCodes.MARKET_DATA_FARM_DISCONNECTED:
                case ErrorCodes.MARKET_DATA_FARM_CONNECTED:
                case ErrorCodes.HISTORICAL_DATA_FARM_DISCONNECTED:
                case ErrorCodes.HISTORICAL_DATA_FARM_CONNECTED:
                case ErrorCodes.HISTORICAL_DATA_FARM_INACTIVE:
                case ErrorCodes.MARKET_DATA_FARM_INACTIVE:
                case ErrorCodes.TICKER_ID_NOT_FOUND:
                case ErrorCodes.CROSS_SIDE_WARNING:
                    return;
            }

            if (!string.IsNullOrWhiteSpace(errorMessage))
            {
                IO.ShowMessage(Messages.TwsErrorFormat, LogLevel.Error, errorMessage);
            }

            if (e != null)
            {
                IO.ShowMessage(Messages.ExceptionFormat, LogLevel.Error, e.Message, e.StackTrace);
            }
        }

        private bool OnWindowClose(CloseReason reason)
        {
            Shutdown();

            // return false since we didn't handle the control signal, 
            // i.e. Environment.Exit(-1);
            return false;
        }

        private void OnPropertyChanged(object sender, PropertyChangedEventArgs eventArgs)
        {
            switch (eventArgs.PropertyName)
            {
                case nameof(client.IsConnected):
                    OnIsConnectedChanged(eventArgs);
                    break;
                case nameof(client.Accounts):
                    OnAccountsChanged(eventArgs);
                    break;
                case nameof(client.TickerSymbol):
                    OnTickerSymbolChanged(eventArgs);
                    break;
                case nameof(client.StepSize):
                    OnStepSizeChanged(eventArgs);
                    break;
                case nameof(client.TickData):
                    OnTickDataChanged(eventArgs);
                    break;
                case nameof(client.Portfolio):
                    OnPortfolioChanged(eventArgs);
                    break;
                case nameof(client.CommissionReports):
                    OnCommissionReportsChanged(eventArgs);
                    break;
            }
        }

        private void OnIsConnectedChanged(PropertyChangedEventArgs eventArgs)
        {
            if (client.IsConnected)
            {
                IO.ShowMessage(Messages.TwsConnected, LogLevel.Warn);
            }
            else
            {
                IO.ShowMessage(Messages.TwsDisconnected, LogLevel.Fatal);
            }
        }

        private void OnAccountsChanged(PropertyChangedEventArgs eventArgs)
        {
            string[] accounts = client.Accounts;
            if (accounts != null && accounts.Length > 0)
            {
                string tradedAccount = accounts[0];
                client.TradedAccount = tradedAccount;

                if (accounts.Length > 1)
                {
                    IO.ShowMessage(Messages.MultipleAccountsWarningFormat, LogLevel.Error, tradedAccount);
                }

                if (tradedAccount.StartsWith(Messages.PaperAccountPrefix, StringComparison.InvariantCulture))
                {
                    IO.ShowMessage(Messages.AccountTypePaper, LogLevel.Warn);
                }
                else
                {
                    IO.ShowMessage(Messages.AccountTypeLive, LogLevel.Error);
                }
            }
        }

        private void OnTickerSymbolChanged(PropertyChangedEventArgs eventArgs)
        {
            var args = eventArgs as PropertyValueChangedEventArgs<string>;
            var oldValue = args.OldValue;
            var newValue = args.NewValue;

            if (!string.IsNullOrWhiteSpace(oldValue))
            {
                IO.ShowMessage(Messages.TickerSymbolClearedFormat, oldValue);
            }

            if (!string.IsNullOrWhiteSpace(newValue))
            {
                IO.ShowMessage(Messages.TickerSymbolSetFormat, newValue);
            }

            UpdateConsoleTitle();
        }

        private void OnStepSizeChanged(PropertyChangedEventArgs eventArgs)
        {
            IO.ShowMessage(Messages.StepSizeSetFormat, client.StepSize);

            UpdateConsoleTitle();
        }

        private void OnTickDataChanged(PropertyChangedEventArgs eventArgs)
        {
            UpdateConsoleTitle();
        }

        private void OnPortfolioChanged(PropertyChangedEventArgs eventArgs)
        {
            UpdateConsoleTitle();
        }

        private void OnCommissionReportsChanged(PropertyChangedEventArgs eventArgs)
        {
            IList<CommissionReport> reports = client.CommissionReports;
            if (reports.IsNullOrEmpty())
            {
                return;
            }

            CommissionReport lastReport = reports.Last();
            double lastCommission = lastReport.Commission;
            double totalCommissions = reports.Sum(report => report.Commission);
            IO.ShowMessage(
                Messages.CommissionFormat,
                LogLevel.Info,
                lastCommission.ToCurrencyString(),
                totalCommissions.ToCurrencyString());
        }
        #endregion

        #region Private helper methods
        private void Shutdown()
        {
            client.Disconnect();
            SaveState();
        }

        private void SaveState()
        {
            client.SaveState();
            IO.ShowMessage(Messages.SavedStateFormat, LogLevel.Warn, PropertyFiles.STATE_FILE);
        }

        private void LoadState()
        {
            IO.ShowMessage(Messages.LoadedStateFormat, LogLevel.Warn, PropertyFiles.STATE_FILE);
            client.LoadState();
        }

        private void UpdateConsoleTitle()
        {
            IList<string> infoStrings = new List<string>();

            string appName = Messages.AppName;
            if (!string.IsNullOrWhiteSpace(appName))
            {
                infoStrings.Add(appName);
            }

            string tickerSymbol = client.TickerSymbol;
            bool isTickerSet = !string.IsNullOrWhiteSpace(tickerSymbol);
            string tickerDisplay = isTickerSet ? tickerSymbol : Messages.TitleTickerSymbolNotSelected;
            infoStrings.Add(string.Format(Messages.TitleTickerSymbol, tickerDisplay));
            infoStrings.Add(string.Format(Messages.TitleStepSize, client.StepSize));

            if (isTickerSet)
            {
                double positionSize = client.Portfolio?.Get(tickerSymbol)?.Position ?? 0;
                infoStrings.Add(string.Format(Messages.TitlePositionSize, positionSize));
                infoStrings.Add(string.Format(Messages.TitleLastFormat, client.GetTick(TickType.LAST)));
                infoStrings.Add(string.Format(Messages.TitleBidAskFormat, client.GetTick(TickType.BID), client.GetTick(TickType.ASK)));
                infoStrings.Add(string.Format(Messages.TitleVolumeFormat, client.GetTick(TickType.VOLUME)));
                infoStrings.Add(string.Format(Messages.TitleCloseFormat, client.GetTick(TickType.CLOSE)));
                infoStrings.Add(string.Format(Messages.TitleOpenFormat, client.GetTick(TickType.OPEN)));
            }

            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }
        #endregion

        #region Validations
        private delegate bool Validation();
        private delegate bool Validator(Action ifValidCallback);

        private void Validate(Validator[] validators, Action ifValidCallback)
        {
            bool valid = true;
            foreach (var validator in validators)
            {
                valid &= validator(null);
            }
            if (valid)
            {
                ifValidCallback();
            }
        }

        private Validator IfTickerSet()
        {
            return CreateValidator(
                () => client.TickerSymbol != null,
                Messages.TickerSymbolNotSetError);
        }

        private Validator IfStepSizeSet()
        {
            return CreateValidator(
                () => client.StepSize > 0,
                Messages.StepSizeNotSetError);
        }

        private Validator IfPriceDataAvailable()
        {
            Func<int, bool> ifAvailable = (tickType)
                => client.GetTick(tickType) > 0;

            return CreateValidator(
                () => ifAvailable(TickType.LAST) && ifAvailable(TickType.ASK) && ifAvailable(TickType.BID),
                Messages.PriceDataUnavailableError);
        }

        private Validator IfPositionExists(PortfolioInfo position)
        {
            return CreateValidator(
                () => position != null,
                Messages.PositionNotFoundError);
        }

        private Validator IfNotNullOrWhiteSpace(string str)
        {
            return CreateValidator(
                () => !string.IsNullOrWhiteSpace(str),
                Messages.InvalidNonEmptyStringInputError);
        }

        private Validator IfHasValue(int? nullable)
        {
            return CreateValidator(
                () => nullable.HasValue,
                Messages.InvalidIntegerInputError);
        }

        private Validator IfHasValue(double? nullable)
        {
            return CreateValidator(
                () => nullable.HasValue,
                Messages.InvalidDecimalInputError);
        }

        private Validator CreateValidator(Validation validation, string errorMessage)
        {
            return (ifValidCallback) =>
            {
                bool valid = validation();
                if (valid)
                {
                    ifValidCallback?.Invoke();
                }
                else
                {
                    IO.ShowMessage(errorMessage, LogLevel.Error);
                }
                return valid;
            };
        }
        #endregion
    }
}
