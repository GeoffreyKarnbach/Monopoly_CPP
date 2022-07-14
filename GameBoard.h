//
// Created by Geoffrey on 13.07.2022.
//

#ifndef MONOPOLY_GAMEBOARD_H
#define MONOPOLY_GAMEBOARD_H

#include "GameFields.h"
#include <string>
#include <math.h>
#include <vector>

/*
 * Implement GameBoard as Ringlist with methode to "jump" given amount of squares
 * In constructor create all the cases, to reduce amount of code in main.cpp to a single GameBoard Objects
 *
 */

class GameBoard {
private:
    int index = 0;
    vector<GameFields> board;

public:
    /*
     * Basic Constructor
     */
    GameBoard();

    /*
     * Generate the game board, by adding all the Fields
     */
    void generate();

    /*
     * Jump X fields and returns the current field
     */
    GameFields getAfter(int startIndex, int steps);

    /*
     * Add new Gamefield to Gameboard
     */
    bool addField(GameFields toAdd);

    /*
     * Get number of fields
     */
    int getFieldNumber();

    /*
     * Method to output current state of Gameboard
     */
    void outputBoard();

    /*
     * Method to output current state of Gameboard with all attributes
     */
    void outputComplexBoard();

    /*
     * Return Start Field
     */
    GameFields getStartField();

};


#endif //MONOPOLY_GAMEBOARD_H
