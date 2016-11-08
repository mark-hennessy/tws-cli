using IBApi;

namespace TradeBot.TwsAbstractions
{
    public static class OrderFactory
    {
        public static Order CreateLimitOrder(OrderActions action, int quantity, double limitPrice)
        {
            return new Order()
            {
                Action = action.ToString(),
                TotalQuantity = quantity,
                LmtPrice = limitPrice,
                OrderType = OrderTypes.LMT.ToString(),
                Tif = TimeInForce.GTC.ToString(),
                Transmit = true,
                OutsideRth = true
            };
        }
    }
}
