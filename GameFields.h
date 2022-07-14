//
// Created by Geoffrey on 13.07.2022.
//

#ifndef MONOPOLY_GAMEFIELDS_H
#define MONOPOLY_GAMEFIELDS_H

#include <string>
#include "Player.h"

using namespace std;

class GameFields {

private:

    enum TrainStations
    {
        NONE,
        READING_RAILROAD,
        PENNSYLVANIA_RAILROAD,
        B_O_RAILROAD,
        SHORT_LINE
    };

    enum Color
    {
        NO_COLOR,
        BROWN,
        LIGHT_BLUE,
        PINK,
        ORANGE,
        RED,
        YELLOW,
        GREEN,
        DARK_BLUE
    };

    bool isStart;
    bool isJail;
    bool isParking;
    bool isPolice;

    bool isLuck;
    bool isCommunity;

    bool isElectric;
    bool isWater;

    bool isLuxuryTax;
    bool isIncomeTax;
    bool isTrainStation;

    TrainStations train_name;
    string name;
    Color color;
    int price;
    Player owner;

public:
    GameFields(int price, string name);

    GameFields();

    /*
     * Returns a string containing a readable form of the given GameField
     *
     */
    string toString();

    /*
     * Handler to interact with the field
     */
    void handler(Player current);

};


#endif //MONOPOLY_GAMEFIELDS_H
