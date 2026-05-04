#include "PotionIngredient.h"

PotionIngredient::PotionIngredient(const string& name, int count) : name(name), count(count) {
}

void PotionIngredient::printInfo() {
	printf("%s x%d", name.c_str(), count);
}
