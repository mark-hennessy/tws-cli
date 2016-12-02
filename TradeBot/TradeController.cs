using IBApi;
using NLog;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using TradeBot.Events;
using TradeBot.Extensions;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.Gui;
using TradeBot.TwsAbstractions;
using static TradeBot.AppProperties;

namespace TradeBot
{
    // TODO: Why was I getting deadlocking if the SynchronizationContext for
    // console applications uses the thread pool?
    public class TradeController
    {
        private const int REQUEST_TIMEOUT = (int)(1.5 * 1000);

        private static readonly int[] COMMON_TICKS = {
            TickType.LAST,
            TickType.ASK,
            TickType.BID
        };

        private TradeService service;
        private TradeMenu menu;
        private TradeStatusBar statusBar;

        public TradeController()
        {
            service = new TradeService(Preferences.ClientId);

            menu = new TradeMenu(this);
            statusBar = new TradeStatusBar(this, service);

            PropertyChanged += OnPropertyChanged;
            service.PropertyChanged += OnPropertyChanged;
            service.Error += OnError;
        }

        #region Events
        public event PropertyChangedEventHandler PropertyChanged;
        #endregion

        #region Properties
        private double _shares;
        public double Shares
        {
            get
            {
                return _shares;
            }
            set
            {
                PropertyChanged.SetPropertyAndRaiseEvent(ref _shares, value);
            }
        }

        private double _cash;
        public double Cash
        {
            get
            {
                return _cash;
            }
            set
            {
                PropertyChanged.SetPropertyAndRaiseEvent(ref _cash, value);
            }
        }
        #endregion

        #region Public methods
        public async Task Run()
        {
            IO.ShowMessage(Messages.WelcomeMessage);
            service.Connect(Preferences.ClientUrl, Preferences.ClientPort);
            while (service.IsConnected)
            {
                await menu.Run();
            }
        }
        #endregion

        #region Menu commands
        public async Task PromptForTickerSymbolCommand(string[] args)
        {
            string tickerSymbol = IO.PromptForInputIfNecessary(args, 0, Messages.SelectTickerPrompt);

            if (ValidateNotNullOrWhiteSpace(tickerSymbol))
            {
                service.TickerSymbol = tickerSymbol;
                await SetInitialSharesAsync();
            }
        }

        public async Task PromptForCashCommand(string[] args)
        {
            string cashInput = IO.PromptForInputIfNecessary(args, 0, Messages.CashPrompt);
            double? cash = cashInput.ToDouble();

            if (ValidateHasValue(cash)
                && ValidatePositive(cash ?? -1))
            {
                Cash = cash.Value;

                if (service.HasTickerSymbol)
                {
                    await SetSharesFromCashAsync();
                }
            }
        }

        public Task PromptForSharesCommand(string[] args)
        {
            string sharesInput = IO.PromptForInputIfNecessary(args, 0, Messages.SharesPrompt);
            int? shares = sharesInput.ToInt();

            if (ValidateHasValue(shares)
                && ValidatePositive(shares ?? -1))
            {
                Shares = shares.Value;
            }

            return Task.CompletedTask;
        }

        public async Task SetSharesFromPositionCommand(string[] args)
        {
            if (ValidateTickerSet())
            {
                Position currentPosition = await service
                    .RequestCurrentPositionAsync();

                if (ValidatePositionExists(currentPosition))
                {
                    Shares = currentPosition.PositionSize;
                }
            }
        }

        public Task BuyCommand(string[] args)
        {
            if (ValidateTickerSet()
                && ValidateSharesSet()
                && ValidateCommonTickDataAvailable())
            {
                service.PlaceBuyLimitOrder(Shares);
            }

            return Task.CompletedTask;
        }

        public Task SellCommand(string[] args)
        {
            if (ValidateTickerSet()
                && ValidateSharesSet()
                && ValidateCommonTickDataAvailable())
            {
                service.PlaceSellLimitOrder(Shares);
            }

            return Task.CompletedTask;
        }

        public async Task ReversePositionCommand(string[] args)
        {
            await ScalePositionAsync(-2);
        }

        public async Task ClosePositionCommand(string[] args)
        {
            await ScalePositionAsync(-1);
        }

        public async Task ListPositionsCommand(string[] args)
        {
            IEnumerable<Position> positions = await service
                .RequestPositionsAsync();

            if (ValidatePositionsExist(positions))
            {
                foreach (var position in positions)
                {
                    IO.ShowMessage(position.ToString());
                }
            }
        }

        public Task LoadStateCommand(string[] args)
        {
            AppState state = PropertySerializer.Deserialize<AppState>(PropertyFiles.STATE_FILE);

            service.TickerSymbol = state.TickerSymbol;
            Cash = state.Cash ?? 0;
            Shares = state.Shares ?? 0;

            IO.ShowMessage(Messages.LoadedStateFormat, PropertyFiles.STATE_FILE);

            return Task.CompletedTask;
        }

