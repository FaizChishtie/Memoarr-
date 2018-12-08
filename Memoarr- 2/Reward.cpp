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

int Reward::getNumRubies() const{
    return numRubies;
}

Reward::operator int(){
    return numRubies;
}



