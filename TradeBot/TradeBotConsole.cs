using IBApi;
using System;
using System.Collections.Generic;
using TradeBot.Events;
using TradeBot.Extensions;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.Gui;
using TradeBot.MenuFramework;
using TradeBot.TwsAbstractions;
using TradeBot.Utils;
using static TradeBot.GlobalProperties;
using static TradeBot.Gui.Window;

namespace TradeBot
{
    public class TradeBotConsole
    {
        public static void Main(string[] args)
        {
            TradeBotConsole console = new TradeBotConsole();
            console.Start();
        }

        private readonly IList<int> ignoredErrorCodes = new List<int>()
        {
            ErrorCodes.MARKET_DATA_FARM_DISCONNECTED,
            ErrorCodes.MARKET_DATA_FARM_CONNECTED,
            ErrorCodes.HISTORICAL_DATA_FARM_DISCONNECTED,
            ErrorCodes.HISTORICAL_DATA_FARM_CONNECTED,
            ErrorCodes.HISTORICAL_DATA_FARM_INACTIVE,
            ErrorCodes.MARKET_DATA_FARM_INACTIVE
        };

        private TradeBotService service;
        private Menu menu;

        private bool shouldExitApplication;

        public TradeBotConsole()
        {
            service = new TradeBotService();

            InitializeEventHandlers();
            InitializeConsole();
            InitializeMenu();
        }

        #region Initialization
        private void InitializeEventHandlers()
        {
            Window.SetWindowCloseHandler(OnWindowClose);

            service.PropertyValueChanged += OnPropertyValueChanged;
            service.ConnectionClosed += OnConnectionClosed;
            service.ErrorOccured += OnError;
        }

        private void InitializeConsole()
        {
            Console.Title = Messages.AppName;
            // Set the console buffer height to the maximum allowed value.
            Console.BufferHeight = Int16.MaxValue - 1;
            if (Preferences.CenterWindow)
            {
                Window.SetWindowSizeAndCenter(
                    Preferences.WindowWidth,
                    Preferences.WindowHeight);
            }
        }

