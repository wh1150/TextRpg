#pragma once

#include "Player.h"

class Archer: public Player {
public:
	Archer(string name, int* stat);
	~Archer() override = default;
	bool Player::attack(Monster* mon);
};
