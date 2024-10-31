#include "../header/player.hpp"
#include "../header/equipment/armor.hpp"
#include "../header/equipment/weapon.hpp"

#include <assert.h>
#include <stdexcept>

using std::runtime_error;

Player::Player(int classNum, const string& pName) {
    if(classNum == 1) {         //Swordsman
        classType = "Swordsman";
        name = pName;
        maxHealth = 110;
        health = 110;
        attack = 5;
        defaultMove1Name = "Slash";
        defaultMove2Name = "Reckless Charge";

        //Load all swordsman weapons
        weaponList.push_back( Weapon(4, "Starter Sword", "", "") );
        weaponList.push_back( Weapon(6, "Adventurer Sword", "Strike", "Slander") );
        weaponList.push_back( Weapon(9, "Ruby Guantlet", "Punch", "Crimson Strike") );
        weaponList.push_back( Weapon(7, "Ragnork Rapier", "Sundering Slash", "Blinding Fury") );
        weaponList.push_back( Weapon(11, "Soulsteel Cleaver", "Sever", "Skull Splitter") );
        weaponList.push_back( Weapon(13, "Kusaragi Dagger", "Shadow Slash", "Abysmal Laceration") );
        weaponList.push_back( Weapon(15, "Hephaestus Blade", "Molten Slash", "Eternal Forge") );

    } else if(classNum == 2) {  //Mage
        classType = "Mage";
        name = pName;
        maxHealth = 75;
        health = 75;
        attack = 5;
        defaultMove1Name = "Fireball";
        defaultMove2Name = "Recite Incantation";

        //Load all mage weapons
        weaponList.push_back( Weapon(5, "Starter Wand", "", "") );
        weaponList.push_back( Weapon(7, "Adventurer Wand", "Curse", "Final Spark") );
        weaponList.push_back( Weapon(9, "Darktaok Spellbook", "Illumination", "Ecliptic Darkness") );
        weaponList.push_back( Weapon(11, "Circe's Staff", "Enchantment", "Elixir of Death") );
        weaponList.push_back( Weapon(13, "Staff of Dreams", "Deception", "Lucid Dream Crawl") );
        weaponList.push_back( Weapon(15, "Nature's Wrath Spellbook", "Elemental Chaos", "Pompeii's Return") );
        weaponList.push_back( Weapon(18, "Odin's Scepter", "Manipulation", "Necromancy Summoning") );

    } else if(classNum == 3) {  //Archer
        classType = "Archer";
        name = pName;
        maxHealth = 90;
        health = 90;
        attack = 5;
        defaultMove1Name = "Shoot";
        defaultMove2Name = "Snipe";

        //Load all archer weapons
        weaponList.push_back( Weapon(4, "Starter Bow", "", "") );
        weaponList.push_back( Weapon(5, "Adventurer Bow", "Fire", "Execute") );
        weaponList.push_back( Weapon(7, "Stargazer Crossbow", "Strike", "Barrage") );
        weaponList.push_back( Weapon(8, "Dawnbringer Longbow", "Ranger's Focus", "Starlight Volley") );
        weaponList.push_back( Weapon(10, "Celestial Starbow", "Blinding Shot", "Radiant Volley") );
        weaponList.push_back( Weapon(12, "Valkyrie's  Wingbow", "Echoing Strike", "Hunter's Mark") );
        weaponList.push_back( Weapon(14, "Artemis Bow", "Silencing Shot", "Piercing Starlight") );

    } else {
        throw runtime_error("player constructor invalid_classNum");
    }
    //Load all armor
    armorList.push_back( Armor(10, "Sylvan Leathers") );
    armorList.push_back( Armor(12, "Knight's Plate") );
    armorList.push_back( Armor(15, "Mithril Chainmail") );
    armorList.push_back( Armor(17, "Phantom Wraps") );
    armorList.push_back( Armor(19, "Infernal Plate") );
    armorList.push_back( Armor(21, "Wyvernscale Coat") );
    armorList.push_back( Armor(25, "Dragonbone Armor") );

    weaponIndex = 0;
    armorIndex = 0;
    attack += weaponList.at(weaponIndex).getAttackPoints();
    health += armorList.at(armorIndex).getHealthPoints();
    maxHealth += armorList.at(armorIndex).getHealthPoints();
}

const string& Player::getPlayerClass() {
    return classType;
}

const string& Player::getName() {
    return name;
}

int Player::getMaxHP() {
    return maxHealth;
}

int Player::getHP() {
    return health;
}

int Player::getATK() {
    return attack;
}

const string& Player::getMove1Name() {
    if(weaponList.at(weaponIndex).getMove1().empty()) {
        return defaultMove1Name;
    } else {
        return weaponList.at(weaponIndex).getMove1();
    }
}

const string& Player::getMove2Name() {
    if(weaponList.at(weaponIndex).getMove2().empty()) {
        return defaultMove2Name;
    } else {
        return weaponList.at(weaponIndex).getMove2();
    }
}

int Player::getCurrentWeaponIndex() {
    return weaponIndex;
}

int Player::getCurrentArmorIndex() {
    return armorIndex;
}

int Player::getSpecificWeaponATK(int index) {
    return weaponList.at(index).getAttackPoints();
}

int Player::getSpecificArmorHP(int index) {
    return armorList.at(index).getHealthPoints();
}

const string& Player::getWeaponName(int index) {
    return weaponList.at(index).getWeaponName();
}

int Player::getWeaponListSize() {
    return weaponList.size();
}

const string& Player::getArmorName(int index) {
    return armorList.at(index).getArmorName();
}

int Player::getArmorListSize() {
    return armorList.size();
}

void Player::setMaxHP(int newMaxHP) {
    maxHealth = newMaxHP;
}

void Player::setHP(int newHP) {
    health = newHP;
}

void Player::setATK(int newATK) {
    attack = newATK;
}

void Player::equipWeapon(int index) {
    // if(index == weaponIndex) {
    //     throw runtime_error("player equipWeapon same_index_error");
    // }

    //Remove old weapon attack bonuses
    setATK( getATK() - weaponList.at(weaponIndex).getAttackPoints() );

    //Change to new weapon and push_back new weapon attack bonuses
    weaponIndex = index;
    setATK( getATK() + weaponList.at(weaponIndex).getAttackPoints() );
}

void Player::equipArmor(int index) {
    // if(index == armorIndex) {
    //     throw runtime_error("player equipArmor same_index_error");
    // }

    //Remove old armor health bonuses
    setMaxHP( getMaxHP() - armorList.at(armorIndex).getHealthPoints() );
    setHP( getHP() - armorList.at(armorIndex).getHealthPoints() );

    //Change to new armor and push_back new armor health bonuses
    armorIndex = index;
    setMaxHP( getMaxHP() + armorList.at(armorIndex).getHealthPoints() );
    setHP( getHP() + armorList.at(armorIndex).getHealthPoints() );

    if(getHP() <= 0) {
        setHP( armorList.at(armorIndex).getHealthPoints() );
    }
}
