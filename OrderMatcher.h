#pragma once
#include "OrderBook.h"
#include "TradeLog.h"


class OrderMatcher {
	OrderBook& orderBook;
	TradeLog& tradeLog;
public:
	void checkForMatch();
	// Member initialiser list code adapter from https://en.cppreference.com/cpp/language/constructor
	OrderMatcher(OrderBook& orderBook, TradeLog& tradeLog) : orderBook{ orderBook }, tradeLog{ tradeLog } {};
};