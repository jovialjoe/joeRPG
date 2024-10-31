#include "../header/enemy.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Enemy::Enemy(const string& name, const string& move1Name, const string& move2Name, int hp, int atk) {
    this->name = name;
    this->hp = hp;
    this->maxHP = hp;
    this->atk = atk;
    this->move1Name = move1Name;
    this->move2Name = move2Name;
}

const string& Enemy::getName() const {
    return name;
}

int Enemy::getHP() {
    return hp;
}

int Enemy::getATK() {
    return atk;
}

int Enemy::getMaxHP() {
    return maxHP;
}

void Enemy::setHP(int newHP) {
    hp = newHP;
}

void Enemy::setATK(int newATK) {
    atk = newATK;
}

void Enemy::setName(string newName) {
    name = newName;
}

const string& Enemy::getMove1Name() {
    return move1Name;
}

const string& Enemy::getMove2Name() {
    return move2Name;
}