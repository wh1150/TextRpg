#pragma once
#include <string>

using namespace std;

class Player;
class Monster {
public:
	string getName() const { return name; }
	void setName(const string& name) { this->name = name; }
	string getDropItemName() const { return dropItemName; }
	void setDropItemName(const string& drop_item_name) { dropItemName = drop_item_name; }
	int getHp() const { return hp; }
	void setHp(int hp) { this->hp = hp; }
	int getAtk() const { return atk; }
	void setAtk(int power) { this->atk = power; }
	int getDef() const { return def; }
	void setDef(int defence) { this->def = defence; }
	int getDropItemPrice() const { return dropItemPrice; }
	void setDropItemPrice(int drop_item_price) { dropItemPrice = drop_item_price; }
	int getExpReward() const { return expReward; }

	string name, dropItemName;
	int hp, atk, def, dropItemPrice, expReward;
	
	Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemPrice, int expReward);
	virtual ~Monster() = default;
	bool attack(Player* player);
};
