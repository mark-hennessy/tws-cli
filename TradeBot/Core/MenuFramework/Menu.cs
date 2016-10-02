using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using TradeBot.Core.Gui;
using TradeBot.Core.Resources;

namespace TradeBot.Core.MenuFramework
{
    public class Menu
    {
        private readonly MenuOption NULL_MENU_OPTION;

        private IList<MenuOption> menuOptions;
        private IDictionary<string, MenuOption> menuOptionMap;

        public Menu()
        {
            NULL_MENU_OPTION = new MenuOption(null, string.Empty, InvalidMenuOptionCommand);

            menuOptions = new List<MenuOption>();
            menuOptionMap = new Dictionary<string, MenuOption>();
        }

        public void AddMenuOption(string key, string description, Action command)
        {
            AddMenuOption(new MenuOption(key, description, command));
        }

        public void AddMenuOption(MenuOption menuOption)
        {
            menuOptions.Add(menuOption);
            menuOptionMap[menuOption.Key] = menuOption;
        }

        public MenuOption PromptForMenuOption()
        {
            string input = Messenger.PromptForInput();
            return getMenuOption(input);
        }

        private MenuOption getMenuOption(string key)
        {
            return menuOptionMap.ContainsKey(key)
                    ? menuOptionMap[key]
                    : NULL_MENU_OPTION;
        }

        private void InvalidMenuOptionCommand()
        {
            Messenger.ShowMessage(Messages.MENU_MESSAGE_INVALIDMENUOPTION, MessageType.ERROR);
        }

        public override string ToString()
        {
            string menuOptionDivider = Messages.MENU_DIVIDER;

            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append(Messages.MENU_TITLE);

            var menuOptionsAsStrings = menuOptions
                .Select(menuOption => menuOption.ToString());
            string joinedMenuOptionString = string.Join(menuOptionDivider, menuOptionsAsStrings);
            stringBuilder.Append(joinedMenuOptionString);

            return stringBuilder.ToString();
        }
    }
}
