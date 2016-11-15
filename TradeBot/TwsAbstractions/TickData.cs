using System;
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
            return ContainsKeys(null, keys);
        }

        public bool ContainsKeys(Func<int, double, bool> criteria, params int[] keys)
        {
            return keys.All(key =>
            {
                double value;
                bool containsKey = TryGetValue(key, out value);
                return containsKey && (criteria?.Invoke(key, value) ?? true);
            });
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
