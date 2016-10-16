using System.Collections.Generic;

namespace TradeBot.TwsAbstractions
{
    public class TickData : Dictionary<int, double>
    {
        public double Get(int tickType)
        {
            double result;
            return TryGetValue(tickType, out result)
                ? result : -1;
        }

        public void Update(int field, double value)
        {
            if (ContainsKey(field))
            {
                this[field] = value;
            }
            else
            {
                Add(field, value);
            }
        }
    }
}
