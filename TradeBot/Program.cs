using IBApi;
using System;
using System.Collections.Generic;
using TradeBot.Collections;
using TradeBot.Extensions;
using TradeBot.FileIO;
using TradeBot.Gen;
using TradeBot.Gui;
using TradeBot.MenuFramework;
using TradeBot.Tws;
using static TradeBot.GlobalProperties;
using static TradeBot.Gui.Window;

namespace TradeBot
{
    public class Program : TwsResponseHandler
    {
        public static void Main(string[] args)
        {
            Program program = new Program();
            program.Start();
        }

        private readonly IList<int> ignoredErrorCodes = new List<int>()
        {
            ErrorCodes.MARKET_DATA_FARM_DISCONNECTED,
            ErrorCodes.MARKET_DATA_FARM_CONNECTED,
            ErrorCodes.HISTORICAL_DATA_FARM_DISCONNECTED,
            ErrorCodes.HISTORICAL_DATA_FARM_CONNECTED
        };

        private Menu menu;
        private TwsClient client;
        private AppState state;
        private PriceDataStore priceDatabase;
        private IDictionary<int, Order> recentOrders;
        private Contract currentContract;

        private int currentTickerId;
        private int nextValidOrderId;
        private bool shouldExitApplication;

        public Program()
        {
            client = new TwsClient(this);
            state = new AppState();
            priceDatabase = new PriceDataStore();
            recentOrders = new Dictionary<int, Order>();

            InitializeConsole();
            InitializeMenu();
        }

        #region Initialization
        private void InitializeConsole()
        {
            Console.Title = Messages.AppName;
            if (Preferences.CenterWindow)
            {
                SetWindowSizeAndCenter(
                    Preferences.WindowWidth,
                    Preferences.WindowHeight);
            }
            SetWindowCloseHandler(OnWindowClose);
        }

        private void InitializeMenu()
        {
            menu = new Menu();

            Action<IList<string>, Action> addMenuOption = (entry, command)
                => menu.AddMenuOption(entry[0], entry[1], command);

            MenuOptionEntries menuOptionEntry = Messages.MenuOptionEntries;
            addMenuOption(menuOptionEntry.ReloadSavedState, ReloadSavedStateCommand);
            addMenuOption(menuOptionEntry.RequestMarketData, RequestMarketDataCommand);
            addMenuOption(menuOptionEntry.CancelMarketData, CancelMarketDataCommand);
            addMenuOption(menuOptionEntry.SetStepSize, SetStepSizeCommand);
            addMenuOption(menuOptionEntry.SetStepSizeFromCash, SetStepSizeFromCashCommand);
            addMenuOption(menuOptionEntry.Buy, BuyCommand);
            addMenuOption(menuOptionEntry.Sell, SellCommand);
            addMenuOption(menuOptionEntry.ReversePosition, ReversePositionCommand);
            addMenuOption(menuOptionEntry.ClosePosition, ClosePositionCommand);
            addMenuOption(menuOptionEntry.ToggleDebugMessages, ToggleDebugMessagesCommand);
            addMenuOption(menuOptionEntry.Misc, MiscCommand);
            addMenuOption(menuOptionEntry.ClearScreen, ClearScreenCommand);
            addMenuOption(menuOptionEntry.Help, HelpCommand);
            addMenuOption(menuOptionEntry.ExitApplication, ExitApplicationCommand);
        }
        #endregion

        #region Events
        private void OnConnectionEstablished()
        {
            IO.ShowMessage(Messages.TwsConnected, MessageType.SUCCESS);
            LoadState();
        }

        private bool OnWindowClose(CloseReason reason)
        {
            Shutdown();

            // return false since we didn't handle the control signal, 
            // i.e. Environment.Exit(-1);
            return false;
        }
        #endregion

        #region Properties
        public string TickerSymbol
        {
            get
            {
                return state.TickerSymbol;
            }
            set
            {
                state.TickerSymbol = value?.ToUpper();
            }
        }

        public int StepSize
        {
            get
            {
                return state.StepSize ?? -1;
            }
            set
            {
                state.StepSize = Math.Abs(value);
            }
        }

        public bool ShowDebugMessages
        {
            get
            {
                return state.ShowDebugMessages ?? false;
            }
            set
            {
                state.ShowDebugMessages = value;
                IO.ShowDebugMessages = value;
            }
        }
        #endregion

