namespace TradeBot.MenuFramework
{
    public class MenuDivider : MenuItem
    {
        public MenuDivider(string dividerString = null)
        {
            DividerString = dividerString;
        }

        public string DividerString { get; set; }

        public string Render()
        {
            if (DividerString == null)
            {
                return string.Empty;
            }

            return DividerString;
        }
    }
}
