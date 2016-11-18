using static TradeBot.AppProperties;

namespace TradeBot
{
    public class Program
    {
        public static void Main()
        {
            var console = new TradeBotConsole(Preferences.ClientId);
            console.Connect(Preferences.ClientUrl, Preferences.ClientPort);
        }
    }
}
