#include <iostream>
#include <string>
#include "Order.h"
using namespace std;


int main() {
	Order order(1, 50, 4, "Sell");
	string time = order.getTime();

	cout << order.id << endl;
	cout << order.price << endl;
	cout << order.qty << endl;
	cout << time;

	return 0;
}