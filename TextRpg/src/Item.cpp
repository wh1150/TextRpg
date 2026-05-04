#include "Item.h"


void Item::printInfo() {
	printf("%s (%d)\n", name.c_str(), price);
}

Item::Item(string name, int price) {
	this->name = name;
	this->price = price;
}