using IBApi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Threading.Tasks;
using TradeBot.Events;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.TwsAbstractions;
using static TradeBot.Properties;

namespace TradeBot
{
    public class TradeBotService : TwsResponseHandler, INotifyPropertyValueChanged
    {
        private EReaderSignal readerSignal;
        private EClientSocket client;
        private EReader reader;

        private Contract contract;
        private TaskCompletionSource<IList<PositionInfo>> allPositionRequestTCS;
        private IList<PositionInfo> allPositions;

        private int currentTickerId;
        private int nextValidOrderId;

        public TradeBotService()
        {
            readerSignal = new EReaderMonitorSignal();
            client = new EClientSocket(this, readerSignal);
            client.AsyncEConnect = false;
            // Create a reader to consume messages from the TWS. 
            // The EReader will consume the incoming messages and put them in a queue.
            reader = new EReader(client, readerSignal);
            reader.Start();
            // Once the messages are in the queue, an additional thread is needed to fetch them.
            Thread thread = new Thread(() =>
            {
                while (client.IsConnected())
                {
                    readerSignal.waitForSignal();
                    reader.processMsgs();
                }
            });
            thread.IsBackground = true;
            thread.Start();
        }

        #region Events
        public event PropertyValueChangedEventHandler PropertyValueChanged;
        public event Action<int, int, string> ErrorOccured;
        #endregion

        #region Properties
        private bool _isConnected;
        public bool IsConnected
        {
            get
            {
                return _isConnected;
            }
            private set
            {
                RaisePropertyValueChangedEvent(ref _isConnected, value);
            }
        }

        private string[] _managedAccounts;
        public string[] ManagedAccounts
        {
            get
            {
                return _managedAccounts;
            }
            private set
            {
                RaisePropertyValueChangedEvent(ref _managedAccounts, value);
            }
        }

        private string _tradedAccount;
        public string TradedAccount
        {
            get
            {
                return _tradedAccount;
            }
            set
            {
                string oldValue = _tradedAccount;
                string newValue = value;
                _tradedAccount = newValue;

                if (Equals(oldValue, newValue))
                {
                    return;
                }

                if (!string.IsNullOrWhiteSpace(oldValue))
                {
                    client.reqAccountUpdates(false, oldValue);
                }

                ClearPortfolio();

                if (!string.IsNullOrWhiteSpace(newValue))
                {
                    client.reqAccountUpdates(true, newValue);
                }

                RaisePropertyValueChangedEvent(oldValue, newValue);
            }
        }

        private Portfolio _portfolio;
        public Portfolio Portfolio
        {
            get
            {
                return _portfolio;
            }
            private set
            {
                RaisePropertyValueChangedEvent(ref _portfolio, value);
            }
        }

        private void UpdatePortfolio(PortfolioInfo info)
        {
            Portfolio.Update(info);
            RaisePropertyValueChangedEvent(Portfolio, propertyName: nameof(Portfolio));
        }

        private void ClearPortfolio()
        {
            // Set the property to a new instance to trigger a property changed event.
            Portfolio = new Portfolio();
        }

        private string _tickerSymbol;
        public string TickerSymbol
        {
            get
            {
                return _tickerSymbol;
            }
            set
            {
                SetTickerSymbol(value, cancelAndRequestMarketData: true);
            }
        }

        private void SetTickerSymbol(string value, bool cancelAndRequestMarketData)
        {
            string oldValue = _tickerSymbol;
            string newValue = value?.Trim().ToUpper();
            _tickerSymbol = newValue;

            if (Equals(oldValue, newValue))
            {
                return;
            }

            if (!string.IsNullOrWhiteSpace(oldValue))
            {
                if (cancelAndRequestMarketData)
                {
                    client.cancelMktData(currentTickerId);
                }
            }

            ClearTickData();
            contract = null;

            if (!string.IsNullOrWhiteSpace(newValue))
            {
                contract = ContractFactory.CreateStockContract(newValue);
                if (cancelAndRequestMarketData)
                {
                    client.reqMktData(++currentTickerId, contract, "", false, null);
                }
            }

            RaisePropertyValueChangedEvent(oldValue, newValue, propertyName: nameof(TickerSymbol));
        }

        private TickData _tickData;
        public TickData TickData
        {
            get
            {
                return _tickData;
            }
            private set
            {
                RaisePropertyValueChangedEvent(ref _tickData, value);
            }
        }

        private void ClearTickData()
        {
            // Set the property to a new instance to trigger a property changed event.
            TickData = new TickData();
        }

        public double GetTick(int tickType)
        {
            return TickData?.Get(tickType) ?? -1;
        }

        private void UpdateTick(int tickType, double value)
        {
            TickData.Update(tickType, value);
            RaisePropertyValueChangedEvent(TickData, propertyName: nameof(TickData));
        }

        private int _stepSize;
        public int StepSize
        {
            get
            {
                return _stepSize;
            }
            set
            {
                RaisePropertyValueChangedEvent(ref _stepSize, Math.Abs(value));
            }
        }

        protected void RaisePropertyValueChangedEvent<T>(T value, [CallerMemberName] string propertyName = null)
        {
            PropertyValueChanged?.Invoke(this, new PropertyValueChangedEventArgs(propertyName, value, value));
        }

