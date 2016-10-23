using IBApi;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using TradeBot.Extensions;
using TradeBot.Gui;

namespace TradeBot
{
    public abstract class DebugableEWrapper : EWrapperEvents
    {
        public override void accountDownloadEnd(string account)
        {
            ShowMethodDebugInfo(account);
        }

        public virtual void accountSummary(int reqId, string account, string tag, string value, string currency)
        {
            ShowMethodDebugInfo(reqId, account, tag, value, currency);
        }

        public virtual void accountSummaryEnd(int reqId)
        {
            ShowMethodDebugInfo(reqId);
        }

        public virtual void accountUpdateMulti(int reqId, string account, string modelCode, string key, string value, string currency)
        {
            ShowMethodDebugInfo(reqId, account, modelCode, key, value, currency);
        }

        public virtual void accountUpdateMultiEnd(int reqId)
        {
            ShowMethodDebugInfo(reqId);
        }

        public virtual void bondContractDetails(int reqId, ContractDetails contract)
        {
            ShowMethodDebugInfo(reqId, contract);
        }

        public virtual void commissionReport(CommissionReport commissionReport)
        {
            ShowMethodDebugInfo(commissionReport);
        }

        public virtual void connectAck()
        {
            ShowMethodDebugInfo();
        }

        public virtual void connectionClosed()
        {
            ShowMethodDebugInfo();
        }

        public virtual void contractDetails(int reqId, ContractDetails contractDetails)
        {
            ShowMethodDebugInfo(reqId, contractDetails);
        }

        public virtual void contractDetailsEnd(int reqId)
        {
            ShowMethodDebugInfo(reqId);
        }

        public virtual void currentTime(long time)
        {
            ShowMethodDebugInfo(time);
        }

        public virtual void deltaNeutralValidation(int reqId, UnderComp underComp)
        {
            ShowMethodDebugInfo(reqId, underComp);
        }

        public virtual void displayGroupList(int reqId, string groups)
        {
            ShowMethodDebugInfo(reqId, groups);
        }

        public virtual void displayGroupUpdated(int reqId, string contractInfo)
        {
            ShowMethodDebugInfo(reqId, contractInfo);
        }

        public virtual void error(Exception e)
        {
            ShowMethodDebugInfo(e);
        }

        public virtual void error(string str)
        {
            ShowMethodDebugInfo(str);
        }

        public virtual void error(int id, int errorCode, string errorMsg)
        {
            ShowMethodDebugInfo(id, errorCode, errorMsg);
        }

        public virtual void execDetails(int reqId, Contract contract, Execution execution)
        {
            ShowMethodDebugInfo(reqId, contract, execution);
        }

        public virtual void execDetailsEnd(int reqId)
        {
            ShowMethodDebugInfo(reqId);
        }

        public virtual void fundamentalData(int reqId, string data)
        {
            ShowMethodDebugInfo(reqId, data);
        }

        public virtual void historicalData(int reqId, string date, double open, double high, double low, double close, int volume, int count, double WAP, bool hasGaps)
        {
            ShowMethodDebugInfo(reqId, date, open, high, low, close, volume, count, WAP, hasGaps);
        }

        public virtual void historicalDataEnd(int reqId, string start, string end)
        {
            ShowMethodDebugInfo(reqId, start, end);
        }

        public virtual void managedAccounts(string accounts)
        {
            ShowMethodDebugInfo(accounts);
        }

