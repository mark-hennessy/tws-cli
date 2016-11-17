using System;

namespace TradeBot.MenuFramework
{
    public class MenuTitle : MenuItem
    {
        public MenuTitle(string title, MenuDivider divider = null)
        {
            Title = title;
            Divider = divider;
        }

        public string Title { get; set; }
        public MenuDivider Divider { get; set; }

        public string Render()
        {
            if (string.IsNullOrEmpty(Title))
            {
                return string.Empty;
            }

            string div = Divider?.Render();
            if (string.IsNullOrEmpty(div))
            {
                return Title;
            }

            int titlePadding = div.Length / 2 + Title.Length / 2;
            return string.Join(Environment.NewLine,
                div,
                Title.PadLeft(titlePadding),
                div);
        }
    }
}
