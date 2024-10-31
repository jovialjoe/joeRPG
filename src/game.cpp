#include "../header/game.hpp"
#include "../header/player.hpp"
#include "../header/helperFunctions.hpp"
#include "../header/prompter.hpp"

#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

Game::Game() {}

Game::~Game() {
    delete player;
}

void Game::intro() {
    string name;
    int classNumber;

    helperPrintLargerSpacer();
    cout << "Hello adventurer, what is thy name?" << endl;

    if (!(cin >> name)) {
        throw runtime_error("game intro cin_name");
    }
    helperPrintLargerSpacer();

    cout << "Greeting " << name << " choose your class. [1-3]" << endl;
    cout << "1. Swordsman" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Archer" << endl;

    if (!(cin >> classNumber)) {
        throw runtime_error("game intro cin_classNumber");
    }
    helperPrintLargerSpacer();

    player = new Player(classNumber, name);

    cout << "Good luck, " << name << " the ";
    if (classNumber == 1) {
        cout << "Swordsman." << endl;
    }
    else if (classNumber == 2) {
        cout << "Mage." << endl;
    }
    else if (classNumber == 3) {
        cout << "Archer." << endl;
    }

    helperWait(2);
    helperPrintLargerSpacer();
}

void Game::outro() {
    helperPrintLargerSpacer();
    cout << "Congrats on completing your adventure! You will be remembers for your feats!" << endl;
}

int Game::getDisanceFromFinalBoss() {
    return distanceFromFinalBoss;
}

void Game::travelCloserToFinalBoss(int travelDistance) {
    if(distanceFromFinalBoss - travelDistance <= 0) {
        distanceFromFinalBoss = 0;
        helperPrintLargerSpacer();
        cout << "You traveled " << travelDistance << " miles. You have reached the Demon King's Castle!" << endl;
        helperWait(2.5);
    } else {
        distanceFromFinalBoss -= travelDistance;
        cout << "You traveled " << travelDistance << " miles. The Demon King is " << distanceFromFinalBoss << " miles away!" << endl;
        helperWait(2.5);
        helperPrintLargerSpacer();
    }
}

void Game::startLethalEncounter() {
    if (!(encounterPrompter.runFightEncounter(distanceFromFinalBoss, *player))) {
        isAlive = false;
        return;
    } 
    travelCloserToFinalBoss(4);
}

void Game::startNonlethalEncounter() {
    int encounterSelector = helperGenerateRandomInteger(0, 99);

    if (encounterSelector >= 0 && encounterSelector < 50) {
        encounterPrompter.runHealthEncounter(*player);
        travelCloserToFinalBoss(1);
    } else {
        encounterPrompter.runEquipmentEncounter(*player);
        travelCloserToFinalBoss(1);
    }
}

void Game::startFinalBoss() {
    cout << "You've reached the Demon King's Castle." << endl;
    cout << "However, he isn't home! Come back next update, " << player->getName()  << "!" << endl;
}

bool Game::isPlayerAlive() {
    return isAlive;
}