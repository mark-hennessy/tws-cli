using System.Collections.Generic;
using System.Linq;

namespace TradeBot.TwsAbstractions
{
    public class TickData : Dictionary<int, double>
    {
        public double? Get(int tickType)
        {
            double result;
            return TryGetValue(tickType, out result)
                ? (double?)result : null;
        }

        public bool ContainsKeys(params int[] keys)
        {
            return keys.All(k => ContainsKey(k));
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
