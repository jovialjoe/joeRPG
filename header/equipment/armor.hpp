#pragma once

#include <string>

using std::string;

class Armor {
 private:
    int healthPoints;
    string armorName;

 public:
    Armor(int hpPnt, string name);
    int getHealthPoints() const;
    const string& getArmorName() const;
    void changeHealthPoints(int changeAmount);
};