        #region Public methods
        public void Start()
        {
            IO.ShowMessage(Messages.WelcomeMessage);

            try
            {
                client.eConnect();
                // It's safe to call OnConnectionEstablished here because eConnect is 
                // a synchronous operation that will throw an exception if it fails. 
                OnConnectionEstablished();
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

        private void RequestMarketDataCommand()
        {
            string tickerSymbol = IO.PromptForInput(Messages.SelectTickerPrompt);
            IfNotNullOrWhiteSpace(tickerSymbol, () =>
            {
                RequestMarketData(tickerSymbol);
            });
        }

        private void CancelMarketDataCommand()
        {
            CancelMarketData();
        }

        private void SetStepSizeCommand()
        {
            string stepSizeString = IO.PromptForInput(Messages.StepSizePrompt);
            int? stepSize = stepSizeString.ToInt();
            IfHasValue(stepSize, () =>
            {
                SetStepSize(stepSize.Value);
            });
        }

        private void SetStepSizeFromCashCommand()
        {
            IfTickerSet(() =>
            {
                IfPriceDataAvailable(() =>
                {
                    string cashString = IO.PromptForInput(Messages.StepSizeFromCashPrompt);
                    double? cash = cashString.ToDouble();
                    IfHasValue(cash, () =>
                    {
                        SetStepSizeFromCash(cash.Value);
                    });
                });
            });
        }

        private void BuyCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                PlaceOrder(OrderActions.BUY, StepSize, GetPrice(TickType.ASK));
            });
        }

