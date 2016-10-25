using IBApi;

namespace TradeBot.TwsAbstractions
{
    public class PortfolioInfo
    {
        public PortfolioInfo(Contract contract, double position, double marketPrice, double marketValue, double averageCost, double unrealisedPNL, double realisedPNL, string account)
        {
            Contract = contract;
            Position = position;
            MarketPrice = marketPrice;
            MarketValue = marketValue;
            AverageCost = averageCost;
            UnrealisedPNL = unrealisedPNL;
            RealisedPNL = realisedPNL;
            Account = account;
        }

        public Contract Contract { get; }
        public double Position { get; }
        public double MarketPrice { get; }
        public double MarketValue { get; }
        public double AverageCost { get; }
        public double UnrealisedPNL { get; }
        public double RealisedPNL { get; }
        public string Account { get; }
    }
}
