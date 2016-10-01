using System.Drawing;

namespace TradeBot.Core.Gui
{
    /// <summary>
    /// A helper class for calculating computer screen dimensions.
    /// </summary>
    public static class Screen
    {
        public static int Width
        {
            get
            {
                return ScreenBounds.Width;
            }
        }

        public static int Height
        {
            get
            {
                return ScreenBounds.Height;
            }
        }

        private static Rectangle ScreenBounds
        {
            get
            {
                return System.Windows.Forms.Screen.PrimaryScreen.Bounds;
            }
        }
    }
}
