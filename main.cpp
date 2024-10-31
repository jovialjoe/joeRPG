#include <iostream>
#include "header/game.hpp"

using std::cout;
using std::endl;

int main() {
    Game rpg;

    rpg.intro();

    while (rpg.getDisanceFromFinalBoss() > 0) {
        rpg.startLethalEncounter();
        if (rpg.isPlayerAlive() == false) {
            cout << "You're dead... better luck next time." << endl;
            return 0; 
        }
        rpg.startNonlethalEncounter();
    }

    rpg.startFinalBoss();
    rpg.outro();  

    return 0;
}

