using System;
using System.Runtime.InteropServices;

namespace TradeBot.Core.Gui
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
        private static extern IntPtr SetWindowPos(IntPtr windowHandle, int insertAfter, int x, int y, int width, int height, int flags);

        private static IntPtr WindowHandle
        {
            get
            {
                return GetConsoleWindow();
            }
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

        public static void SetWindowPositionAndSize(int x, int y, int width, int height)
        {
            SetWindowPos(WindowHandle, 0, x, y, width, height, SWP_NOZORDER | SWP_NOACTIVATE);
        }

        public static void SetWindowSizeAndCenter(int width, int height)
        {
            int x = (Screen.Width - width) / 2;
            int y = (Screen.Height - height) / 2;
            SetWindowPositionAndSize(x, y, width, height);
        }
    }
}
