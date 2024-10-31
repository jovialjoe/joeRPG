#pragma once

#include "../header/equipment/armor.hpp"
#include "../header/equipment/weapon.hpp"

#include <string>
#include <vector>

using std::string;
using std::vector;

class Player {
 private:
    string classType;
    string name;        
    int maxHealth;
    int health;
    int attack;
    string defaultMove1Name;
    string defaultMove2Name;
    vector<Weapon> weaponList;
    vector<Armor> armorList;
    int weaponIndex;
    int armorIndex;

 public:
    Player(int classNum, const string& pName);
    const string& getPlayerClass();
    const string& getName();
    int getMaxHP();
    int getHP();
    int getATK();
    const string& getMove1Name();
    const string& getMove2Name();
    int getCurrentWeaponIndex();
    int getCurrentArmorIndex();
    int getSpecificWeaponATK(int index);
    int getSpecificArmorHP(int index);

    const string& getWeaponName(int index);
    int getWeaponListSize();
    const string& getArmorName(int index);
    int getArmorListSize();

    void setMaxHP(int newMaxHP);
    void setHP(int newHP);
    void setATK(int newATK);

    void equipWeapon(int index);
    void equipArmor(int index);
    
};