using TradeBot.FileIO;
using TradeBot.Generated;

namespace TradeBot
{
    public static class GlobalProperties
    {
        public static AppPreferences Preferences { get; }
        public static AppMessages Messages { get; }

        static GlobalProperties()
        {
            Preferences = PropertySerializer.Deserialize<AppPreferences>(PropertyFiles.PREFERENCES_FILE);
            Messages = PropertySerializer.Deserialize<AppMessages>(PropertyFiles.MESSAGES_FILE);
        }
    }
}
