using IBApi;
using TradeBot.Extensions;

namespace TradeBot.Tws
{
    public class StockContract : Contract
    {
        private static int nextId = 1;

        public StockContract(string ticker)
        {
            Id = nextId++;
            Symbol = ticker;
            SecType = SecurityTypeConst.STOCK;
            Currency = CurrencyConst.USD;
            Exchange = ExchangeConst.SMART;
            PriceData = new PriceData();
        }

        public int Id { get; }

        public PriceData PriceData { get; }

        public override string ToString()
        {
            return this.ToPrettyString();
        }
    }
}
