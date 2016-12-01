#pragma warning disable CS4014 // Because this call is not awaited, execution of the current method continues before the call is completed

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
using TradeBot.MenuFramework;
using TradeBot.TwsAbstractions;
using static TradeBot.AppProperties;

namespace TradeBot
{
    // TODO: Move the try/catch to the main method?
    // TODO: Can the ShowException method simply ToString the exception?
    // TODO: Why was I getting deadlocking if the SynchronizationContext for
    // console applications uses the thread pool?
    // TODO: Move private methods to the bottom of the file
    public class TradeBotConsole
    {
        private const int REQUEST_TIMEOUT = (int)(1.5 * 1000);
        private static readonly int[] COMMON_TICKS = { TickType.LAST, TickType.ASK, TickType.BID };

        private TradeBotMenu menu;
        private TradeBotService service;

        public TradeBotConsole(int clientId)
        {
            InitMenu();
            InitService(clientId);
        }

        #region Initialization
        private void InitMenu()
        {
            menu = new TradeBotMenu(this);
        }

        private void InitService(int clientId)
        {
            service = new TradeBotService(clientId);
            service.IgnoredDebugMessages = new string[] {
                nameof(EWrapper.error),
                nameof(EWrapper.connectAck),
                nameof(EWrapper.connectionClosed),
                nameof(EWrapper.managedAccounts),
                nameof(EWrapper.nextValidId),
                nameof(EWrapper.tickPrice),
                nameof(EWrapper.tickSize),
                nameof(EWrapper.tickString),
                nameof(EWrapper.tickGeneric),
                nameof(EWrapper.updateAccountValue),
                nameof(EWrapper.updateAccountTime),
                nameof(EWrapper.accountDownloadEnd),
                nameof(EWrapper.updatePortfolio),
                nameof(EWrapper.position),
                nameof(EWrapper.positionEnd),
                nameof(EWrapper.openOrder),
                nameof(EWrapper.openOrderEnd),
                nameof(EWrapper.orderStatus),
                nameof(EWrapper.execDetails),
                nameof(EWrapper.commissionReport)
            };

            service.PropertyChanged += OnPropertyChanged;
            service.TickUpdated += OnTickUpdated;
            service.PositionUpdated += OnPositionUpdated;
            service.Error += OnError;
        }
        #endregion

        #region Properties
        private double _shares;
        private double Shares
        {
            get
            {
                return _shares;
            }
            set
            {
                SetProperty(ref _shares, value, Messages.SharesSetFormat, value);
            }
        }

        private double _cash;
        private double Cash
        {
            get
            {
                return _cash;
            }
            set
            {
                SetProperty(ref _cash, value, Messages.CashSetFormat, value.ToCurrencyString());
            }
        }

        protected void SetProperty<T>(ref T field, T newValue, string message = null, params object[] messageArgs)
        {
            T oldValue = field;
            if (!Equals(oldValue, newValue))
            {
                field = newValue;

                UpdateConsoleTitleAsync();

                if (!message.IsNullOrEmpty())
                {
                    IO.ShowMessage(message, messageArgs);
                }
            }
        }
        #endregion

