using System.Collections.Generic;

namespace TradeBot.TwsAbstractions
{
    public class TickData
    {
        private IDictionary<int, double> data;

        public TickData()
        {
            data = new Dictionary<int, double>();
        }

        public double this[int field]
        {
            get
            {
                double result;
                return data.TryGetValue(field, out result)
                    ? result : -1;
            }
            set
            {
                if (data.ContainsKey(field))
                {
                    data[field] = value;
                }
                else
                {
                    data.Add(field, value);
                }
            }
        }
    }
}
