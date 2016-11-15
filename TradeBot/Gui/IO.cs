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
                ShowInlineMessage(message);
            }
            string input = Console.ReadLine() ?? string.Empty;
            ShowMessage(LogLevel.Trace, input);
            return input;
        }

        public static char PromptForChar(string message = null)
        {
            if (!string.IsNullOrEmpty(message))
            {
                ShowInlineMessage(message);
            }
            char input = Console.ReadKey().KeyChar;
            ShowMessage(LogLevel.Trace, input.ToString());
            return input;
        }

        public static void ShowMessage(LogLevel logLevel, string message, params object[] messageArgs)
        {
            logger.Log(logLevel, message, messageArgs);
        }

        private static void ShowInlineMessage(string message, params object[] messageArgs)
        {
            // We don't want a new line after the message in the console,
            // but we do want a new line after the message in the log file.

            // Console.Write to circumnavigate the logging.
            Console.Write(message, messageArgs);
            // Trace the message to circumnavigate the console.
            ShowMessage(LogLevel.Trace, message, messageArgs);
        }
    }

}
