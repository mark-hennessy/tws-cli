using IBApi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Threading;
using System.Threading.Tasks;
using TradeBot.Events;
using TradeBot.Extensions;
using TradeBot.TwsAbstractions;
using TradeBot.Utils;

namespace TradeBot
{
    public class TradeBotService : EWrapperImpl
    {
        private EReaderSignal readerSignal;
        private EClientSocket clientSocket;

        private Contract selectedContract;
        private int selectedTickerId;
        private int nextValidOrderId;

        public TradeBotService(int clientId)
        {
            ClientId = clientId;

            initClientSocket();
            initEventHandlers();
        }

        private void initClientSocket()
        {
            readerSignal = new EReaderMonitorSignal();
            clientSocket = new EClientSocket(this, readerSignal);
        }

        private void initEventHandlers()
        {
            // TradeBot events
            PropertyChanged += OnPropertyChanged;

            // EWrapperImpl events
            Error += OnError;
            ConnectAck += OnConnectAck;
            ConnectionClosed += OnConnectionClosed;
            ManagedAccounts += OnManagedAccounts;
            NextValidId += OnNextValidId;
            TickPrice += OnTickPrice;
            TickSize += OnTickSize;
            TickGeneric += OnTickGeneric;
            UpdatePortfolio += OnUpdatePortfolio;
            CommissionReport += OnCommissionReport;
        }

        #region Events
        public event PropertyChangedEventHandler PropertyChanged;
        public event TickUpdatedEventHandler TickUpdated;
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

