//
//  Game.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <stdio.h>
#include "Game.h"

int Game::getNumPlayers(){
    return static_cast<int>(players.size());
}

int Game::getRound() const{
    return round;
}

void Game::nextRound(){
    ++round;
    
}

void Game::addPlayer( const Player& p){
    for(std::vector<Player>::iterator it = players.begin(); it != players.end(); ++it) {
        if(it->getName() == p.getName()){
            *it = p;
            return;
        }
    }
    players.push_back(p);
}

Player& Game::getPlayer(Side s){
    return players[s];
}

const Card* Game::getPreviousCard(){
    return previousCard;
}

const Card* Game::getCurrentCard(){
    return currentCard;
}

void Game::setCurrentCard( const Card* newC){
    previousCard = currentCard;
    currentCard = newC;
    
}

Card* Game::getCard( const Letter& _l, const Number& _n){
    return board->getCard(_l, _n);
}
void Game::setCard( const Letter& _l, const Number& _n, Card* c){
    board->setCard(_l, _n, c);
}
