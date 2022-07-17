//
// Created by Geoffrey on 14.07.2022.
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

#pragma once
#include <string>
#include "GameFields.h"
#include <vector>

using namespace std;

class GameFields;

class Player {

    private:
        int money;
        string name;
        int position;
        const int JAIL_ID = 10;
        bool inJail;

        /*
         * Saves the amount of houses for each of the 40 Gamefields
         * Houses = 1->4 ; Hotel = 5
         */
        vector<int> houses;

        vector<bool> owned; //Saves if the player owns the Gamefield at index n

    public:
        /*
         * A new player is defined by its name and starting money.
         */
        Player(int startMoney, string name);

        /*
         * Default constructor for Player class
         */
        Player();

        /*
         * Method to make payment from Player this to the Bank
         * If there is not enough money, the player loses
         */
        bool takeMoney(int amount);

        /*
         * Method to make payment from Player this to Player to
         * If not enough money is available, the player loses
         */
        bool takeMoney(int amount, Player to);

        /*
         * Method to add money to player
         */
        bool addMoney(int amount);

        /*
         * Two Player objects are considered equal if their names are identical.
         * Implementation of == operator.
         */
        bool operator==(Player toCompare);

        /*
         * Returns a string containing a readable definition of the given player in the format
         *  "Player XXXXXX currently has YYYYY euros"
         */
        string toString();

        /*
         * Set current Gamefield for specific player
         */
        bool setField(int index);

        /*
         * Return current PlayerPosition
         */
        int getField();

        /*
         * Method to send player to jail
         */
        void goToJail();
};


#endif //MONOPOLY_PLAYER_H
