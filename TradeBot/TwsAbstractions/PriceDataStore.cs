using System.Collections.Generic;

namespace TradeBot.TwsAbstractions
{
    public class PriceDataStore
    {
        private IDictionary<int, PriceData> dataStore;

        public PriceDataStore()
        {
            dataStore = new Dictionary<int, PriceData>();
        }

        public PriceData this[int tickerId]
        {
            get
            {
                return GetPriceData(tickerId);
            }
        }

        public PriceData GetPriceData(int tickerId)
        {
            PriceData priceData;

            if (dataStore.ContainsKey(tickerId))
            {
                priceData = dataStore[tickerId];
            }
            else
            {
                priceData = new PriceData();
                dataStore.Add(tickerId, priceData);
            }

            return priceData;
        }

        public void RemovePriceData(int tickerId)
        {
            dataStore.Remove(tickerId);
        }
    }
}
