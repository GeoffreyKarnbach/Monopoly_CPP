//
// Created by Geoffrey on 14.07.2022.
//

#include "Player.h"
#include <string>
#include "GameFields.h"
#include <iostream>

using namespace std;

Player::Player(int startMoney, string name) {
    this->money = startMoney;
    this->name = name;
    this->position = 0;
    this->inJail = false;

    for (int i = 0; i < 40; i++)
    {
        this->houses.push_back(0);
        this->owned.push_back(false);
    }

    cout << this->houses.size() << endl;

}

Player::Player() {}

bool Player::addMoney(int amount) {
    this->money += amount;
    return true;
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
    return "Player "+this->name+" currently has "+ to_string(this->money)+" euros and being at field with index "+to_string(this->position);
}

bool Player::setField(int index) {
    this->position = index;
    return true;
}

int Player::getField() {
    return this->position;
}

void Player::goToJail() {
    this->setField(JAIL_ID);
    this->inJail = true;
}