        protected void RaisePropertyValueChangedEvent<T>(T oldValue, T newValue, [CallerMemberName] string propertyName = null)
        {
            if (!Equals(oldValue, newValue))
            {
                PropertyValueChanged?.Invoke(this, new PropertyValueChangedEventArgs(propertyName, oldValue, newValue));
            }
        }

        protected void RaisePropertyValueChangedEvent<T>(ref T field, T newValue, [CallerMemberName] string propertyName = null)
        {
            T oldValue = field;
            if (!Equals(oldValue, newValue))
            {
                field = newValue;
                PropertyValueChanged?.Invoke(this, new PropertyValueChangedEventArgs(propertyName, oldValue, newValue));
            }
        }
        #endregion

        #region Public methods
        public void Connect()
        {
            client.eConnect(Preferences.ClientUrl, Preferences.ClientPort, Preferences.ClientId);
        }

        public void Disconnect()
        {
            client.eDisconnect();
        }

        public void LoadState()
        {
            AppState state = PropertySerializer.Deserialize<AppState>(PropertyFiles.STATE_FILE);

            TickerSymbol = state.TickerSymbol;
            StepSize = state.StepSize ?? 0;
        }

        public void SaveState()
        {
            AppState state = new AppState();
            state.TickerSymbol = TickerSymbol;
            state.StepSize = StepSize;

            PropertySerializer.Serialize(state, PropertyFiles.STATE_FILE);
        }

        public Task<IList<PositionInfo>> GetAllPositionsForAllAccountsAsync()
        {
            allPositionRequestTCS = new TaskCompletionSource<IList<PositionInfo>>();
            allPositions = new List<PositionInfo>();
            client.reqPositions();
            return allPositionRequestTCS.Task;
        }

        public void PlaceBuyOrder(int totalQuantity, int tickType = TickType.ASK)
        {
            PlaceOrder(OrderActions.BUY, totalQuantity, GetTick(tickType));
        }

        public void PlaceSellOrder(int totalQuantity, int tickType = TickType.BID)
        {
            PlaceOrder(OrderActions.SELL, totalQuantity, GetTick(tickType));
        }

        public void PlaceOrder(OrderActions action, int totalQuantity, double price)
        {
            if (contract == null || price <= 0)
            {
                return;
            }

            int orderId = nextValidOrderId++;
            Order order = OrderFactory.CreateLimitOrder(action, totalQuantity, price);
            order.Account = TradedAccount;
            client.placeOrder(orderId, contract, order);
        }
        #endregion

        #region TWS callbacks
        public override void connectAck()
        {
            IsConnected = true;
        }

        public override void connectionClosed()
        {
            IsConnected = false;
        }

        public override void managedAccounts(string accounts)
        {
            ManagedAccounts = accounts
                .Split(new string[] { "," }, StringSplitOptions.None)
                .Select(s => s.Trim())
                .ToArray();
        }

        public override void nextValidId(int nextValidOrderId)
        {
            this.nextValidOrderId = nextValidOrderId;
        }

        public override void tickPrice(int tickerId, int tickType, double price, int canAutoExecute)
        {
            UpdateTickData(tickerId, tickType, price);
        }

        public override void tickSize(int tickerId, int tickType, int size)
        {
            UpdateTickData(tickerId, tickType, size);
        }

        public override void tickGeneric(int tickerId, int tickType, double value)
        {
            UpdateTickData(tickerId, tickType, value);
        }

        private void UpdateTickData(int tickerId, int tickType, double value)
        {
            if (tickerId != currentTickerId)
            {
                return;
            }

            UpdateTick(tickType, value);
        }

        public override void updatePortfolio(Contract contract, int positionSize, double marketPrice, double marketValue, double averageCost, double unrealisedPNL, double realisedPNL, string account)
        {
            UpdatePortfolio(new PortfolioInfo(contract, positionSize, marketPrice, marketValue, averageCost, unrealisedPNL, realisedPNL, account));
        }

        public override void position(string account, Contract contract, int positionSize, double averageCost)
        {
            allPositions.Add(new PositionInfo(account, contract, positionSize, averageCost));
        }

        public override void positionEnd()
        {
            allPositionRequestTCS.SetResult(allPositions);
            allPositionRequestTCS = null;
            allPositions = null;
        }

        public override void error(Exception exception)
        {
            error(exception.Message);
        }

        public override void error(string errorMessage)
        {
            error(-1, -1, errorMessage);
        }

        public override void error(int id, int errorCode, string errorMessage)
        {
            ErrorOccured?.Invoke(id, errorCode, errorMessage);

            switch (errorCode)
            {
                case ErrorCodes.TICKER_NOT_FOUND:
                    SetTickerSymbol(null, cancelAndRequestMarketData: false);
                    break;
            }
        }

        public override void tickString(int tickerId, int tickType, string value)
        {
            // no-op, this is not needed for our basic feature set
            //base.tickString(tickerId, tickType, value);
        }

        public override void updateAccountValue(string key, string value, string currency, string account)
        {
            // no-op, this is not needed for our basic feature set
            //base.updateAccountValue(key, value, currency, account);
        }

        public override void updateAccountTime(string timestamp)
        {
            // no-op, this is not needed for our basic feature set
            //base.updateAccountTime(timestamp);
        }

        public override void accountDownloadEnd(string account)
        {
            // no-op, this is not needed for our basic feature set
            //base.accountDownloadEnd(account);
        }
        #endregion
    }
}
