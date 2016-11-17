using System;

namespace TradeBot.MenuFramework
{
    public class MenuTitle : MenuItem
    {
        public MenuTitle(string title, string divider = null)
        {
            Title = title;
            Divider = divider;
        }

        public string Title { get; set; }
        public string Divider { get; set; }

        public string Render()
        {
            if (string.IsNullOrEmpty(Title))
            {
                return string.Empty;
            }

            if (string.IsNullOrEmpty(Divider))
            {
                return Title;
            }

            int titlePadding = Divider.Length / 2 + Title.Length / 2;
            return string.Join(Environment.NewLine,
                Divider,
                Title.PadLeft(titlePadding),
                Divider);
        }
    }
}
