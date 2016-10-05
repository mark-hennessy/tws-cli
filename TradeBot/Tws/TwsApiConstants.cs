namespace TradeBot.Tws
{
    public static class SecurityTypeConst
    {
        public const string STOCK = "STK";
        public const string OPTION = "OPT";
        public const string FUTURE = "FUT";
        public const string INDEX = "IND";
        public const string FUTURE_ON_AN_OPTION = "FOP";
        public const string FOREX_PAIR = "CASH";
        public const string COMBO_ORDER = "BAG";
        public const string WARRANT = "WAR";
        public const string NEWS_EVENTS_FOR_UNDERLYING_CONTRACTS = "NEWS";
    }

    public static class CurrencyConst
    {
        public const string USD = "USD";
        public const string GBP = "GBP";
    }

    public static class ExchangeConst
    {
        public const string SMART = "SMART";
    }

    public static class ErrorCodes
    {
        public const int TICKER_NOT_FOUND = 200;

        public const int MARKET_DATA_FARM_DISCONNECTED = 2103;
        public const int MARKET_DATA_FARM_CONNECTED = 2104;
        public const int HISTORICAL_DATA_FARM_DISCONNECTED = 2105;
        public const int HISTORICAL_DATA_FARM_CONNECTED = 2106;
    }
}
