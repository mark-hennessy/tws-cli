using IBApi;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Threading.Tasks;
using TradeBot.Events;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.TwsAbstractions;
using TradeBot.Utils;

namespace TradeBot
{
    public class TradeBotClient : EWrapperImpl, INotifyPropertyChanged
    {
        private EReaderSignal readerSignal;
        private EClientSocket clientSocket;
        private EReader reader;

        private Contract contract;

        private int nextValidOrderId;
        private int currentTickerId;

        public TradeBotClient(int clientId = 0)
        {
            ClientId = clientId;

            PropertyChanged += OnPropertyChanged;
            RegisterTwsEventHandlers();

            initEReader();
            Start();
        }

        private void RegisterTwsEventHandlers()
        {
            ConnectAck += OnConnectAck;
            ConnectionClosed += OnConnectionClosed;
            ManagedAccounts += OnManagedAccounts;
            NextValidId += OnNextValidId;
            TickPrice += OnTickPrice;
            TickSize += OnTickSize;
            TickGeneric += OnTickGeneric;
            UpdatePortfolio += OnUpdatePortfolio;
            Error += OnError;
        }

        private void initEReader()
        {
            readerSignal = new EReaderMonitorSignal();
            clientSocket = new EClientSocket(this, readerSignal);
            clientSocket.AsyncEConnect = false;
            // Create a reader to consume messages from the TWS. 
            // The EReader will consume the incoming messages and put them in a queue.
            reader = new EReader(clientSocket, readerSignal);
        }

        private void Start()
        {
            reader.Start();
            // Once the messages are in the queue, an additional thread is needed to fetch them.
            Thread thread = new Thread(() =>
            {
                while (clientSocket.IsConnected())
                {
                    readerSignal.waitForSignal();
                    reader.processMsgs();
                }
            });
            thread.IsBackground = true;
            thread.Start();
        }

        #region Events
        public event PropertyChangedEventHandler PropertyChanged;
        public event Action<int, int, string, Exception> ErrorOccured;
        #endregion

        #region Properties
        public int ClientId { get; }

        private bool _isConnected;
        public bool IsConnected
        {
            get
            {
                return _isConnected;
            }
            private set
            {
                SetPropertyAndRaiseValueChangedEvent(ref _isConnected, value);
            }
        }

        private string[] _accounts;
        public string[] Accounts
        {
            get
            {
                return _accounts;
            }
            private set
            {
                SetPropertyAndRaiseValueChangedEvent(ref _accounts, value);
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
                SetPropertyAndRaiseValueChangedEvent(ref _tradedAccount, value);
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
                SetPropertyAndRaiseValueChangedEvent(ref _portfolio, value);
            }
        }