        #region Public methods
        public async Task Run(string clientUrl, int clientPort)
        {
            try
            {
                IO.ShowMessage(Messages.WelcomeMessage);
                service.Connect(clientUrl, clientPort);
                while (service.IsConnected)
                {
                    await menu.Run();
                }
            }
            catch (Exception e)
            {
                ShowException(e, LogLevel.Fatal);
            }
            finally
            {
                if (OS.IsWindows())
                {
                    IO.PromptForChar(Messages.PressAnyKeyToExit);
                }
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

        #region Event handlers
        private void OnPropertyChanged(PropertyChangedEventArgs eventArgs)
        {
            switch (eventArgs.PropertyName)
            {
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
                await SelectLargestPositionAsync();

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

            UpdateConsoleTitleAsync();
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

        private void OnTickUpdated(int tickType, double value)
        {
            UpdateConsoleTitleAsync();
        }

        private void OnPositionUpdated(Position position)
        {
            UpdateConsoleTitleAsync();
        }

        private void OnError(int id, int errorCode, string errorMessage, Exception exception)
        {
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

            if (!string.IsNullOrWhiteSpace(errorMessage))
            {
                IO.ShowMessage(LogLevel.Error, Messages.TwsErrorFormat, errorMessage);
            }

            if (exception != null)
            {
                ShowException(exception);
            }

            switch (errorCode)
            {
                case ErrorCodes.TICKER_NOT_FOUND:
                    Shares = 0;
                    break;
            }
        }
        #endregion

        #region Private helper methods
        private async Task SelectLargestPositionAsync()
        {
            IEnumerable<Position> positions = await service.RequestPositionsAsync();

            Position largestPosition = positions
                .OrderByDescending(p => p.PositionSize)
                .FirstOrDefault();

            SetPosition(largestPosition);
        }

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

        private void ShowException(Exception exception, LogLevel logLevel = null)
        {
            if (logLevel == null)
            {
                logLevel = LogLevel.Error;
            }

            var aggregateException = exception as AggregateException;
            if (aggregateException != null)
            {
                IO.ShowMessage(logLevel, Messages.ExceptionMessageFormat, aggregateException.Message);
            }

            var baseException = aggregateException?.GetBaseException() ?? exception;
            IO.ShowMessage(logLevel, Messages.ExceptionMessageFormat, baseException.Message);
            IO.ShowMessage(logLevel, Messages.ExceptionStackTraceFormat, baseException.StackTrace);
        }

        private async Task UpdateConsoleTitleAsync()
        {
            IList<string> infoStrings = new List<string>();

            string appName = Messages.AppName;
            if (!string.IsNullOrWhiteSpace(appName))
            {
                infoStrings.Add(appName);
            }

            bool hasTickerSymbol = service.HasTickerSymbol;
            string tickerSymbol = service.TickerSymbol;
            string tickerDisplayValue = hasTickerSymbol ? tickerSymbol : Messages.TitleUnavailable;
            infoStrings.Add(string.Format(Messages.TitleTickerSymbol, tickerDisplayValue));

            infoStrings.Add(string.Format(Messages.TitleShares, Shares));

            if (hasTickerSymbol)
            {
                Position currentPosition = await service.RequestCurrentPositionAsync();
                double positionSize = currentPosition?.PositionSize ?? 0;
                infoStrings.Add(string.Format(Messages.TitlePositionSize, positionSize));

                infoStrings.Add(string.Format(Messages.TitleLastFormat, GetTickAsCurrencyString(TickType.LAST)));
                infoStrings.Add(string.Format(Messages.TitleBidAskFormat, GetTickAsCurrencyString(TickType.BID), GetTickAsCurrencyString(TickType.ASK)));
                infoStrings.Add(string.Format(Messages.TitleVolumeFormat, GetTickAsString(TickType.VOLUME)));
                infoStrings.Add(string.Format(Messages.TitleCloseFormat, GetTickAsCurrencyString(TickType.CLOSE)));
                infoStrings.Add(string.Format(Messages.TitleOpenFormat, GetTickAsCurrencyString(TickType.OPEN)));
            }

            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }

        private string GetTickAsString(int tickType)
        {
            return GetTickAsFormattedString(tickType, v => v.ToString());
        }

        private string GetTickAsCurrencyString(int tickType)
        {
            return GetTickAsFormattedString(tickType, v => v.ToCurrencyString());
        }

        private string GetTickAsFormattedString(int tickType, Func<double, string> messageFormatter)
        {
            double? tick = service.GetTick(tickType);
            return tick.HasValue && tick.Value >= 0
                ? messageFormatter(tick.Value)
                : Messages.TitleUnavailable;
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
    }
}