using IBApi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Threading.Tasks;
using TradeBot.Events;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.TwsAbstractions;

namespace TradeBot
{
    public class TradeBotService : TwsResponseHandler, INotifyPropertyValueChanged
    {
        private TwsClient client;

        private Contract contract;
        private TaskCompletionSource<IList<PositionInfo>> allPositionRequestTCS;
        private IList<PositionInfo> allPositions;

        private int currentTickerId;
        private int nextValidOrderId;

        public TradeBotService()
        {
            client = new TwsClient(this);
        }

        #region Events
        public event PropertyValueChangedEventHandler PropertyValueChanged;
        public event Action ConnectionClosed;
        public event Action<int, int, string> ErrorOccured;
        #endregion

        #region Properties
        private string[] _managedAccounts;
        public string[] ManagedAccounts
        {
            get
            {
                return _managedAccounts;
            }
            private set
            {
                string[] oldValue = _managedAccounts;
                string[] newValue = value;
                _managedAccounts = newValue;

                RaisePropertyValueChangedEvent(oldValue, newValue);
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

                if (!string.IsNullOrWhiteSpace(newValue))
                {
                    Portfolio = new Portfolio();
                    client.reqAccountUpdates(true, newValue);
                }
                else
                {
                    Portfolio = null;
                }

                RaisePropertyValueChangedEvent(oldValue, newValue);
            }
        }

        public Portfolio Portfolio { get; private set; }

        private void UpdatePortfolio(PortfolioInfo info)
        {
            Portfolio.Update(info);
            RaisePropertyValueChangedEvent(Portfolio, propertyName: nameof(Portfolio));
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

            if (!string.IsNullOrWhiteSpace(newValue))
            {
                contract = ContractFactory.CreateStockContract(newValue);
                TickData = new TickData();
                if (cancelAndRequestMarketData)
                {
                    client.reqMktData(++currentTickerId, contract, "", false, null);
                }
            }
            else
            {
                contract = null;
                TickData = null;
            }

            RaisePropertyValueChangedEvent(oldValue, newValue, propertyName: nameof(TickerSymbol));
        }

        public TickData TickData { get; private set; }

        private void UpdateTickData(int field, double value)
        {
            TickData.Update(field, value);
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
                int oldValue = _stepSize;
                int newValue = Math.Abs(value);
                _stepSize = newValue;

                RaisePropertyValueChangedEvent(oldValue, newValue);
            }
        }

        protected void RaisePropertyValueChangedEvent(object value, [CallerMemberName] string propertyName = null)
        {
            PropertyValueChanged?.Invoke(this, new PropertyValueChangedEventArgs(propertyName, value, value));
        }

        protected void RaisePropertyValueChangedEvent(object oldValue, object newValue, [CallerMemberName] string propertyName = null)
        {
            if (Equals(oldValue, newValue))
            {
                return;
            }

            PropertyValueChanged?.Invoke(this, new PropertyValueChangedEventArgs(propertyName, oldValue, newValue));
        }
        #endregion

        #region Public methods
        public void Connect()
        {
            client.eConnect();
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

        public async Task<IList<PositionInfo>> GetAllPositionsForAllAccounts()
        {
            allPositionRequestTCS = new TaskCompletionSource<IList<PositionInfo>>();
            allPositions = new List<PositionInfo>();
            client.reqPositions();
            return await allPositionRequestTCS.Task;
        }

        public void PlaceOrder(OrderActions action, int totalQuantity, double price)
        {
            int orderId = nextValidOrderId++;
            Order order = OrderFactory.CreateLimitOrder(action, totalQuantity, price);
            order.Account = TradedAccount;
            client.placeOrder(orderId, contract, order);
        }
        #endregion

        #region TWS callbacks
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

        public override void tickPrice(int tickerId, int field, double price, int canAutoExecute)
        {
            UpdateTickData(tickerId, field, price);
        }

        public override void tickSize(int tickerId, int field, int size)
        {
            UpdateTickData(tickerId, field, size);
        }

        public override void tickGeneric(int tickerId, int field, double value)
        {
            UpdateTickData(tickerId, field, value);
        }

        private void UpdateTickData(int tickerId, int field, double value)
        {
            if (tickerId != currentTickerId)
            {
                return;
            }

            UpdateTickData(field, value);
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

        public override void connectionClosed()
        {
            ConnectionClosed?.Invoke();
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

        public override void tickString(int tickerId, int field, string value)
        {
            // no-op, this is not needed for our basic feature set
            //base.tickString(tickerId, field, value);
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
