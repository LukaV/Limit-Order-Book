#include <vector>
#include <iostream>
#include "OrderMatcher.h"
#include "TradeLog.h"
#include "Order.h"

/*
Checks for compatible buy and sell orders and executes them to the trade log.
*/
void OrderMatcher::checkForMatch() {
	// Check if the orderBook contains any orders for matching
	if ((orderBook.buyOrders.empty()) || (orderBook.sellOrders.empty())) {
		return;
	}
	// Check for bids against asks
	// If a bid is >= an ask, a trade will execute
	while ((!orderBook.buyOrders.empty() && !orderBook.sellOrders.empty()) && 
		(orderBook.buyOrders[0].price >= orderBook.sellOrders[0].price)) {
		Order buyOrder = orderBook.buyOrders[0];
		Order sellOrder = orderBook.sellOrders[0];

		try {
			tradeLog.executeTrade(buyOrder);
			tradeLog.executeTrade(sellOrder);
		}
		catch (runtime_error) {
			// CSV file containing trade could not be opened/found
			return;
		}
		orderBook.buyOrders.erase(orderBook.buyOrders.begin());
		orderBook.sellOrders.erase(orderBook.sellOrders.begin());
	}
}