        public Task SaveStateCommand(string[] args)
        {
            AppState state = new AppState();
            state.TickerSymbol = service.TickerSymbol;
            state.Shares = Shares;
            state.Cash = Cash;

            PropertySerializer.Serialize(state, PropertyFiles.STATE_FILE);

            IO.ShowMessage(Messages.SavedStateFormat, PropertyFiles.STATE_FILE);

            return Task.CompletedTask;
        }

        public Task ClearScreenCommand(string[] args)
        {
            Console.Clear();

            return Task.CompletedTask;
        }

        public Task ShowMenuCommand(string[] args)
        {
            IO.ShowMessage(menu.Render());

            return Task.CompletedTask;
        }
        #endregion

        #region Private helper methods
        private void SetPosition(Position position)
        {
            service.TickerSymbol = position?.Symbol ?? null;
            Shares = position?.PositionSize ?? 0;
        }

        private async Task SetInitialSharesAsync()
        {
            if (!service.HasTickerSymbol)
            {
                return;
            }

            Position existingPosition = await service.RequestCurrentPositionAsync();
            double existingPositionSize = existingPosition?.PositionSize ?? 0;
            if (existingPositionSize > 0)
            {
                Shares = existingPositionSize;
            }
            else if (Cash > 0)
            {
                await SetSharesFromCashAsync();
            }
        }

        private async Task SetSharesFromCashAsync()
        {
            await Timeout(service.HasTicksAsync(COMMON_TICKS));

            int tickType = TickType.LAST;
            if (ValidateTickDataAvailable(tickType))
            {
                double sharePrice = service.GetTick(tickType).Value;
                if (sharePrice > 0)
                {
                    Shares = (int)Math.Floor(Cash / sharePrice);
                }
            }
        }

        private async Task Timeout(Task task)
        {
            try
            {
                await task.TimeoutAfter(REQUEST_TIMEOUT);
            }
            catch (TimeoutException)
            {
                IO.ShowMessage(LogLevel.Error, Messages.TimeoutErrorFormat,
                               TimeSpan.FromMilliseconds(REQUEST_TIMEOUT).TotalSeconds);
            }
        }

        private async Task ScalePositionAsync(double percent)
        {
            Position position = await service.RequestCurrentPositionAsync();
            if (ValidateTickerSet()
                && ValidatePositionExists(position)
                && ValidateCommonTickDataAvailable())
            {
                int orderDelta = (int)Math.Round(position.PositionSize * percent);
                int orderQuantity = Math.Abs(orderDelta);

                if (orderDelta > 0)
                {
                    service.PlaceBuyLimitOrder(orderQuantity);
                }
                else if (orderDelta < 0)
                {
                    service.PlaceSellLimitOrder(orderQuantity);
                }
            }
        }
        #endregion

        #region Validations
        private bool ValidateTickerSet()
        {
            return Validate(
                service.HasTickerSymbol,
                Messages.TickerSymbolNotSetError);
        }

        private bool ValidateSharesSet()
        {
            return Validate(
                Shares > 0,
                Messages.SharesNotSetError);
        }

        private bool ValidateCommonTickDataAvailable()
        {
            return ValidateTickDataAvailable(COMMON_TICKS);
        }

        private bool ValidateTickDataAvailable(params int[] tickTypes)
        {
            return Validate(
                service.HasTicks(tickTypes),
                Messages.PriceDataUnavailableError);
        }

        private bool ValidatePositionExists(Position position)
        {
            return Validate(
                position != null,
                Messages.PositionNotFoundError);
        }

        private bool ValidatePositionsExist(IEnumerable<Position> positions)
        {
            return Validate(
                !positions.IsNullOrEmpty(),
                Messages.PositionsNotFoundError);
        }

        private bool ValidateNotNullOrWhiteSpace(string str)
        {
            return Validate(
                !string.IsNullOrWhiteSpace(str),
                Messages.InvalidNonEmptyStringInputError);
        }

        private bool ValidateHasValue(int? value)
        {
            return Validate(
                value.HasValue,
                Messages.InvalidIntegerInputError);
        }

        private bool ValidateHasValue(double? value)
        {
            return Validate(
                value.HasValue,
                Messages.InvalidDecimalInputError);
        }

        private bool ValidatePositive(int value)
        {
            return Validate(
                value >= 0,
                Messages.InvalidPositiveInputError);
        }

        private bool ValidatePositive(double value)
        {
            return Validate(
                value >= 0,
                Messages.InvalidPositiveInputError);
        }

        private bool Validate(bool isValid, string errorMessage)
        {
            if (!isValid)
            {
                IO.ShowMessage(LogLevel.Error, errorMessage);
                return false;
            }

            return true;
        }
        #endregion

