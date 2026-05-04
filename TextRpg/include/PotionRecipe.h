#pragma once
#include <string>
#include <vector>

#include "PotionIngredient.h"

using namespace std;
class PotionRecipe {
	string name;
	vector<PotionIngredient> ingredients;
public:
	PotionRecipe(string name, vector<PotionIngredient> ingredients);
	void printRecipe();
	string getName() const { return name; }
	vector<PotionIngredient> getIngredients() const { return ingredients; }
};
