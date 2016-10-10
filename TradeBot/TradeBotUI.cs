using IBApi;
using System;
using System.Collections.Generic;
using TradeBot.Events;
using TradeBot.Extensions;
using TradeBot.FileIO;
using TradeBot.Generated;
using TradeBot.Gui;
using TradeBot.MenuFramework;
using TradeBot.Tws;
using static TradeBot.GlobalProperties;
using static TradeBot.Gui.Window;

namespace TradeBot
{
    public class TradeBotUI
    {
        public static void Main(string[] args)
        {
            TradeBotService service = new TradeBotService();
            TradeBotUI program = new TradeBotUI(service);
            program.Loop();
        }

        private readonly IList<int> ignoredErrorCodes = new List<int>()
        {
            ErrorCodes.MARKET_DATA_FARM_DISCONNECTED,
            ErrorCodes.MARKET_DATA_FARM_CONNECTED,
            ErrorCodes.HISTORICAL_DATA_FARM_DISCONNECTED,
            ErrorCodes.HISTORICAL_DATA_FARM_CONNECTED
        };

        private TradeBotService service;
        private Menu menu;

        private bool shouldExitApplication;

        public TradeBotUI(TradeBotService service)
        {
            this.service = service;

            InitializeEventHandlers();
            InitializeConsole();
            InitializeMenu();
        }

        #region Initialization
        private void InitializeEventHandlers()
        {
            Window.SetWindowCloseHandler(OnWindowClose);

            service.PropertyValueChanged += OnPropertyValueChanged;
            service.ConnectionClosed += OnConnectionClosed;
            service.PriceDataUpdated += OnPriceDataUpdated;
            service.ErrorOccured += OnError;
        }

        private void InitializeConsole()
        {
            Console.Title = Messages.AppName;
            if (Preferences.CenterWindow)
            {
                Window.SetWindowSizeAndCenter(
                    Preferences.WindowWidth,
                    Preferences.WindowHeight);
            }
        }

        private void InitializeMenu()
        {
            menu = new Menu();

            Action<IList<string>, Action> addMenuOption = (entry, command)
                => menu.AddMenuOption(entry[0], entry[1], command);

            MenuOptionEntries menuOptionEntry = Messages.MenuOptionEntries;
            addMenuOption(menuOptionEntry.ReloadSavedState, ReloadSavedStateCommand);
            addMenuOption(menuOptionEntry.RequestMarketData, RequestMarketDataCommand);
            addMenuOption(menuOptionEntry.CancelMarketData, CancelMarketDataCommand);
            addMenuOption(menuOptionEntry.SetStepSize, SetStepSizeCommand);
            addMenuOption(menuOptionEntry.SetStepSizeFromCash, SetStepSizeFromCashCommand);
            addMenuOption(menuOptionEntry.Buy, BuyCommand);
            addMenuOption(menuOptionEntry.Sell, SellCommand);
            addMenuOption(menuOptionEntry.ReversePosition, ReversePositionCommand);
            addMenuOption(menuOptionEntry.ClosePosition, ClosePositionCommand);
            addMenuOption(menuOptionEntry.Misc, MiscCommand);
            addMenuOption(menuOptionEntry.ClearScreen, ClearScreenCommand);
            addMenuOption(menuOptionEntry.Help, HelpCommand);
            addMenuOption(menuOptionEntry.ExitApplication, ExitApplicationCommand);
        }
        #endregion

        #region Public methods
        public void Loop()
        {
            IO.ShowMessage(Messages.WelcomeMessage);

            try
            {
                service.Connect();
                LoadState();
                while (!shouldExitApplication)
                {
                    menu.PromptForMenuOption().Command();
                }
            }
            catch (Exception e)
            {
                IO.ShowMessage(e.Message, MessageType.ERROR);
            }
            finally
            {
                Shutdown();
                if (OS.IsWindows())
                {
                    IO.PromptForChar(Messages.PressAnyKeyToExit);
                }
            }
        }
        #endregion

        #region Menu commands
        private void ReloadSavedStateCommand()
        {
            LoadState();
        }

        private void RequestMarketDataCommand()
        {
            string tickerSymbol = IO.PromptForInput(Messages.SelectTickerPrompt);
            IfNotNullOrWhiteSpace(tickerSymbol, () =>
            {
                service.RequestMarketData(tickerSymbol);
            });
        }

        private void CancelMarketDataCommand()
        {
            service.CancelMarketData();
        }

        private void SetStepSizeCommand()
        {
            string stepSizeString = IO.PromptForInput(Messages.StepSizePrompt);
            int? stepSize = stepSizeString.ToInt();
            IfHasValue(stepSize, () =>
            {
                service.StepSize = stepSize.Value;
            });
        }

        private void SetStepSizeFromCashCommand()
        {
            IfTickerSet(() =>
            {
                IfPriceDataAvailable(() =>
                {
                    string cashString = IO.PromptForInput(Messages.StepSizeFromCashPrompt);
                    double? cash = cashString.ToDouble();
                    IfHasValue(cash, () =>
                    {
                        service.SetStepSizeFromCash(cash.Value);
                    });
                });
            });
        }

