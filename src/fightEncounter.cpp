#include "../header/fightEncounter.hpp"
#include "../header/enemy.hpp"

FightEncounter::FightEncounter(string p, string o1, string o2, string r1, string r2, Enemy* e1, Enemy* e2, int diff) {
    prompt = p;
    choice1 = o1;
    choice2 = o2;
    response1 = r1;
    response2 = r2;
    opp1 = e1;
    opp2 = e2;
    difficulty = diff;
}

const string& FightEncounter::getPrompt() {
    return prompt;
}

const string& FightEncounter::getChoice1() {
    return choice1;
}

const string& FightEncounter::getChoice2() {
    return choice2;
}

const string& FightEncounter::getResponse1() {
    return response1;
}

const string& FightEncounter::getResponse2() {
    return response2;
}

Enemy FightEncounter::getEnemy1() {
    return *opp1;
}

Enemy FightEncounter::getEnemy2() {
    return *opp2;
}

int FightEncounter::getDifficulty() {
    return difficulty;
}

const Enemy* FightEncounter::getEnemy1Destroy() {
    return opp1;
}

const Enemy* FightEncounter::getEnemy2Destroy() {
    return opp2;
}