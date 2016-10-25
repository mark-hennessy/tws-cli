using System;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;
using System.Reflection;
using IBApi;
using TradeBot.Gui;
using TradeBot.Extensions;

namespace TradeBot.TwsAbstractions
{
    public abstract class EWrapperImpl : EWrapper
    {
        public string[] IgnoredDebugMessages { get; set; }

        public event Action<int, int, string, Exception> Error;

        void EWrapper.error(Exception e)
        {
            ShowDebugMessage(e);

            Error?.Invoke(0, 0, null, e);
        }

        void EWrapper.error(string str)
        {
            ShowDebugMessage(str);

            Error?.Invoke(0, 0, str, null);
        }

        void EWrapper.error(int id, int errorCode, string errorMsg)
        {
            ShowDebugMessage(id, errorCode, errorMsg);

            Error?.Invoke(id, errorCode, errorMsg, null);
        }

        public event Action ConnectionClosed;

        void EWrapper.connectionClosed()
        {
            ShowDebugMessage();

            ConnectionClosed?.Invoke();
        }

        public event Action<long> CurrentTime;

        void EWrapper.currentTime(long time)
        {
            ShowDebugMessage(time);

            CurrentTime?.Invoke(time);
        }

        public event Action<int, int, double, int> TickPrice;

        void EWrapper.tickPrice(int tickerId, int tickType, double price, int canAutoExecute)
        {
            ShowDebugMessage(tickerId, TickType.getField(tickType), price, canAutoExecute);

            TickPrice?.Invoke(tickerId, tickType, price, canAutoExecute);
        }

        public event Action<int, int, int> TickSize;

        void EWrapper.tickSize(int tickerId, int tickType, int size)
        {
            ShowDebugMessage(tickerId, TickType.getField(tickType), size);

            TickSize?.Invoke(tickerId, tickType, size);
        }

        public event Action<int, int, string> TickString;

        void EWrapper.tickString(int tickerId, int tickType, string value)
        {
            ShowDebugMessage(tickerId, TickType.getField(tickType), value);

            TickString?.Invoke(tickerId, tickType, value);
        }

        public event Action<int, int, double> TickGeneric;

        void EWrapper.tickGeneric(int tickerId, int tickType, double value)
        {
            ShowDebugMessage(tickerId, TickType.getField(tickType), value);

            TickGeneric?.Invoke(tickerId, tickType, value);
        }

        public event Action<int, int, double, string, double, int, string, double, double> TickEFP;

        void EWrapper.tickEFP(int tickerId, int tickType, double basisPoints, string formattedBasisPoints, double impliedFuture, int holdDays, string futureLastTradeDate, double dividendImpact, double dividendsToLastTradeDate)
        {
            ShowDebugMessage(tickerId, tickType, basisPoints, formattedBasisPoints, impliedFuture, holdDays, futureLastTradeDate, dividendImpact, dividendsToLastTradeDate);

            TickEFP?.Invoke(tickerId, tickType, basisPoints, formattedBasisPoints, impliedFuture, holdDays, futureLastTradeDate, dividendImpact, dividendsToLastTradeDate);
        }

        public event Action<int> TickSnapshotEnd;

        void EWrapper.tickSnapshotEnd(int tickerId)
        {
            ShowDebugMessage(tickerId);

            TickSnapshotEnd?.Invoke(tickerId);
        }

        public event Action<int> NextValidId;

        void EWrapper.nextValidId(int orderId)
        {
            ShowDebugMessage(orderId);

            NextValidId?.Invoke(orderId);
        }

        public event Action<int, UnderComp> DeltaNeutralValidation;

        void EWrapper.deltaNeutralValidation(int reqId, UnderComp underComp)
        {
            ShowDebugMessage(reqId, underComp);

            DeltaNeutralValidation?.Invoke(reqId, underComp);
        }

        public event Action<string> ManagedAccounts;

        void EWrapper.managedAccounts(string accountsList)
        {
            ShowDebugMessage(accountsList);

            ManagedAccounts?.Invoke(accountsList);
        }

        public event Action<int, int, double, double, double, double, double, double, double, double> TickOptionCommunication;

        void EWrapper.tickOptionComputation(int tickerId, int tickType, double impliedVolatility, double delta, double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice)
        {
            ShowDebugMessage(tickerId, TickType.getField(tickType), impliedVolatility, delta, optPrice, pvDividend, gamma, vega, theta, undPrice);

            TickOptionCommunication?.Invoke(tickerId, tickType, impliedVolatility, delta, optPrice, pvDividend, gamma, vega, theta, undPrice);
        }

