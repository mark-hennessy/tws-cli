using static TradeBot.AppProperties;

namespace TradeBot.MenuFramework
{
    public class MenuOption : MenuItem
    {
        public MenuOption(string key, string description, MenuCommand command)
        {
            Key = key;
            Description = description;
            Command = command;
        }

        public string Key { get; }
        public string Description { get; set; }
        public MenuCommand Command { get; set; }

        public string Render()
        {
            string paddedKey = Key.PadRight(Messages.LongestMenuOptionKey.Length);
            return string.Format(Messages.MenuOptionFormat, paddedKey, Description);
        }
    }
}
