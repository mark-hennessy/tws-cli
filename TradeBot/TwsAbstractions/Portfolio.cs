using System.Collections.Generic;

namespace TradeBot.TwsAbstractions
{
    public class Portfolio : Dictionary<string, PortfolioInfo>
    {
        public PortfolioInfo Get(string tickerSymbol)
        {
            if (tickerSymbol == null)
            {
                return null;
            }

            PortfolioInfo result;
            TryGetValue(tickerSymbol, out result);
            return result;
        }

        public void Update(PortfolioInfo info)
        {
            string tickerSymbol = info.Contract.Symbol;
            if (info.PositionSize == 0)
            {
                Remove(tickerSymbol);
            }
            else
            {
                if (ContainsKey(tickerSymbol))
                {
                    this[tickerSymbol] = info;
                }
                else
                {
                    Add(tickerSymbol, info);
                }
            }
        }
    }
}
