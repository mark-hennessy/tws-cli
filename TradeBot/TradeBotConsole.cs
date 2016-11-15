using IBApi;
using NLog;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TradeBot.Events;
using TradeBot.Extensions;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.Gui;
using TradeBot.MenuFramework;
using TradeBot.TwsAbstractions;
using static TradeBot.AppProperties;
using static TradeBot.Gui.Window;

namespace TradeBot
{
    public class TradeBotConsole
    {
        private TradeBotClient client;
        private Menu menu;

        private int clientId;
        private string clientUrl;
        private int clientPort;

        private bool shouldExitApplication;

        public TradeBotConsole(int clientId, string clientUrl, int clientPort)
        {
            this.clientId = clientId;
            this.clientUrl = clientUrl;
            this.clientPort = clientPort;

            InitClient();
            InitConsole();
            InitMenu();
            InitEventHandlers();
        }

        #region Initialization
        private void InitClient()
        {
            client = new TradeBotClient(clientId);
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

            client.PropertyChanged += OnPropertyChanged;
            client.TickUpdated += OnTickUpdated;
            client.Error += OnError;
            Window.SetWindowCloseHandler(OnWindowClose);
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
            addMenuOption(entries.ReloadSavedState, ReloadSavedState);
            addMenuOption(entries.SetTickerSymbol, PromptForTickerSymbol);
            addMenuOption(entries.SetShares, PromptForShares);
            addMenuOption(entries.SetCash, PromptForCash);
            addMenuOption(entries.Buy, Buy);
            addMenuOption(entries.Sell, Sell);
            addMenuOption(entries.ReversePosition, ReversePosition);
            addMenuOption(entries.ClosePosition, ClosePosition);
            addMenuOption(entries.ListPositions, ListPositions);
            addMenuOption(entries.ListAllPositions, ListAllPositions);
            addMenuOption(entries.ClearScreen, ClearScreen);
            addMenuOption(entries.Help, Help);
            addMenuOption(entries.ExitApplication, ExitApplication);
        }
        #endregion

        #region Properties
        private int _shares;
        private int Shares
        {
            get
            {
                return _shares;
            }
            set
            {
                SetProperty(ref _shares, value, Messages.SharesSetFormat, value);
            }
        }

        private double _cash;
        private double Cash
        {
            get
            {
                return _cash;
            }
            set
            {
                SetProperty(ref _cash, value, Messages.CashSetFormat, value.ToCurrencyString());
            }
        }

        protected void SetProperty<T>(ref T field, T newValue, string message = null, params object[] messageArgs)
        {
            T oldValue = field;
            if (!Equals(oldValue, newValue))
            {
                field = newValue;

                if (!message.IsNullOrEmpty())
                {
                    IO.ShowMessage(LogLevel.Info, message, messageArgs);
                }
            }
        }
        #endregion

