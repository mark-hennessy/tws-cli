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

        public static string PromptForInputIfNecessary(string[] args, int argIndex, string promptMessage = null)
        {
            return args.Length > argIndex ? args[argIndex] : PromptForInput(promptMessage);
        }

        public static string PromptForInput(string promptMessage = null)
        {
            if (!string.IsNullOrEmpty(promptMessage))
            {
                ShowInlineMessage(promptMessage);
            }
            string input = Console.ReadLine() ?? string.Empty;
            ShowMessage(LogLevel.Trace, input);
            return input;
        }

        public static char PromptForChar(string promptMessage = null)
        {
            if (!string.IsNullOrEmpty(promptMessage))
            {
                ShowInlineMessage(promptMessage);
            }
            char input = Console.ReadKey().KeyChar;
            ShowMessage(LogLevel.Trace, input.ToString());
            return input;
        }

        public static void ShowMessage(string message, params object[] messageArgs)
        {
            logger.Log(LogLevel.Info, message, messageArgs);
        }

        public static void ShowMessage(LogLevel logLevel, string message, params object[] messageArgs)
        {
            logger.Log(logLevel, message, messageArgs);
        }

        private static void ShowInlineMessage(string message, params object[] messageArgs)
        {
            // We don't want a new line after the message in the console,
            // but we do want a new line after the message in the logs.

            // Console.Write to hide the message from the logs
            Console.Write(message, messageArgs);
            // Trace the message to hide the message from the console
            ShowMessage(LogLevel.Trace, message, messageArgs);
        }
    }
}
