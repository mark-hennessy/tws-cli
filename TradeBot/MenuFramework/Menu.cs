using NLog;
using System;
using System.Collections.Generic;
using System.Linq;
using TradeBot.Gui;
using static TradeBot.AppProperties;

namespace TradeBot.MenuFramework
{
    public class Menu : MenuItem
    {
        private readonly MenuOption NULL_MENU_OPTION;

        private IList<MenuItem> menuItems;
        private IDictionary<string, MenuOption> menuOptionMap;

        public Menu()
        {
            NULL_MENU_OPTION = new MenuOption(null, string.Empty, InvalidMenuOptionCommand);

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

        public MenuOption PromptForMenuOption()
        {
            string input = IO.PromptForInput();
            return getMenuOption(input);
        }

        private MenuOption getMenuOption(string key)
        {
            return key != null && menuOptionMap.ContainsKey(key)
                ? menuOptionMap[key]
                : NULL_MENU_OPTION;
        }

        private void InvalidMenuOptionCommand()
        {
            IO.ShowMessage(LogLevel.Error, Messages.InvalidMenuOption);
        }

        public string Render()
        {
            IEnumerable<string> renderedMenuItems = menuItems
                .Select(item => item.Render());
            return string.Join(Environment.NewLine, renderedMenuItems); ;
        }
    }
}
