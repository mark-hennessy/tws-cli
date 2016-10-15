using IBApi;

namespace TradeBot.TwsAbstractions
{
    public class PositionInfo
    {
        public PositionInfo(string account, Contract contract, int positionSize, double averageCost)
        {
            Account = account;
            Contract = contract;
            PositionSize = positionSize;
            AverageCost = averageCost;
        }

        public string Account { get; }
        public Contract Contract { get; }
        public int PositionSize { get; }
        public double AverageCost { get; }
    }
}
