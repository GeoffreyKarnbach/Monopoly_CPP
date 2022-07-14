//
// Created by Geoffrey on 13.07.2022.
//

#include "GameBoard.h"
#include <iostream>
#include <string>

using namespace std;

GameBoard::GameBoard() {

}

void GameBoard::generate() {
    //TODO: Read all the fields from CSV files "Fields.csv" and generate fields. Insert them into "Ring list".
}

GameFields GameBoard::getAfter(int number) {
    return GameFields(10,"Test");
}

bool GameBoard::addField(GameFields toAdd) {
    return true;
}

int GameBoard::getFieldNumber() {
    return this->board.size();
}

void GameBoard::outputBoard() {
    cout << endl << "=================================================================================" << endl;
    cout << "BEGIN OF BOARD STATUS." << endl;

    for(int i = 0; i < this->getFieldNumber();i++)
    {
        cout << this->board.at(i).toString() << endl;
    }
    cout << "END OF BOARD STATUS." << endl;
    cout << "=================================================================================" << endl << endl;
}