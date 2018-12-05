//
//  Reward.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-26.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Reward.h"

Reward::Reward(unsigned int num){
    srand(num);
    numRubies = rand()%4 + 1;
}

std::ostream& operator<<(std::ostream& _os, const Reward& r){
    _os << r.numRubies;
    return _os;
}

int Reward::getNumRubies() const{
    return numRubies;
}



