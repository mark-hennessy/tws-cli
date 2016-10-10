using Newtonsoft.Json;
using System.IO;
using TradeBot.FileIO;
using TradeBot.Gen;
using TradeBot.Gui;

namespace TradeBot
{
    public static class Resources
    {
        public static AppState State { get; private set; }
        public static AppPreferences Preferences { get; }
        public static AppMessages Messages { get; }

        static Resources()
        {
            State = new AppState();
            Preferences = JsonConvert.DeserializeObject<AppPreferences>(File.ReadAllText(PropertyFiles.PREFERENCES_FILE));
            Messages = JsonConvert.DeserializeObject<AppMessages>(File.ReadAllText(PropertyFiles.MESSAGES_FILE));
        }

        public static void LoadState()
        {
            State = JsonConvert.DeserializeObject<AppState>(File.ReadAllText(PropertyFiles.STATE_FILE));
        }

        public static void PersistState()
        {
            string path = PropertyFiles.STATE_FILE;
            File.WriteAllText(path, JsonConvert.SerializeObject(State));
            IO.ShowMessage(Messages.StateSavedFormat, MessageType.SUCCESS, path);
        }
    }
}
