using TradeBot.FileIO;
using TradeBot.Generated;

namespace TradeBot
{
    public static class AppProperties
    {
        public static AppPreferences Preferences { get; }
        public static AppMessages Messages { get; }

        static AppProperties()
        {
            Preferences = PropertySerializer.Deserialize<AppPreferences>(PropertyFiles.PREFERENCES_FILE);
            Messages = PropertySerializer.Deserialize<AppMessages>(PropertyFiles.MESSAGES_FILE);
        }
    }
}
