using IBApi;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using TradeBot.Extensions;
using TradeBot.Gui;

namespace TradeBot.Tws
{
    public abstract class TwsResponseHandler : EWrapper
    {
        public virtual void accountDownloadEnd(string account)
        {
            ShowMethodDebugInfo(account);
        }

        public virtual void accountSummary(int requestId, string account, string tag, string value, string currency)
        {
            ShowMethodDebugInfo(requestId, account, tag, value, currency);
        }

        public virtual void accountSummaryEnd(int requestId)
        {
            ShowMethodDebugInfo(requestId);
        }

        public virtual void bondContractDetails(int requestId, ContractDetails contract)
        {
            ShowMethodDebugInfo(requestId, contract);
        }

        public virtual void commissionReport(CommissionReport commissionReport)
        {
            ShowMethodDebugInfo(commissionReport);
        }

        public virtual void connectionClosed()
        {
            ShowMethodDebugInfo();
        }

        public virtual void contractDetails(int requestId, ContractDetails contractDetails)
        {
            ShowMethodDebugInfo(requestId, contractDetails);
        }

        public virtual void contractDetailsEnd(int requestId)
        {
            ShowMethodDebugInfo(requestId);
        }

        public virtual void currentTime(long time)
        {
            ShowMethodDebugInfo(time);
        }

        public virtual void deltaNeutralValidation(int requestId, UnderComp underComp)
        {
            ShowMethodDebugInfo(requestId, underComp);
        }

        public virtual void displayGroupList(int requestId, string groups)
        {
            ShowMethodDebugInfo(requestId, groups);
        }

        public virtual void displayGroupUpdated(int requestId, string contractInfo)
        {
            ShowMethodDebugInfo(requestId, contractInfo);
        }

        public virtual void error(Exception exception)
        {
            ShowMethodDebugInfo(exception);
        }

        public virtual void error(string errorMessage)
        {
            ShowMethodDebugInfo(errorMessage);
        }

        public virtual void error(int id, int errorCode, string errorMessage)
        {
            ShowMethodDebugInfo(id, errorCode, errorMessage);
        }

        public virtual void execDetails(int requestId, Contract contract, Execution execution)
        {
            ShowMethodDebugInfo(requestId, contract, execution);
        }

        public virtual void execDetailsEnd(int requestId)
        {
            ShowMethodDebugInfo(requestId);
        }

        public virtual void fundamentalData(int requestId, string data)
        {
            ShowMethodDebugInfo(requestId, data);
        }

        public virtual void historicalData(int requestId, string date, double open, double high, double low, double close, int volume, int count, double WAP, bool hasGaps)
        {
            ShowMethodDebugInfo(requestId, date, open, high, low, close, volume, count, WAP, hasGaps);
        }

        public virtual void historicalDataEnd(int requestId, string start, string end)
        {
            ShowMethodDebugInfo(requestId, start, end);
        }

        public virtual void managedAccounts(string accounts)
        {
            ShowMethodDebugInfo(accounts);
        }

        public virtual void marketDataType(int requestId, int marketDataType)
        {
            ShowMethodDebugInfo(requestId, marketDataType);
        }

        public virtual void nextValidId(int nextValidOrderId)
        {
            ShowMethodDebugInfo(nextValidOrderId);
        }

        public virtual void openOrder(int orderId, Contract contract, Order order, OrderState orderState)
        {
            ShowMethodDebugInfo(orderId, contract, order, orderState);
        }

        public virtual void openOrderEnd()
        {
            ShowMethodDebugInfo();
        }

        public virtual void orderStatus(int orderId, string status, int filled, int remaining, double avgFillPrice, int permId, int parentId, double lastFillPrice, int clientId, string whyHeld)
        {
            ShowMethodDebugInfo(orderId, status, filled, remaining, avgFillPrice, permId, parentId, lastFillPrice, clientId, whyHeld);
        }

        public virtual void position(string account, Contract contract, int position, double averageCost)
        {
            ShowMethodDebugInfo(account, contract, position, averageCost);
        }

        public virtual void positionEnd()
        {
            ShowMethodDebugInfo();
        }

        public virtual void realtimeBar(int requestId, long time, double open, double high, double low, double close, long volume, double WAP, int count)
        {
            ShowMethodDebugInfo(requestId, time, open, high, low, close, volume, WAP, count);
        }