        #region Event handlers
        private void OnPropertyChanged(PropertyChangedEventArgs eventArgs)
        {
            switch (eventArgs.PropertyName)
            {
                case nameof(Shares):
                    OnSharesChanged(eventArgs);
                    break;
                case nameof(Cash):
                    OnCashChanged(eventArgs);
                    break;

                case nameof(service.IsConnected):
                    OnIsConnectedChanged(eventArgs);
                    break;
                case nameof(service.Accounts):
                    OnAccountsChanged(eventArgs);
                    break;
                case nameof(service.TickerSymbol):
                    OnTickerSymbolChanged(eventArgs);
                    break;
                case nameof(service.CommissionReports):
                    OnCommissionReportsChanged(eventArgs);
                    break;
            }
        }

        private void OnSharesChanged(PropertyChangedEventArgs eventArgs)
        {
            IO.ShowMessage(Messages.SharesSetFormat, Shares);
        }

        private void OnCashChanged(PropertyChangedEventArgs eventArgs)
        {
            IO.ShowMessage(Messages.CashSetFormat, Cash.ToCurrencyString());
        }

        private void OnIsConnectedChanged(PropertyChangedEventArgs eventArgs)
        {
            if (service.IsConnected)
            {
                IO.ShowMessage(LogLevel.Trace, Messages.TwsConnected);
            }
            else
            {
                IO.ShowMessage(LogLevel.Fatal, Messages.TwsDisconnected);
            }
        }

        private async void OnAccountsChanged(PropertyChangedEventArgs eventArgs)
        {
            string[] accounts = service.Accounts;
            if (accounts != null && accounts.Length > 0)
            {
                string tradedAccount = accounts[0];
                service.TradedAccount = tradedAccount;

                Position largestPosition = await service.RequestLargestPosition();
                SetPosition(largestPosition);

                // Warn about multiple accounts
                if (accounts.Length > 1)
                {
                    IO.ShowMessage(LogLevel.Error, Messages.MultipleAccountsWarningFormat, tradedAccount);
                }

                // Show account type message
                if (tradedAccount.StartsWith(Messages.PaperAccountPrefix, StringComparison.InvariantCulture))
                {
                    IO.ShowMessage(LogLevel.Warn, Messages.AccountTypePaper);
                }
                else
                {
                    IO.ShowMessage(LogLevel.Error, Messages.AccountTypeLive);
                }
            }
        }

        private void OnTickerSymbolChanged(PropertyChangedEventArgs eventArgs)
        {
            var args = eventArgs as PropertyValueChangedEventArgs<string>;
            var oldValue = args.OldValue;
            var newValue = args.NewValue;

            if (!string.IsNullOrWhiteSpace(oldValue))
            {
                IO.ShowMessage(LogLevel.Trace, Messages.TickerSymbolClearedFormat, oldValue);
            }

            if (!string.IsNullOrWhiteSpace(newValue))
            {
                IO.ShowMessage(Messages.TickerSymbolSetFormat, newValue);
            }
        }

        private void OnCommissionReportsChanged(PropertyChangedEventArgs eventArgs)
        {
            IList<CommissionReport> reports = service.CommissionReports;
            if (reports.IsNullOrEmpty())
            {
                return;
            }

            CommissionReport lastReport = reports.Last();
            double lastCommission = lastReport.Commission;
            double totalCommission = reports.Sum(report => report.Commission);

            IO.ShowMessage(Messages.CommissionFormat,
                lastCommission.ToCurrencyString(),
                totalCommission.ToCurrencyString());
        }

        private void OnError(int id, int errorCode, string errorMessage, Exception exception)
        {
            // Pre-output
            switch (errorCode)
            {
                // Ignore common error codes
                case ErrorCodes.MARKET_DATA_FARM_DISCONNECTED:
                case ErrorCodes.MARKET_DATA_FARM_CONNECTED:
                case ErrorCodes.HISTORICAL_DATA_FARM_DISCONNECTED:
                case ErrorCodes.HISTORICAL_DATA_FARM_CONNECTED:
                case ErrorCodes.HISTORICAL_DATA_FARM_INACTIVE:
                case ErrorCodes.MARKET_DATA_FARM_INACTIVE:
                case ErrorCodes.TICKER_ID_NOT_FOUND:
                case ErrorCodes.CROSS_SIDE_WARNING:
                    return;
            }

            // Output
            if (!string.IsNullOrWhiteSpace(errorMessage))
            {
                IO.ShowMessage(LogLevel.Error, Messages.TwsErrorFormat, errorMessage);
            }
            if (exception != null)
            {
                IO.ShowMessage(LogLevel.Error, exception.ToString());
            }

            // Post-output
            switch (errorCode)
            {
                case ErrorCodes.TICKER_NOT_FOUND:
                    Shares = 0;
                    break;
            }
        }
        #endregion
    }
}