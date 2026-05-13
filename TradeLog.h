#pragma once
#include "Order.h"

/*
Keeps a record of executed trades in csv format.
*/
class TradeLog {
public:
	void executeTrade(Order order);
	void displayTrades();
};