        public virtual void marketDataType(int reqId, int marketDataType)
        {
            ShowMethodDebugInfo(reqId, marketDataType);
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

        public virtual void orderStatus(int orderId, string status, double filled, double remaining, double avgFillPrice, int permId, int parentId, double lastFillPrice, int clientId, string whyHeld)
        {
            ShowMethodDebugInfo(orderId, status, filled, remaining, avgFillPrice, permId, parentId, lastFillPrice, clientId, whyHeld);
        }

        public virtual void orderStatus(int orderId, string status, int filled, int remaining, double avgFillPrice, int permId, int parentId, double lastFillPrice, int clientId, string whyHeld)
        {
            ShowMethodDebugInfo(orderId, status, filled, remaining, avgFillPrice, permId, parentId, lastFillPrice, clientId, whyHeld);
        }

        public virtual void position(string account, Contract contract, double position, double avgCost)
        {
            ShowMethodDebugInfo(account, contract, position, avgCost);
        }

        public virtual void position(string account, Contract contract, int position, double avgCost)
        {
            ShowMethodDebugInfo(account, contract, position, avgCost);
        }

        public virtual void positionEnd()
        {
            ShowMethodDebugInfo();
        }

        public virtual void positionMulti(int reqId, string account, string modelCode, Contract contract, double position, double avgCost)
        {
            ShowMethodDebugInfo(reqId, account, modelCode, contract, position, avgCost);
        }

        public virtual void positionMultiEnd(int reqId)
        {
            ShowMethodDebugInfo(reqId);
        }

        public virtual void realtimeBar(int reqId, long time, double open, double high, double low, double close, long volume, double WAP, int count)
        {
            ShowMethodDebugInfo(reqId, time, open, high, low, close, volume, WAP, count);
        }

        public virtual void receiveFA(int faDataType, string faXmlData)
        {
            ShowMethodDebugInfo(faDataType, faXmlData);
        }

        public virtual void scannerData(int reqId, int rank, ContractDetails contractDetails, string distance, string benchmark, string projection, string legsStr)
        {
            ShowMethodDebugInfo(reqId, rank, contractDetails, distance, benchmark, projection, legsStr);
        }

        public virtual void scannerDataEnd(int reqId)
        {
            ShowMethodDebugInfo(reqId);
        }

        public virtual void scannerParameters(string xml)
        {
            ShowMethodDebugInfo(xml);
        }

        public virtual void securityDefinitionOptionParameter(int reqId, string exchange, int underlyingConId, string tradingClass, string multiplier, HashSet<string> expirations, HashSet<double> strikes)
        {
            ShowMethodDebugInfo(reqId, exchange, underlyingConId, tradingClass, multiplier, expirations, strikes);
        }

        public virtual void securityDefinitionOptionParameterEnd(int reqId)
        {
            ShowMethodDebugInfo(reqId);
        }

        public virtual void softDollarTiers(int reqId, SoftDollarTier[] tiers)
        {
            ShowMethodDebugInfo(reqId, tiers);
        }

        public virtual void tickEFP(int tickerId, int field, double basisPoints, string formattedBasisPoints, double impliedFuture, int holdDays, string futureExpiry, double dividendImpact, double dividendsToExpiry)
        {
            ShowMethodDebugInfo(tickerId, field, basisPoints, formattedBasisPoints, impliedFuture, holdDays, futureExpiry, dividendImpact, dividendsToExpiry);
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

        public virtual void updateAccountValue(string key, string value, string currency, string account)
        {
            ShowMethodDebugInfo(key, value, currency, account);
        }

        public virtual void updateMktDepth(int tickerId, int rowId, int operation, int side, double price, int size)
        {
            ShowMethodDebugInfo(tickerId, rowId, operation, side, price, size);
        }

        public virtual void updateMktDepthL2(int tickerId, int rowId, string marketMaker, int operation, int side, double price, int size)
        {
            ShowMethodDebugInfo(tickerId, rowId, marketMaker, operation, side, price, size);
        }

        public virtual void updateNewsBulletin(int msgId, int msgType, string message, string origExchange)
        {
            ShowMethodDebugInfo(msgId, msgType, message, origExchange);
        }

        public virtual void updatePortfolio(Contract contract, double position, double marketPrice, double marketValue, double avgCost, double unrealisedPNL, double realisedPNL, string account)
        {
            ShowMethodDebugInfo(contract, position, marketPrice, marketValue, avgCost, unrealisedPNL, realisedPNL, account);
        }

        public virtual void updatePortfolio(Contract contract, int position, double marketPrice, double marketValue, double avgCost, double unrealisedPNL, double realisedPNL, string account)
        {
            ShowMethodDebugInfo(contract, position, marketPrice, marketValue, avgCost, unrealisedPNL, realisedPNL, account);
        }

        public virtual void verifyAndAuthCompleted(bool isSuccessful, string errorText)
        {
            ShowMethodDebugInfo(isSuccessful, errorText);
        }

        public virtual void verifyAndAuthMessageAPI(string apiData, string xyzChallenge)
        {
            ShowMethodDebugInfo(apiData, xyzChallenge);
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
