using System.Threading.Tasks;
using static TradeBot.AppProperties;

namespace TradeBot
{
    public class Program
    {
        public static void Main()
        {
            MainAsync().Wait();
        }

        public static async Task MainAsync()
        {
            var console = new TradeBotConsole(Preferences.ClientId);
            await console.Run(Preferences.ClientUrl, Preferences.ClientPort);
        }
    }
}