        public event Action<int, string, string, string, string> AccountSummary;

        void EWrapper.accountSummary(int reqId, string account, string tag, string value, string currency)
        {
            ShowDebugMessage(reqId, account, tag, value, currency);

            AccountSummary?.Invoke(reqId, account, tag, value, currency);
        }

        public event Action<int> AccountSummaryEnd;

        void EWrapper.accountSummaryEnd(int reqId)
        {
            ShowDebugMessage(reqId);

            AccountSummaryEnd?.Invoke(reqId);
        }

        public event Action<string, string, string, string> UpdateAccountValue;

        void EWrapper.updateAccountValue(string key, string value, string currency, string accountName)
        {
            ShowDebugMessage(key, value, currency, accountName);

            UpdateAccountValue?.Invoke(key, value, currency, accountName);
        }

        public event Action<Contract, double, double, double, double, double, double, string> UpdatePortfolio;

        void EWrapper.updatePortfolio(Contract contract, double position, double marketPrice, double marketValue, double averageCost, double unrealisedPNL, double realisedPNL, string accountName)
        {
            ShowDebugMessage(contract, position, marketPrice, marketValue, averageCost, unrealisedPNL, realisedPNL, accountName);

            UpdatePortfolio?.Invoke(contract, position, marketPrice, marketValue, averageCost, unrealisedPNL, realisedPNL, accountName);
        }

        public event Action<string> UpdateAccountTime;

        void EWrapper.updateAccountTime(string timestamp)
        {
            ShowDebugMessage(timestamp);

            UpdateAccountTime?.Invoke(timestamp);
        }

        public event Action<string> AccountDownloadEnd;

        void EWrapper.accountDownloadEnd(string account)
        {
            ShowDebugMessage(account);

            AccountDownloadEnd?.Invoke(account);
        }

        public event Action<int, string, double, double, double, int, int, double, int, string> OrderStatus;

        void EWrapper.orderStatus(int orderId, string status, double filled, double remaining, double avgFillPrice, int permId, int parentId, double lastFillPrice, int clientId, string whyHeld)
        {
            ShowDebugMessage(orderId, status, filled, remaining, avgFillPrice, permId, parentId, lastFillPrice, clientId, whyHeld);

            OrderStatus?.Invoke(orderId, status, filled, remaining, avgFillPrice, permId, parentId, lastFillPrice, clientId, whyHeld);
        }

        public event Action<int, Contract, Order, OrderState> OpenOrder;

        void EWrapper.openOrder(int orderId, Contract contract, Order order, OrderState orderState)
        {
            ShowDebugMessage(orderId, contract, order, orderState);

            OpenOrder?.Invoke(orderId, contract, order, orderState);
        }

        public event Action OpenOrderEnd;

        void EWrapper.openOrderEnd()
        {
            ShowDebugMessage();

            OpenOrderEnd?.Invoke();
        }

        public event Action<int, ContractDetails> ContractDetails;

        void EWrapper.contractDetails(int reqId, ContractDetails contractDetails)
        {
            ShowDebugMessage(reqId, contractDetails);

            ContractDetails?.Invoke(reqId, contractDetails);
        }

        public event Action<int> ContractDetailsEnd;

        void EWrapper.contractDetailsEnd(int reqId)
        {
            ShowDebugMessage(reqId);

            ContractDetailsEnd?.Invoke(reqId);
        }

        public event Action<int, Contract, Execution> ExecDetails;

        void EWrapper.execDetails(int reqId, Contract contract, Execution execution)
        {
            ShowDebugMessage(reqId, contract, execution);

            ExecDetails?.Invoke(reqId, contract, execution);
        }

        public event Action<int> ExecDetailsEnd;

        void EWrapper.execDetailsEnd(int reqId)
        {
            ShowDebugMessage(reqId);

            ExecDetailsEnd?.Invoke(reqId);
        }

        public event Action<CommissionReport> CommissionReport;

        void EWrapper.commissionReport(CommissionReport commissionReport)
        {
            ShowDebugMessage(commissionReport);

            CommissionReport?.Invoke(commissionReport);
        }

        public event Action<int, string> FundamentalData;

        void EWrapper.fundamentalData(int reqId, string data)
        {
            ShowDebugMessage(reqId, data);

            FundamentalData?.Invoke(reqId, data);
        }

        public event Action<int, string, double, double, double, double, int, int, double, bool> HistoricalData;

