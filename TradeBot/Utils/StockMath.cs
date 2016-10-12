using System;
namespace TradeBot.Utils
{
    public static class StockMath
    {
        public static int CalculateStepSizeFromCashValue(double cash, double sharePrice)
        {
            return (int)Math.Floor(cash / sharePrice);
        }
    }
}
