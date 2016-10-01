using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using TradeBot.Core.Gui;
using TradeBot.Core.Resources;
using static TradeBot.Core.MenuFramework.MenuOption;

namespace TradeBot.Core.MenuFramework
{
    public class Menu
    {
        private const int MENU_DELAY = 1000;
        private readonly MenuOption NULL_MENU_OPTION;

        private IList<MenuOption> menuOptions;
        private IDictionary<string, MenuOption> menuOptionMap;

        public Menu()
        {
            NULL_MENU_OPTION = new MenuOption(null, string.Empty, InvalidMenuOptionCommand);

            menuOptions = new List<MenuOption>();
            menuOptionMap = new Dictionary<string, MenuOption>();

            Verbose = true;
        }

        public bool Verbose { get; set; }

        public void AddMenuOption(string key, string description, MenuOptionCommand command)
        {
            AddMenuOption(new MenuOption(key, description, command));
        }

        public void AddMenuOption(MenuOption menuOption)
        {
            menuOptions.Add(menuOption);
            menuOptionMap[menuOption.Key] = menuOption;
        }

        public void Loop()
        {
            do
            {
                // The TWS API continuously polls for TCP messages on a background thread.
                // Delay the menu prompt to give the background thread reasonable time to 
                // finish handling responses from previous requests.
                Task.Delay(MENU_DELAY).Wait();
            }
            while (PromptForMenuOption().Command());
        }

        private MenuOption PromptForMenuOption()
        {
            string promptMessage = BuildMenuString(Verbose);
            string input = Messenger.PromptForInput(promptMessage);
            return getMenuOption(input);
        }

        private MenuOption getMenuOption(string key)
        {
            return menuOptionMap.ContainsKey(key)
                    ? menuOptionMap[key]
                    : NULL_MENU_OPTION;
        }

        private bool InvalidMenuOptionCommand()
        {
            Messenger.ShowMessage(Messages.MENU_PROMPT_INVALIDMENUOPTION, MessageType.ERROR);
            return true;
        }

        private string BuildMenuString(bool verbose)
        {
            string menuTitle = verbose ? Messages.MENU_TITLE_MULTILINE : Messages.MENU_TITLE_INLINE;
            string menuOptionDivider = verbose ? Messages.MENU_DIVIDER_MULTILINE : Messages.MENU_DIVIDER_INLINE;
            string menuInputPrompt = Messages.MENU_PROMPT_FORINPUT;

            StringBuilder stringBuilder = new StringBuilder();

            stringBuilder.Append(menuTitle);

            IEnumerable<string> menuOptionsAsStrings = menuOptions
                .Select(menuOption => menuOption.BuildMenuOptionString(verbose));
            string joinedMenuOptionString = string.Join(menuOptionDivider, menuOptionsAsStrings);
            stringBuilder.Append(joinedMenuOptionString);

            stringBuilder.Append(menuInputPrompt);

            return stringBuilder.ToString();
        }

        public override string ToString()
        {
            return BuildMenuString(true);
        }
    }
}
