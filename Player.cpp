//
// Created by Geoffrey on 14.07.2022.
//

#include "Player.h"
#include <string>

using namespace std;

Player::Player(int startMoney, string name) {
    this->money = startMoney;
    this->name = name;
}

bool Player::takeMoney(int amount) {
    if (this->money >= amount)
    {
        this->money-=amount;
        return true;
    }
    return false;
}

bool Player::takeMoney(int amount, Player to) {
    if (this->money >= amount)
    {
        this->money-=amount;
        to.money += amount;
        return true;
    }
    to.money += this->money;
    return false;
}

bool Player::operator==(Player toCompare) {
    return this->name == toCompare.name;
}

string Player::toString() {
    return "Player "+this->name+" currently has "+ to_string(this->money)+" euros";
}