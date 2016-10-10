using IBApi;

namespace TradeBot.Tws
{
    public static class ContractFactory
    {
        public static Contract CreateStockContract(string tickerSymbol)
        {
            Contract contract = new Contract();
            contract.Symbol = tickerSymbol.ToUpper();
            contract.SecType = SecurityTypes.STK.ToString();
            contract.Currency = Currencies.USD.ToString();
            contract.Exchange = Exchanges.SMART.ToString();
            return contract;
        }
    }
}