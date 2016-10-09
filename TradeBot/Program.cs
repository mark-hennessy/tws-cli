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
        private StockContract selectedContract;
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
            addMenuOption(menuOptionEntry.SetPositionSize, SetPositionSizeCommand);
            addMenuOption(menuOptionEntry.SetPositionSizeFromCash, SetPositionSizeFromCashCommand);
            addMenuOption(menuOptionEntry.BuyPosition, BuyPositionCommand);
            addMenuOption(menuOptionEntry.SellPosition, SellPositionCommand);
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

        private void LoadStateCommand()
        {
            LoadPersistedState();
            IO.ShowMessage(Messages.LoadedState, MessageType.SUCCESS);
            SetTicker(State.Ticker);
            SetShares(State.Shares);
        }

        private void SetTickerCommand()
        {
            string ticker = IO.PromptForInput(Messages.SelectTickerPrompt);
            SetTicker(ticker);
        }

        private void SetTicker(string ticker)
        {
            ValidateNotNullOrWhiteSpace(ticker, () =>
            {
                ClearTicker();
                SetSelectedTickerState(ticker);
                client.reqMktData(selectedContract.Id, selectedContract, "", false, null);
            });
        }

        private void ClearTickerCommand()
        {
            ClearTicker();
        }

        private void ClearTicker()
        {
            if (selectedContract == null)
            {
                return;
            }

            client.cancelMktData(selectedContract.Id);
            ClearSelectedTickerState();
        }

        private void SetPositionSizeFromCashCommand()
        {
            ValidateTickerSetAndPriceDataAvailable(() =>
            {
                string cashString = IO.PromptForInput(Messages.SetCashPrompt);
                double? cash = cashString.ToDouble();
                ValidateHasValue(cash, () =>
                {
                    double sharePrice = selectedContract.PriceData[TickType.LAST];
                    int shares = (int)Math.Floor(cash.Value / sharePrice);
                    SetShares(shares);
                });
            });
        }

        private void SetPositionSizeCommand()
        {
            ValidateTickerSetAndPriceDataAvailable(() =>
            {
                string sharesString = IO.PromptForInput(Messages.SetSharesPrompt);
                int? shares = sharesString.ToInt();
                SetShares(shares);
            });
        }

        private void BuyPositionCommand()
        {
        }

        private void SellPositionCommand()
        {
        }

        private void ReversePositionCommand()
        {
        }

        private void ClosePositionCommand()
        {
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
            IO.ShowMessage(Messages.TwsDisconnected, MessageType.ERROR);
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
            selectedContract = new StockContract(ticker);
            contracts.Add(selectedContract.Id, selectedContract);
            State.Ticker = ticker;
            IO.ShowMessage(Messages.TickerSelectedFormat, selectedContract.Symbol);
        }

        private void ClearSelectedTickerState()
        {
            string ticker = selectedContract.Symbol;
            contracts.Remove(selectedContract.Id);
            selectedContract = null;
            State.Ticker = null;
            State.Shares = null;
            Console.Title = string.Empty;
            IO.ShowMessage(Messages.TickerClearedFormat, ticker);
        }

        private void SetShares(int? shares)
        {
            ValidateTickerSetAndPriceDataAvailable(() =>
            {
                ValidateHasValue(shares, () =>
                {
                    selectedContract.PositionSize = shares.Value;
                    State.Shares = shares;
                    IO.ShowMessage(Messages.PositionSizeSetFormat, shares);
                });
            });
        }

        private void UpdatePriceInfo(int tickerId, int field, double value)
        {
            if (contracts.ContainsKey(tickerId))
            {
                contracts[tickerId].PriceData[field] = value;
            }
        }

        private void UpdateWindowTitleIfNecessary(int tickerId)
        {
            if (tickerId != selectedContract.Id)
            {
                return;
            }

            PriceData priceInfo = selectedContract.PriceData;
            IList<string> infoStrings = new List<string>();
            string appName = Messages.AppName;
            if (!string.IsNullOrWhiteSpace(appName))
            {
                infoStrings.Add(appName);
            }
            infoStrings.Add(string.Format(Messages.TitleTicker, selectedContract.Symbol));
            infoStrings.Add(string.Format(Messages.TitleLastFormat, priceInfo[TickType.LAST]));
            infoStrings.Add(string.Format(Messages.TitlePositionSize, selectedContract.PositionSize));
            infoStrings.Add(string.Format(Messages.TitleBidAskFormat, priceInfo[TickType.BID], priceInfo[TickType.ASK]));
            infoStrings.Add(string.Format(Messages.TitleOpenFormat, priceInfo[TickType.OPEN]));
            infoStrings.Add(string.Format(Messages.TitleCloseFormat, priceInfo[TickType.CLOSE]));
            infoStrings.Add(string.Format(Messages.TitleVolumeFormat, priceInfo[TickType.VOLUME]));
            infoStrings.Add(string.Format(Messages.TitleAverageVolumeFormat, priceInfo[TickType.AVG_VOLUME]));
            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }

        private void ValidateTickerSetAndPriceDataAvailable(Action action)
        {
            ValidateTickerSet(() =>
            {
                ValidatePriceDataAvailable(() =>
                {
                    action();
                });
            });
        }

        private void ValidateTickerSet(Action action)
        {
            if (selectedContract == null)
            {
                IO.ShowMessage(Messages.TickerNotSelectedError, MessageType.ERROR);
                return;
            }

            action();
        }

        private void ValidatePriceDataAvailable(Action action)
        {
            if (selectedContract == null || selectedContract.PriceData[TickType.LAST] <= 0)
            {
                IO.ShowMessage(Messages.PriceDataUnavailableError, MessageType.ERROR);
                return;
            }

            action();
        }

        private void ValidateNotNullOrWhiteSpace(string str, Action action)
        {
            if (string.IsNullOrWhiteSpace(str))
            {
                IO.ShowMessage(Messages.InvalidNonEmptyStringInput, MessageType.ERROR);
                return;
            }

            action();
        }

        private void ValidateHasValue(int? nullable, Action action)
        {
            if (!nullable.HasValue)
            {
                IO.ShowMessage(Messages.InvalidIntegerInput, MessageType.ERROR);
                return;
            }

            action();
        }

        private void ValidateHasValue(double? nullable, Action action)
        {
            if (!nullable.HasValue)
            {
                IO.ShowMessage(Messages.InvalidDecimalInput, MessageType.ERROR);
                return;
            }

            action();
        }
    }
}