        public virtual void receiveFA(int faDataType, string faXmlData)
        {
            ShowMethodDebugInfo(faDataType, faXmlData);
        }

        public virtual void scannerData(int requestId, int rank, ContractDetails contractDetails, string distance, string benchmark, string projection, string legsStr)
        {
            ShowMethodDebugInfo(requestId, rank, contractDetails, distance, benchmark, projection, legsStr);
        }

        public virtual void scannerDataEnd(int requestId)
        {
            ShowMethodDebugInfo(requestId);
        }

        public virtual void scannerParameters(string xml)
        {
            ShowMethodDebugInfo(xml);
        }

        public virtual void tickEFP(int tickerId, int tickType, double basisPoints, string formattedBasisPoints, double impliedFuture, int holdDays, string futureExpiry, double dividendImpact, double dividendsToExpiry)
        {
            ShowMethodDebugInfo(tickerId, tickType, basisPoints, formattedBasisPoints, impliedFuture, holdDays, futureExpiry, dividendImpact, dividendsToExpiry);
        }

        public virtual void tickGeneric(int tickerId, int field, double value)
        {
            ShowMethodDebugInfo(tickerId, TickType.getField(field), value);
        }

        public virtual void tickOptionComputation(int tickerId, int field, double impliedVolatility, double delta, double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice)
        {
            ShowMethodDebugInfo(tickerId, TickType.getField(field), impliedVolatility, delta, optPrice, pvDividend, gamma, vega, theta, undPrice);
        }

        public virtual void tickPrice(int tickerId, int field, double price, int canAutoExecute)
        {
            ShowMethodDebugInfo(tickerId, TickType.getField(field), price, canAutoExecute);
        }

        public virtual void tickSize(int tickerId, int field, int size)
        {
            ShowMethodDebugInfo(tickerId, TickType.getField(field), size);
        }

        public virtual void tickSnapshotEnd(int tickerId)
        {
            ShowMethodDebugInfo(tickerId);
        }

        public virtual void tickString(int tickerId, int field, string value)
        {
            ShowMethodDebugInfo(tickerId, TickType.getField(field), value);
        }

        public virtual void updateAccountTime(string timestamp)
        {
            ShowMethodDebugInfo(timestamp);
        }

        public virtual void updateAccountValue(string key, string value, string currency, string accountName)
        {
            ShowMethodDebugInfo(key, value, currency, accountName);
        }

        public virtual void updateMktDepth(int tickerId, int position, int operation, int side, double price, int size)
        {
            ShowMethodDebugInfo(tickerId, position, operation, side, price, size);
        }

        public virtual void updateMktDepthL2(int tickerId, int position, string marketMaker, int operation, int side, double price, int size)
        {
            ShowMethodDebugInfo(tickerId, position, marketMaker, operation, side, price, size);
        }

        public virtual void updateNewsBulletin(int messageId, int messageType, string message, string origExchange)
        {
            ShowMethodDebugInfo(messageId, messageType, message, origExchange);
        }

        public virtual void updatePortfolio(Contract contract, int position, double marketPrice, double marketValue, double averageCost, double unrealisedPNL, double realisedPNL, string accountName)
        {
            ShowMethodDebugInfo(contract, position, marketPrice, marketValue, averageCost, unrealisedPNL, realisedPNL, accountName);
        }

        public virtual void verifyCompleted(bool isSuccessful, string errorText)
        {
            ShowMethodDebugInfo(isSuccessful, errorText);
        }

        public virtual void verifyMessageAPI(string apiData)
        {
            ShowMethodDebugInfo(apiData);
        }

        protected void ShowMethodDebugInfo(params object[] parameterValues)
        {
            StackTrace stackTrace = new StackTrace();
            MethodBase callingMethod = stackTrace.GetFrame(1).GetMethod();

            var parameterNameValuePairs = callingMethod.GetParameters()
                .Select((p, i) => new KeyValuePair<string, object>(p.Name, parameterValues[i]));

            IO.ShowMessage(
                "{0} : {1}",
                MessageType.DEBUG,
                callingMethod.Name,
                parameterNameValuePairs.ToPrettyString());
        }
    }
}
