using System.Collections.Generic;

namespace TradeBot.TwsAbstractions
{
    public class TickDataStore
    {
        private IDictionary<int, TickData> dataStore;

        public TickDataStore()
        {
            dataStore = new Dictionary<int, TickData>();
        }

        public TickData this[int tickerId]
        {
            get
            {
                return GetTickData(tickerId);
            }
        }

        public TickData GetTickData(int tickerId)
        {
            TickData tickData;

            if (dataStore.ContainsKey(tickerId))
            {
                tickData = dataStore[tickerId];
            }
            else
            {
                tickData = new TickData();
                dataStore.Add(tickerId, tickData);
            }

            return tickData;
        }

        public void RemovePriceData(int tickerId)
        {
            dataStore.Remove(tickerId);
        }
    }
}
