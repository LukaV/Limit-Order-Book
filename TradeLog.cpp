#include <iostream>
#include <fstream>
#include "TradeLog.h"
#include "Order.h"

using namespace std;

void TradeLog::executeTrade(Order order) {
	// File code adapted from https://www.w3schools.com/cpp/cpp_files.asp
	// Open file in append mode code adapted from https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c
	ofstream TradesFile("Trades.csv", ios_base::app);
	if (TradesFile.is_open()) {
		TradesFile << order.id << "," << order.price << "," << order.qty << "," << order.buySell << "," << order.getTime() << endl;
		TradesFile.close();
	}
	else {
		cout << "ERROR. Cannot Open Trades.csv";
	}
}