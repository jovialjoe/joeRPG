#pragma once

#include "../header/enemy.hpp"
#include "../header/player.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class FightSystem {
 private:
    int GAME_SCREEN_SIZE;
    bool Skip_Turn_Flag;
    int Mage_Charge_Stacks;

 public:
    FightSystem();
    bool fighting(Enemy enemy, Player& player);
	void fightDisplay(Enemy& enemy, Player& player);
    void playerTurn(Enemy& enemy, Player& player);
    void enemyTurn(Enemy& enemy, Player& player);
};