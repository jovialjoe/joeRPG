#include "../header/fightSystem.hpp"
#include "../header/enemy.hpp"
#include "../header/player.hpp"
#include "../header/helperFunctions.hpp"

#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

FightSystem::FightSystem() {
    GAME_SCREEN_SIZE = 80;
    Skip_Turn_Flag = false;
    Mage_Charge_Stacks = 1;
}

void FightSystem::fightDisplay(Enemy& enemy, Player& player) { 
    string playerSide, enemySide, playerHPSide, enemyHPSide;

    string playerTitle = player.getName() + " the " + player.getPlayerClass();
    string playerHP = "[HP: " + to_string(player.getHP()) + "/" + to_string(player.getMaxHP()) + "]";
    string enemyHP = "[HP: " + to_string(enemy.getHP()) + "/" + to_string(enemy.getMaxHP()) + "]";

    int playerSideWhiteSpace = (GAME_SCREEN_SIZE/2 - playerTitle.length())/2;
    int enemySideWhiteSpace = (GAME_SCREEN_SIZE/2 - enemy.getName().length())/2;
    int playerHPSideWhiteSpace = (GAME_SCREEN_SIZE/2 - playerHP.length())/2;
    int enemyHPSideWhiteSpace = (GAME_SCREEN_SIZE/2 - enemyHP.length())/2;

    if(playerSideWhiteSpace%2 != 0) { playerSideWhiteSpace++; }
    if(enemySideWhiteSpace%2 != 0) { enemySideWhiteSpace++; }
    if(playerHPSideWhiteSpace%2 != 0) { playerHPSideWhiteSpace++; }
    if(enemyHPSideWhiteSpace%2 != 0) { enemyHPSideWhiteSpace++; }
    
    //First line, player name
    for(int i = 0; i < playerSideWhiteSpace; i++) {
        playerSide += " ";
    }
    playerSide += playerTitle;
    for(int i = 0; i < playerSideWhiteSpace; i++) {
        playerSide += " ";
    }

    //First line, enemy name

    for(int i = 0; i < enemySideWhiteSpace; i++) {
        enemySide += " ";
    }
    enemySide += enemy.getName();
    for(int i = 0; i < enemySideWhiteSpace; i++) {
        enemySide += " ";
    }

    //Second line, player HP

    for(int i = 0; i < playerHPSideWhiteSpace; i++) {
        playerHPSide += " ";
    }
    playerHPSide += playerHP;
    for(int i = 0; i < playerHPSideWhiteSpace; i++) {
        playerHPSide += " ";
    }

    //Second line, enemy HP

    for(int i = 0; i < enemyHPSideWhiteSpace; i++) {
        enemyHPSide += " ";
    }
    enemyHPSide += enemyHP;
    for(int i = 0; i < enemyHPSideWhiteSpace; i++) {
        enemyHPSide += " ";
    }

    //Clear screen
    helperPrintLargerSpacer();

    //Print name line and HP line
    cout << playerSide << enemySide << endl;
    cout << playerHPSide << enemyHPSide << endl << endl;

    //Print divider
    for(int i = 0; i < GAME_SCREEN_SIZE; i++) {
        cout << "=";
    }

    cout << endl;
}

