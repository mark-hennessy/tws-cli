using System;
using System.Collections.Generic;
using IBApi;

namespace TradeBot
{
    public abstract class EWrapperEvents : EWrapper
    {
        public event Action<int, int, string, Exception> Error;

        void EWrapper.error(Exception e)
        {
            Error?.Invoke(0, 0, null, e);
        }

        void EWrapper.error(string str)
        {
            Error?.Invoke(0, 0, str, null);
        }

        void EWrapper.error(int id, int errorCode, string errorMsg)
        {
            Error?.Invoke(id, errorCode, errorMsg, null);
        }

        public event Action ConnectionClosed;

        void EWrapper.connectionClosed()
        {
            ConnectionClosed?.Invoke();
        }

        public event Action<long> CurrentTime;

        void EWrapper.currentTime(long time)
        {
            CurrentTime?.Invoke(time);
        }

        public event Action<int, int, double, int> TickPrice;

        void EWrapper.tickPrice(int tickerId, int field, double price, int canAutoExecute)
        {
            TickPrice?.Invoke(tickerId, field, price, canAutoExecute);
        }

        public event Action<int, int, int> TickSize;

        void EWrapper.tickSize(int tickerId, int field, int size)
        {
            TickSize?.Invoke(tickerId, field, size);
        }

        public event Action<int, int, string> TickString;

        void EWrapper.tickString(int tickerId, int tickType, string value)
        {
            TickString?.Invoke(tickerId, tickType, value);
        }

        public event Action<int, int, double> TickGeneric;

        void EWrapper.tickGeneric(int tickerId, int field, double value)
        {
            TickGeneric?.Invoke(tickerId, field, value);
        }

        public event Action<int, int, double, string, double, int, string, double, double> TickEFP;

        void EWrapper.tickEFP(int tickerId, int tickType, double basisPoints, string formattedBasisPoints, double impliedFuture, int holdDays, string futureLastTradeDate, double dividendImpact, double dividendsToLastTradeDate)
        {
            TickEFP?.Invoke(tickerId, tickType, basisPoints, formattedBasisPoints, impliedFuture, holdDays, futureLastTradeDate, dividendImpact, dividendsToLastTradeDate);
        }

        public event Action<int> TickSnapshotEnd;

        void EWrapper.tickSnapshotEnd(int tickerId)
        {
            TickSnapshotEnd?.Invoke(tickerId);
        }

        public event Action<int> NextValidId;

        void EWrapper.nextValidId(int orderId)
        {
            NextValidId?.Invoke(orderId);
        }

        public event Action<int, UnderComp> DeltaNeutralValidation;

        void EWrapper.deltaNeutralValidation(int reqId, UnderComp underComp)
        {
            DeltaNeutralValidation?.Invoke(reqId, underComp);
        }

        public event Action<string> ManagedAccounts;

        void EWrapper.managedAccounts(string accountsList)
        {
            ManagedAccounts?.Invoke(accountsList);
        }

        public event Action<int, int, double, double, double, double, double, double, double, double> TickOptionCommunication;

        void EWrapper.tickOptionComputation(int tickerId, int field, double impliedVolatility, double delta, double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice)
        {
            TickOptionCommunication?.Invoke(tickerId, field, impliedVolatility, delta, optPrice, pvDividend, gamma, vega, theta, undPrice);
        }

        public event Action<int, string, string, string, string> AccountSummary;

        void EWrapper.accountSummary(int reqId, string account, string tag, string value, string currency)
        {
            AccountSummary?.Invoke(reqId, account, tag, value, currency);
        }

        public event Action<int> AccountSummaryEnd;

        void EWrapper.accountSummaryEnd(int reqId)
        {
            AccountSummaryEnd?.Invoke(reqId);
        }

        public event Action<string, string, string, string> UpdateAccountValue;

        void EWrapper.updateAccountValue(string key, string value, string currency, string accountName)
        {
            UpdateAccountValue?.Invoke(key, value, currency, accountName);
        }

        public event Action<Contract, double, double, double, double, double, double, string> UpdatePortfolio;

        void EWrapper.updatePortfolio(Contract contract, double position, double marketPrice, double marketValue, double averageCost, double unrealisedPNL, double realisedPNL, string accountName)
        {
            UpdatePortfolio?.Invoke(contract, position, marketPrice, marketValue, averageCost, unrealisedPNL, realisedPNL, accountName);
        }

        public event Action<string> UpdateAccountTime;

