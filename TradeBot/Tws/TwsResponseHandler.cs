using IBApi;
using System;
using System.Collections.Generic;
using TradeBot.Gui;
using static TradeBot.Resources;

namespace TradeBot.Tws
{
    public class TwsResponseHandler : EWrapper
    {
        private IList<int> ignoredErrorCodes = new List<int> { 2104, 2106 };

        public void accountDownloadEnd(string account)
        {
            throw new NotImplementedException();
        }

        public void accountSummary(int requestId, string account, string tag, string value, string currency)
        {
            throw new NotImplementedException();
        }

        public void accountSummaryEnd(int requestId)
        {
            throw new NotImplementedException();
        }

        public void bondContractDetails(int requestId, ContractDetails contract)
        {
            throw new NotImplementedException();
        }

        public void commissionReport(CommissionReport commissionReport)
        {
            throw new NotImplementedException();
        }

        public void connectionClosed()
        {
            IO.ShowMessage(Messages.TwsMessages.ConnectionClosed, MessageType.ERROR);
        }

        public void contractDetails(int requestId, ContractDetails contractDetails)
        {
            throw new NotImplementedException();
        }

        public void contractDetailsEnd(int requestId)
        {
            throw new NotImplementedException();
        }

        public void currentTime(long time)
        {
            IO.ShowMessage(Messages.TwsMessages.CurrentTimeFormat, MessageType.INFO, time);
        }

        public void deltaNeutralValidation(int requestId, UnderComp underComp)
        {
            throw new NotImplementedException();
        }

        public void displayGroupList(int requestId, string groups)
        {
            throw new NotImplementedException();
        }

        public void displayGroupUpdated(int requestId, string contractInfo)
        {
            throw new NotImplementedException();
        }

        public void error(string errorMessage)
        {
            IO.ShowMessage(Messages.TwsMessages.ErrorMessageFormat, MessageType.ERROR, errorMessage);
        }

        public void error(Exception exception)
        {
            IO.ShowMessage(Messages.TwsMessages.ErrorMessageFormat, MessageType.ERROR, exception.Message);
        }

        public void error(int id, int errorCode, string errorMessage)
        {
            if (ignoredErrorCodes.Contains(errorCode))
            {
                IO.ShowMessage(Messages.TwsMessages.InfoMessageFormat, MessageType.INFO, errorMessage);
            }
            else
            {
                IO.ShowMessage(Messages.TwsMessages.ErrorMessageFormat, MessageType.ERROR, errorMessage);
            }
        }

        public void execDetails(int requestId, Contract contract, Execution execution)
        {
            throw new NotImplementedException();
        }

        public void execDetailsEnd(int requestId)
        {
            throw new NotImplementedException();
        }

        public void fundamentalData(int requestId, string data)
        {
            throw new NotImplementedException();
        }

        public void historicalData(int requestId, string date, double open, double high, double low, double close, int volume, int count, double WAP, bool hasGaps)
        {
            throw new NotImplementedException();
        }

        public void historicalDataEnd(int requestId, string start, string end)
        {
            throw new NotImplementedException();
        }

        public void managedAccounts(string accounts)
        {
            IO.ShowMessage(Messages.TwsMessages.AccountIdFormat, MessageType.INFO, accounts);
            if (accounts.Contains(Preferences.AccountInfo.Live))
            {
                IO.ShowMessage(Messages.TwsMessages.AccountTypeLive, MessageType.ERROR);
            }
            if (accounts.Contains(Preferences.AccountInfo.Paper))
            {
                IO.ShowMessage(Messages.TwsMessages.AccountTypePaper, MessageType.SUCCESS);
            }
        }

        public void marketDataType(int requestId, int marketDataType)
        {
            throw new NotImplementedException();
        }

        public void nextValidId(int orderId)
        {
            IO.ShowMessage(Messages.TwsMessages.NextValidIdFormat, MessageType.INFO, orderId);
        }

        public void openOrder(int orderId, Contract contract, Order order, OrderState orderState)
        {
            throw new NotImplementedException();
        }

        public void openOrderEnd()
        {
            throw new NotImplementedException();
        }

        public void orderStatus(int orderId, string status, int filled, int remaining, double avgFillPrice, int permId, int parentId, double lastFillPrice, int clientId, string whyHeld)
        {
            throw new NotImplementedException();
        }

        public void position(string account, Contract contract, int position, double averageCost)
        {
            throw new NotImplementedException();
        }

        public void positionEnd()
        {
            throw new NotImplementedException();
        }

        public void realtimeBar(int requestId, long time, double open, double high, double low, double close, long volume, double WAP, int count)
        {
            throw new NotImplementedException();
        }

        public void receiveFA(int faDataType, string faXmlData)
        {
            throw new NotImplementedException();
        }

        public void scannerData(int requestId, int rank, ContractDetails contractDetails, string distance, string benchmark, string projection, string legsStr)
        {
            throw new NotImplementedException();
        }

        public void scannerDataEnd(int requestId)
        {
            throw new NotImplementedException();
        }

        public void scannerParameters(string xml)
        {
            throw new NotImplementedException();
        }

        public void tickEFP(int tickerId, int tickType, double basisPoints, string formattedBasisPoints, double impliedFuture, int holdDays, string futureExpiry, double dividendImpact, double dividendsToExpiry)
        {
            throw new NotImplementedException();
        }

        public void tickGeneric(int tickerId, int field, double value)
        {
            throw new NotImplementedException();
        }

        public void tickOptionComputation(int tickerId, int field, double impliedVolatility, double delta, double optPrice, double pvDividend, double gamma, double vega, double theta, double undPrice)
        {
            throw new NotImplementedException();
        }

        public void tickPrice(int tickerId, int field, double price, int canAutoExecute)
        {
            IO.ShowMessage(Messages.TwsMessages.TickPriceFormat, MessageType.INFO, tickerId, field, price, canAutoExecute);
        }

        public void tickSize(int tickerId, int field, int size)
        {
            IO.ShowMessage(Messages.TwsMessages.TickSizeFormat, MessageType.INFO, tickerId, field, size);
        }

        public void tickSnapshotEnd(int tickerId)
        {
            IO.ShowMessage(Messages.TwsMessages.TickSnapshotEndFormat, MessageType.INFO, tickerId);
        }

        public void tickString(int tickerId, int field, string value)
        {
            throw new NotImplementedException();
        }

        public void updateAccountTime(string timestamp)
        {
            throw new NotImplementedException();
        }

        public void updateAccountValue(string key, string value, string currency, string accountName)
        {
            throw new NotImplementedException();
        }

        public void updateMktDepth(int tickerId, int position, int operation, int side, double price, int size)
        {
            throw new NotImplementedException();
        }

        public void updateMktDepthL2(int tickerId, int position, string marketMaker, int operation, int side, double price, int size)
        {
            throw new NotImplementedException();
        }

        public void updateNewsBulletin(int messageId, int messageType, string message, string origExchange)
        {
            throw new NotImplementedException();
        }

        public void updatePortfolio(Contract contract, int position, double marketPrice, double marketValue, double averageCost, double unrealisedPNL, double realisedPNL, string accountName)
        {
            throw new NotImplementedException();
        }

        public void verifyCompleted(bool isSuccessful, string errorText)
        {
            throw new NotImplementedException();
        }

        public void verifyMessageAPI(string apiData)
        {
            throw new NotImplementedException();
        }
    }
}
