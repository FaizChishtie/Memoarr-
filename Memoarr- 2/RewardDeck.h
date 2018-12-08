//
//  RewardDeck.h
//  Memoarr-
//
//  Created by Amro Ahmed on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef RewardDeck_h
#define RewardDeck_h
#include "Deck.h"
#include "Reward.h"
#include <iostream>
#include <vector>
using namespace std;

class RewardDeck : public Deck<Reward>{

private:
    Reward* rewardDeck = new Reward[7];
    Reward* rewardDeck2 = new Reward[7];
    RewardDeck() = default;
    void setCards();
    void shuffle();
    Reward* getNext();
    bool isEmpty() const;
    
public:
    ~RewardDeck();
    static RewardDeck& make_RewardDeck();
    Reward* returnReward();
};
#endif /* RewardDeck_h */
