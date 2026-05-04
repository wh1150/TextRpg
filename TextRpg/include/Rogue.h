#pragma once

#include "Player.h"

class Rogue: public Player {
public:
	Rogue(string name, int* stat);
	~Rogue() override = default;
	bool Player::attack(Monster* mon);
};
