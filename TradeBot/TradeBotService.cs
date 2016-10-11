using IBApi;
using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using TradeBot.Events;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.Gui;
using TradeBot.TwsAbstractions;
using static TradeBot.GlobalProperties;

namespace TradeBot
{
    public class TradeBotService : TwsResponseHandler, INotifyPropertyValueChanged
    {
        private TwsClient client;
        private PriceData priceData;
        private Contract contract;
        // TODO: delete this?
        private IDictionary<int, Order> recentOrders;

        private int currentTickerId;
        private int nextValidOrderId;

        public TradeBotService()
        {
            client = new TwsClient(this);
            priceData = new PriceData();
            recentOrders = new Dictionary<int, Order>();
        }

        #region Events
        public event PropertyValueChangedEventHandler PropertyValueChanged;
        public event Action ConnectionClosed;
        public event Action<PriceData> PriceDataUpdated;
        public event Action<int, int, string> ErrorOccured;
        #endregion

        #region Properties
        private string _managedAccounts;
        public string ManagedAccounts
        {
            get
            {
                return _managedAccounts;
            }
            private set
            {
                string oldValue = _managedAccounts;
                string newValue = value;
                _managedAccounts = newValue;
                RaisePropertyValueChangedEvent(oldValue, newValue);
            }
        }

        private string _tickerSymbol;
        public string TickerSymbol
        {
            get
            {
                return _tickerSymbol;
            }
            private set
            {
                string oldValue = _tickerSymbol;
                string newValue = value?.ToUpper();
                _tickerSymbol = newValue;
                RaisePropertyValueChangedEvent(oldValue, newValue);
            }
        }

        private int _stepSize = -1;
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

        protected void RaisePropertyValueChangedEvent(object oldValue, object newValue, [CallerMemberName] string propertyName = null)
        {
            if (!Equals(oldValue, newValue))
            {
                PropertyValueChanged?.Invoke(this, new PropertyValueChangedEventArgs(propertyName, oldValue, newValue));
            }
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
            StepSize = state.StepSize ?? -1;

            RequestMarketData(TickerSymbol);
        }

        public void SaveState()
        {
            AppState state = new AppState();
            state.TickerSymbol = TickerSymbol;
            state.StepSize = StepSize;

            PropertySerializer.Serialize(state, PropertyFiles.STATE_FILE);
        }

        public void RequestMarketData(string ticker)
        {
            // Don't do anything if the same ticker symbol is already selected.
            if (Equals(ticker, TickerSymbol))
            {
                return;
            }

            CancelMarketData();

            if (!string.IsNullOrWhiteSpace(ticker))
            {
                TickerSymbol = ticker;
                currentTickerId++;
                contract = ContractFactory.CreateStockContract(ticker);
                client.reqMktData(currentTickerId, contract, "", false, null);
            }
        }

        public void CancelMarketData()
        {
            if (contract != null)
            {
                client.cancelMktData(currentTickerId);
                priceData = new PriceData();
            }
            ClearCurrentContract();
        }

        public void SetStepSizeFromCash(double cash)
        {
            double sharePrice = GetCurrentTickerPrice(TickType.LAST);
            StepSize = (int)Math.Floor(cash / sharePrice);
        }

        public double GetCurrentTickerPrice(int tickType)
        {
            return priceData[tickType];
        }

        public void PlaceOrder(OrderActions action, int totalQuantity, double price)
        {
            int orderId = nextValidOrderId++;
            Order order = OrderFactory.CreateLimitOrder(action, totalQuantity, price);
            client.placeOrder(orderId, contract, order);
        }
        #endregion

        #region TWS callbacks
        public override void managedAccounts(string accounts)
        {
            ManagedAccounts = accounts;
        }

        public override void nextValidId(int nextValidOrderId)
        {
            this.nextValidOrderId = nextValidOrderId;
        }

        public override void tickPrice(int tickerId, int field, double price, int canAutoExecute)
        {
            UpdatePriceData(tickerId, field, price);
        }

        public override void tickSize(int tickerId, int field, int size)
        {
            UpdatePriceData(tickerId, field, size);
        }

        public override void error(Exception exception)
        {
            error(exception.Message);
        }

        public override void error(string errorMessage)
        {
            error(-1, -1, errorMessage);

            IO.ShowMessage(Messages.TwsErrorFormat, MessageType.ERROR, errorMessage);
        }

        public override void error(int id, int errorCode, string errorMessage)
        {
            ErrorOccured?.Invoke(id, errorCode, errorMessage);

            switch (errorCode)
            {
                case ErrorCodes.TICKER_NOT_FOUND:
                    ClearCurrentContract();
                    break;
            }
        }

        public override void connectionClosed()
        {
            ConnectionClosed?.Invoke();
        }
        #endregion

        #region Private helper methods
        private void UpdatePriceData(int tickerId, int field, double price)
        {
            if (tickerId != currentTickerId)
            {
                return;
            }

            priceData[field] = price;

            PriceDataUpdated?.Invoke(priceData);
        }

        private void ClearCurrentContract()
        {
            contract = null;
            TickerSymbol = null;
        }
        #endregion
    }
}
