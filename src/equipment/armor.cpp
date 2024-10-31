#include <string>

#include "../header/equipment/armor.hpp"


using std::string;

Armor::Armor(int hpPnt, string name) {
    healthPoints = hpPnt;
    armorName = name;
}

int Armor::getHealthPoints() const {
    return healthPoints;
}

const string& Armor::getArmorName() const {
    return armorName;
}

void Armor::changeHealthPoints(int changeAmount) {
    healthPoints += changeAmount;
}