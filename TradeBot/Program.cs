using IBApi;
using System;
using System.Collections.Generic;
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
            if (Preferences.WindowCentered)
            {
                SetWindowSizeAndCenter(Preferences.WindowWidth, Preferences.WindowHeight);
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
            addMenuOption(menuOptionEntry.SelectTicker, SelectTickerCommand);
            addMenuOption(menuOptionEntry.DeselectCurrentTicker, DeselectCurrentTickerCommand);
            addMenuOption(menuOptionEntry.BuyPosition, BuyPositionCommand);
            addMenuOption(menuOptionEntry.SellPosition, SellPositionCommand);
            addMenuOption(menuOptionEntry.ReversePosition, ReversePositionCommand);
            addMenuOption(menuOptionEntry.ClosePosition, ClosePositionCommand);
            addMenuOption(menuOptionEntry.ToggleInfoMessages, ToggleInfoMessagesCommand);
            addMenuOption(menuOptionEntry.Misc, MiscCommand);
            addMenuOption(menuOptionEntry.Help, HelpCommand);
            addMenuOption(menuOptionEntry.ExitApplication, ExitApplicationCommand);
        }

        public void Start()
        {
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
                    IO.PromptForKey(Messages.Exiting);
                }
            }
        }

        private void OnConnectionEstablished()
        {
            string selectedTicker = State.SelectedTicker;
            if (!string.IsNullOrWhiteSpace(selectedTicker))
            {
                SelectTicker(selectedTicker);
            }
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
            PersistState();
            client.eDisconnect();
        }

        private void SelectTickerCommand()
        {
            string ticker = IO.PromptForInput(Messages.SelectTickerPrompt);
            ExecuteIfInputNotEmpty(() => SelectTicker(ticker), ticker);
        }

        private void SelectTicker(string ticker)
        {
            DeselectCurrentTicker();
            SetSelectedTickerState(ticker);
            client.reqMktData(selectedContract.Id, selectedContract, "", false, null);
        }

        private void DeselectCurrentTickerCommand()
        {
            DeselectCurrentTicker();
        }

        private void DeselectCurrentTicker()
        {
            if (selectedContract == null)
            {
                return;
            }

            client.cancelMktData(selectedContract.Id);
            ClearSelectedTickerState();
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

        private void ToggleInfoMessagesCommand()
        {
            State.ShowInfoMessages = !State.ShowInfoMessages;
            IO.ShowMessage(Messages.ShowInfoToggleFormat, State.ShowInfoMessages);
        }

        private void MiscCommand()
        {
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
            IO.ShowMessage(Messages.ErrorMessageFormat, MessageType.ERROR, errorMessage);
        }

        public override void error(int id, int errorCode, string errorMessage)
        {
            if (ignoredErrorCodes.Contains(errorCode))
            {
                return;
            }

            IO.ShowMessage(Messages.ErrorMessageFormat, MessageType.ERROR, errorMessage);

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
            State.SelectedTicker = ticker;

            IO.ShowMessage(Messages.SelectedCurrentTickerFormat, selectedContract.Symbol);
        }

        private void ClearSelectedTickerState()
        {
            string ticker = selectedContract.Symbol;
            contracts.Remove(selectedContract.Id);
            selectedContract = null;
            State.SelectedTicker = null;
            Console.Title = string.Empty;

            IO.ShowMessage(Messages.DeselectedCurrentTickerFormat, ticker);
        }

        private void UpdatePriceInfo(int tickerId, int field, double value)
        {
            if (contracts.ContainsKey(tickerId))
            {
                contracts[tickerId].PriceInfo[field] = value;
            }
        }

        private void UpdateWindowTitleIfNecessary(int tickerId)
        {
            if (tickerId != selectedContract.Id)
            {
                return;
            }

            PriceInfo priceInfo = selectedContract.PriceInfo;
            IList<string> infoStrings = new List<string>();
            infoStrings.Add(string.Format(Messages.TitleTicker, selectedContract.Symbol));
            infoStrings.Add(string.Format(Messages.TitleLastFormat, priceInfo[TickType.LAST]));
            infoStrings.Add(string.Format(Messages.TitleBidAskFormat, priceInfo[TickType.BID], priceInfo[TickType.ASK]));
            infoStrings.Add(string.Format(Messages.TitleOpenFormat, priceInfo[TickType.OPEN]));
            infoStrings.Add(string.Format(Messages.TitleCloseFormat, priceInfo[TickType.CLOSE]));
            infoStrings.Add(string.Format(Messages.TitleVolumeFormat, priceInfo[TickType.VOLUME]));
            infoStrings.Add(string.Format(Messages.TitleAvgVolumeFormat, priceInfo[TickType.AVG_VOLUME]));
            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }

        private void ExecuteIfInputNotEmpty(Action action, string input)
        {
            if (string.IsNullOrWhiteSpace(input))
            {
                IO.ShowMessage(Messages.CanceledDueToEmptyInput);
                return;
            }

            action();
        }
    }
}
