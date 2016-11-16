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
        // Limit
        LMT,
        // Market
        MKT
    }

    public enum TimeInForce
    {
        // Valid for the day only
        DAY,
        // Good until canceled
        // The order will continue to work within the system and in the marketplace until 
        // it executes or is canceled. GTC orders will be automatically be cancelled under 
        // the following conditions: If a corporate action on a security results in a stock 
        // split (forward or reverse), exchange for shares, or distribution of shares. 
        // If you do not log into your IB account for 90 days.
        // At the end of the calendar quarter following the current quarter. For example, 
        // an order placed during the third quarter of 2011 will be canceled at the end of 
        // the first quarter of 2012. If the last day is a non-trading day, the cancellation 
        // will occur at the close of the final trading day of that quarter. For example, if the 
        // last day of the quarter is Sunday, the orders will be cancelled on the preceding Friday.
        // Orders that are modified will be assigned a new “Auto Expire” date consistent with 
        // the end of the calendar quarter following the current quarter.
        // Orders submitted to IB that remain in force for more than one day will not be reduced 
        // for dividends. To allow adjustment to your order price on ex-dividend date, 
        // consider using a Good-Til-Date/Time(GTD) or Good-after-Time/Date(GAT) order type, 
        // or a combination of the two.
        GTC,
        // Immediate or Cancel
        // Any portion that is not filled as soon as it becomes available in the market is canceled.
        IOC,
        // Good until Date
        // It will remain working within the system and in the marketplace until it executes 
        // or until the close of the market on the date specified.
        GTD,
        // Use OPG to send a market-on-open(MOO) or limit-on-open(LOO) order.
        OPG,
        // Fill-or-Kill
        // If the entire Fill-or-Kill order does not execute as soon as it becomes available, 
        // then the entire order is canceled.
        FOK,
        // Day until Canceled
        DTC
    }

    public enum OrderActions
    {
        BUY,
        SELL
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
        // Occurs when cancelMktData has already been called for a tickerId.
        public const int TICKER_ID_NOT_FOUND = 300;

        public const int NOT_CONNECTED = 504;

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
