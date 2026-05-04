#include <iostream>
#include "Player.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemPrice, int expReward) {
	this->name = name;
	this->hp = hp;
	this->atk = power;
	this->def = defence;
	this->dropItemName = dropItemName;
	this->dropItemPrice = dropItemPrice;
	this->expReward = expReward;
}

bool Monster::attack(Player* player) {
	int damage = atk - player->getDef();
	if (damage < 1)	damage = 1;
	printf("%d damage to %s!\n", damage, player->getName().c_str());
	printf("%s HP: %d -> %d", player->getName().c_str(), player->getHp(), player->getHp() - damage);
	player->setHp(
		player->getHp() - damage
	);
	if (player->getHp() <= 0) {
		cout << " (Dead)" << "\n";
		cout << "You're dead.. exit game." << "\n";
		return false;
	}
	return true;
}
