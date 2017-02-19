# tws-cli

A C# command-line interface for the IB Trader Workstation trading platform.

I built this app to help me execute trades faster since I found Trader Workstation to be a bit clunky on a laptop. The app tracks a single ticker symbol at a time and can calculate the quantity of shares to trade based off of a cash value. The app makes it easy to buy, sell, reverse, and close positions.

The app is built on top of an example [API client](http://interactivebrokers.github.io) provided by IB. The example client was difficult to work with because it used onStart/onUpdate/onEnd method hooks instead of async callbacks. I mapped these method hooks to events and then mapped the events to C# Task and TaskCompletionSource objects (sort of like Promises in JS). This allowed me to write asynchrounous code that was easy to work with and reason about. It also allowed me to use the awesome async/await keywords so that I could write asynchronous code as if it were normal synchronous code. Even if you don't plan on using my app, the source code is a great example for how to use the TWS API. I was inspired to open source my project after googling and discovering that there were very few C# TWS API examples/repositories like mine.

## Prerequisites

To use the app you must have a brokerage account with [Interactive Brokers](https://www.interactivebrokers.com/en/home.php). You must also have Trader Workstation installed and running on the same machine. This is so that the app can open a localhost TCP connection with Trader Workstation and send messages back and forth using the Trader Workstation [API](http://interactivebrokers.github.io/tws-api/index.html).

## Menu
Type '?' and press 'Enter' to show the menu.
<pre>
========================================================================
                                  Menu
========================================================================
f  Set ticker symbol to trade

m  Set shares to trade based on a cash value and the current share price
j  Set shares to trade to a fixed value
u  Set shares to trade equal to your current position

b  Place limit order to Buy at ask price
s  Place limit order to Sell at bid price
r  Place limit order to Reverse position
c  Place limit order to Close position

a  List positions

l  Load default state
p  Save current state as default state

.  Clear screen
?  Show menu
------------------------------------------------------------------------
</pre>

## Title Bar
The app streams live stock data from TWS and continuously updates the terminal window's title bar with the following information:

* **Symbol:** The currently selected stock ticker symbol
* **Shares:** The currently selected number of shares to trade
* **Pos:** The current number of shares owned
* **Last:** The latest stock price
* **Bid/Ask:** The latest Bid and Ask prices
* **Vol:** The volume at which the stock is currently being traded
* **Close:** Yesterday's close price
* **Open:** Today's opening price

Note that live data is only reliable during market hours. If data is unavailable then a '?' will be displayed in place of values.

## License & copyright

© Mark Hennessy

Licensed under the [MIT License](LICENSE).
