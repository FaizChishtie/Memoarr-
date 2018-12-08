//
//  Card.h
//  Memoarr-
//
//  Created by Amro Ahmed on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef Card_h
#define Card_h
#include <stdio.h>
#include <iostream>

using namespace std;
enum FaceAnimal{
    Crab='C',
    Penguin='P',
    Octopus='O',
    Turtle='T',
    Walrus='W'
};

enum FaceBackground{
    Red='r',
    Green='g',
    Purple='p',
    Blue='b',
    Yellow='y'
};

class Card{
    int nRow = 3;
    bool inGame = true;
    FaceAnimal animal;
    FaceBackground face;
    string card[3];
    
    
private:
    void makeCard();
    
public:
    Card(FaceAnimal _animal, FaceBackground _background): animal{_animal} , face{_background} {
        makeCard();
    }
    Card()= default;
    string operator()(int index);
    
    int getNRows();
    void removeCard();
    bool isInGame();
    operator FaceAnimal();
    operator FaceBackground();
    friend inline ostream& operator<<(ostream& os, Card& c);
    friend class CardDeck;
};

inline ostream& operator<<(ostream& os, Card& c){
    
    for (int row = 0; row <c.getNRows(); ++row ) {
        string rowString = c(row);
        os << rowString << endl;
    }
    return os;
}


#endif /* Card_h */
