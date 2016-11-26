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
            bool success = TryGetValue(tickType, out result);
            return success ? (double?)result : null;
        }

        public bool HasTicks(params int[] tickTypes)
        {
            return HasTicks(null, tickTypes);
        }

        public bool HasTicks(Func<int, double, bool> criteria, params int[] tickTypes)
        {
            return tickTypes.All(key =>
            {
                double value;
                bool success = TryGetValue(key, out value);
                return success && (criteria == null || criteria.Invoke(key, value));
            });
        }

        public void Update(int tickType, double value)
        {
            if (ContainsKey(tickType))
            {
                this[tickType] = value;
            }
            else
            {
                Add(tickType, value);
            }
        }
    }
}
