using System.Collections.Generic;

namespace TradeBot.TwsAbstractions
{
    public class Portfolio : Dictionary<string, Position>
    {
        public Position Get(string tickerSymbol)
        {
            if (tickerSymbol == null)
            {
                return null;
            }

            Position position;
            TryGetValue(tickerSymbol, out position);
            return position;
        }

        public void Update(Position position)
        {
            string tickerSymbol = position.Symbol;
            if (position.PositionSize == 0)
            {
                Remove(tickerSymbol);
            }
            else
            {
                if (ContainsKey(tickerSymbol))
                {
                    this[tickerSymbol] = position;
                }
                else
                {
                    Add(tickerSymbol, position);
                }
            }
        }
    }
}
