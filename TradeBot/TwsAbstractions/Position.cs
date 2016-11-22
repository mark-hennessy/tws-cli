using IBApi;
using TradeBot.Extensions;

namespace TradeBot.TwsAbstractions
{
    public class Position
    {
        public Position(string account, Contract contract, double positionSize, double averageCost)
        {
            Account = account;
            Contract = contract;
            PositionSize = positionSize;
            AverageCost = averageCost;
        }

        public Position(string account, Contract contract, double positionSize, double averageCost, double marketPrice, double marketValue, double unrealizedPNL, double realizedPNL)
            : this(account, contract, positionSize, averageCost)
        {
            MarketPrice = marketPrice;
            MarketValue = marketValue;
            UnrealizedPNL = unrealizedPNL;
            RealizedPNL = realizedPNL;
        }

        public string Symbol
        {
            get
            {
                return Contract?.Symbol;
            }
        }

        public Contract Contract { get; }

        public double PositionSize { get; }

        public double AverageCost { get; }

        public double? MarketPrice { get; }

        public double? MarketValue { get; }

        public double? UnrealizedPNL { get; }

        public double? RealizedPNL { get; }

        public string Account { get; }

        public override string ToString()
        {
            return this.ToPrettyString(maxIndentLevel: 0);
        }
    }
}
