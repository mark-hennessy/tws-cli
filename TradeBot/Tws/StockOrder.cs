using IBApi;
using TradeBot.Extensions;

namespace TradeBot.Tws
{
    public class StockOrder : Order
    {
        private static int nextId = 1;

        public StockOrder()
        {
            Id = nextId++;
        }

        public int Id { get; }

        public override string ToString()
        {
            return this.ToPrettyString();
        }
    }
}
