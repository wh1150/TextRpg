
#include "PotionRecipe.h"

#include <iostream>
#include <ostream>
using namespace std;

PotionRecipe::PotionRecipe(string name, vector<PotionIngredient> ingredients) : name(name), ingredients(ingredients){
}

void PotionRecipe::printRecipe() {
	cout << name << ": (";
	for (int i = 0 ; i < ingredients.size() ; i++) {
		ingredients[i].printInfo();
		 if (i != ingredients.size() - 1) cout << ", ";
	}
	cout << ")";
}
