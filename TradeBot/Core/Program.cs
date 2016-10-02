using IBApi;
using System;
using TradeBot.Core.FileIO;
using TradeBot.Core.Gui;
using TradeBot.Core.MenuFramework;
using TradeBot.Core.Resources;
using TradeBot.Core.Tws;
using static TradeBot.Core.Gui.Window;

namespace TradeBot.Core
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Program program = new Program();
            program.Start();
        }

        private TwsClient twsClient;
        private Menu menu;
        private bool exit;

        public Program()
        {
            InitializeConsole();
            InitializeTwsClient();
            InitializeMenu();
        }

        private void InitializeTwsClient()
        {
            twsClient = new TwsClient();
        }

        private void InitializeConsole()
        {
            Console.Title = Preferences.WINDOW_TITLE;
            SetWindowSizeAndCenter(
                Preferences.WINDOW_SIZE_WIDTH,
                Preferences.WINDOW_SIZE_HEIGHT);
            SetWindowCloseHandler(OnWindowClose);
        }

        private void InitializeMenu()
        {
            menu = new Menu();

            menu.AddMenuOption(
                Messages.MENUOPTION_COMMAND_FINDPOSITION_KEY,
                Messages.MENUOPTION_COMMAND_FINDPOSITION_DESCRIPTION,
                FindCommand);

            menu.AddMenuOption(
                Messages.MENUOPTION_COMMAND_BUYPOSITION_KEY,
                Messages.MENUOPTION_COMMAND_BUYPOSITION_DESCRIPTION,
                BuyPositionCommand);

            menu.AddMenuOption(
                Messages.MENUOPTION_COMMAND_SELLPOSITION_KEY,
                Messages.MENUOPTION_COMMAND_SELLPOSITION_DESCRIPTION,
                SellPositionCommand);

            menu.AddMenuOption(
                Messages.MENUOPTION_COMMAND_REVERSEPOSITION_KEY,
                Messages.MENUOPTION_COMMAND_REVERSEPOSITION_DESCRIPTION,
                ReversePositionCommand);

            menu.AddMenuOption(
                Messages.MENUOPTION_COMMAND_CLOSEPOSITION_KEY,
                Messages.MENUOPTION_COMMAND_CLOSEPOSITION_DESCRIPTION,
                ClosePositionCommand);

            menu.AddMenuOption(
                Messages.MENUOPTION_COMMAND_TOGGLEINFOMESSAGES_KEY,
                Messages.MENUOPTION_COMMAND_TOGGLEINFOMESSAGES_DESCRIPTION,
                ToggleInfoMessages);

            menu.AddMenuOption(
                Messages.MENUOPTION_COMMAND_SHOWMENU_KEY,
                Messages.MENUOPTION_COMMAND_SHOWMENU_DESCRIPTION,
                ShowMenu);

            menu.AddMenuOption(
                Messages.MENUOPTION_COMMAND_EXITAPPLICATION_KEY,
                Messages.MENUOPTION_COMMAND_EXITAPPLICATION_DESCRIPTION,
                ExitApplicationCommand);
        }

        public void Start()
        {
            try
            {
                twsClient.eConnect();
                while (!exit)
                {
                    menu.PromptForMenuOption().Command();
                }
            }
            catch (Exception e)
            {
                Messenger.ShowMessage(e.Message, MessageType.ERROR);
            }
            finally
            {
                Shutdown();
                Messenger.PromptForKey(Messages.APP_INFO_PROGRAMEXITING);
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
            PersistAppState();
            twsClient.eDisconnect();
        }

        private void PersistAppState()
        {
            Properties appStateProperties = new Properties();
            appStateProperties.Load(typeof(AppState));
            appStateProperties.Save(ResourceFiles.APP_STATE_FILE);
        }

        private void FindCommand()
        {
            Contract contract = new Contract();
            contract.Symbol = "EUR";
            contract.SecType = "CASH";
            contract.Currency = "GBP";
            contract.Exchange = "IDEALPRO";

            twsClient.reqMktData(1, contract, "", false, null);
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

        private void ToggleInfoMessages()
        {
            AppState.ShowInfoMessages = !AppState.ShowInfoMessages;
            Messenger.ShowMessage(Messages.MENUOPTION_COMMAND_TOGGLEINFOMESSAGES_STATE, AppState.ShowInfoMessages);
        }

        private void ShowMenu()
        {
            Messenger.ShowMessage(menu.ToString());
        }

        private void ExitApplicationCommand()
        {
            exit = true;
        }
    }
}
