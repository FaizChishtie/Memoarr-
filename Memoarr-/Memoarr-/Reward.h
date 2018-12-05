//
//  Reward.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-04.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//
#include <iostream>

#ifndef Reward_h
#define Reward_h

class Reward{
private:
    Reward() = default;
    Reward(unsigned int num); 
public:
    int numRubies;
    int getNumRubies() const;
    friend std::ostream& operator<<(std::ostream& os, Reward& r);
};

#endif /* Reward_h */
