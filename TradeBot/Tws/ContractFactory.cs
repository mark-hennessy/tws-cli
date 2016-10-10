using IBApi;

namespace TradeBot.Tws
{
    public static class ContractFactory
    {
        private static int nextContractId = 1;

        public static Contract CreateStockContract(string tickerSymbol)
        {
            Contract contract = new Contract();
            contract.Symbol = tickerSymbol.ToUpper();
            contract.SecType = SecurityTypes.STK.ToString();
            contract.Currency = Currencies.USD.ToString();
            contract.Exchange = Exchanges.SMART.ToString();
            return contract;
        }

        public static int GenerateContractId()
        {
            return nextContractId++;
        }
    }
}