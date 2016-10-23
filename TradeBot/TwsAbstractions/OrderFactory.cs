using IBApi;

namespace TradeBot.TwsAbstractions
{
    public static class OrderFactory
    {
        public static Order CreateLimitOrder(OrderActions action, int totalQuantity, double limitPrice)
        {
            return new Order()
            {
                Action = action.ToString(),
                TotalQuantity = totalQuantity,
                LmtPrice = limitPrice,
                OrderType = OrderTypes.LMT.ToString(),
                Tif = TimeInForce.GTC.ToString(),
                Transmit = true,
                OutsideRth = true
            };
        }
    }
}
