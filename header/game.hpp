#pragma once

#include <iostream>
#include <string>
#include "../header/player.hpp"
#include "../header/prompter.hpp"

using std::cout;
using std::endl;
using std::string;

class Game {
    private:
        int classNumber;
        int distanceFromFinalBoss = 30; //30->0
        bool isAlive = true;
        Player* player;
        Prompter encounterPrompter;
    
    public:
        Game();
        ~Game();
        void intro(); // prompt for and cin player name and class
        void outro(); 
        int getDisanceFromFinalBoss(); // return distanceFromFinalBoss
        void travelCloserToFinalBoss(int travelDistance);
        void startLethalEncounter();
        void startNonlethalEncounter();
        void startFinalBoss();
        bool isPlayerAlive();
};
