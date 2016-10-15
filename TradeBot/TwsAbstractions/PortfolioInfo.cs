using IBApi;

namespace TradeBot.TwsAbstractions
{
    public class PortfolioInfo
    {
        public PortfolioInfo(Contract contract, int positionSize, double marketPrice, double marketValue, double averageCost, double unrealisedPNL, double realisedPNL, string account)
        {
            Contract = contract;
            PositionSize = positionSize;
            MarketPrice = marketPrice;
            MarketValue = marketValue;
            AverageCost = averageCost;
            UnrealisedPNL = unrealisedPNL;
            RealisedPNL = realisedPNL;
            Account = account;
        }

        public Contract Contract { get; }
        public int PositionSize { get; }
        public double MarketPrice { get; }
        public double MarketValue { get; }
        public double AverageCost { get; }
        public double UnrealisedPNL { get; }
        public double RealisedPNL { get; }
        public string Account { get; }
    }
}
