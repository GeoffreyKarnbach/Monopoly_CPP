//
// Created by Geoffrey on 13.07.2022.
//

#include "GameFields.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

GameFields::GameFields() {
    this->name = "Default";
    this->price = -1;
}

string GameFields::boolToString(bool value) {
    return value ? "true" : "false";
}

string GameFields::toString() {
    return "Field ("+this->name+") costs "+ to_string(this->price)+" .";
}

string GameFields::complexToString() {
    string toReturn = "{\n\tisStart: "+ boolToString(isStart)+
                        "\n\tisJail: "+ boolToString(isJail)+
                        "\n\tisParking: "+boolToString(isParking)+
                        "\n\tisPolice: "+ boolToString(isPolice)+
                        "\n\tisLuck: "+ boolToString(isLuck)+
                        "\n\tisCommunity: "+ boolToString(isCommunity)+
                        "\n\tisElectric: "+ boolToString(isElectric)+
                        "\n\tisWater: "+ boolToString(isWater)+
                        "\n\tisLuxuryTax: "+ boolToString(isLuxuryTax)+
                        "\n\tisIncomeTax: "+ boolToString(isIncomeTax)+
                        "\n\tisTrainStation: "+ boolToString(isTrainStation)+
                        "\n\tTrain_Name: "+this->Stations[this->train_name]+
                        "\n\tField Name: "+this->name+
                        "\n\tField color: "+this->Colors[this->color]+
                        "\n\tPrice: "+ to_string(this->price)+
                        "\n}";
    return toReturn;
}

void GameFields::handler(Player current) {
    //TODO
}

GameFields::GameFields(int index) {

    //Phase 1: Find corresponding line in given CSV file
    ifstream myFile("../Fields.csv");
    string line;
    int counter = 0;
    while (getline(myFile, line)) {
        if (counter == index)
        {
            break;
        }
        counter++;
    }

    //Phase 2: Separate tokens from delimiter ","
    string delimiter = ",";
    int pos = 0;
    string token;
    vector<string> splitted;
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        splitted.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    splitted.push_back(line);

    //Configure instance of GameFields according to attributes from CSV file

    if (splitted.at(0) == "1")
    {
        this->isStart = true;
    }
    if (splitted.at(1) == "1")
    {
        this->isJail = true;
    }
    if (splitted.at(2) == "1")
    {
        this->isParking = true;
    }
    if (splitted.at(3) == "1")
    {
        this->isPolice = true;
    }
    if (splitted.at(4) == "1")
    {
        this->isLuck = true;
    }
    if (splitted.at(5) == "1")
    {
        this->isCommunity = true;
    }
    if (splitted.at(6) == "1")
    {
        this->isElectric = true;
    }
    if (splitted.at(7) == "1")
    {
        this->isWater = true;
    }
    if (splitted.at(8) == "1")
    {
        this->isLuxuryTax = true;
    }
    if (splitted.at(9) == "1")
    {
        this->isIncomeTax = true;
    }
    if (splitted.at(10) == "1")
    {
        this->isTrainStation = true;
    }
    this->train_name = TrainStations(stoi(splitted.at(11)));
    this->name = splitted.at(12);
    this->color = Color(stoi(splitted.at(13)));
    this->price = stoi(splitted.at(14));
}