//
//  Player.cpp
//  Memoarr-
//
//  Created by Amro Ahmed on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const Player& oS): name{oS.name} , boardSide{oS.boardSide}, rubiesNum{oS.rubiesNum}, active{oS.active} {}

Player& Player::operator= (const Player& oS){
    if (this != &oS){
        name = oS.name;
        boardSide = oS.boardSide;
        rubiesNum = oS.rubiesNum;
        active = oS.active;
    }
    return *this;
}

string Player::getName() const{
    return name;
}

void Player::setActive(bool ac){
    active = ac;
}

bool Player::isActive(){
    return active;
}

int Player::getNRubies() const{
    return rubiesNum;
}

void Player::addReward(const Reward& rew){
    rubiesNum+=rew.getNumRubies();
}

void Player::setDisplayMode(bool endOfGame){
    end = endOfGame;
}
Side Player::getSlide(){
    return boardSide;
}
void Player::setSide(Side s){
    boardSide = s;
}
