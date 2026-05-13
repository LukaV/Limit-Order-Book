#pragma once
#include <string>
#include <vector>
#include "Order.h"

using namespace std;

/*
This class holds incoming buy and sell orders.
*/
class OrderBook {
public:
	void placeOrder(int price, int qty, string buySell);
	vector<Order> buyOrders;
	vector<Order> sellOrders;
};