#pragma once

#include "Player.h"

class Warrior: public Player {
public:
	Warrior(string name, int* stat);
	~Warrior() override = default;
	bool Player::attack(Monster* mon);
};
