using System;
using System.Runtime.InteropServices;
using static TradeBot.Resources;

namespace TradeBot.Gui
{
    public enum MessageType { STANDARD, SUCCESS, ERROR, DEBUG }

    /// <summary>
    /// A helper class for console window input/output.
    /// </summary>
    public static class IO
    {
        private static readonly object threadLock = new object();

        public static string PromptForInput([Optional] string message)
        {
            ShowMessage(message);
            return Console.ReadLine() ?? string.Empty;
        }

        public static char PromptForChar([Optional] string message)
        {
            ShowMessage(message);
            return Console.ReadKey().KeyChar;
        }

        public static void ShowMessage(string message, params object[] args)
        {
            ShowMessage(message, MessageType.STANDARD, args);
        }

        public static void ShowMessage(string message, MessageType type, params object[] args)
        {
            if (string.IsNullOrEmpty(message))
            {
                return;
            }

            switch (type)
            {
                case MessageType.STANDARD:
                    ShowMessage(message, ConsoleColor.White, args);
                    break;
                case MessageType.DEBUG:
                    if (State.HideDebugMessages ?? false)
                    {
                        ShowMessage(message, ConsoleColor.DarkGray, args);
                    }
                    break;
                case MessageType.SUCCESS:
                    ShowMessage(message, ConsoleColor.Green, args);
                    break;
                case MessageType.ERROR:
                    ShowMessage(message, ConsoleColor.Red, args);
                    break;
            }
        }

        private static void ShowMessage(string message, ConsoleColor color, params object[] args)
        {
            lock (threadLock)
            {
                ConsoleColor originalForgroundColor = Console.ForegroundColor;
                Console.ForegroundColor = color;

                Console.WriteLine(string.Format(message, args) + Environment.NewLine);

                Console.ForegroundColor = originalForgroundColor;
            }
        }
    }

}
