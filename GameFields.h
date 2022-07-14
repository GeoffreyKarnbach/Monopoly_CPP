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
    string Colors[9] = {"NO_COLOR",
                       "BROWN",
                       "LIGHT_BLUE",
                       "PINK",
                       "ORANGE",
                       "RED",
                       "YELLOW",
                       "GREEN",
                       "DARK_BLUE"};

    string Stations[5] = {
            "NONE",
            "READING_RAILROAD",
            "PENNSYLVANIA_RAILROAD",
            "B_O_RAILROAD",
            "SHORT_LINE"
    };

    bool isStart = false;
    bool isJail = false;
    bool isParking= false;
    bool isPolice= false;

    bool isLuck= false;
    bool isCommunity= false;

    bool isElectric= false;
    bool isWater= false;

    bool isLuxuryTax= false;
    bool isIncomeTax= false;
    bool isTrainStation= false;

    TrainStations train_name;
    string name;
    Color color;
    int price;
    Player owner;

    string boolToString(bool value);

public:
    /*
     * Default Constructor
     */
    GameFields();

    /*
     * Constructor using data from csv file to load data (specific field index 0->39);
     */
    GameFields(int index);

    /*
     * Returns a string containing a readable form of the given GameField
     *
     */
    string toString();

    /*
     * Returns a complex representation of the given Gamefield as a String
     */
    string complexToString();

    /*
     * Handler to interact with the field
     */
    void handler(Player current);

};


#endif //MONOPOLY_GAMEFIELDS_H
