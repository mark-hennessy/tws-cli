using System.Collections.Generic;

namespace TradeBot.Tws
{
    public class PriceData
    {
        private IDictionary<int, double> priceInfoDictionary;

        public PriceData()
        {
            priceInfoDictionary = new Dictionary<int, double>();
        }

        /// <summary>
        /// Custom indexer for getting and setting price info.
        /// </summary>
        /// <param name="tickType">an IBApi.TickType int code</param>
        /// <returns>the price for the given tick type or -1 
        /// if no information for the tick type is found</returns>
        public double this[int tickType]
        {
            get
            {
                return priceInfoDictionary.ContainsKey(tickType)
                    ? priceInfoDictionary[tickType] : -1;
            }
            set
            {
                if (priceInfoDictionary.ContainsKey(tickType))
                {
                    priceInfoDictionary[tickType] = value;
                }
                else
                {
                    priceInfoDictionary.Add(tickType, value);
                }
            }
        }
    }
}