        private void SellCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                PlaceOrder(OrderActions.SELL, StepSize, GetPrice(TickType.BID));
            });
        }

        private void ReversePositionCommand()
        {
            client.reqPositions();
            //IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            //{
            //});
        }

        private void ClosePositionCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
            });
        }

        private void ToggleDebugMessagesCommand()
        {
            ToggleDebugMessages();
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

        #region TWS callbacks
        public override void managedAccounts(string accounts)
        {
            if (accounts.Contains(Preferences.AccountLive))
            {
                IO.ShowMessage(Messages.AccountTypeLive, MessageType.ERROR);
            }
            else if (accounts.Contains(Preferences.AccountPaper))
            {
                IO.ShowMessage(Messages.AccountTypePaper, MessageType.SUCCESS);
            }
        }

        public override void nextValidId(int nextValidOrderId)
        {
            this.nextValidOrderId = nextValidOrderId;
        }

        public override void tickPrice(int tickerId, int field, double price, int canAutoExecute)
        {
            priceDatabase[tickerId][field] = price;
            if (tickerId == currentTickerId)
            {
                UpdateWindowTitle(tickerId);
            }
        }

        public override void tickSize(int tickerId, int field, int size)
        {
            priceDatabase[tickerId][field] = size;
        }

        public override void error(Exception exception)
        {
            error(exception.Message);
        }

        public override void error(string errorMessage)
        {
            IO.ShowMessage(Messages.TwsErrorFormat, MessageType.ERROR, errorMessage);
        }

        public override void error(int id, int errorCode, string errorMessage)
        {
            if (ignoredErrorCodes.Contains(errorCode))
            {
                return;
            }

            IO.ShowMessage(Messages.TwsErrorFormat, MessageType.ERROR, errorMessage);

            switch (errorCode)
            {
                case ErrorCodes.TICKER_NOT_FOUND:
                    ClearCurrentContract();
                    break;
            }
        }

        public override void connectionClosed()
        {
            IO.ShowMessage(Messages.TwsDisconnectedError, MessageType.ERROR);
        }
        #endregion

        #region Helper methods
        private void LoadState()
        {
            state = PropertySerializer.Deserialize<AppState>(PropertyFiles.STATE_FILE);
            IO.ShowMessage(Messages.LoadedState, MessageType.SUCCESS);

            if (!string.IsNullOrWhiteSpace(TickerSymbol))
            {
                RequestMarketData(TickerSymbol);
            }

            SetStepSize(StepSize);

            IO.ShowDebugMessages = ShowDebugMessages;
        }

        private void SaveState()
        {
            string path = PropertyFiles.STATE_FILE;
            PropertySerializer.Serialize(state, path);
            IO.ShowMessage(Messages.StateSavedFormat, MessageType.SUCCESS, path);
        }

        private void Shutdown()
        {
            client.eDisconnect();
            SaveState();
        }

        private void RequestMarketData(string tickerSymbol)
        {
            CancelMarketData();

            currentTickerId++;
            currentContract = ContractFactory.CreateStockContract(tickerSymbol);
            client.reqMktData(currentTickerId, currentContract, "", false, null);
            TickerSymbol = tickerSymbol;

            IO.ShowMessage(Messages.TickerSelectedFormat, TickerSymbol);
        }

        private void CancelMarketData()
        {
            if (currentContract != null)
            {
                client.cancelMktData(currentTickerId);
                priceDatabase.RemovePriceData(currentTickerId);
            }
            ClearCurrentContract();
        }

        private void ClearCurrentContract()
        {
            if (currentContract != null)
            {
                IO.ShowMessage(Messages.TickerClearedFormat, currentContract.Symbol);
            }
            currentContract = null;
            TickerSymbol = null;
            Console.Title = string.Empty;
        }

        private void SetStepSize(int stepSize)
        {
            StepSize = stepSize;

            IO.ShowMessage(Messages.StepSizeSetFormat, stepSize);
        }

        private void SetStepSizeFromCash(double cash)
        {
            double sharePrice = GetPrice(TickType.LAST);
            int stepSize = (int)Math.Floor(cash / sharePrice);
            SetStepSize(stepSize);
        }

        private double GetPrice(int tickType)
        {
            return priceDatabase[currentTickerId][tickType];
        }

        private void PlaceOrder(OrderActions action, int totalQuantity, double price)
        {
            int orderId = nextValidOrderId++;
            Order order = OrderFactory.CreateLimitOrder(action, totalQuantity, price);
            client.placeOrder(orderId, currentContract, order);
        }

        private void ToggleDebugMessages()
        {
            ShowDebugMessages = !ShowDebugMessages;
            IO.ShowMessage(Messages.ShowDebugMessagesFormat, ShowDebugMessages);
        }

        private void UpdateWindowTitle(int tickerId)
        {
            var priceData = priceDatabase[tickerId];
            IList<string> infoStrings = new List<string>();
            string appName = Messages.AppName;
            if (!string.IsNullOrWhiteSpace(appName))
            {
                infoStrings.Add(appName);
            }
            infoStrings.Add(string.Format(Messages.TitleTicker, TickerSymbol));
            infoStrings.Add(string.Format(Messages.TitleLastFormat, priceData[TickType.LAST]));
            infoStrings.Add(string.Format(Messages.TitleStepSize, StepSize));
            infoStrings.Add(string.Format(Messages.TitlePositionSize, 0));
            infoStrings.Add(string.Format(Messages.TitleBidAskFormat, priceData[TickType.BID], priceData[TickType.ASK]));
            infoStrings.Add(string.Format(Messages.TitleVolumeFormat, priceData[TickType.VOLUME]));
            infoStrings.Add(string.Format(Messages.TitleCloseFormat, priceData[TickType.CLOSE]));
            infoStrings.Add(string.Format(Messages.TitleOpenFormat, priceData[TickType.OPEN]));
            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }
        #endregion

        #region Validations
        private void IfTickerSet(Action action)
        {
            if (currentContract != null)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.TickerNotSelectedError, MessageType.VALIDATION_ERROR);
            }

        }

        private void IfStepSizeSet(Action action)
        {
            if (StepSize > 0)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.StepSizeNotSetError, MessageType.VALIDATION_ERROR);
            }

        }

        private void IfPriceDataAvailable(Action action)
        {
            if (GetPrice(TickType.LAST) > 0)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.PriceDataUnavailableError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfNotNullOrWhiteSpace(string str, Action action)
        {
            if (!string.IsNullOrWhiteSpace(str))
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.InvalidNonEmptyStringInputError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfHasValue(int? nullable, Action action)
        {
            if (nullable.HasValue)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.InvalidIntegerInputError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfHasValue(double? nullable, Action action)
        {
            if (nullable.HasValue)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.InvalidDecimalInputError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfTickerAndStepSizeSetAndPriceDataAvailable(Action action)
        {
            IfTickerSet(() =>
            {
                IfStepSizeSet(() =>
                {
                    IfPriceDataAvailable(() =>
                    {
                        action();
                    });
                });
            });
        }
        #endregion
    }
}
