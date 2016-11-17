namespace TradeBot.MenuFramework
{
    public class MenuDivider : MenuItem
    {
        public MenuDivider(string divider)
        {
            Divider = divider;
        }

        public string Divider { get; set; }

        public string Render()
        {
            return Divider;
        }
    }
}
