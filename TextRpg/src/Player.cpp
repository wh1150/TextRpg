#include <string>

#include "RPGConst.h"
#include "Player.h"
#include <iostream>

using namespace std;
Player::Player(string name, int* stat, string job) {
	this->name = name;
	this->hp = stat[RPGConst::Status::HEALTH_POINT];
	this->mp = stat[RPGConst::Status::MANA_POINT];
	this->atk = stat[RPGConst::Status::ATTACK_POINT];
	this->def = stat[RPGConst::Status::DEFENSE_POINT];
	this->job = job;
	this->level = 1;
	this->maxExp = this-> level * 100;
	
	printPlayerStatus();
}

Player::~Player() {
	for (auto inventory : inventory) delete inventory;
	inventory.clear();
}
void Player::printPlayerStatus() {
	printf(RPGConst::Message::InitSystem::CURRENT_STATUS_AFTER_JOB, this->name.c_str(), this->job.c_str(), this->level, this->hp, this->mp, this->atk, this->def);
}

void Player::printInventory() {
	printf("[ inventory (%d/%d) ]", this->inventory.size(), RPGConst::Init::INVENTORY_SIZE);
	if (this->inventory.empty())	
		printf("Inventory is empty!\n");
	else {
		int i = 1;
		for (auto item : this->inventory) {
			printf("%d. ",i++);
			item->printInfo();
		} 
	}
	cout << "\n";
}
