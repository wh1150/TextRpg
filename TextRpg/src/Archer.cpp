#include "Archer.h"
#include <iostream>

#include "RPGConst.h"
#include "Monster.h"

Archer::Archer(string name, int* stat)
	: Player(name, stat, "Archer") {
}
bool Archer::attack(Monster* mon) {
	cout << RPGConst::Message::Fight::ATTACK_ARCHER;
	int damage = this->atk - mon->getDef();
	if (damage <= 0) damage = 1;
	printf("%d x 5 damage to %s!\n", damage / 5, mon->getName().c_str());
	for (int i = 0 ; i < damage / 5 ; i++) {
		printf("%s HP: %d -> %d\n", mon->name.c_str(), mon->getHp(), mon->getHp() - damage / 5);
		mon->setHp(mon->getHp() - damage);
		if (mon->getHp() <= 0)	{
			cout << " (Dead)" << "\n";
			cout << "★ Victory!" << "\n";
			printf("  -> Get : %s\n  (Will be saved to inventory in the next STEP)\n\n", mon->getDropItemName().c_str());
			this->inventory.addItem(new Item(mon->getDropItemName(), mon->getDropItemPrice()));
			this->exp += mon->getExpReward();
			if (this->exp >= this->maxExp) {
				this->level++;
				this->maxExp = 100 + (this->level - 1) * 50;
				this->exp -= this->maxExp;
				this->setHp(this->getHp() + 10);
				this->setMp(this->getMp() + 5);
				this->setAtk(this->getAtk() + 5);
				cout << RPGConst::Message::Fight::LEVEL_UP << "\n";
			}
			return false;
		}
	}
	return true;
}