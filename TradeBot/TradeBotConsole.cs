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
    public class TradeBotConsole
    {
        private const int REQUEST_TIMEOUT = (int)(4.5 * 1000);
        private static readonly int[] COMMON_TICKS = { TickType.LAST, TickType.ASK, TickType.BID };

        private TradeBotService service;
        private Menu menu;

        public TradeBotConsole(int clientId)
        {
            InitService(clientId);
            InitMenu();
        }

        #region Initialization
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

        private void InitMenu()
        {
            menu = new Menu();

            var titleDivider = new MenuDivider();
            menu.AddMenuItem(new MenuTitle(Messages.MenuTitle, titleDivider));

            var addMenuOption = new Action<IList<string>, MenuCommand>((entry, command)
                => menu.AddMenuItem(new MenuOption(entry[0], entry[1], command)));

            var menuOptionDivider = new MenuDivider();
            var addMenuOptionDivider = new Action(()
                => menu.AddMenuItem(menuOptionDivider));

            MenuOptionEntries entries = Messages.MenuOptionEntries;

            addMenuOption(entries.SetTickerSymbol, PromptForTickerSymbolCommand);
            addMenuOptionDivider();

            addMenuOption(entries.SetSharesFromCash, PromptForCashCommand);
            addMenuOption(entries.SetShares, PromptForSharesCommand);
            addMenuOption(entries.SetSharesFromPosition, SetSharesFromPositionCommand);
            addMenuOptionDivider();

            addMenuOption(entries.Buy, BuyCommand);
            addMenuOption(entries.Sell, SellCommand);
            addMenuOption(entries.ReversePosition, ReversePositionCommand);
            addMenuOption(entries.ClosePosition, ClosePositionCommand);
            addMenuOptionDivider();

            addMenuOption(entries.ListPositions, ListPositionsCommand);
            addMenuOptionDivider();

            addMenuOption(entries.LoadState, LoadStateCommand);
            addMenuOption(entries.SaveState, SaveStateCommand);
            addMenuOptionDivider();

            addMenuOption(entries.ClearScreen, ClearScreenCommand);
            addMenuOption(entries.ShowMenu, ShowMenuCommand);

            var menuEndDivider = new MenuDivider();
            menu.AddMenuItem(menuEndDivider);

            int dividerLength = menu.GetLongestMenuEntryLength();
            var createDividerString = new Func<string, string>((charString) =>
            {
                return !string.IsNullOrEmpty(charString)
                    ? new string(charString.First(), dividerLength)
                    : string.Empty;
            });
            titleDivider.DividerString = createDividerString(Messages.MenuTitleDividerChar);
            menuOptionDivider.DividerString = createDividerString(Messages.MenuOptionDividerChar);
            menuEndDivider.DividerString = createDividerString(Messages.MenuEndDividerChar);
        }

        public void Connect(string clientUrl, int clientPort)
        {
            IO.ShowMessage(Messages.WelcomeMessage);
            try
            {
                service.Connect(clientUrl, clientPort);
                while (service.IsConnected)
                {
                    HandleMenuOptionInput(PromptForMenuOptionInput());
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

        private string[] PromptForMenuOptionInput()
        {
            return IO.PromptForInput().Split();
        }

        private void HandleMenuOptionInput(string[] input)
        {
            string key = input.FirstOrDefault();
            MenuOption menuOption = menu.getMenuOption(key);
            if (menuOption != null)
            {
                string[] args = input.Skip(1).ToArray();
                menuOption.Command(args);
            }
            else
            {
                IO.ShowMessage(LogLevel.Error, Messages.InvalidMenuOption);
            }
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

                UpdateConsoleTitle();

                if (!message.IsNullOrEmpty())
                {
                    IO.ShowMessage(message, messageArgs);
                }
            }
        }
        #endregion

        #region Menu commands
        private void PromptForTickerSymbolCommand(string[] args)
        {
            string tickerSymbol = IO.PromptForInputIfNecessary(args, 0, Messages.SelectTickerPrompt);

            if (ValidateNotNullOrWhiteSpace(tickerSymbol))
            {
                service.TickerSymbol = tickerSymbol;
                SetInitialSharesAsync().Wait();
            }
        }

        private void PromptForCashCommand(string[] args)
        {
            string cashInput = IO.PromptForInputIfNecessary(args, 0, Messages.CashPrompt);
            double? cash = cashInput.ToDouble();

            if (ValidateHasValue(cash)
                && ValidatePositive(cash ?? -1))
            {
                Cash = cash.Value;

                if (service.HasTickerSymbol)
                {
                    SetSharesFromCashAsync().Wait();
                }
            }
        }

        private void PromptForSharesCommand(string[] args)
        {
            string sharesInput = IO.PromptForInputIfNecessary(args, 0, Messages.SharesPrompt);
            int? shares = sharesInput.ToInt();

            if (ValidateHasValue(shares)
                && ValidatePositive(shares ?? -1))
            {
                Shares = shares.Value;
            }
        }

        private void SetSharesFromPositionCommand(string[] args)
        {
            if (ValidateTickerSet())
            {
                Position currentPosition = service
                    .RequestCurrentPositionAsync()
                    .Result;
                if (ValidatePositionExists(currentPosition))
                {
                    Shares = currentPosition.PositionSize;
                }
            }
        }

        private void BuyCommand(string[] args)
        {
            if (ValidateTickerSet()
                && ValidateSharesSet()
                && ValidateCommonTickDataAvailable())
            {
                service.PlaceBuyLimitOrder(Shares);
            }
        }

        private void SellCommand(string[] args)
        {
            if (ValidateTickerSet()
                && ValidateSharesSet()
                && ValidateCommonTickDataAvailable())
            {
                service.PlaceSellLimitOrder(Shares);
            }
        }

        private void ReversePositionCommand(string[] args)
        {
            ScalePosition(-2);
        }

        private void ClosePositionCommand(string[] args)
        {
            ScalePosition(-1);
        }

        private void ListPositionsCommand(string[] args)
        {
            IEnumerable<Position> positions = service
                .RequestPositionsAsync()
                .Result;

            if (ValidatePositionsExist(positions))
            {
                foreach (var position in positions)
                {
                    IO.ShowMessage(position.ToString());
                }
            }
        }

        private void LoadStateCommand(string[] args)
        {
            AppState state = PropertySerializer.Deserialize<AppState>(PropertyFiles.STATE_FILE);

            service.TickerSymbol = state.TickerSymbol;
            Cash = state.Cash ?? 0;
            Shares = state.Shares ?? 0;

            IO.ShowMessage(Messages.LoadedStateFormat, PropertyFiles.STATE_FILE);
        }

        private void SaveStateCommand(string[] args)
        {
            AppState state = new AppState();
            state.TickerSymbol = service.TickerSymbol;
            state.Shares = Shares;
            state.Cash = Cash;

            PropertySerializer.Serialize(state, PropertyFiles.STATE_FILE);

            IO.ShowMessage(Messages.SavedStateFormat, PropertyFiles.STATE_FILE);
        }

        private void ClearScreenCommand(string[] args)
        {
            Console.Clear();
        }

        private void ShowMenuCommand(string[] args)
        {
            IO.ShowMessage(menu.Render());
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

            UpdateConsoleTitle();
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
            UpdateConsoleTitle();
        }

        private void OnPositionUpdated(Position position)
        {
            UpdateConsoleTitle();
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
            await Timeout(service.AwaitTicksAsync(COMMON_TICKS));

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
                await task.TimeoutAfter(REQUEST_TIMEOUT).ConfigureAwait(false);
            }
            catch (TimeoutException)
            {
                IO.ShowMessage(LogLevel.Error, Messages.TimeoutErrorFormat,
                               TimeSpan.FromMilliseconds(REQUEST_TIMEOUT).TotalSeconds);
            }
        }

        private void ScalePosition(double percent)
        {
            Position position = service.RequestCurrentPositionAsync().Result;
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

        private void UpdateConsoleTitle()
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
                Position currentPosition = service.RequestCurrentPositionAsync().Result;
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