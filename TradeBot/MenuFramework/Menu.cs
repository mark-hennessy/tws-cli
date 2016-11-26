using System;
using System.Collections.Generic;
using System.Linq;
using TradeBot.Extensions;

namespace TradeBot.MenuFramework
{
    public class Menu : MenuItem
    {
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
            if (key == null)
            {
                return null;
            }

            MenuOption menuOption;
            menuOptionMap.TryGetValue(key, out menuOption);
            return menuOption;
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

        public string Render()
        {
            IEnumerable<string> renderedMenuItems = menuItems
                .Select(item => item.Render());
            return string.Join(Environment.NewLine, renderedMenuItems); ;
        }
    }
}
