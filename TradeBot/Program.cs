using IBApi;
using System;
using System.Collections.Generic;
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


        private TwsClient client;
        private Menu menu;

        private IList<int> ignoredErrorCodes;
        private IDictionary<int, StockContract> contracts;
        private StockContract currentContract;
        private LimitOrder pendingOrder;
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

            contracts = new Dictionary<int, StockContract>();
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
            addMenuOption(menuOptionEntry.LoadState, LoadStateCommand);
            addMenuOption(menuOptionEntry.SetTicker, SetTickerCommand);
            addMenuOption(menuOptionEntry.ClearTicker, ClearTickerCommand);
            addMenuOption(menuOptionEntry.SetStepSize, SetStepSizeCommand);
            addMenuOption(menuOptionEntry.SetStepSizeFromCash, SetStepSizeFromCashCommand);
            addMenuOption(menuOptionEntry.Buy, BuyCommand);
            addMenuOption(menuOptionEntry.Sell, SellCommand);
            addMenuOption(menuOptionEntry.ReversePosition, ReversePositionCommand);
            addMenuOption(menuOptionEntry.ClosePosition, ClosePositionCommand);
            addMenuOption(menuOptionEntry.CancelOrder, CancelOrderCommand);
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

        private void LoadStateCommand()
        {
            LoadPersistedState();
            IO.ShowMessage(Messages.LoadedState, MessageType.SUCCESS);
            string ticker = State.Ticker;
            if (!string.IsNullOrWhiteSpace(ticker))
            {
                SetTicker(ticker);
            }
            int? stepSize = State.StepSize;
            if (stepSize.HasValue)
            {
                SetStepSize(stepSize.Value);
            }
        }

        private void SetTickerCommand()
        {
            string ticker = IO.PromptForInput(Messages.SelectTickerPrompt);
            SetTicker(ticker);
        }

        private void SetTicker(string ticker)
        {
            IfNotNullOrWhiteSpace(ticker, () =>
            {
                ClearTicker();
                SetSelectedTickerState(ticker);
                client.reqMktData(currentContract.Id, currentContract, "", false, null);
            });
        }

        private void ClearTickerCommand()
        {
            ClearTicker();
        }

        private void ClearTicker()
        {
            if (currentContract == null)
            {
                return;
            }

            client.cancelMktData(currentContract.Id);
            ClearSelectedTickerState();
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
                        double sharePrice = currentContract.PriceData[TickType.LAST];
                        int stepSize = (int)Math.Floor(cash.Value / sharePrice);
                        SetStepSize(stepSize);
                    });
                });
            });
        }

        private void BuyCommand()
        {
            PlaceOrder(OrderActions.BUY);
        }

        private void SellCommand()
        {
            PlaceOrder(OrderActions.SELL);
        }

        private void PlaceOrder(OrderActions action)
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                IfPendingOrderDoesNotExist(() =>
                {
                    int orderId = GenerateOrderId();
                    pendingOrder = new LimitOrder(action, State.StepSize.Value, 127.46);
                    client.placeOrder(orderId, currentContract, pendingOrder);
                });
            });
        }

        private void ReversePositionCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                IfPendingOrderDoesNotExist(() =>
                {
                });
            });
        }

        private void ClosePositionCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                IfPendingOrderDoesNotExist(() =>
                {
                });
            });
        }

        private void CancelOrderCommand()
        {
            IfPendingOrderExists(() =>
            {
                client.cancelOrder(pendingOrder.OrderId);
            });
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
            UpdatePriceInfo(tickerId, field, price);
            UpdateWindowTitleIfNecessary(tickerId);
        }

        public override void tickSize(int tickerId, int field, int size)
        {
            UpdatePriceInfo(tickerId, field, size);
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
                    ClearSelectedTickerState();
                    break;
            }
        }

        private void SetSelectedTickerState(string ticker)
        {
            ticker = ticker.ToUpper();
            currentContract = new StockContract(ticker);
            contracts.Add(currentContract.Id, currentContract);
            State.Ticker = ticker;
            IO.ShowMessage(Messages.TickerSelectedFormat, currentContract.Symbol);
        }

        private void ClearSelectedTickerState()
        {
            string ticker = currentContract.Symbol;
            contracts.Remove(currentContract.Id);
            currentContract = null;
            State.Ticker = null;
            State.StepSize = null;
            Console.Title = string.Empty;
            IO.ShowMessage(Messages.TickerClearedFormat, ticker);
        }

        private void SetStepSize(int stepSize)
        {
            stepSize = Math.Abs(stepSize);
            State.StepSize = stepSize;
            IO.ShowMessage(Messages.StepSizeSetFormat, stepSize);
        }

        private void UpdatePriceInfo(int tickerId, int field, double value)
        {
            if (contracts.ContainsKey(tickerId))
            {
                contracts[tickerId].PriceData[field] = value;
            }
        }

        private int GenerateOrderId()
        {
            return nextValidOrderId++;
        }

        private void UpdateWindowTitleIfNecessary(int tickerId)
        {
            if (tickerId != currentContract.Id)
            {
                return;
            }

            PriceData priceInfo = currentContract.PriceData;
            IList<string> infoStrings = new List<string>();
            string appName = Messages.AppName;
            if (!string.IsNullOrWhiteSpace(appName))
            {
                infoStrings.Add(appName);
            }
            infoStrings.Add(string.Format(Messages.TitleTicker, currentContract.Symbol));
            infoStrings.Add(string.Format(Messages.TitleLastFormat, priceInfo[TickType.LAST]));
            infoStrings.Add(string.Format(Messages.TitleStepSize, State.StepSize));
            infoStrings.Add(string.Format(Messages.TitlePositionSize, 0));
            infoStrings.Add(string.Format(Messages.TitleBidAskFormat, priceInfo[TickType.BID], priceInfo[TickType.ASK]));
            infoStrings.Add(string.Format(Messages.TitleOpenFormat, priceInfo[TickType.OPEN]));
            infoStrings.Add(string.Format(Messages.TitleCloseFormat, priceInfo[TickType.CLOSE]));
            infoStrings.Add(string.Format(Messages.TitleVolumeFormat, priceInfo[TickType.VOLUME]));
            infoStrings.Add(string.Format(Messages.TitleAverageVolumeFormat, priceInfo[TickType.AVG_VOLUME]));
            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
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
            if (currentContract != null && currentContract.PriceData[TickType.LAST] > 0)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.PriceDataUnavailableError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfPendingOrderExists(Action action)
        {
            if (pendingOrder != null)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.PendingOrderNotFoundError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfPendingOrderDoesNotExist(Action action)
        {
            if (pendingOrder == null)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.PendingOrderFoundError, MessageType.VALIDATION_ERROR);
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