        #region Public methods
        public void Start()
        {
            IO.ShowMessage(LogLevel.Info, Messages.WelcomeMessage);

            try
            {
                client.Connect(clientUrl, clientPort);
                LoadState();
                while (!shouldExitApplication)
                {
                    menu.PromptForMenuOption().Command();
                }
            }
            catch (Exception e)
            {
                IO.ShowMessage(LogLevel.Fatal, Messages.ExceptionFormat, e.Message, e.StackTrace);
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

        private void ReloadSavedState()
        {
            LoadState();
        }

        private void PromptForTickerSymbol()
        {
            string tickerSymbol = IO.PromptForInput(Messages.SelectTickerPrompt);
            Do(() =>
            {
                client.TickerSymbol = tickerSymbol;
            },
            IfNotNullOrWhiteSpace(tickerSymbol));
        }

        private void PromptForShares()
        {
            string sharesInput = IO.PromptForInput(Messages.SharesPrompt);
            int? shares = sharesInput.ToInt();
            Do(() =>
            {
                Shares = shares.Value;
            },
            IfHasValue(shares), IfPositive(shares ?? -1));
        }

        private void PromptForCash()
        {
            string cashInput = IO.PromptForInput(Messages.CashPrompt);
            double? cash = cashInput.ToDouble();
            Do(() =>
            {
                Cash = cash.Value;
                SetSharesFromCash();
            },
            IfHasValue(cash), IfPositive(cash ?? -1));
        }

        private void Buy()
        {
            Do(() =>
            {
                client.PlaceBuyLimitOrder(Shares);
            },
            IfTickerSet(), IfSharesSet(), IfCommonTickDataAvailable());
        }

        private void Sell()
        {
            Do(() =>
            {
                client.PlaceSellLimitOrder(Shares);
            },
            IfTickerSet(), IfSharesSet(), IfCommonTickDataAvailable());
        }

        private void ReversePosition()
        {
            ScalePosition(-2);
        }

        private void ClosePosition()
        {
            ScalePosition(-1);
        }

        private void ScalePosition(double percent)
        {
            PortfolioInfo position = client.Portfolio?.Get(client.TickerSymbol);
            Do(() =>
            {
                int orderDelta = (int)Math.Round(position.Position * percent);
                int orderQuantity = Math.Abs(orderDelta);

                if (orderDelta > 0)
                {
                    client.PlaceBuyLimitOrder(orderQuantity);
                }
                else if (orderDelta < 0)
                {
                    client.PlaceSellLimitOrder(orderQuantity);
                }
            },
            IfTickerSet(), IfPositionExists(position), IfCommonTickDataAvailable());
        }

        private void ListPositions()
        {
            Portfolio portfolio = client.Portfolio;
            if (portfolio != null)
            {
                StringBuilder builder = new StringBuilder();
                var portfolioEntries = portfolio.ToList();
                int lastIndex = portfolioEntries.LastIndex();
                for (int i = 0; i < portfolioEntries.Count; i++)
                {
                    var portfolioEntry = portfolioEntries[i];
                    string tickerSymbol = portfolioEntry.Key;
                    PortfolioInfo position = portfolioEntry.Value;

                    builder.AppendFormat(
                        Messages.ListPositionsFormat,
                        position.Position,
                        position.Contract.Symbol,
                        position.AverageCost.ToCurrencyString(),
                        position.MarketPrice.ToCurrencyString(),
                        position.UnrealisedPNL.ToCurrencyString(),
                        position.MarketValue.ToCurrencyString());

                    if (i != lastIndex)
                    {
                        builder.AppendLine();
                    }
                }
                IO.ShowMessage(LogLevel.Info, builder.ToString());
            }
            else
            {
                IO.ShowMessage(LogLevel.Error, Messages.PortfolioNotFound);
            }
        }

        private void ListAllPositions()
        {
            StringBuilder builder = new StringBuilder();
            IList<PositionInfo> positions = client.RequestAllPositionsForAllAccountsAsync().Result;
            int lastIndex = positions.LastIndex();
            for (int i = 0; i < positions.Count; i++)
            {
                var position = positions[i];

                builder.AppendFormat(
                    Messages.ListAllPositionsFormat,
                    position.PositionSize,
                    position.Contract.Symbol,
                    position.Account);

                if (i != lastIndex)
                {
                    builder.AppendLine();
                }
            }
            IO.ShowMessage(LogLevel.Info, builder.ToString());
        }

        private void ClearScreen()
        {
            Console.Clear();
        }

        private void Help()
        {
            IO.ShowMessage(LogLevel.Info, menu.ToString());
        }

        private void ExitApplication()
        {
            shouldExitApplication = true;
        }
        #endregion

        #region Event handlers
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
                IO.ShowMessage(LogLevel.Trace, Messages.TwsConnected);
            }
            else
            {
                IO.ShowMessage(LogLevel.Fatal, Messages.TwsDisconnected);
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
                    IO.ShowMessage(LogLevel.Error, Messages.MultipleAccountsWarningFormat, tradedAccount);
                }

                if (tradedAccount.StartsWith(Messages.PaperAccountPrefix, StringComparison.InvariantCulture))
                {
                    IO.ShowMessage(LogLevel.Warn, Messages.AccountTypePaper);
                }
                else
                {
                    IO.ShowMessage(LogLevel.Error, Messages.AccountTypeLive);
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
                IO.ShowMessage(LogLevel.Trace, Messages.TickerSymbolClearedFormat, oldValue);
            }

            if (!string.IsNullOrWhiteSpace(newValue))
            {
                IO.ShowMessage(LogLevel.Info, Messages.TickerSymbolSetFormat, newValue);

                SetSharesFromCash();
            }

            UpdateConsoleTitle();
        }

        private void OnTickDataChanged(PropertyChangedEventArgs eventArgs)
        {
            UpdateConsoleTitle();
        }

