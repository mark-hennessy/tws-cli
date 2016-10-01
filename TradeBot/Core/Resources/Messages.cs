
namespace TradeBot.Core.Resources
{
    public static class Messages
    {
        public const string APP_INFO_PROGRAMEXITING = "Goodbye! Press any key to exit...";
        public const string MENU_DIVIDER_INLINE = ", ";
        public const string MENU_DIVIDER_MULTILINE = "\n";
        public const string MENU_FORMAT_KEY = "{0}";
        public const string MENU_FORMAT_KEYANDVALUE = "{0} - {1}";
        public const string MENU_OPTION_BUYPOSITION_DESCRIPTION = "Buy Position";
        public const string MENU_OPTION_BUYPOSITION_KEY = "b";
        public const string MENU_OPTION_CLOSEPOSITION_DESCRIPTION = "Close Position";
        public const string MENU_OPTION_CLOSEPOSITION_KEY = "c";
        public const string MENU_OPTION_EXITAPPLICATION_DESCRIPTION = "Exit Application";
        public const string MENU_OPTION_EXITAPPLICATION_KEY = "q";
        public const string MENU_OPTION_FINDPOSITION_DESCRIPTION = "Find Position";
        public const string MENU_OPTION_FINDPOSITION_KEY = "f";
        public const string MENU_OPTION_REVERSEPOSITION_DESCRIPTION = "Reverse Position";
        public const string MENU_OPTION_REVERSEPOSITION_KEY = "r";
        public const string MENU_OPTION_SELLPOSITION_DESCRIPTION = "Sell Position";
        public const string MENU_OPTION_SELLPOSITION_KEY = "s";
        public const string MENU_OPTION_TOGGLEMENUVERBOSITY_DESCRIPTION = "Toggle Menu Verbosity";
        public const string MENU_OPTION_TOGGLEMENUVERBOSITY_KEY = "?";
        public const string MENU_PROMPT_FORINPUT = "\n";
        public const string MENU_PROMPT_INVALIDMENUOPTION = "No such menu option. Please try again.";
        public const string MENU_TITLE_INLINE = "Menu: ";
        public const string MENU_TITLE_MULTILINE = "====================\nMenu\n====================\n";
        public const string TWS_ERROR = "Error: {0}";
        public const string TWS_INFO = "Info: {0}";
        public const string TWS_INFO_ACCOUNT_ID = "Account: {0}";
        public const string TWS_INFO_ACCOUNT_TYPE_LIVE = "Live Trading!";
        public const string TWS_INFO_ACCOUNT_TYPE_PAPER = "Paper Trading!";
        public const string TWS_INFO_CONNECTIONCLOSED = "TWS Connection Closed";
        public const string TWS_INFO_CONNECTIONESTABLISHED = "TWS Connection Established";
        public const string TWS_INFO_CURRENTTIME = "Current Time: {0}";
        public const string TWS_INFO_NEXTVALIDID = "Next Valid OrderId: {0}";
        public const string TWS_INFO_TICKPRICE = "Tick Price: tickerId={0}, field={1}, price={2}, canAutoExecute={3}";
        public const string TWS_INFO_TICKSIZE = "Tick Size: tickerId={0}, field={1}, size={2}";
        public const string TWS_INFO_TICKSNAPSHOTEND = "Tick Snapshot End: tickerId={0}";
    }
}