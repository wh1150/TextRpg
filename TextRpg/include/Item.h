#pragma once
#include <string>

using namespace std;

class Item {
public:
	string getName() const { return name; }
	void setName(const string& name) { this->name = name; }
	int getPrice() const { return price; }
	void setPrice(int price) { this->price = price; }

protected:
	string name;
	int price;
public:
	virtual void printInfo();
	Item(string name, int price);
};