        private void OnTickUpdated(object sender, int tickType, double value)
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
                LogLevel.Info,
                Messages.CommissionFormat,
                lastCommission.ToCurrencyString(),
                totalCommissions.ToCurrencyString());
        }

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
                IO.ShowMessage(LogLevel.Error, Messages.TwsErrorFormat, errorMessage);
            }

            if (e != null)
            {
                IO.ShowMessage(LogLevel.Error, Messages.ExceptionFormat, e.Message, e.StackTrace);
            }
        }

        private bool OnWindowClose(CloseReason reason)
        {
            Shutdown();

            // return false since we didn't handle the control signal, 
            // i.e. Environment.Exit(-1);
            return false;
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
            AppState state = new AppState();
            state.TickerSymbol = client.TickerSymbol;
            state.Shares = Shares;
            state.Cash = Cash;

            PropertySerializer.Serialize(state, PropertyFiles.STATE_FILE);

            IO.ShowMessage(LogLevel.Trace, Messages.SavedStateFormat, PropertyFiles.STATE_FILE);
        }

        private void LoadState()
        {
            AppState state = PropertySerializer.Deserialize<AppState>(PropertyFiles.STATE_FILE);

            client.TickerSymbol = state.TickerSymbol;
            Shares = state.Shares ?? 0;
            Cash = state.Cash ?? 0;

            SetSharesFromCashAsync().Wait();

            IO.ShowMessage(LogLevel.Trace, Messages.LoadedStateFormat, PropertyFiles.STATE_FILE);
        }

        private void SetSharesFromCash()
        {
            if (Cash <= 0)
            {
                return;
            }

            Do(() =>
            {
                double? sharePrice = client.GetTick(TickType.LAST);
                Shares = (int)Math.Floor(Cash / sharePrice.Value);
            },
            IfCommonTickDataAvailable());
        }

        private Task<bool> SetSharesFromCashAsync()
        {
            var tcs = new TaskCompletionSource<bool>();

            var tickHandler = new TickUpdatedEventHandler((sender, tickType, value) =>
            {
                if (!IsCommonTickDataAvailable())
                {
                    return;
                }

                SetSharesFromCash();

                tcs.SafelySetResult(true);
            });

            var onError = new Action<int, int, string, Exception>((id, code, msg, ex) =>
            {
                tcs.SafelySetResult(false);
            });

            tcs.Task.ContinueWith(t =>
            {
                client.TickUpdated -= tickHandler;
                client.Error -= onError;
            });

            client.TickUpdated += tickHandler;
            client.Error += onError;

            return tcs.Task;
        }

        private bool IsCommonTickDataAvailable()
        {
            return client.HasTicks(TickType.LAST, TickType.ASK, TickType.BID);
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
            string tickerDisplay = isTickerSet ? tickerSymbol : Messages.TitleUnavailable;
            infoStrings.Add(string.Format(Messages.TitleTickerSymbol, tickerDisplay));
            infoStrings.Add(string.Format(Messages.TitleShares, Shares));

            if (isTickerSet)
            {
                double position = client.Portfolio?.Get(tickerSymbol)?.Position ?? 0;
                infoStrings.Add(string.Format(Messages.TitlePosition, position));
                infoStrings.Add(string.Format(Messages.TitleLastFormat, GetTickAsCurrencyString(TickType.LAST)));
                infoStrings.Add(string.Format(Messages.TitleBidAskFormat, GetTickAsCurrencyString(TickType.BID), GetTickAsCurrencyString(TickType.ASK)));
                infoStrings.Add(string.Format(Messages.TitleVolumeFormat, GetTickAsString(TickType.VOLUME)));
                infoStrings.Add(string.Format(Messages.TitleCloseFormat, GetTickAsCurrencyString(TickType.CLOSE)));
                infoStrings.Add(string.Format(Messages.TitleOpenFormat, GetTickAsCurrencyString(TickType.OPEN)));
            }

            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }

        private string GetTickAsString(int tickType)
        {
            return GetTickAsFormattedString(tickType, (v) => v.ToString());
        }

        private string GetTickAsCurrencyString(int tickType)
        {
            return GetTickAsFormattedString(tickType, (v) => v.ToCurrencyString());
        }

        private string GetTickAsFormattedString(int tickType, Func<double, string> messageFormatter)
        {
            double? tick = client.GetTick(tickType);
            if (tick.HasValue && tick.Value >= 0)
            {
                return messageFormatter(tick.Value);
            }
            else
            {
                return Messages.TitleUnavailable;
            }
        }
        #endregion

        #region Validations
        /// <summary>
        /// A closure around an isValid condition
        /// such as value != null or value >= 0
        /// </summary>
        /// <returns>true if valid</returns>
        private delegate bool Validation();

        /// <summary>
        /// A closure around a single validation and a corresponding error message.
        /// If valid, then the given callback will be invoked.
        /// If not valid, then the enclosed error message will be shown.
        /// </summary>
        /// <param name="ifValidCallback">the callback to invoke if valid</param>
        /// <returns>true if valid</returns>
        private delegate bool Validator(Action ifValidCallback);

        /// <summary>
        /// Iterates through the given list of validators and invokes the given ifValidCallback 
        /// a single time if all validators are valid.
        /// </summary>
        /// <param name="ifValidCallback">the callback to invoke if valid</param>
        /// <param name="validators">the list of validators</param>
        private void Do(Action ifValidCallback, params Validator[] validators)
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

        private Validator IfSharesSet()
        {
            return CreateValidator(
                () => Shares > 0,
                Messages.SharesNotSetError);
        }

        private Validator IfTickDataAvailable(params int[] tickTypes)
        {
            return CreateValidator(
                () => client.HasTicks(tickTypes),
                Messages.PriceDataUnavailableError);
        }

        private Validator IfCommonTickDataAvailable()
        {
            return CreateValidator(
                () => IsCommonTickDataAvailable(),
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

        private Validator IfHasValue(int? value)
        {
            return CreateValidator(
                () => value.HasValue,
                Messages.InvalidIntegerInputError);
        }

        private Validator IfHasValue(double? value)
        {
            return CreateValidator(
                () => value.HasValue,
                Messages.InvalidDecimalInputError);
        }

        private Validator IfPositive(int value)
        {
            return CreateValidator(
                () => value >= 0,
                Messages.InvalidPositiveInputError);
        }

        private Validator IfPositive(double value)
        {
            return CreateValidator(
                () => value >= 0,
                Messages.InvalidPositiveInputError);
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
                    IO.ShowMessage(LogLevel.Error, errorMessage);
                }
                return valid;
            };
        }
        #endregion
    }
}
