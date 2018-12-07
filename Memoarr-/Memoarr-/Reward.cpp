//
//  Reward.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-26.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include "Reward.h"

Reward::Reward(unsigned int num){
    srand(num);
    numRubies = rand()%4 + 1;
}

int Reward::getNumRubies() const{
    return numRubies;
}