        void EWrapper.historicalData(int reqId, string date, double open, double high, double low, double close, int volume, int count, double WAP, bool hasGaps)
        {
            ShowDebugMessage(reqId, date, open, high, low, close, volume, count, WAP, hasGaps);

            HistoricalData?.Invoke(reqId, date, open, high, low, close, volume, count, WAP, hasGaps);
        }

        public event Action<int, string, string> HistoricalDataEnd;

        void EWrapper.historicalDataEnd(int reqId, string startDate, string endDate)
        {
            ShowDebugMessage(reqId, startDate, endDate);

            HistoricalDataEnd?.Invoke(reqId, startDate, endDate);
        }

        public event Action<int, int> MarketDataType;

        void EWrapper.marketDataType(int reqId, int marketDataType)
        {
            ShowDebugMessage(reqId, marketDataType);

            MarketDataType?.Invoke(reqId, marketDataType);
        }

        public event Action<int, int, int, int, double, int> UpdateMktDepth;

        void EWrapper.updateMktDepth(int tickerId, int position, int operation, int side, double price, int size)
        {
            ShowDebugMessage(tickerId, position, operation, side, price, size);

            UpdateMktDepth?.Invoke(tickerId, position, operation, side, price, size);
        }

        public event Action<int, int, string, int, int, double, int> UpdateMktDepthL2;

        void EWrapper.updateMktDepthL2(int tickerId, int position, string marketMaker, int operation, int side, double price, int size)
        {
            ShowDebugMessage(tickerId, position, marketMaker, operation, side, price, size);

            UpdateMktDepthL2?.Invoke(tickerId, position, marketMaker, operation, side, price, size);
        }

        public event Action<int, int, string, string> UpdateNewsBulletin;

        void EWrapper.updateNewsBulletin(int msgId, int msgType, string message, string origExchange)
        {
            ShowDebugMessage(msgId, msgType, message, origExchange);

            UpdateNewsBulletin?.Invoke(msgId, msgType, message, origExchange);
        }

        public event Action<string, Contract, double, double> Position;

        void EWrapper.position(string account, Contract contract, double pos, double avgCost)
        {
            ShowDebugMessage(account, contract, pos, avgCost);

            Position?.Invoke(account, contract, pos, avgCost);
        }

        public event Action PositionEnd;

        void EWrapper.positionEnd()
        {
            ShowDebugMessage();

            PositionEnd?.Invoke();
        }

        public event Action<int, long, double, double, double, double, long, double, int> RealtimeBar;

        void EWrapper.realtimeBar(int reqId, long time, double open, double high, double low, double close, long volume, double WAP, int count)
        {
            ShowDebugMessage(reqId, time, open, high, low, close, volume, WAP, count);

            RealtimeBar?.Invoke(reqId, time, open, high, low, close, volume, WAP, count);
        }

        public event Action<string> ScannerParameters;

        void EWrapper.scannerParameters(string xml)
        {
            ShowDebugMessage(xml);

            ScannerParameters?.Invoke(xml);
        }

        public event Action<int, int, ContractDetails, string, string, string, string> ScannerData;

        void EWrapper.scannerData(int reqId, int rank, ContractDetails contractDetails, string distance, string benchmark, string projection, string legsStr)
        {
            ShowDebugMessage(reqId, rank, contractDetails, distance, benchmark, projection, legsStr);

            ScannerData?.Invoke(reqId, rank, contractDetails, distance, benchmark, projection, legsStr);
        }

        public event Action<int> ScannerDataEnd;

        void EWrapper.scannerDataEnd(int reqId)
        {
            ShowDebugMessage(reqId);

            ScannerDataEnd?.Invoke(reqId);
        }

        public event Action<int, string> ReceiveFA;

        void EWrapper.receiveFA(int faDataType, string faXmlData)
        {
            ShowDebugMessage(faDataType, faXmlData);

            ReceiveFA?.Invoke(faDataType, faXmlData);
        }

        public event Action<int, ContractDetails> BondContractDetails;

        void EWrapper.bondContractDetails(int requestId, ContractDetails contractDetails)
        {
            ShowDebugMessage(requestId, contractDetails);

            BondContractDetails?.Invoke(requestId, contractDetails);
        }

        public event Action<string> VerifyMessageAPI;

        void EWrapper.verifyMessageAPI(string apiData)
        {
            ShowDebugMessage(apiData);

            VerifyMessageAPI?.Invoke(apiData);
        }
        public event Action<bool, string> VerifyCompleted;

        void EWrapper.verifyCompleted(bool isSuccessful, string errorText)
        {
            ShowDebugMessage(isSuccessful, errorText);

            VerifyCompleted?.Invoke(isSuccessful, errorText);
        }

