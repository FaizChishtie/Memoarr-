//
//  RewardDeck.cpp
//  FinlProject
//
//  Created by Amro Ahmed on 2018-12-07.
//  Copyright © 2018 Amro Ahmed. All rights reserved.
//

#include <stdio.h>
#include "RewardDeck.h"
#include <iostream>

RewardDeck::~RewardDeck(){
}

void RewardDeck::setCards(){

    for(int i = 0; i < 7; ++i){
        rewardDeck[i] = Reward(time(NULL));
    }
}

void RewardDeck::shuffle(){
    setCards();
    random_shuffle(&rewardDeck[0],  &rewardDeck[6]);
    rewardDeck2 = &rewardDeck[0];
}

Reward* RewardDeck::getNext(){
    rewardDeck2++;
    return rewardDeck2;
}

bool RewardDeck::isEmpty() const {
    if (rewardDeck==nullptr) return false;
    for (int i=0; i<7; i++){
        if(&rewardDeck[0] == 0) return false;
    }
    return true;
}

RewardDeck& RewardDeck::make_RewardDeck(){
    static RewardDeck rDeck;
    rDeck.setCards();
    rDeck.shuffle();
    return rDeck;
}

Reward* RewardDeck::returnReward(){
    return rewardDeck2;
}
