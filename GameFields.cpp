//
// Created by Geoffrey on 13.07.2022.
//

#include "GameFields.h"
#include <string>

using namespace std;



GameFields::GameFields(int price, string name) {
    this->price = price;
    this->name = name;
}

string GameFields::toString() {
    return "Field ("+this->name+") costs "+ to_string(this->price)+" euros.";
}

void GameFields::handler(Player current) {

}