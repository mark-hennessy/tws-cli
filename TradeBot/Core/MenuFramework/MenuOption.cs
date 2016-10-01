using TradeBot.Core.FileIO;
using TradeBot.Core.Resources;

namespace TradeBot.Core.MenuFramework
{
    public class MenuOption
    {
        public MenuOption(string key, string description, MenuOptionCommand command)
        {
            Key = key;
            Description = description;
            Command = command;
        }

        /// <summary>
        /// The function that gets called when a menu option is selected.
        /// </summary>
        /// <returns>true to continue prompting for other commands</returns>
        public delegate bool MenuOptionCommand();

        public string Key { get; }
        public string Description { get; }
        public MenuOptionCommand Command { get; }

        public string BuildMenuOptionString(bool verbose)
        {
            if (verbose)
            {
                return string.Format(Messages.MENU_FORMAT_KEYANDVALUE, Key, Description);
            }
            else
            {
                return string.Format(Messages.MENU_FORMAT_KEY, Key);
            }
        }

        public override string ToString()
        {
            return BuildMenuOptionString(true);
        }
    }
}
