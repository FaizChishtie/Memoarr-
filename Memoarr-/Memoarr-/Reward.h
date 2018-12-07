//
//  Reward.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-04.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//
using namespace std;

#ifndef Reward_h
#define Reward_h

#include <iostream>

class Reward{
private:
    Reward() = default;
    Reward(unsigned int num); 
public:
    int numRubies;
    int getNumRubies() const;
    friend inline ostream& operator<<(ostream& os, const Reward& r);
};


inline ostream& operator<<(ostream& _os, const Reward& r){
    _os << r.numRubies;
    return _os;
}

#endif /* Reward_h */
