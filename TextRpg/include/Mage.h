#pragma once

#include "Player.h"

class Mage: public Player {
public:
	Mage(string name, int* stat);
	~Mage() override = default;
	bool Player::attack(Monster* mon);
};
