#pragma once
#include <string>
#include <chrono>

using namespace std;

/*
This struct holds properties of an Order for a trade.
*/
struct Order {
	int id;
	int price;
	int qty;
	string buySell;
	string getTime() const { return time; }
	Order(int id, int price, int qty, string buySell) {
		this->id = id;
		this->price = price;
		this->qty = qty;
		this->buySell = buySell;
		// Time format code adapted from https://stackoverflow.com/questions/70696610/is-there-an-easier-way-to-get-the-current-time-in-hhmmss-format
		time = format("{:%T}", chrono::floor<chrono::seconds>(chrono::system_clock::now()));
	};
private:
	// Note that time is in UTC. This is fine since this is an example application, the time is only to be used as an example.
	string time;
};