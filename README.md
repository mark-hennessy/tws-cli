# tws-cli

A C# command-line interface for the IB Trader Workstation trading platform.

To use this app you must have a brokerage account with [Interactive Brokers](https://www.interactivebrokers.com/en/home.php). You must also have Trader Workstation installed and running on the same machine. This is so that the cli client can open a localhost TCP connection with Trader Workstation and send messages back and forth using the Trader Workstation [API](http://interactivebrokers.github.io/tws-api/index.html).

The cli client is built on top of an example [API client](http://interactivebrokers.github.io) provided by IB.


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

## License & copyright

© Mark Hennessy

Licensed under the [MIT License](LICENSE).
