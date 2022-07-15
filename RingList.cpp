//
// Created by Geoffrey on 14.07.2022.
//

#include "RingList.h"
#include "Player.h"
#include <iostream>
#include <math.h>

using namespace std;

bool RingList::addPlayer(Player& toAdd) {
    this->playerList.push_back(&toAdd);
    return true;
}

int RingList::playerNumber() {
    return this->playerList.size();
}

RingList::RingList() {
    this->index = 0;
    this->playerList.clear();
}

RingList::RingList(Player& first) {
    RingList();
    this->addPlayer(first);
}

Player& RingList::getNext() {
    Player& toReturn = *(this->playerList.at(index%this->playerList.size()));
    index++;
    return toReturn;
}

int RingList::getIndex(Player& toFind) {
    for (int i = 0; i < this->playerList.size(); i++)
    {
        if (toFind == *(this->playerList.at(i)))
        {
            return i;
        }
    }
    return -1;
}

bool RingList::removePlayer(Player& toRemove) {
    int position = this->getIndex(toRemove);
    if (position >= 0)
    {
        if (position != this->playerNumber()-1 && position != 0){
            this->index--;
        }

        this->playerList.erase(this->playerList.begin() + position);
        return true;
    }
    return false;
}