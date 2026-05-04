#pragma once
#include <string>

using namespace std;
class PotionIngredient {
public:
	string getName() const { return name; }
	void setName(const string& name) { this->name = name; }
	int getCount() const { return count; }
	void setCount(int count) { this->count = count; }

	PotionIngredient(const string& name, int count);
	void printInfo();
private:
	string name;
	int count;
	
};
