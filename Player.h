//
// Created by Geoffrey on 14.07.2022.
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

#include <string>

using namespace std;

class Player {
private:
    int money;
    string name;
public:
    /*
     * A new player is defined by its name and starting capital.
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
     * Two Player objects are considered equal if their names are identical.
     * Implementation of == operator.
     */
    bool operator==(Player toCompare);

    /*
     * Returns a string containing a readable definition of the given player in the format
     *  "Player XXXXXX currently has YYYYY euros"
     */
    string toString();

};


#endif //MONOPOLY_PLAYER_H