        void EWrapper.updateAccountTime(string timestamp)
        {
            UpdateAccountTime?.Invoke(timestamp);
        }

        public event Action<string> AccountDownloadEnd;

        void EWrapper.accountDownloadEnd(string account)
        {
            AccountDownloadEnd?.Invoke(account);
        }

        public event Action<int, string, double, double, double, int, int, double, int, string> OrderStatus;

        void EWrapper.orderStatus(int orderId, string status, double filled, double remaining, double avgFillPrice, int permId, int parentId, double lastFillPrice, int clientId, string whyHeld)
        {
            OrderStatus?.Invoke(orderId, status, filled, remaining, avgFillPrice, permId, parentId, lastFillPrice, clientId, whyHeld);
        }

        public event Action<int, Contract, Order, OrderState> OpenOrder;

        void EWrapper.openOrder(int orderId, Contract contract, Order order, OrderState orderState)
        {
            OpenOrder?.Invoke(orderId, contract, order, orderState);
        }

        public event Action OpenOrderEnd;

        void EWrapper.openOrderEnd()
        {
            OpenOrderEnd?.Invoke();
        }

        public event Action<int, ContractDetails> ContractDetails;

        void EWrapper.contractDetails(int reqId, ContractDetails contractDetails)
        {
            ContractDetails?.Invoke(reqId, contractDetails);
        }

        public event Action<int> ContractDetailsEnd;

        void EWrapper.contractDetailsEnd(int reqId)
        {
            ContractDetailsEnd?.Invoke(reqId);
        }

        public event Action<int, Contract, Execution> ExecDetails;

        void EWrapper.execDetails(int reqId, Contract contract, Execution execution)
        {
            ExecDetails?.Invoke(reqId, contract, execution);
        }

        public event Action<int> ExecDetailsEnd;

        void EWrapper.execDetailsEnd(int reqId)
        {
            ExecDetailsEnd?.Invoke(reqId);
        }

        public event Action<CommissionReport> CommissionReport;

        void EWrapper.commissionReport(CommissionReport commissionReport)
        {
            CommissionReport?.Invoke(commissionReport);
        }

        public event Action<int, string> FundamentalData;

        void EWrapper.fundamentalData(int reqId, string data)
        {
            FundamentalData?.Invoke(reqId, data);
        }

        public event Action<int, string, double, double, double, double, int, int, double, bool> HistoricalData;

        void EWrapper.historicalData(int reqId, string date, double open, double high, double low, double close, int volume, int count, double WAP, bool hasGaps)
        {
            HistoricalData?.Invoke(reqId, date, open, high, low, close, volume, count, WAP, hasGaps);
        }

        public event Action<int, string, string> HistoricalDataEnd;

        void EWrapper.historicalDataEnd(int reqId, string startDate, string endDate)
        {
            HistoricalDataEnd?.Invoke(reqId, startDate, endDate);
        }

        public event Action<int, int> MarketDataType;

        void EWrapper.marketDataType(int reqId, int marketDataType)
        {
            MarketDataType?.Invoke(reqId, marketDataType);
        }

        public event Action<int, int, int, int, double, int> UpdateMktDepth;

        void EWrapper.updateMktDepth(int tickerId, int position, int operation, int side, double price, int size)
        {
            UpdateMktDepth?.Invoke(tickerId, position, operation, side, price, size);
        }

        public event Action<int, int, string, int, int, double, int> UpdateMktDepthL2;

        void EWrapper.updateMktDepthL2(int tickerId, int position, string marketMaker, int operation, int side, double price, int size)
        {
            UpdateMktDepthL2?.Invoke(tickerId, position, marketMaker, operation, side, price, size);
        }

        public event Action<int, int, string, string> UpdateNewsBulletin;

        void EWrapper.updateNewsBulletin(int msgId, int msgType, string message, string origExchange)
        {
            UpdateNewsBulletin?.Invoke(msgId, msgType, message, origExchange);
        }

        public event Action<string, Contract, double, double> Position;

        void EWrapper.position(string account, Contract contract, double pos, double avgCost)
        {
            Position?.Invoke(account, contract, pos, avgCost);
        }

        public event Action PositionEnd;

        void EWrapper.positionEnd()
        {
            PositionEnd?.Invoke();
        }

        public event Action<int, long, double, double, double, double, long, double, int> RealtimeBar;

        void EWrapper.realtimeBar(int reqId, long time, double open, double high, double low, double close, long volume, double WAP, int count)
        {
            RealtimeBar?.Invoke(reqId, time, open, high, low, close, volume, WAP, count);
        }

