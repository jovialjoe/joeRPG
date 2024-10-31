#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Enemy {
 private:
    int hp, maxHP, atk;
    string name;
    string move1Name;
    string move2Name;
    
 public:
    Enemy(const string& name, const string& move1Name, const string& move2Name, int hp, int atk);

    const string& getName() const;
    const string& getMove1Name();
    const string& getMove2Name();
    int getMaxHP();
    int getHP();
    int getATK();

    void setHP(int n);
    void setATK(int n);
    void setName(string n);
};