        private void BuyCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                service.PlaceOrder(OrderActions.BUY, service.StepSize, service.GetCurrentTickerPrice(TickType.ASK));
            });
        }

        private void SellCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
                service.PlaceOrder(OrderActions.SELL, service.StepSize, service.GetCurrentTickerPrice(TickType.BID));
            });
        }

        private void ReversePositionCommand()
        {
            //IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            //{
            //});
        }

        private void ClosePositionCommand()
        {
            IfTickerAndStepSizeSetAndPriceDataAvailable(() =>
            {
            });
        }

        private void MiscCommand()
        {
        }

        private void ClearScreenCommand()
        {
            Console.Clear();
        }

        private void HelpCommand()
        {
            IO.ShowMessage(menu.ToString());
        }

        private void ExitApplicationCommand()
        {
            shouldExitApplication = true;
        }
        #endregion

        #region Event handlers
        private bool OnWindowClose(CloseReason reason)
        {
            Shutdown();

            // return false since we didn't handle the control signal, 
            // i.e. Environment.Exit(-1);
            return false;
        }

        private void OnPropertyValueChanged(object sender, PropertyValueChangedEventArgs eventArgs)
        {
            switch (eventArgs.PropertyName)
            {
                case nameof(service.ManagedAccounts):
                    OnManagedAccountsSet(eventArgs);
                    break;
                case nameof(service.TickerSymbol):
                    OnTickerChanged(eventArgs);
                    break;
                case nameof(service.StepSize):
                    OnStepSizeChanged(eventArgs);
                    break;
            }
        }

        private void OnManagedAccountsSet(PropertyValueChangedEventArgs eventArgs)
        {
            string accounts = service.ManagedAccounts;

            if (accounts.Contains(Preferences.AccountLive))
            {
                IO.ShowMessage(Messages.AccountTypeLive, MessageType.ERROR);
            }

            if (accounts.Contains(Preferences.AccountPaper))
            {
                IO.ShowMessage(Messages.AccountTypePaper, MessageType.SUCCESS);
            }
        }

        private void OnTickerChanged(PropertyValueChangedEventArgs eventArgs)
        {
            string oldValue = eventArgs.OldValue as string;
            if (!string.IsNullOrWhiteSpace(oldValue))
            {
                IO.ShowMessage(Messages.TickerClearedFormat, oldValue);
            }
            string newValue = eventArgs.NewValue as string;
            if (!string.IsNullOrWhiteSpace(newValue))
            {
                IO.ShowMessage(Messages.TickerSelectedFormat, newValue);
            }
            else
            {
                Console.Title = string.Empty;
            }
        }

        private void OnStepSizeChanged(PropertyValueChangedEventArgs eventArgs)
        {
            IO.ShowMessage(Messages.StepSizeSetFormat, eventArgs.NewValue);
        }

        private void OnConnectionClosed()
        {
            IO.ShowMessage(Messages.TwsDisconnectedError, MessageType.ERROR);
        }

        private void OnPriceDataUpdated(PriceData priceData)
        {
            UpdateConsoleTitle(priceData);
        }

        private void OnError(int id, int errorCode, string errorMessage)
        {
            if (ignoredErrorCodes.Contains(errorCode))
            {
                return;
            }

            IO.ShowMessage(Messages.TwsErrorFormat, MessageType.ERROR, errorMessage);
        }
        #endregion

        #region Private helper methods
        private void Shutdown()
        {
            service.Disconnect();
            SaveState();
        }

        private void SaveState()
        {
            service.SaveState();
            IO.ShowMessage(Messages.SavedStateFormat, MessageType.SUCCESS, PropertyFiles.STATE_FILE);
        }

        private void LoadState()
        {
            IO.ShowMessage(Messages.LoadedStateFormat, MessageType.SUCCESS, PropertyFiles.STATE_FILE);
            service.LoadState();
        }

        private void UpdateConsoleTitle(PriceData priceData)
        {
            IList<string> infoStrings = new List<string>();
            string appName = Messages.AppName;
            if (!string.IsNullOrWhiteSpace(appName))
            {
                infoStrings.Add(appName);
            }
            infoStrings.Add(string.Format(Messages.TitleTicker, service.TickerSymbol));
            infoStrings.Add(string.Format(Messages.TitleLastFormat, priceData[TickType.LAST]));
            infoStrings.Add(string.Format(Messages.TitleStepSize, service.StepSize));
            infoStrings.Add(string.Format(Messages.TitlePositionSize, 0));
            infoStrings.Add(string.Format(Messages.TitleBidAskFormat, priceData[TickType.BID], priceData[TickType.ASK]));
            infoStrings.Add(string.Format(Messages.TitleVolumeFormat, priceData[TickType.VOLUME]));
            infoStrings.Add(string.Format(Messages.TitleCloseFormat, priceData[TickType.CLOSE]));
            infoStrings.Add(string.Format(Messages.TitleOpenFormat, priceData[TickType.OPEN]));
            Console.Title = string.Join(Messages.TitleDivider, infoStrings);
        }
        #endregion

        #region Validations
        private void IfTickerSet(Action action)
        {
            if (service.TickerSymbol != null)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.TickerNotSelectedError, MessageType.VALIDATION_ERROR);
            }

        }

        private void IfStepSizeSet(Action action)
        {
            if (service.StepSize > 0)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.StepSizeNotSetError, MessageType.VALIDATION_ERROR);
            }

        }

        private void IfPriceDataAvailable(Action action)
        {
            if (service.GetCurrentTickerPrice(TickType.LAST) > 0)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.PriceDataUnavailableError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfNotNullOrWhiteSpace(string str, Action action)
        {
            if (!string.IsNullOrWhiteSpace(str))
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.InvalidNonEmptyStringInputError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfHasValue(int? nullable, Action action)
        {
            if (nullable.HasValue)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.InvalidIntegerInputError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfHasValue(double? nullable, Action action)
        {
            if (nullable.HasValue)
            {
                action();
            }
            else
            {
                IO.ShowMessage(Messages.InvalidDecimalInputError, MessageType.VALIDATION_ERROR);
            }
        }

        private void IfTickerAndStepSizeSetAndPriceDataAvailable(Action action)
        {
            IfTickerSet(() =>
            {
                IfStepSizeSet(() =>
                {
                    IfPriceDataAvailable(() =>
                    {
                        action();
                    });
                });
            });
        }
        #endregion
    }
}
