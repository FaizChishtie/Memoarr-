//
//  Reward.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-04.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;

#ifndef Reward_h
#define Reward_h

class Reward{
    
private:
    int numRubies = 0;
    Reward() = default;
    Reward(unsigned int num){
        srand(num);
        numRubies = rand()%4;
    }
    
public:
    friend class RewardDeck;
    int getNumRubies() const;
    operator int();
    friend inline ostream& operator<< (ostream& os, const Reward& r);
};


 inline ostream& operator<<(ostream& os, const Reward& r){
    os << r.getNumRubies();
    return os;
}

#endif /* Reward_h */
