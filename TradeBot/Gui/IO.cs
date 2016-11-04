using NLog;
using System;

namespace TradeBot.Gui
{
    /// <summary>
    /// A helper class for console window input/output.
    /// </summary>
    public static class IO
    {
        private static readonly Logger logger = LogManager.GetCurrentClassLogger();
        public static string PromptForInput(string message = null)
        {
            if (!string.IsNullOrEmpty(message))
            {
                ShowMessage(message);
            }
            string input = Console.ReadLine() ?? string.Empty;
            ShowMessage(input, LogLevel.Debug);
            return input;
        }

        public static char PromptForChar(string message = null)
        {
            if (!string.IsNullOrEmpty(message))
            {
                ShowMessage(message);
            }
            char input = Console.ReadKey().KeyChar;
            ShowMessage(input.ToString(), LogLevel.Debug);
            return input;
        }

        public static void ShowMessage(string message, params object[] args)
        {
            ShowMessage(message, LogLevel.Info, args);
        }

        public static void ShowMessage(string message, LogLevel logLevel, params object[] args)
        {
            logger.Log(logLevel, message, args);
        }
    }

}
