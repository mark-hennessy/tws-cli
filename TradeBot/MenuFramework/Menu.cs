using NLog;
using System;
using System.Collections.Generic;
using System.Linq;
using TradeBot.Extensions;
using TradeBot.Gui;
using static TradeBot.AppProperties;

namespace TradeBot.MenuFramework
{
    public class Menu : MenuItem
    {
        private readonly MenuOption NULL_MENU_OPTION
            = new MenuOption(null, string.Empty, InvalidMenuOptionCommand);

        private IList<MenuItem> menuItems;
        private IDictionary<string, MenuOption> menuOptionMap;

        public Menu()
        {
            menuItems = new List<MenuItem>();
            menuOptionMap = new Dictionary<string, MenuOption>();
        }

        public Menu AddMenuItem(MenuOption menuOption)
        {
            menuItems.Add(menuOption);
            menuOptionMap[menuOption.Key] = menuOption;
            return this;
        }

        public Menu AddMenuItem(MenuItem menuItem)
        {
            menuItems.Add(menuItem);
            return this;
        }

        public MenuOption getMenuOption(string key)
        {
            return key != null && menuOptionMap.ContainsKey(key)
                ? menuOptionMap[key]
                : NULL_MENU_OPTION;
        }

        public int GetLongestMenuEntryLength()
        {
            var menuOptions = menuOptionMap.Values;
            if (menuOptions.IsEmpty())
            {
                return 0;
            }

            return menuOptions
                .Select(item => item.Render())
                .OrderByDescending(s => s.Length)
                .First()
                .Length;
        }

        public MenuOption PromptForMenuOption()
        {
            string input = IO.PromptForInput();
            return getMenuOption(input);
        }

        public string Render()
        {
            IEnumerable<string> renderedMenuItems = menuItems
                .Select(item => item.Render());
            return string.Join(Environment.NewLine, renderedMenuItems); ;
        }

        private static void InvalidMenuOptionCommand()
        {
            IO.ShowMessage(LogLevel.Error, Messages.InvalidMenuOption);
        }
    }
}