        private void InitializeMenu()
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
            addMenuOption(entries.Misc, MiscCommand);
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
                service.Connect();
                LoadState();
                while (!shouldExitApplication)
                {
                    menu.PromptForMenuOption().Command();
                }
            }
            catch (Exception e)
            {
                IO.ShowMessage(e.Message, MessageType.ERROR);
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
                service.TickerSymbol = tickerSymbol;
            });
        }

        private void ClearTickerSymbolCommand()
        {
            service.TickerSymbol = null;
        }

        private void SetStepSizeCommand()
        {
            string stepSizeString = IO.PromptForInput(Messages.StepSizePrompt);
            int? stepSize = stepSizeString.ToInt();
            IfHasValue(stepSize)(() =>
            {
                service.StepSize = stepSize.Value;
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
                    double sharePrice = service.GetTick(TickType.LAST);
                    service.StepSize = StockMath.CalculateStepSizeFromCashValue(cash.Value, sharePrice);
                });
            });
        }

        private void BuyCommand()
        {
            Validator[] validators = { IfTickerSet(), IfStepSizeSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                service.PlaceBuyOrder(service.StepSize);
            });
        }

        private void SellCommand()
        {
            Validator[] validators = { IfTickerSet(), IfStepSizeSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                service.PlaceSellOrder(service.StepSize);
            });
        }

        private void ReversePositionCommand()
        {
            Validator[] validators = { IfTickerSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                PortfolioInfo position = service.Portfolio.Get(service.TickerSymbol);
                IfPositionExists(position)(() =>
                {
                    int positionSize = position.PositionSize;
                    int orderSize = Math.Abs(positionSize) * 2;

                    if (positionSize > 0)
                    {
                        service.PlaceSellOrder(orderSize);

                    }
                    else if (positionSize < 0)
                    {
                        service.PlaceBuyOrder(orderSize);
                    }
                });
            });
        }

        private void ClosePositionCommand()
        {
            Validator[] validators = { IfTickerSet(), IfPriceDataAvailable() };
            Validate(validators, () =>
            {
                PortfolioInfo position = service.Portfolio.Get(service.TickerSymbol);
                IfPositionExists(position)(() =>
                {
                    int positionSize = position.PositionSize;
                    int orderSize = Math.Abs(positionSize);

                    if (positionSize > 0)
                    {
                        service.PlaceSellOrder(orderSize);

                    }
                    else if (positionSize < 0)
                    {
                        service.PlaceBuyOrder(orderSize);
                    }
                });
            });
        }

        private void ListPositionsCommand()
        {
            foreach (var portfolioEntry in service.Portfolio)
            {
                string tickerSymbol = portfolioEntry.Key;
                PortfolioInfo position = portfolioEntry.Value;
                IO.ShowMessage(Messages.ListPositionsFormat,
                    position.PositionSize,
                    position.Contract.Symbol,
                    position.AverageCost.ToCurrencyString(),
                    position.MarketPrice.ToCurrencyString(),
                    position.UnrealisedPNL.ToCurrencyString(),
                    position.MarketValue.ToCurrencyString());
            }
        }

        private async void ListAllPositionsCommand()
        {
            IList<PositionInfo> positions = await service.GetAllPositionsForAllAccounts();
            foreach (var position in positions)
            {
                IO.ShowMessage(Messages.ListAllPositionsFormat,
                    position.PositionSize,
                    position.Contract.Symbol,
                    position.Account);
            }
        }

        private void MiscCommand()
        {
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
        private bool OnWindowClose(CloseReason reason)
        {
            Shutdown();

            // return false since we didn't handle the control signal, 
            // i.e. Environment.Exit(-1);
            return false;
        }

        private void OnPropertyValueChanged(object sender, PropertyValueChangedEventArgs eventArgs)
        {
            switch (eventArgs.PropertyName)
            {
                case nameof(service.ManagedAccounts):
                    OnManagedAccountsChanged(eventArgs);
                    break;
                case nameof(service.TickerSymbol):
                    OnTickerChanged(eventArgs);
                    break;
                case nameof(service.StepSize):
                    OnStepSizeChanged(eventArgs);
                    break;
                case nameof(service.TickData):
                    OnTickDataUpdated(eventArgs);
                    break;
                case nameof(service.Portfolio):
                    OnPortfolioUpdated(eventArgs);
                    break;
            }
        }

        private void OnManagedAccountsChanged(PropertyValueChangedEventArgs eventArgs)
        {
            string[] accounts = eventArgs.NewValue as string[];
            if (accounts != null && accounts.Length > 0)
            {
                string tradedAccount = accounts[0];
                service.TradedAccount = tradedAccount;

                if (accounts.Length > 1)
                {
                    IO.ShowMessage(Messages.MultipleAccountsWarningFormat, MessageType.WARNING, tradedAccount);
                }

                if (tradedAccount.StartsWith(Messages.PaperAccountPrefix, StringComparison.InvariantCulture))
                {
                    IO.ShowMessage(Messages.AccountTypePaper, MessageType.SUCCESS);
                }
                else
                {
                    IO.ShowMessage(Messages.AccountTypeLive, MessageType.WARNING);
                }
            }
        }

        private void OnTickerChanged(PropertyValueChangedEventArgs eventArgs)
        {
            string oldValue = eventArgs.OldValue as string;
            if (!string.IsNullOrWhiteSpace(oldValue))
            {
                IO.ShowMessage(Messages.TickerSymbolClearedFormat, oldValue);
            }
            string newValue = eventArgs.NewValue as string;
            if (!string.IsNullOrWhiteSpace(newValue))
            {
                IO.ShowMessage(Messages.TickerSymbolSetFormat, newValue);
            }

            UpdateConsoleTitle();
        }

        private void OnStepSizeChanged(PropertyValueChangedEventArgs eventArgs)
        {
            IO.ShowMessage(Messages.StepSizeSetFormat, eventArgs.NewValue);

            UpdateConsoleTitle();
        }

        private void OnTickDataUpdated(PropertyValueChangedEventArgs eventArgs)
        {
            UpdateConsoleTitle();
        }

        private void OnPortfolioUpdated(PropertyValueChangedEventArgs eventArgs)
        {
            UpdateConsoleTitle();
        }

        private void OnConnectionClosed()
        {
            IO.ShowMessage(Messages.TwsDisconnectedError, MessageType.ERROR);
        }

        private void OnError(int id, int errorCode, string errorMessage)
        {
            if (ignoredErrorCodes.Contains(errorCode))
            {
                return;
            }

            IO.ShowMessage(Messages.TwsErrorFormat, MessageType.ERROR, errorMessage);
        }
        #endregion

        #region Private helper methods
        private void Shutdown()
        {
            service.Disconnect();
            SaveState();
        }

        private void SaveState()
        {
            service.SaveState();
            IO.ShowMessage(Messages.SavedStateFormat, MessageType.SUCCESS, PropertyFiles.STATE_FILE);
        }

        private void LoadState()
        {
            IO.ShowMessage(Messages.LoadedStateFormat, MessageType.SUCCESS, PropertyFiles.STATE_FILE);
            service.LoadState();
        }

        private void UpdateConsoleTitle()
        {
            IList<string> infoStrings = new List<string>();

            string appName = Messages.AppName;
            if (!string.IsNullOrWhiteSpace(appName))
            {
                infoStrings.Add(appName);
            }

            string tickerSymbol = service.TickerSymbol;
            bool isTickerSet = !string.IsNullOrWhiteSpace(tickerSymbol);
            string tickerDisplay = isTickerSet ? tickerSymbol : Messages.TitleTickerSymbolNotSelected;
            infoStrings.Add(string.Format(Messages.TitleTickerSymbol, tickerDisplay));
            infoStrings.Add(string.Format(Messages.TitleStepSize, service.StepSize));

            if (isTickerSet)
            {
                int positionSize = service.Portfolio.Get(tickerSymbol)?.PositionSize ?? 0;
                infoStrings.Add(string.Format(Messages.TitlePositionSize, positionSize));
                infoStrings.Add(string.Format(Messages.TitleLastFormat, service.GetTick(TickType.LAST)));
                infoStrings.Add(string.Format(Messages.TitleBidAskFormat, service.GetTick(TickType.BID), service.GetTick(TickType.ASK)));
                infoStrings.Add(string.Format(Messages.TitleVolumeFormat, service.GetTick(TickType.VOLUME)));
                infoStrings.Add(string.Format(Messages.TitleCloseFormat, service.GetTick(TickType.CLOSE)));
                infoStrings.Add(string.Format(Messages.TitleOpenFormat, service.GetTick(TickType.OPEN)));
            }

            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }
        #endregion

        #region Validations
        private delegate bool Validation();
        private delegate bool Validator(Action ifValidCallback);

        private void Validate(Validator[] validators, Action ifValidCallback)
        {
            bool valid = false;
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
                () => service.TickerSymbol != null,
                Messages.TickerSymbolNotSetError);
        }

        private Validator IfStepSizeSet()
        {
            return CreateValidator(
                () => service.StepSize > 0,
                Messages.StepSizeNotSetError);
        }

        private Validator IfPriceDataAvailable()
        {
            Func<int, bool> ifAvailable = (tickType)
                => service.GetTick(tickType) > 0;

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
                    IO.ShowMessage(errorMessage, MessageType.VALIDATION_ERROR);
                }
                return valid;
            };
        }
        #endregion
    }
}