        public event Action<string> ScannerParameters;

        void EWrapper.scannerParameters(string xml)
        {
            ScannerParameters?.Invoke(xml);
        }

        public event Action<int, int, ContractDetails, string, string, string, string> ScannerData;

        void EWrapper.scannerData(int reqId, int rank, ContractDetails contractDetails, string distance, string benchmark, string projection, string legsStr)
        {
            ScannerData?.Invoke(reqId, rank, contractDetails, distance, benchmark, projection, legsStr);
        }

        public event Action<int> ScannerDataEnd;

        void EWrapper.scannerDataEnd(int reqId)
        {
            ScannerDataEnd?.Invoke(reqId);
        }

        public event Action<int, string> ReceiveFA;

        void EWrapper.receiveFA(int faDataType, string faXmlData)
        {
            ReceiveFA?.Invoke(faDataType, faXmlData);
        }

        public event Action<int, ContractDetails> BondContractDetails;

        void EWrapper.bondContractDetails(int requestId, ContractDetails contractDetails)
        {
            BondContractDetails?.Invoke(requestId, contractDetails);
        }

        public event Action<string> VerifyMessageAPI;

        void EWrapper.verifyMessageAPI(string apiData)
        {
            VerifyMessageAPI?.Invoke(apiData);
        }
        public event Action<bool, string> VerifyCompleted;

        void EWrapper.verifyCompleted(bool isSuccessful, string errorText)
        {
            VerifyCompleted?.Invoke(isSuccessful, errorText);
        }

        public event Action<string, string> VerifyAndAuthMessageAPI;

        void EWrapper.verifyAndAuthMessageAPI(string apiData, string xyzChallenge)
        {
            VerifyAndAuthMessageAPI?.Invoke(apiData, xyzChallenge);
        }

        public event Action<bool, string> VerifyAndAuthCompleted;

        void EWrapper.verifyAndAuthCompleted(bool isSuccessful, string errorText)
        {
            VerifyAndAuthCompleted?.Invoke(isSuccessful, errorText);
        }

        public event Action<int, string> DisplayGroupList;

        void EWrapper.displayGroupList(int reqId, string groups)
        {
            DisplayGroupList?.Invoke(reqId, groups);
        }

        public event Action<int, string> DisplayGroupUpdated;

        void EWrapper.displayGroupUpdated(int reqId, string contractInfo)
        {
            DisplayGroupUpdated?.Invoke(reqId, contractInfo);
        }

        public event Action ConnectAck;

        void EWrapper.connectAck()
        {
            ConnectAck?.Invoke();
        }

        public event Action<int, string, string, Contract, double, double> PositionMulti;

        void EWrapper.positionMulti(int reqId, string account, string modelCode, Contract contract, double pos, double avgCost)
        {
            PositionMulti?.Invoke(reqId, account, modelCode, contract, pos, avgCost);
        }

        public event Action<int> PositionMultiEnd;

        void EWrapper.positionMultiEnd(int reqId)
        {
            PositionMultiEnd?.Invoke(reqId);
        }

        public event Action<int, string, string, string, string, string> AccountUpdateMulti;

        void EWrapper.accountUpdateMulti(int reqId, string account, string modelCode, string key, string value, string currency)
        {
            AccountUpdateMulti?.Invoke(reqId, account, modelCode, key, value, currency);
        }

        public event Action<int> AccountUpdateMultiEnd;

        void EWrapper.accountUpdateMultiEnd(int reqId)
        {
            AccountUpdateMultiEnd?.Invoke(reqId);
        }

        public event Action<int, string, int, string, string, HashSet<string>, HashSet<double>> SecurityDefinitionOptionParameter;

        void EWrapper.securityDefinitionOptionParameter(int reqId, string exchange, int underlyingConId, string tradingClass, string multiplier, HashSet<string> expirations, HashSet<double> strikes)
        {
            SecurityDefinitionOptionParameter?.Invoke(reqId, exchange, underlyingConId, tradingClass, multiplier, expirations, strikes);
        }

        public event Action<int> SecurityDefinitionOptionParameterEnd;

        void EWrapper.securityDefinitionOptionParameterEnd(int reqId)
        {
            SecurityDefinitionOptionParameterEnd?.Invoke(reqId);
        }

        public event Action<int, SoftDollarTier[]> SoftDollarTiers;

        void EWrapper.softDollarTiers(int reqId, SoftDollarTier[] tiers)
        {
            SoftDollarTiers?.Invoke(reqId, tiers);
        }
    }
}
