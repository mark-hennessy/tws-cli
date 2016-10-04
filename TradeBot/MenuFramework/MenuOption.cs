using System;
using static TradeBot.Resources;

namespace TradeBot.MenuFramework
{
    public class MenuOption
    {
        public MenuOption(string key, string description, Action command)
        {
            Key = key;
            Description = description;
            Command = command;
        }

        public string Key { get; }
        public string Description { get; }
        public Action Command { get; }

        public override string ToString()
        {
            return string.Format(Messages.MenuOptionFormat, Key, Description);
        }
    }
}
