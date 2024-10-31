#pragma once

#include "../header/enemy.hpp"
#include <string>
#include <iostream>

using std::string;

class FightEncounter {
 private: 
    int difficulty;
    string prompt;
    string choice1;
    string choice2;
    string response1;
    string response2;
    Enemy* opp1;
    Enemy* opp2;
 public:
    FightEncounter() {};
    FightEncounter(string p, string o1, string o2, string r1, string r2, Enemy* e1, Enemy* e2, int diff);
    const string& getPrompt();
    const string& getChoice1();
    const string& getChoice2();
    const string& getResponse1();
    const string& getResponse2();
    Enemy getEnemy1();
    Enemy getEnemy2();
    int getDifficulty();

    const Enemy* getEnemy1Destroy();
    const Enemy* getEnemy2Destroy();

};