//
//  Card.cpp
//  Memoarr-
//
//  Created by Amro Ahmed on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <stdio.h>
#include "Card.h"
#include <iostream>

using namespace std;

string Card::operator() (int index){
    return card[index];
}


bool Card::isInGame(){
    return inGame;
}

void Card::removeCard(){
    string s;
    inGame = false;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++) s+=" ";
        card[i] = s;
        s ="";
    }
}

int Card::getNRows(){
    return nRow;
}

Card::operator FaceAnimal(){
    return animal;
}

Card::operator FaceBackground(){
    return face;
}

void Card::makeCard(){
    char f = 'z',a = 'z';
    string s="";
    
    if (face == Red) f = 'r';
    else if (face == Green) f = 'g';
    else if (face == Purple) f = 'p';
    else if (face == Blue) f = 'b';
    else if (face == Yellow) f = 'y';
    
    if (animal == Crab) a = 'C';
    else if (animal == Penguin) a = 'P';
    else if (animal == Octopus) a = 'O';
    else if (animal == Turtle) a = 'T';
    else if (animal == Walrus) a = 'W';
    
    
    for (int i=0; i < nRow; i++){
        for (int j =0; j < nRow; j++){
            if(j==1 && i==1) s+=a;
            else s+=f;
        }
        card[i] = s;
        s="";
    }
    
    
}
