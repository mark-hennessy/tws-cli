using NLog;
using System;
using System.Threading.Tasks;
using TradeBot.Gui;
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
            try
            {
                await console.Run(Preferences.ClientUrl, Preferences.ClientPort);
            }
            catch (Exception e)
            {
                IO.ShowMessage(LogLevel.Fatal, e.ToString());
            }
            finally
            {
                if (OS.IsWindows())
                {
                    IO.PromptForChar(Messages.PressAnyKeyToExit);
                }
            }
        }
    }
}
