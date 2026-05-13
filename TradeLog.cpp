#include <iostream>
#include <fstream>
#include <string>
#include "TradeLog.h"
#include "Order.h"

using namespace std;

/*
Commits trades to the csv files.
*/
void TradeLog::executeTrade(Order order) {
	// File code adapted from https://www.w3schools.com/cpp/cpp_files.asp
	// Open file in append mode code adapted from https://stackoverflow.com/questions/2393345/how-to-append-text-to-a-text-file-in-c
	ofstream TradesFile("Trades.csv", ios_base::app);
	if (TradesFile.is_open()) {
		TradesFile << order.id << "," << order.price << "," << order.qty << "," << order.buySell << "," << order.getTime() << endl;
		TradesFile.close();
	}
	else {
		throw runtime_error("ERROR. Cannot Open Trades.csv");
	}
}

/*
Displays all commited trades.
*/
void TradeLog::displayTrades() {
	string trade;
	ifstream TradesFile("Trades.csv");
	if (TradesFile.is_open())
	{
		cout << "===== All Executed Trades =====";
		while (true) {
			getline(TradesFile, trade, ','); // Skips displaying Order ID and checks if end of file is reached
			if (TradesFile.eof()) {
				break;
			}
			getline(TradesFile, trade, ',');
			cout << "\nPrice: " << trade << endl;
			getline(TradesFile, trade, ',');
			cout << "Quantity: " << trade << endl;
			getline(TradesFile, trade, ',');
			cout << "Position: " << trade << endl;
			getline(TradesFile, trade);
			cout << "Time: " << trade << endl;
		}
		TradesFile.close();
	}
	else {
		cout << "ERROR. Trades.csv not found.";
	}

}