        public event Action<string, string> VerifyAndAuthMessageAPI;

        void EWrapper.verifyAndAuthMessageAPI(string apiData, string xyzChallenge)
        {
            ShowDebugMessage(apiData, xyzChallenge);

            VerifyAndAuthMessageAPI?.Invoke(apiData, xyzChallenge);
        }

        public event Action<bool, string> VerifyAndAuthCompleted;

        void EWrapper.verifyAndAuthCompleted(bool isSuccessful, string errorText)
        {
            ShowDebugMessage(isSuccessful, errorText);

            VerifyAndAuthCompleted?.Invoke(isSuccessful, errorText);
        }

        public event Action<int, string> DisplayGroupList;

        void EWrapper.displayGroupList(int reqId, string groups)
        {
            ShowDebugMessage(reqId, groups);

            DisplayGroupList?.Invoke(reqId, groups);
        }

        public event Action<int, string> DisplayGroupUpdated;

        void EWrapper.displayGroupUpdated(int reqId, string contractInfo)
        {
            ShowDebugMessage(reqId, contractInfo);

            DisplayGroupUpdated?.Invoke(reqId, contractInfo);
        }

        public event Action ConnectAck;

        void EWrapper.connectAck()
        {
            ShowDebugMessage();

            ConnectAck?.Invoke();
        }

        public event Action<int, string, string, Contract, double, double> PositionMulti;

        void EWrapper.positionMulti(int reqId, string account, string modelCode, Contract contract, double pos, double avgCost)
        {
            ShowDebugMessage(reqId, account, modelCode, contract, pos, avgCost);

            PositionMulti?.Invoke(reqId, account, modelCode, contract, pos, avgCost);
        }

        public event Action<int> PositionMultiEnd;

        void EWrapper.positionMultiEnd(int reqId)
        {
            ShowDebugMessage(reqId);

            PositionMultiEnd?.Invoke(reqId);
        }

        public event Action<int, string, string, string, string, string> AccountUpdateMulti;

        void EWrapper.accountUpdateMulti(int reqId, string account, string modelCode, string key, string value, string currency)
        {
            ShowDebugMessage(reqId, account, modelCode, key, value, currency);

            AccountUpdateMulti?.Invoke(reqId, account, modelCode, key, value, currency);
        }

        public event Action<int> AccountUpdateMultiEnd;

        void EWrapper.accountUpdateMultiEnd(int reqId)
        {
            ShowDebugMessage(reqId);

            AccountUpdateMultiEnd?.Invoke(reqId);
        }

        public event Action<int, string, int, string, string, HashSet<string>, HashSet<double>> SecurityDefinitionOptionParameter;

        void EWrapper.securityDefinitionOptionParameter(int reqId, string exchange, int underlyingConId, string tradingClass, string multiplier, HashSet<string> expirations, HashSet<double> strikes)
        {
            ShowDebugMessage(reqId, exchange, underlyingConId, tradingClass, multiplier, expirations, strikes);

            SecurityDefinitionOptionParameter?.Invoke(reqId, exchange, underlyingConId, tradingClass, multiplier, expirations, strikes);
        }

        public event Action<int> SecurityDefinitionOptionParameterEnd;

        void EWrapper.securityDefinitionOptionParameterEnd(int reqId)
        {
            ShowDebugMessage(reqId);

            SecurityDefinitionOptionParameterEnd?.Invoke(reqId);
        }

        public event Action<int, SoftDollarTier[]> SoftDollarTiers;

        void EWrapper.softDollarTiers(int reqId, SoftDollarTier[] tiers)
        {
            ShowDebugMessage(reqId, tiers);

            SoftDollarTiers?.Invoke(reqId, tiers);
        }

        private void ShowDebugMessage(params object[] parameterValues)
        {
            StackTrace stackTrace = new StackTrace();
            MethodBase callingMethod = stackTrace.GetFrame(1).GetMethod();

            // The method name may look something like IBApi.EWrapper.connectAck,
            // but we only care about the actual method name, i.e. connectAck
            string methodName = callingMethod.Name.Split('.').Last();

            if (IgnoredDebugMessages?.Contains(methodName) ?? false)
            {
                return;
            }

            var parameterNameValuePairs = callingMethod.GetParameters()
                .Select((p, i) => new KeyValuePair<string, object>(p.Name, parameterValues[i]));

            IO.ShowMessage(
                "{0} : {1}",
                MessageType.DEBUG,
                methodName,
                parameterNameValuePairs.ToPrettyString());
        }
    }
}
