using static TradeBot.AppProperties;

namespace TradeBot
{
    public class Program
    {
        public static void Main()
        {
            TradeBotConsole console = new TradeBotConsole(
                Preferences.ClientId,
                Preferences.ClientUrl,
                Preferences.ClientPort);

            console.Start();
        }
    }
}
