//
// Created by Geoffrey on 13.07.2022.
//

#include "GameBoard.h"
#include <iostream>
#include <string>

using namespace std;

GameBoard::GameBoard() {
    //TODO
}

void GameBoard::generate() {
    for (int i = 1; i <= 40;i++)
    {
        GameFields current(i);
        this->board.push_back(current);
    }
}

GameFields GameBoard::getAfter(int startIndex, int steps) {
    //TODO
}

bool GameBoard::addField(GameFields toAdd) {
    this->board.push_back(toAdd);
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

void GameBoard::outputComplexBoard() {
    cout << endl << "=================================================================================" << endl;
    cout << "BEGIN OF BOARD STATUS." << endl;

    for(int i = 0; i < this->getFieldNumber();i++)
    {
        cout << this->board.at(i).complexToString() << endl << endl;
    }
    cout << "END OF BOARD STATUS." << endl;
    cout << "=================================================================================" << endl << endl;
}