        private void UpdatePortfolioInfo(PortfolioInfo info)
        {
            Portfolio.Update(info);
            RaisePropertyValueChangedEvent(Portfolio, nameof(Portfolio));
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
                SetPropertyAndRaiseValueChangedEvent(ref _tickerSymbol, value?.Trim().ToUpper());
            }
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
                SetPropertyAndRaiseValueChangedEvent(ref _tickData, value);
            }
        }

        public double GetTick(int tickType)
        {
            return TickData?.Get(tickType) ?? -1;
        }

        private void UpdateTick(int tickType, double value)
        {
            TickData.Update(tickType, value);
            RaisePropertyValueChangedEvent(TickData, nameof(TickData));
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
                SetPropertyAndRaiseValueChangedEvent(ref _stepSize, Math.Abs(value));
            }
        }

        protected void RaisePropertyValueChangedEvent<T>(T value, [CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyValueChangedEventArgs<T>(propertyName, value, value));
        }

        protected void SetPropertyAndRaiseValueChangedEvent<T>(ref T field, T newValue, [CallerMemberName] string propertyName = null)
        {
            T oldValue = field;
            if (!Equals(oldValue, newValue))
            {
                field = newValue;
                PropertyChanged?.Invoke(this, new PropertyValueChangedEventArgs<T>(propertyName, oldValue, newValue));
            }
        }
        #endregion

        #region Event Handlers
        private void OnPropertyChanged(object sender, PropertyChangedEventArgs eventArgs)
        {
            switch (eventArgs.PropertyName)
            {
                case nameof(TradedAccount):
                    OnTradedAccountChanged(eventArgs);
                    break;
                case nameof(TickerSymbol):
                    OnTickerSymbolChanged(eventArgs);
                    break;
            }
        }

        private void OnTradedAccountChanged(PropertyChangedEventArgs eventArgs)
        {
            var args = eventArgs as PropertyValueChangedEventArgs<string>;
            var oldValue = args.OldValue;
            var newValue = args.NewValue;

            if (!string.IsNullOrWhiteSpace(oldValue))
            {
                clientSocket.reqAccountUpdates(false, oldValue);
            }

            if (!string.IsNullOrWhiteSpace(newValue))
            {
                Portfolio = new Portfolio();

                clientSocket.reqAccountUpdates(true, newValue);
            }
            else
            {
                Portfolio = null;
            }
        }

        private void OnTickerSymbolChanged(PropertyChangedEventArgs eventArgs)
        {
            var args = eventArgs as PropertyValueChangedEventArgs<string>;
            var oldValue = args.OldValue;
            var newValue = args.NewValue;

            if (!string.IsNullOrWhiteSpace(oldValue))
            {
                clientSocket.cancelMktData(currentTickerId);
            }

            if (!string.IsNullOrWhiteSpace(newValue))
            {
                TickData = new TickData();
                contract = ContractFactory.CreateStockContract(newValue);

                currentTickerId = NumberGenerator.RandomInt();
                clientSocket.reqMktData(currentTickerId, contract, "", false, null);
            }
            else
            {
                TickData = null;
                contract = null;
            }
        }

        private int GenerateId()
        {
            return new Random().Next();
        }
        #endregion

        #region Public methods
        public void Connect(string host, int port)
        {
            clientSocket.eConnect(host, port, ClientId);
        }

        public void Disconnect()
        {
            clientSocket.eDisconnect();
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

            Order order = OrderFactory.CreateLimitOrder(action, totalQuantity, price);
            order.Account = TradedAccount;
            clientSocket.placeOrder(nextValidOrderId++, contract, order);
        }

        public Task<IList<PositionInfo>> RequestAllPositionsForAllAccountsAsync()
        {
            var request = new TaskCompletionSource<IList<PositionInfo>>();
            var positions = new List<PositionInfo>();

            var onError = new Action<int, int, string, Exception>((id, code, msg, ex) =>
            {
                request.SetResult(null);
            });

            var onPosition = new Action<string, Contract, double, double>((account, contract, position, avgCost) =>
            {
                positions.Add(new PositionInfo(account, contract, position, avgCost));
            });

            var onPositionEnd = new Action(() =>
            {
                if (request.Task.IsCompleted)
                {
                    return;
                }

                request.SetResult(positions);
            });

            Error += onError;
            Position += onPosition;
            PositionEnd += onPositionEnd;

            request.Task.ContinueWith(t =>
            {
                Error -= onError;
                Position -= onPosition;
                PositionEnd -= onPositionEnd;
            });

            clientSocket.reqPositions();

            return request.Task;
        }
        #endregion

        #region TWS callbacks
        public void OnConnectAck()
        {
            if (clientSocket.AsyncEConnect)
            {
                clientSocket.startApi();
            }

            IsConnected = true;
        }

        public void OnConnectionClosed()
        {
            IsConnected = false;
        }

        public void OnManagedAccounts(string accounts)
        {
            Accounts = accounts
                .Split(new string[] { "," }, StringSplitOptions.None)
                .Select(s => s.Trim())
                .ToArray();
        }

        public void OnNextValidId(int nextValidOrderId)
        {
            this.nextValidOrderId = nextValidOrderId;
        }

        public void OnTickPrice(int tickerId, int field, double price, int canAutoExecute)
        {
            UpdateTickData(tickerId, field, price);
        }

        public void OnTickSize(int tickerId, int field, int size)
        {
            UpdateTickData(tickerId, field, size);
        }

        public void OnTickGeneric(int tickerId, int field, double value)
        {
            UpdateTickData(tickerId, field, value);
        }

        private void UpdateTickData(int tickerId, int tickType, double value)
        {
            if (tickerId != currentTickerId)
            {
                return;
            }

            UpdateTick(tickType, value);
        }

        public void OnUpdatePortfolio(Contract contract, double position, double marketPrice, double marketValue, double avgCost, double unrealisedPNL, double realisedPNL, string account)
        {
            UpdatePortfolioInfo(new PortfolioInfo(contract, position, marketPrice, marketValue, avgCost, unrealisedPNL, realisedPNL, account));
        }

        public void OnError(int id, int errorCode, string errorMessage, Exception exception)
        {
            ErrorOccured?.Invoke(id, errorCode, errorMessage, exception);

            switch (errorCode)
            {
                case ErrorCodes.TICKER_NOT_FOUND:
                    TickerSymbol = null;
                    break;
            }
        }
        #endregion
    }
}