        private IList<CommissionReport> _commissionReports = new List<CommissionReport>();
        public IList<CommissionReport> CommissionReports
        {
            get
            {
                return _commissionReports;
            }
            private set
            {
                SetPropertyAndRaiseValueChangedEvent(ref _commissionReports, value);
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

        #region Public methods
        public void Connect(string clientUrl, int clientPort)
        {
            clientSocket.eConnect(clientUrl, clientPort, ClientId);

            // Create a reader to consume incoming messages 
            // and store them in a queue.
            var reader = new EReader(clientSocket, readerSignal);
            reader.Start();
            // Once the messages are in the queue, an additional thread is needed to fetch them.
            var thread = new Thread(() =>
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

        public void Disconnect()
        {
            clientSocket.eDisconnect();
            IsConnected = false;
        }

        public void PlaceBuyLimitOrder(int quantity, int tickType = TickType.ASK)
        {
            PlaceLimitOrder(OrderActions.BUY, quantity, tickType);
        }

        public void PlaceSellLimitOrder(int quantity, int tickType = TickType.BID)
        {
            PlaceLimitOrder(OrderActions.SELL, quantity, tickType);
        }

        public void PlaceLimitOrder(OrderActions action, int quantity, int tickType)
        {
            double? price = GetTick(tickType);
            if (!price.HasValue)
            {
                return;
            }

            PlaceLimitOrder(action, quantity, price.Value);
        }

        public void PlaceLimitOrder(OrderActions action, int quantity, double price)
        {
            if (selectedContract == null || price <= 0)
            {
                return;
            }

            Order order = OrderFactory.CreateLimitOrder(action, quantity, price);
            order.Account = TradedAccount;
            clientSocket.placeOrder(nextValidOrderId++, selectedContract, order);
        }

        public Task<IList<PositionInfo>> RequestAllPositionsForAllAccountsAsync()
        {
            var tcs = new TaskCompletionSource<IList<PositionInfo>>();
            var positions = new List<PositionInfo>();

            var onPosition = new Action<string, Contract, double, double>((account, contract, position, avgCost) =>
            {
                positions.Add(new PositionInfo(account, contract, position, avgCost));
            });

            var onError = new Action<int, int, string, Exception>((id, code, msg, ex) =>
            {
                tcs.SafelySetResult(null);
            });

            var onPositionEnd = new Action(() =>
            {
                tcs.SafelySetResult(positions);
            });

            tcs.Task.ContinueWith(t =>
            {
                Position -= onPosition;
                Error -= onError;
                PositionEnd -= onPositionEnd;
            });

            Position += onPosition;
            Error += onError;
            PositionEnd += onPositionEnd;

            clientSocket.reqPositions();

            return tcs.Task;
        }

        public bool HasTicks(params int[] tickTypes)
        {
            var withPositiveValue = new Func<int, double, bool>((key, value) => value >= 0);
            return TickData?.ContainsKeys(withPositiveValue, tickTypes) ?? false;
        }

        public Task<bool> HasTicksAsync(params int[] tickTypes)
        {
            // If we already have the tick data, then there is no need 
            // to wait for the next round of tick updates.
            if (HasTicks(tickTypes))
            {
                return Task.FromResult(true);
            }

            // Otherwise, proceed with fancy asynchronous code!
            var tcs = new TaskCompletionSource<bool>();

            var onTickUpdated = new TickUpdatedEventHandler((sender, tickType, value) =>
            {
                if (HasTicks(tickTypes))
                {
                    tcs.SafelySetResult(true);
                }
            });

            var onPropertyChanged = new PropertyChangedEventHandler((sender, eventArgs) =>
            {
                switch (eventArgs.PropertyName)
                {
                    case nameof(TickData):
                        // If the TickData collection was re-assigned, then abort.
                        tcs.SafelySetResult(false);
                        break;
                }
            });

            var onError = new Action<int, int, string, Exception>((id, code, msg, ex) =>
            {
                tcs.SafelySetResult(false);
            });

            tcs.Task.ContinueWith(t =>
            {
                TickUpdated -= onTickUpdated;
                PropertyChanged -= onPropertyChanged;
                Error -= onError;
            });

            TickUpdated += onTickUpdated;
            PropertyChanged += onPropertyChanged;
            Error += onError;

            return tcs.Task;
        }

        public double? GetTick(int tickType)
        {
            return TickData?.Get(tickType);
        }
        #endregion

        #region PropertyChanged callbacks
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

            Portfolio = new Portfolio();
            if (!string.IsNullOrWhiteSpace(newValue))
            {
                clientSocket.reqAccountUpdates(true, newValue);
            }
        }

        private void OnTickerSymbolChanged(PropertyChangedEventArgs eventArgs)
        {
            var args = eventArgs as PropertyValueChangedEventArgs<string>;
            var oldValue = args.OldValue;
            var newValue = args.NewValue;

            if (!string.IsNullOrWhiteSpace(oldValue))
            {
                clientSocket.cancelMktData(selectedTickerId);
            }

            TickData = new TickData();
            if (!string.IsNullOrWhiteSpace(newValue))
            {
                selectedContract = ContractFactory.CreateStockContract(newValue);

                selectedTickerId = NumberGenerator.NextRandomInt();
                clientSocket.reqMktData(selectedTickerId, selectedContract, "", false, null);
            }
            else
            {
                selectedContract = null;
            }
        }
        #endregion

        #region TWS callbacks
        private void OnError(int id, int errorCode, string errorMessage, Exception exception)
        {
            switch (errorCode)
            {
                case ErrorCodes.TICKER_NOT_FOUND:
                    TickerSymbol = null;
                    break;
            }
        }

        private void OnConnectAck()
        {
            // When this event is triggered within an asynchronous context, 
            // the client will have to start the flow of information to TWS.
            if (clientSocket.AsyncEConnect)
            {
                clientSocket.startApi();
            }

            IsConnected = true;
        }

        private void OnConnectionClosed()
        {
            IsConnected = false;
        }

        private void OnManagedAccounts(string accounts)
        {
            Accounts = accounts
                .Split(new string[] { "," }, StringSplitOptions.None)
                .Select(s => s.Trim())
                .ToArray();
        }

        private void OnNextValidId(int orderId)
        {
            nextValidOrderId = orderId;
        }

        private void OnTickPrice(int tickerId, int field, double price, int canAutoExecute)
        {
            UpdateTickData(tickerId, field, price);
        }

        private void OnTickSize(int tickerId, int field, int size)
        {
            UpdateTickData(tickerId, field, size);
        }

        private void OnTickGeneric(int tickerId, int field, double value)
        {
            UpdateTickData(tickerId, field, value);
        }

        private void UpdateTickData(int tickerId, int tickType, double value)
        {
            if (tickerId != selectedTickerId)
            {
                return;
            }

            TickData.Update(tickType, value);
            TickUpdated?.Invoke(this, tickType, value);
        }

        private void OnUpdatePortfolio(Contract contract, double position, double marketPrice, double marketValue, double avgCost, double unrealisedPNL, double realisedPNL, string account)
        {
            var info = new PortfolioInfo(contract, position, marketPrice, marketValue, avgCost, unrealisedPNL, realisedPNL, account);
            Portfolio.Update(info);
            RaisePropertyValueChangedEvent(Portfolio, nameof(Portfolio));
        }

        private void OnCommissionReport(CommissionReport report)
        {
            CommissionReports.Add(report);
            RaisePropertyValueChangedEvent(CommissionReports, nameof(CommissionReports));
        }
        #endregion
    }
}