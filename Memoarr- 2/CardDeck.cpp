//
//  CardDeck.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <stdio.h>
#include "CardDeck.h"
#include <iostream>
using namespace std;

 CardDeck::~CardDeck(){
}


void CardDeck::setCards(){
    FaceAnimal animal[5] = {Crab, Penguin, Octopus, Turtle, Walrus};
    FaceBackground face[5] = {Red, Green, Purple, Blue, Yellow};
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            cardPtr[i*size + j] = Card(animal[i], face[j]);
        }
    }
}

void CardDeck::shuffle(){
    setCards();
    random_shuffle(&cardPtr[0], &cardPtr[size*size - 1]);
    cardPtr[2*size+2].removeCard();
    cardPtr2 = &cardPtr[0];
}


Card* CardDeck::getNext(){
    cardPtr2++;
    return cardPtr2;
    
}
bool CardDeck::isEmpty() const {
    if(cardPtr==nullptr) return false;
    for (int i=0; i<25; i++){
        if(&cardPtr[0] == 0) return false;
    }
    return true;
}

Card& CardDeck::operator()(int i, int j){
    return cardPtr[i*size + j];
}


 CardDeck& CardDeck::make_CardDeck(){
     static CardDeck cDeck;
     cDeck.shuffle();
     return cDeck;
}