void FightSystem::playerTurn(Enemy& enemy, Player& player) {
    if(Skip_Turn_Flag == true) {
        Skip_Turn_Flag = false;
        fightDisplay(enemy, player);
        cout << "You skip your turn." << endl;
        helperWait(2.5);
        return;
    }

    int moveChoice = 0;

    while(!(moveChoice == 1 || moveChoice == 2)) {
        fightDisplay(enemy, player);

        if(player.getPlayerClass() == "Archer") {
            cout << "Your Moves:" << endl;
            cout << "1. " << player.getMove1Name() << " - (" << player.getATK() << ")" << endl;
            cout << "2. " << player.getMove2Name() << " - (" << int(player.getATK()*1.5) << "-" << int(player.getATK()*2.5) << ", Skip Next Turn)" << endl;
        } else if(player.getPlayerClass() == "Swordsman") {
            cout << "Your Moves:" << endl;
            cout << "1. " << player.getMove1Name() << " - (" << player.getATK() << ")" << endl;
            cout << "2. " << player.getMove2Name() << " - (" << int(player.getATK()*1.5) << ", Lose 4 HP)" << endl;
        } else if(player.getPlayerClass() == "Mage") {
            cout << "Your Moves:" << endl;
            cout << "1. " << player.getMove1Name() << " - (" << player.getATK()*Mage_Charge_Stacks << ")" << endl;
            cout << "2. " << player.getMove2Name() << " - (" << "0, Empower Next Attack)" << endl;
        }

        if (!(cin >> moveChoice)) {
            throw runtime_error("fightSystem playerTurn cin_read_error");
        }

        if(!(moveChoice == 1 || moveChoice == 2)) {
            fightDisplay(enemy, player);
            cout << "Invalid, please enter a proper move number..." << endl;
            helperWait(2);
        }
    }

    if(player.getPlayerClass() == "Archer") {
        int damageDone = player.getATK();
        if(moveChoice == 1) {
            enemy.setHP(enemy.getHP()-damageDone);
            fightDisplay(enemy, player);
            cout << "You did " << damageDone << " DMG with " << player.getMove1Name() << endl;
            
        } else if(moveChoice == 2) {
            damageDone *= (1.5 + (helperGenerateRandomInteger(0,10)/10.0));
            enemy.setHP(enemy.getHP()-damageDone);
            fightDisplay(enemy, player);
            cout << "You did " << damageDone << " DMG! You will skip your next turn."  << endl;
            Skip_Turn_Flag = true;
        }
    } else if(player.getPlayerClass() == "Swordsman") {
        int damageDone = player.getATK();
        if(moveChoice == 1) {
            enemy.setHP(enemy.getHP()-damageDone);
            fightDisplay(enemy, player);
            cout << "You did " << damageDone << " DMG with " << player.getMove1Name() << endl;
            
        } else if(moveChoice == 2) {
            damageDone *= 1.5;
            enemy.setHP(enemy.getHP()-damageDone);
            player.setHP(player.getHP()-4);
            fightDisplay(enemy, player);
            cout << "You did " << damageDone << " DMG! But lost 4 HP" << endl;
        }
    } else if(player.getPlayerClass() == "Mage") {
        int damageDone = player.getATK()*Mage_Charge_Stacks;
        if(moveChoice == 1) {
            enemy.setHP(enemy.getHP()-damageDone);
            fightDisplay(enemy, player);
            cout << "You did " << damageDone << " DMG with " << player.getMove1Name() << endl; 
            Mage_Charge_Stacks = 1; 
        } else if(moveChoice == 2) {
            Mage_Charge_Stacks *= 2;
            fightDisplay(enemy, player);
            cout << "Your next attack is strengthened by " << Mage_Charge_Stacks << "x!" << endl;
        }
    }
    helperWait(2.5);
}

void FightSystem::enemyTurn(Enemy& enemy, Player& player) {
    int chanceNum = helperGenerateRandomInteger(0, 99);
    int damageDone = enemy.getATK();

    if (chanceNum >= 0 && chanceNum < 70) {
        player.setHP(player.getHP() - damageDone);
        fightDisplay(enemy, player);
        cout << enemy.getName() << " used " << enemy.getMove1Name() << "."; 
        cout << " You took "<< damageDone << " damage!" << endl;

    } else {
        damageDone *= 1.3;
        player.setHP(player.getHP() - damageDone);
        fightDisplay(enemy, player);
        cout << enemy.getName() << " used " << enemy.getMove2Name() << ".";
        cout << " You took "<< damageDone << " damage!" << endl;
    }
    helperWait(2.5);
}

bool FightSystem::fighting(Enemy enemy, Player& player) {
    while(true) {
        playerTurn(enemy, player);
        if(enemy.getHP() <= 0) {
            break;
        }

        enemyTurn(enemy, player);
        if(player.getHP() <= 0) {
            break;
        }
    }

    fightDisplay(enemy, player);
    if(player.getHP() <= 0) {
        cout << "You were defeated by " << enemy.getName() << "..." << endl;
        helperWait(2.5);
        helperPrintLargerSpacer();
        return false;
    } else {
        cout << "You have slain " << enemy.getName() << "!" << endl;
        helperWait(2.5);
        helperPrintLargerSpacer();
        return true;
    }
}