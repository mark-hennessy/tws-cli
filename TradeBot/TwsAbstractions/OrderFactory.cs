using IBApi;

namespace TradeBot.TwsAbstractions
{
    public static class OrderFactory
    {
        public static Order CreateLimitOrder(OrderActions action, int totalQuantity, double limitPrice)
        {
            Order order = new Order();
            order.Action = action.ToString();
            order.OrderType = OrderTypes.LMT.ToString();
            order.TotalQuantity = totalQuantity;
            order.LmtPrice = limitPrice;
            order.Tif = TimeInForce.DAY.ToString();
            order.Transmit = true;
            order.OutsideRth = true;
            return order;
        }
    }
}
