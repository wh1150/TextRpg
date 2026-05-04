#pragma once
#include <string>

using namespace std;

class Item {
protected:
	string name;
	int price;
public:
	virtual void printInfo();
	Item(string name, int price);
};
