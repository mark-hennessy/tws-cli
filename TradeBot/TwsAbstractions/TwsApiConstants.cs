namespace TradeBot.TwsAbstractions
{
    public enum SecurityTypes
    {
        // Stock
        STK,
        // Option
        OPT,
        // Future
        FUT,
        // Index
        IND,
        // Future on an option
        FOP,
        // Forex pair
        CASH,
        // Combo order
        BAG,
        // Warrant
        WAR,
        // News events for underlying contracts
        NEWS
    }

    // Additional order types are documented here:
    // https://www.interactivebrokers.com/en/software/api/apiguide/tables/supported_order_types.htm
    public enum OrderTypes
    {
        LMT,
        MKT
    }

    public enum TimeInForce
    {
        DAY,
        GTC
    }

    public enum OrderActions
    {
        BUY,
        SELL,
        // No idea what this is for...
        SSHORT
    }

    public enum Currencies
    {
        USD,
        GBP
    }

    public enum Exchanges
    {
        SMART
    }

    // Error codes are documented at:
    // http://interactivebrokers.github.io/tws-api/message_codes.html
    public static class ErrorCodes
    {
        public const int TICKER_NOT_FOUND = 200;
        public const int TICKER_ID_NOT_FOUND = 300;

        public const int MARKET_DATA_FARM_DISCONNECTED = 2103;
        public const int MARKET_DATA_FARM_CONNECTED = 2104;
        public const int HISTORICAL_DATA_FARM_DISCONNECTED = 2105;
        public const int HISTORICAL_DATA_FARM_CONNECTED = 2106;
        public const int HISTORICAL_DATA_FARM_INACTIVE = 2107;
        public const int MARKET_DATA_FARM_INACTIVE = 2108;

        // Occurs when an order will change the position in an account from long to short or from short to long.
        public const int CROSS_SIDE_WARNING = 2137;
    }
}
