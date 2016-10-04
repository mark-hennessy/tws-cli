using System;
using System.Runtime.InteropServices;

namespace TradeBot.Gui
{
    /// <summary>
    /// A helper class for interacting with the console window.
    /// </summary>
    public static class Window
    {
        private const int SWP_NOZORDER = 0x4;
        private const int SWP_NOACTIVATE = 0x10;

        [DllImport("kernel32.dll", ExactSpelling = true)]
        private static extern IntPtr GetConsoleWindow();

        [DllImport("user32.dll", EntryPoint = "SetWindowPos")]
        private static extern IntPtr SetWindowPosition(IntPtr windowHandle, int insertAfter, int x, int y, int width, int height, int flags);

        [DllImport("Kernel32", EntryPoint = "SetConsoleCtrlHandler")]
        private static extern bool SetConsoleCloseHandler(WindowCloseHandler handler, bool add);

        public delegate bool WindowCloseHandler(CloseReason closeReason);

        public enum CloseReason
        {
            CTRL_C_EVENT = 0,
            BREAK_EVENT = 1,
            CLOSE_EVENT = 2,
            LOGOFF_EVENT = 5,
            SHUTDOWN_EVENT = 6
        }

        public static ConsoleColor BackgroundColor
        {
            get
            {
                return Console.BackgroundColor;
            }
            set
            {
                Console.BackgroundColor = value;
                Console.Clear();
            }
        }

        public static void SetWindowSizeAndCenter(int width, int height)
        {
            if (!OS.IsWindows())
            {
                return;
            }

            int x = (Screen.Width - width) / 2;
            int y = (Screen.Height - height) / 2;
            SetWindowPositionAndSize(x, y, width, height);
        }

        public static void SetWindowPositionAndSize(int x, int y, int width, int height)
        {
            if (!OS.IsWindows())
            {
                return;
            }

            SetWindowPosition(GetConsoleWindow(), 0, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
        }

        public static void SetWindowCloseHandler(WindowCloseHandler handler)
        {
            if (!OS.IsWindows())
            {
                return;
            }

            SetConsoleCloseHandler(handler, true);
        }

    }
}
