using System;
using System.Runtime.InteropServices;
using TradeBot.Core.Resources;

namespace TradeBot.Core.Gui
{
    public enum MessageType { STANDARD, INFO, ERROR, SUCCESS }

    /// <summary>
    /// A helper class for console window input/output.
    /// </summary>
    public class Messenger
    {
        private static readonly object threadLock = new object();

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
                case MessageType.INFO:
                    if (Preferences.SHOWINFOMESSAGES)
                    {
#pragma warning disable CS0162 // Unreachable code detected
                        ShowMessage(message, ConsoleColor.DarkGray, args);
#pragma warning restore CS0162 // Unreachable code detected
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

                Console.WriteLine(Environment.NewLine + string.Format(message, args));

                Console.ForegroundColor = originalForgroundColor;
            }
        }

        public static string PromptForInput([Optional] string message)
        {
            ShowPromptMessage(message);
            return Console.ReadLine();
        }

        public static char PromptForKey([Optional] string message)
        {
            ShowPromptMessage(message);
            return Console.ReadKey().KeyChar;
        }

        private static void ShowPromptMessage([Optional] string message)
        {
            ShowMessage(message);
        }
    }

}
