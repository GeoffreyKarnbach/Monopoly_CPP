//
// Created by Geoffrey on 13.07.2022.
//

#ifndef MONOPOLY_GAMEFIELDS_H
#define MONOPOLY_GAMEFIELDS_H

#include <string>

using namespace std;

class GameFields {

private:
    int price;
    string name;

public:
    GameFields(int price, string name);
    string toString();


};


#endif //MONOPOLY_GAMEFIELDS_H
