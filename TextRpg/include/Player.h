#pragma once
#include <string>
#include <iostream>

#include "Inventory.h"
#include "Item.h"

using namespace std;

class Monster;
class Player {
public:
	Player(string name, int* stat, string job);
	virtual ~Player();
	void printPlayerStatus();
	virtual bool attack(Monster* mon) = 0;
	void printInventory();
	
	
	string getName() const { return name; }
	void setName(const std::string& name) { this->name = name; }
	string getJob() const { return job; }
	void setJob(const std::string& job) { this->job = job; }
	int getHp() const { return hp; }
	void setHp(int hp) { this->hp = hp; }
	int getMp() const { return mp; }
	void setMp(int mp) { this->mp = mp; }
	int getAtk() const { return atk; }
	void setAtk(int atk) { this->atk = atk; }
	int getDef() const { return def; }
	void setDef(int def) { this->def = def; }
	int getLevel() const { return level; }
	void setLevel(int level) { this->level = level; }
	int getExp() const { return exp; }
	void setExp(int exp) { this->exp = exp; }
	Inventory<Item*> getInventory() const { return this->inventory; }
	
protected:
	string name, job;
	int hp, mp, atk, def, level = 1, exp = 0, maxExp;
	Inventory<Item*> inventory;
};
