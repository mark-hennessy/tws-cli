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
        public static PreferenceProperties Preferences { get; private set; }
        public static MessageProperties Messages { get; private set; }

        static Resources()
        {
            State = JsonConvert.DeserializeObject<StateProperties>(File.ReadAllText(PropertyFiles.STATE_FILE));
            Preferences = JsonConvert.DeserializeObject<PreferenceProperties>(File.ReadAllText(PropertyFiles.PREFERENCES_FILE));
            Messages = JsonConvert.DeserializeObject<MessageProperties>(File.ReadAllText(PropertyFiles.MESSAGES_FILE));
        }

        public static void SaveState()
        {
            File.WriteAllText(PropertyFiles.STATE_FILE, JsonConvert.SerializeObject(State));
            IO.ShowMessage(Messages.AppStateSaved);
        }
    }
}
