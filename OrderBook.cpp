#include <string>
#include <algorithm>
#include <iostream>
#include "OrderBook.h"
#include "Order.h"

using namespace std;

/*
This method pushes order to either the buy or sell vector

price is the price at which the user wants to place the order at.
qty is the amount of the item to purchase.
buySell is the position the user wants to enter.
*/
void OrderBook::placeOrder(int price, int qty, string buySell) {
	static int nextId = 0;
	int id = nextId++;
	// Lower buySell input
	// Code adapted from https://caasify.com/blog/master-c-string-case-conversion-with-stdtransform-and-icu-library
	transform(buySell.begin(), buySell.end(), buySell.begin(), ::tolower);

	Order order(id, price, qty, buySell);
	if (buySell == "buy") {
		buyOrders.push_back(order);
		// Sort best bid (highest buy price) at the front
		// Code adapted from https://stackoverflow.com/questions/5122804/how-to-sort-with-a-lambda
		ranges::sort(buyOrders, [](const Order &o1, const Order  &o2) {
			return o1.price > o2.price; 
		});
	}
	else if (buySell == "sell") {
		sellOrders.push_back(order);
		// Sort best ask (lowest sell price) at the front
		// Code adapted from https://stackoverflow.com/questions/5122804/how-to-sort-with-a-lambda
		ranges::sort(sellOrders, [](const Order& o1, const Order& o2) {
			return o1.price < o2.price;
		});
	}
	else {
		cout << "ERROR. Invalid input." << endl;
		return;
	}
}
