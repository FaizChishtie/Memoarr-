//
//  Game.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <stdio.h>
#include "Game.h"

Player& Game::returnFirstValidPlayer(){
    for(int i = 0; i < players.size(); ++i){
        if (players[i].isActive()){
            return players[i];
        }
    }
    Side s = Top;
    Player p("-1",s);
    return p;
}



void Game::getUniqueAbility(Card* card, int x, int y, int cardNum, Board& board){
    char animalChar;
    std::string newLoc;
    if(animalChar == 'O'){
        std::cout<< "Octopus card! Exchange place in row or column!" << std::endl;
        std::cout<< "Enter new location: ";
        std::cin >> newLoc;
        
        if(y==3){
            
        }
    }
    if(animalChar == 'P' && cardNum == 1){
        std::cout<< "Penguin card! Turn a face up card down!" << std::endl;
        std::cout<< "Enter location: ";
        std::cin >> newLoc;
        char c_letter = newLoc[0];
        char c_number = newLoc[1];
        Letter letter = charToLetter(c_letter);
        Number number = charToNumber(c_number);
        while(!board.isFaceUp(letter, number)){
            std::cout<< "Card is not face up! Choose a face up card!" << std::endl;
            std::cout<< "Enter location: ";
            std::cin >> newLoc;
            c_letter = newLoc[0];
            c_number = newLoc[1];
            letter = charToLetter(c_letter);
            number = charToNumber(c_number);
        }
        board.turnFaceDown(letter, number);
    }
    if(animalChar == 'W'){
        std::cout<< "Walrus card! Block a card!" << std::endl;
        std::cout<< "Enter location: ";
        std::cin >> newLoc;
        char c_letter = newLoc[0];
        char c_number = newLoc[1];
        Letter letter = charToLetter(c_letter);
        Number number = charToNumber(c_number);
        while(board.isFaceUp(letter, number)){
            std::cout<< "Card is face up! Choose a face up card!" << std::endl;
            std::cout<< "Enter location: ";
            std::cin >> newLoc;
            c_letter = newLoc[0];
            c_number = newLoc[1];
            letter = charToLetter(c_letter);
            number = charToNumber(c_number);
        }
        board.disableCardForTurn(letter, number);
    }
}

int Game::getNumPlayers(){
    return static_cast<int>(players.size());
}

Player& Game::getWinner(){
    Player& player = players[0];
    for(int i = 1; i < players.size(); ++i){
        if(player.getNRubies() < players[i].getNRubies()){
            player = players[i];
        }
    }
    return player;
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

Game::~Game(){
    delete board;
    delete currentCard;
    delete previousCard;
}

void Game::decrementDisabledTurnsRemaining(){
    board->decrementTurnsDisabled();
}
int Game::getDisabledTurnsRemaining(){
    return board->getTurnsDisabled();
}

void Game::enableCard(){
    board->enableCard();
}
