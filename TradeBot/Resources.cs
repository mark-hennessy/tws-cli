using Newtonsoft.Json;
using System.IO;
using TradeBot.FileIO;
using TradeBot.Gen;
using TradeBot.Gui;

namespace TradeBot
{
    public static class Resources
    {
        public static StateProperties State { get; private set; }
        public static PreferenceProperties Preferences { get; }
        public static MessageProperties Messages { get; }

        static Resources()
        {
            State = new StateProperties();
            Preferences = JsonConvert.DeserializeObject<PreferenceProperties>(File.ReadAllText(PropertyFiles.PREFERENCES_FILE));
            Messages = JsonConvert.DeserializeObject<MessageProperties>(File.ReadAllText(PropertyFiles.MESSAGES_FILE));
        }

        public static void LoadPersistedState()
        {
            State = JsonConvert.DeserializeObject<StateProperties>(File.ReadAllText(PropertyFiles.STATE_FILE));
        }

        public static void PersistState()
        {
            string path = PropertyFiles.STATE_FILE;
            File.WriteAllText(path, JsonConvert.SerializeObject(State));
            IO.ShowMessage(Messages.StateSavedFormat, MessageType.SUCCESS, path);
        }
    }
}
