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
                ShowAndLogPromptMessage(message);
            }
            string input = Console.ReadLine() ?? string.Empty;
            ShowMessage(LogLevel.Trace, input);
            return input;
        }

        public static char PromptForChar(string message = null)
        {
            if (!string.IsNullOrEmpty(message))
            {
                ShowAndLogPromptMessage(message);
            }
            char input = Console.ReadKey().KeyChar;
            ShowMessage(LogLevel.Trace, input.ToString());
            return input;
        }

        public static void ShowMessage(LogLevel logLevel, string message, params object[] messageArgs)
        {
            logger.Log(logLevel, message, messageArgs);
        }

        private static void ShowAndLogPromptMessage(string message, params object[] messageArgs)
        {
            Console.Write(message, messageArgs);
            ShowMessage(LogLevel.Trace, message, messageArgs);
        }
    }

}
