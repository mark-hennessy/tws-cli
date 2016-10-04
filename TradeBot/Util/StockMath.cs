using System;

namespace TradeBot.Util
{
    public static class StockMath
    {
        public static int CalculateShareQuantity(decimal cash, decimal sharePrice)
        {
            return (int)Math.Floor(cash / sharePrice);
        }
    }
}
