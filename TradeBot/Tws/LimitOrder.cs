using IBApi;
using TradeBot.Extensions;

namespace TradeBot.Tws
{
    public class LimitOrder : Order
    {
        public LimitOrder(OrderActions action, int totalQuantity, double limitPrice)
        {
            Action = action.ToString();
            OrderType = OrderTypes.LMT.ToString();
            TotalQuantity = totalQuantity;
            LmtPrice = limitPrice;
            Tif = TimeInForce.DAY.ToString();
            Transmit = true;
            OutsideRth = true;
        }

        public override string ToString()
        {
            return this.ToPrettyString();
        }
    }
}
