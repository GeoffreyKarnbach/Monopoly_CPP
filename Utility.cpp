//
// Created by Geoffrey on 15.07.2022.
//

#include "Utility.h"
#include <cstdlib>

int Utility::getRandom(int maxi) {
    return rand()%maxi+1;
}