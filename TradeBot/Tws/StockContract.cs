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
            SecType = SecurityTypes.STK.ToString();
            Currency = Currencies.USD.ToString();
            Exchange = Exchanges.SMART.ToString();
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
