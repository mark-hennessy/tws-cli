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

        private void InitializeConsole()
        {
            Console.Title = Preferences.WindowTitle;
            if (Preferences.WindowCentered)
            {
                SetWindowSizeAndCenter(Preferences.WindowWidth, Preferences.WindowHeight);
            }
            SetWindowCloseHandler(OnWindowClose);
        }

        private void InitializeTwsClient()
        {
            twsClient = new TwsClient();
        }

        private void InitializeMenu()
        {
            menu = new Menu();

            Action<IList<string>, Action> addMenuOption = (entry, command)
                => menu.AddMenuOption(entry[0], entry[1], command);

            MenuOptionEntries menuOptionEntry = Messages.MenuOptionEntries;
            addMenuOption(menuOptionEntry.FindPosition, FindCommand);
            addMenuOption(menuOptionEntry.BuyPosition, BuyPositionCommand);
            addMenuOption(menuOptionEntry.SellPosition, SellPositionCommand);
            addMenuOption(menuOptionEntry.ReversePosition, ReversePositionCommand);
            addMenuOption(menuOptionEntry.ClosePosition, ClosePositionCommand);
            addMenuOption(menuOptionEntry.ToggleInfoMessages, ToggleInfoMessages);
            addMenuOption(menuOptionEntry.Help, HelpCommand);
            addMenuOption(menuOptionEntry.ExitApplication, ExitApplicationCommand);
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
                IO.ShowMessage(e.Message, MessageType.ERROR);
            }
            finally
            {
                Shutdown();
                if (OS.IsWindows())
                {
                    IO.PromptForKey(Messages.AppExiting);
                }
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
            SaveState();
            twsClient.eDisconnect();
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
            State.ShowInfoMessages = !State.ShowInfoMessages;
            IO.ShowMessage(Messages.TwsInfoMessageToggleStateFormat, State.ShowInfoMessages);
        }

        private void HelpCommand()
        {
            IO.ShowMessage(menu.ToString());
        }

        private void ExitApplicationCommand()
        {
            exit = true;
        }
    }
}