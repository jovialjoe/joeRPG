#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "../header/fightEncounter.hpp"
#include "../header/player.hpp"

using std::vector;

class Prompter {
    private: 
        vector<FightEncounter> fightEncounterList;
    public:
        Prompter();
        ~Prompter();
        void runEquipmentEncounter(Player& player);
        void runHealthEncounter(Player& player);
        bool runFightEncounter(int distance, Player& player);
};