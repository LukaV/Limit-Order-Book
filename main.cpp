#include <iostream>
#include <string>
#include <algorithm>
#include "Order.h"
#include "OrderMatcher.h"
#include "TradeLog.h"
using namespace std;


int main() {
	// Instantiate system classes
	OrderBook orderBook;
	TradeLog tradeLog;
	OrderMatcher orderMatcher(orderBook, tradeLog);

	// Enter application loop
	while (true) {
		char userInput;
		cout << "\n===== LIMIT ORDER TRADING SYSTEM =====\n";
		cout << "\nWhat would you like to do?" << endl;
		cout << "[1] Enter a trade\n[2] View Trade Log\n[3] Exit" << endl;
		cin >> userInput;
		if ((userInput != '1') && (userInput != '2') && (userInput != '3')) {
			cout << "ERROR. Invalid selection." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		if (userInput == '2') {
			tradeLog.displayTrades();
			continue;
		}
		else if (userInput == '3') {
			break;
		}

		// User input for order details
		// Validate inputs
		int userOrderPrice;
		cout << "Enter a price to enter an order at: ";
		if (!(cin >> userOrderPrice)) {
			cout << "ERROR. Please enter a number.";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		int userOrderQty;
		cout << "Enter the quantity: ";
		if (!(cin >> userOrderQty)) {
			cout << "ERROR. Please enter a number.";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		string userOrderBuySell;
		cout << "Do you want to buy or sell ('buy' or 'sell'): ";
		cin >> userOrderBuySell;
		transform(userOrderBuySell.begin(), userOrderBuySell.end(), userOrderBuySell.begin(), ::tolower);
		if ((userOrderBuySell != "buy") && (userOrderBuySell != "sell")) {
			cout << "ERROR. Please enter a valid position.";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		// Place user order for bid/ask matching
		orderBook.placeOrder(userOrderPrice, userOrderQty, userOrderBuySell);
		orderMatcher.checkForMatch();
		cout << "SUCCESS. A " << userOrderBuySell << " order at $" << userOrderPrice << " with a quantity of " << userOrderQty
			<< " was placed! It will appear in the trade log if executed." << endl;
	}
	return 0;
}