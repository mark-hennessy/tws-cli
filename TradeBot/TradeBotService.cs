using IBApi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using TradeBot.Events;
using TradeBot.TwsAbstractions;
using TradeBot.Utils;

namespace TradeBot
{
    public class TradeBotService : EWrapperImpl
    {
        private EReaderSignal readerSignal;
        private EClientSocket clientSocket;

        private Portfolio portfolio;
        private TaskCompletionSource<string> accountDownloadEndTCS;

        private int tickerId;
        private Contract tickerContract;
        private TickData tickData;

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
            AccountDownloadEnd += OnAccountDownloadEnd;
            CommissionReport += OnCommissionReport;
        }

        #region Events
        public event PropertyChangedEventHandler PropertyChanged;
        public event TickUpdatedEventHandler TickUpdated;
        public event PositionUpdatedEventHandler PositionUpdated;
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
                PropertyChanged.SetPropertyAndRaiseEvent(ref _isConnected, value);
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
                PropertyChanged.SetPropertyAndRaiseEvent(ref _accounts, value);
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
                PropertyChanged.SetPropertyAndRaiseEvent(ref _tradedAccount, value);
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
                PropertyChanged.SetPropertyAndRaiseEvent(ref _tickerSymbol, value?.Trim().ToUpper());
            }
        }

        public bool HasTickerSymbol
        {
            get
            {
                return !string.IsNullOrWhiteSpace(TickerSymbol);
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
                PropertyChanged.SetPropertyAndRaiseEvent(ref _commissionReports, value);
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

            // Once the messages are in the queue, an additional thread is needed to process them.
            // This is best accomplished by a dedicated long-running background thread.
            Task.Factory.StartNew(() =>
            {
                while (clientSocket.IsConnected())
                {
                    readerSignal.waitForSignal();
                    // It's worth noting that message processing is what raises all EWrapper events,
                    // e.g. NextValidId, TickPrice, Position, PositionEnd, Error, ConnectionClosed, etc.
                    // Events are handled by the thread that raises them, i.e. this thread!
                    reader.processMsgs();
                }
            },
            TaskCreationOptions.LongRunning);
        }

        public void Disconnect()
        {
            clientSocket.eDisconnect();
            IsConnected = false;
        }

        public void PlaceBuyLimitOrder(double quantity, int tickType = TickType.ASK)
        {
            PlaceLimitOrder(OrderActions.BUY, quantity, tickType);
        }

        public void PlaceSellLimitOrder(double quantity, int tickType = TickType.BID)
        {
            PlaceLimitOrder(OrderActions.SELL, quantity, tickType);
        }

        public void PlaceLimitOrder(OrderActions action, double quantity, int tickType)
        {
            double? price = GetTick(tickType);
            if (!price.HasValue)
            {
                return;
            }

            PlaceLimitOrder(action, quantity, price.Value);
        }

        public void PlaceLimitOrder(OrderActions action, double quantity, double price)
        {
            if (tickerContract == null || price <= 0)
            {
                return;
            }

            Order order = OrderFactory.CreateLimitOrder(action, quantity, price);
            order.Account = TradedAccount;
            clientSocket.placeOrder(nextValidOrderId++, tickerContract, order);
        }

        public async Task<Position> RequestCurrentPositionAsync()
        {
            Portfolio positions = await RequestPortfolioAsync();
            return positions.Get(TickerSymbol);
        }

        public async Task<IEnumerable<Position>> RequestPositionsAsync()
        {
            Portfolio positions = await RequestPortfolioAsync();
            return positions.Values;
        }

        public async Task<Portfolio> RequestPortfolioAsync()
        {
            await accountDownloadEndTCS.Task;
            return portfolio;
        }

        public bool HasTicks(params int[] tickTypes)
        {
            if (tickData == null)
            {
                return false;
            }

            var withPositiveValue = new Func<int, double, bool>((key, value)
                => value >= 0);
            return tickData.HasTicks(withPositiveValue, tickTypes);
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

            var onTickUpdated = new TickUpdatedEventHandler((tickType, value) =>
            {
                if (HasTicks(tickTypes))
                {
                    tcs.TrySetResult(true);
                }
            });

            var onPropertyChanged = new PropertyChangedEventHandler((eventArgs) =>
            {
                switch (eventArgs.PropertyName)
                {
                    case nameof(tickData):
                        // If the TickData collection was re-assigned, then abort.
                        tcs.TrySetResult(false);
                        break;
                }
            });

            var onError = new Action<int, int, string, Exception>((id, code, msg, ex) =>
            {
                tcs.TrySetResult(false);
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
            return tickData?.Get(tickType);
        }
        #endregion

        #region PropertyChanged callbacks
        private void OnPropertyChanged(PropertyChangedEventArgs eventArgs)
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

            portfolio = new Portfolio();
            accountDownloadEndTCS = new TaskCompletionSource<string>();

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
                clientSocket.cancelMktData(tickerId);
            }

            tickData = new TickData();
            if (!string.IsNullOrWhiteSpace(newValue))
            {
                tickerId = NumberGenerator.NextRandomInt();
                tickerContract = ContractFactory.CreateStockContract(newValue);
                clientSocket.reqMktData(tickerId, tickerContract, "", false, null);
            }
            else
            {
                tickerId = -1;
                tickerContract = null;
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

        private void OnTickPrice(int tickId, int field, double price, int canAutoExecute)
        {
            UpdateTickData(tickId, field, price);
        }

        private void OnTickSize(int tickId, int field, int size)
        {
            UpdateTickData(tickId, field, size);
        }

        private void OnTickGeneric(int tickId, int field, double value)
        {
            UpdateTickData(tickId, field, value);
        }

        private void UpdateTickData(int tickId, int tickType, double value)
        {
            if (tickId != tickerId)
            {
                return;
            }

            tickData.Update(tickType, value);
            TickUpdated?.Invoke(tickType, value);
        }

        private void OnUpdatePortfolio(Contract contract, double positionSize, double marketPrice, double marketValue, double avgCost, double unrealisedPNL, double realisedPNL, string account)
        {
            var position = new Position(account, contract, positionSize, avgCost, marketPrice, marketValue, unrealisedPNL, realisedPNL);
            portfolio.Update(position);
            PositionUpdated?.Invoke(position);
        }

        private void OnAccountDownloadEnd(string account)
        {
            accountDownloadEndTCS.TrySetResult(account);
        }

        private void OnCommissionReport(CommissionReport report)
        {
            CommissionReports.Add(report);
            PropertyChanged.RaiseEvent(CommissionReports, nameof(CommissionReports));
        }
        #endregion
    }
}
