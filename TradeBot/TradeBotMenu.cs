using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using NLog;
using TradeBot.Generated;
using TradeBot.Gui;
using TradeBot.MenuFramework;
using static TradeBot.AppProperties;

namespace TradeBot
{
    public class TradeBotMenu : Menu
    {
        public TradeBotMenu(TradeBotConsole console)
        {
            InitMenu(console);
        }

        private void InitMenu(TradeBotConsole console)
        {
            var titleDivider = new MenuDivider();
            AddMenuItem(new MenuTitle(Messages.MenuTitle, titleDivider));

            var addMenuOption = new Action<IList<string>, MenuCommand>((entry, command)
                => AddMenuItem(new MenuOption(entry[0], entry[1], command)));

            var menuOptionDivider = new MenuDivider();
            var addMenuOptionDivider = new Action(()
                => AddMenuItem(menuOptionDivider));

            MenuOptionEntries entries = Messages.MenuOptionEntries;

            addMenuOption(entries.SetTickerSymbol, console.PromptForTickerSymbolCommand);
            addMenuOptionDivider();

            addMenuOption(entries.SetSharesFromCash, console.PromptForCashCommand);
            addMenuOption(entries.SetShares, console.PromptForSharesCommand);
            addMenuOption(entries.SetSharesFromPosition, console.SetSharesFromPositionCommand);
            addMenuOptionDivider();

            addMenuOption(entries.Buy, console.BuyCommand);
            addMenuOption(entries.Sell, console.SellCommand);
            addMenuOption(entries.ReversePosition, console.ReversePositionCommand);
            addMenuOption(entries.ClosePosition, console.ClosePositionCommand);
            addMenuOptionDivider();

            addMenuOption(entries.ListPositions, console.ListPositionsCommand);
            addMenuOptionDivider();

            addMenuOption(entries.LoadState, console.LoadStateCommand);
            addMenuOption(entries.SaveState, console.SaveStateCommand);
            addMenuOptionDivider();

            addMenuOption(entries.ClearScreen, console.ClearScreenCommand);
            addMenuOption(entries.ShowMenu, console.ShowMenuCommand);

            var menuEndDivider = new MenuDivider();
            AddMenuItem(menuEndDivider);

            int dividerLength = GetLongestMenuEntryLength();
            var createDividerString = new Func<string, string>((charString) =>
            {
                return !string.IsNullOrEmpty(charString)
                    ? new string(charString.First(), dividerLength)
                    : string.Empty;
            });
            titleDivider.DividerString = createDividerString(Messages.MenuTitleDividerChar);
            menuOptionDivider.DividerString = createDividerString(Messages.MenuOptionDividerChar);
            menuEndDivider.DividerString = createDividerString(Messages.MenuEndDividerChar);
        }

        public async Task Run()
        {
            string[] input = PromptForMenuOptionInput();
            await HandleMenuOptionInputAsync(input);
        }

        private string[] PromptForMenuOptionInput()
        {
            return IO.PromptForInput().Split();
        }

        private async Task HandleMenuOptionInputAsync(string[] input)
        {
            string key = input.FirstOrDefault();
            MenuOption menuOption = getMenuOption(key);
            if (menuOption != null)
            {
                string[] args = input.Skip(1).ToArray();
                await menuOption.Command(args);
            }
            else
            {
                IO.ShowMessage(LogLevel.Error, Messages.InvalidMenuOption);
            }
        }

    }
}
