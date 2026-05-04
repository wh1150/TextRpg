#include "Mage.h"
#include "RPGConst.h"
#include "Monster.h"
#include <iostream>

Mage::Mage(string name, int* stat)
	: Player(name, stat, "Mage") {
}

bool Mage::attack(Monster* mon) {
	cout << RPGConst::Message::Fight::ATTACK_MAGE;
	int damage = this->atk - mon->getDef();
	if (damage <= 0) damage = 1;
	printf("%d damage to %s!\n", damage, mon->getName().c_str());
	printf("%s HP: %d -> %d", mon->name.c_str(), mon->getHp(), mon->getHp() - damage);
	mon->setHp(mon->getHp() - damage);
	if (mon->getHp() <= 0)	{
		cout << " (Dead)" << "\n";
		cout << "★ Victory!" << "\n";
		printf("  -> Get : %s\n  (Will be saved to inventory in the next STEP)\n\n", mon->getDropItemName().c_str());
		this->inventory.push_back(new Item(mon->getDropItemName(), mon->getDropItemPrice()));
		return false;
	}
	return true;
}
