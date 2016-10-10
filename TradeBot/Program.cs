using IBApi;
using System;
using System.Collections.Generic;
using TradeBot.Collections;
using TradeBot.Extensions;
using TradeBot.Gen;
using TradeBot.Gui;
using TradeBot.MenuFramework;
using TradeBot.Tws;
using static TradeBot.Gui.Window;
using static TradeBot.Resources;

namespace TradeBot
{
    public class Program : TwsResponseHandler
    {
        public static void Main(string[] args)
        {
            Program program = new Program();
            program.Start();
        }



        private IList<int> ignoredErrorCodes;
        private IDictionary<int, Order> recentOrders;
        private PriceDataStore priceDatabase;
        private Contract currentContract;

        private TwsClient client;
        private Menu menu;
        private int currentTickerId;
        private int nextValidOrderId;
        private bool shouldExitApplication;

        public Program()
        {
            InitializeCollections();
            InitializeConsole();
            InitializeClient();
            InitializeMenu();
        }

        private void InitializeCollections()
        {
            ignoredErrorCodes = new List<int>()
            {
                ErrorCodes.MARKET_DATA_FARM_DISCONNECTED,
                ErrorCodes.MARKET_DATA_FARM_CONNECTED,
                ErrorCodes.HISTORICAL_DATA_FARM_DISCONNECTED,
                ErrorCodes.HISTORICAL_DATA_FARM_CONNECTED
            };

            recentOrders = new Dictionary<int, Order>();
            priceDatabase = new PriceDataStore();
        }

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

        private void InitializeClient()
        {
            client = new TwsClient(this);
        }

        private void InitializeMenu()
        {
            menu = new Menu();

            Action<IList<string>, Action> addMenuOption = (entry, command)
                => menu.AddMenuOption(entry[0], entry[1], command);

            MenuOptionEntries menuOptionEntry = Messages.MenuOptionEntries;
            addMenuOption(menuOptionEntry.LoadSavedState, LoadSavedStateCommand);
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

        private void OnConnectionEstablished()
        {
            IO.ShowMessage(Messages.TwsConnected, MessageType.SUCCESS);
        }

        private bool OnWindowClose(CloseReason reason)
        {
            Shutdown();

            // return false since we didn't handle the control signal, 
            // i.e. Environment.Exit(-1);
            return false;
        }

        private void Shutdown()
        {
            client.eDisconnect();
            PersistState();
        }

        private void LoadSavedStateCommand()
        {
            LoadPersistedState();
            IO.ShowMessage(Messages.LoadedState, MessageType.SUCCESS);

            string ticker = State.TickerSymbol;
            if (!string.IsNullOrWhiteSpace(ticker))
            {
                RequestMarketData(ticker);
            }
            int? stepSize = State.StepSize;
            if (stepSize.HasValue)
            {
                SetStepSize(stepSize.Value);
            }
        }

        private void RequestMarketDataCommand()
        {
            string tickerSymbol = IO.PromptForInput(Messages.SelectTickerPrompt);
            RequestMarketData(tickerSymbol);
        }

        private void RequestMarketData(string tickerSymbol)
        {
            IfNotNullOrWhiteSpace(tickerSymbol, () =>
            {
                CancelMarketData();

                currentTickerId++;
                currentContract = ContractFactory.CreateStockContract(tickerSymbol);
                client.reqMktData(currentTickerId, currentContract, "", false, null);
                State.TickerSymbol = tickerSymbol;

                IO.ShowMessage(Messages.TickerSelectedFormat, currentContract.Symbol);
            });
        }

        private void CancelMarketDataCommand()
        {
            CancelMarketData();
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
                        double sharePrice = priceDatabase.GetPriceData(currentContract.ConId)[TickType.LAST];
                        int stepSize = (int)Math.Floor(cash.Value / sharePrice);
                        SetStepSize(stepSize);
                    });
                });
            });
        }

        private void BuyCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                int totalQuantity = State.StepSize.Value;
                double price = GetCurrentPrice(TickType.ASK);
                PlaceOrder(OrderActions.BUY, totalQuantity, price);
            });
        }

        private void SellCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                int totalQuantity = State.StepSize.Value;
                double price = GetCurrentPrice(TickType.BID);
                PlaceOrder(OrderActions.SELL, totalQuantity, price);
            });
        }

        private void ReversePositionCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
            });
        }

        private void ClosePositionCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
            });
        }

        private void PlaceOrder(OrderActions action, int totalQuantity, double price)
        {
            int orderId = nextValidOrderId++;
            Order order = OrderFactory.CreateLimitOrder(action, totalQuantity, price);
            client.placeOrder(orderId, currentContract, order);
        }

        private void ToggleDebugMessagesCommand()
        {
            bool hideDebugMessages = State.HideDebugMessages ?? false;
            bool toggledValue = !hideDebugMessages;
            State.HideDebugMessages = toggledValue;

            IO.ShowMessage(Messages.HideDebugMessagesFormat, toggledValue);
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

        public override void connectionClosed()
        {
            IO.ShowMessage(Messages.TwsDisconnectedError, MessageType.ERROR);
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

        public override void nextValidId(int nextValidOrderId)
        {
            this.nextValidOrderId = nextValidOrderId;
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

        private void ClearCurrentContract()
        {
            if (currentContract != null)
            {
                IO.ShowMessage(Messages.TickerClearedFormat, currentContract.Symbol);
            }
            currentContract = null;
            Console.Title = string.Empty;
            State.TickerSymbol = null;
        }

        private void SetStepSize(int stepSize)
        {
            stepSize = Math.Abs(stepSize);
            State.StepSize = stepSize;

            IO.ShowMessage(Messages.StepSizeSetFormat, stepSize);
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
            infoStrings.Add(string.Format(Messages.TitleTicker, currentContract.Symbol));
            infoStrings.Add(string.Format(Messages.TitleLastFormat, priceData[TickType.LAST]));
            infoStrings.Add(string.Format(Messages.TitleStepSize, State.StepSize ?? -1));
            infoStrings.Add(string.Format(Messages.TitlePositionSize, 0));
            infoStrings.Add(string.Format(Messages.TitleBidAskFormat, priceData[TickType.BID], priceData[TickType.ASK]));
            infoStrings.Add(string.Format(Messages.TitleVolumeFormat, priceData[TickType.VOLUME]));
            infoStrings.Add(string.Format(Messages.TitleCloseFormat, priceData[TickType.CLOSE]));
            infoStrings.Add(string.Format(Messages.TitleOpenFormat, priceData[TickType.OPEN]));
            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }

        private double GetCurrentPrice(int tickType)
        {
            return priceDatabase[currentTickerId][tickType];
        }

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
            int? stepSize = State.StepSize;
            if (stepSize.HasValue && stepSize.Value > 0)
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
            if (GetCurrentPrice(TickType.ASK) > 0)
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
    }
}
