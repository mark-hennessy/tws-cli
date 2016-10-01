using IBApi;
using System;
using TradeBot.Core.FileIO;
using TradeBot.Core.Gui;
using TradeBot.Core.MenuFramework;
using TradeBot.Core.Resources;
using TradeBot.Core.Tws;

namespace TradeBot.Core
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Program program = new Program();
            program.Run();
        }

        public static Properties State { get; }

        static Program()
        {
            State = new Properties();
            State.Load(ResourceFiles.STATE_FILE);
        }

        private TwsClient twsClient;
        private Menu menu;

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
            Window.SetWindowSizeAndCenter(
                Preferences.WINDOW_SIZE_WIDTH,
                Preferences.WINDOW_SIZE_HEIGHT);
        }

        private void InitializeMenu()
        {
            menu = new Menu();

            menu.AddMenuOption(
                Messages.MENU_OPTION_FINDPOSITION_KEY,
                Messages.MENU_OPTION_FINDPOSITION_DESCRIPTION,
                FindCommand);

            menu.AddMenuOption(
                Messages.MENU_OPTION_BUYPOSITION_KEY,
                Messages.MENU_OPTION_BUYPOSITION_DESCRIPTION,
                BuyPositionCommand);

            menu.AddMenuOption(
                Messages.MENU_OPTION_SELLPOSITION_KEY,
                Messages.MENU_OPTION_SELLPOSITION_DESCRIPTION,
                SellPositionCommand);

            menu.AddMenuOption(
                Messages.MENU_OPTION_REVERSEPOSITION_KEY,
                Messages.MENU_OPTION_REVERSEPOSITION_DESCRIPTION,
                ReversePositionCommand);

            menu.AddMenuOption(
                Messages.MENU_OPTION_CLOSEPOSITION_KEY,
                Messages.MENU_OPTION_CLOSEPOSITION_DESCRIPTION,
                ClosePositionCommand);

            menu.AddMenuOption(
                Messages.MENU_OPTION_EXITAPPLICATION_KEY,
                Messages.MENU_OPTION_EXITAPPLICATION_DESCRIPTION,
                ExitApplicationCommand);

            menu.Verbose = Preferences.SHOWVERBOSEMENU;
            if (!menu.Verbose)
            {
                menu.AddMenuOption(
                    Messages.MENU_OPTION_TOGGLEMENUVERBOSITY_KEY,
                    Messages.MENU_OPTION_TOGGLEMENUVERBOSITY_DESCRIPTION,
                    HelpCommand);
            }
        }

        public void Run()
        {
            try
            {
                twsClient.eConnect();
                menu.Loop();
            }
            catch (Exception e)
            {
                Messenger.ShowMessage(e.StackTrace, MessageType.ERROR);
            }
            finally
            {
                twsClient.eDisconnect();
                Messenger.PromptForKey(Messages.APP_INFO_PROGRAMEXITING);
            }
        }

        private bool FindCommand()
        {
            Contract contract = new Contract();
            contract.Symbol = "EUR";
            contract.SecType = "CASH";
            contract.Currency = "GBP";
            contract.Exchange = "IDEALPRO";

            twsClient.reqMktData(1, contract, "", false, null);

            return true;
        }

        private bool BuyPositionCommand()
        {
            return true;
        }

        private bool SellPositionCommand()
        {
            return true;
        }

        private bool ReversePositionCommand()
        {
            return true;
        }

        private bool ClosePositionCommand()
        {
            return true;
        }

        private bool ExitApplicationCommand()
        {
            return false;
        }

        private bool HelpCommand()
        {
            menu.Verbose = !menu.Verbose;
            return true;
        }
    }
}
