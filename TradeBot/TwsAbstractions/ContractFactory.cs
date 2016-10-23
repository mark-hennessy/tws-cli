using IBApi;

namespace TradeBot.TwsAbstractions
{
    public static class ContractFactory
    {
        public static Contract CreateStockContract(string tickerSymbol)
        {
            return new Contract()
            {
                Symbol = tickerSymbol.ToUpper(),
                SecType = SecurityTypes.STK.ToString(),
                Currency = Currencies.USD.ToString(),
                Exchange = Exchanges.SMART.ToString()
            };
        }
    }
}