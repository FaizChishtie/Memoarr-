//
//  CardDeck.h
//  Memoarr-
//
//  Created by Amro Ahmed on 2018-12-06.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef CardDeck_h
#define CardDeck_h
#include "Deck.h"
#include "Card.h"
#include <iostream>
using namespace std;
class CardDeck : public Deck<Card>{
    
    Card *cardPtr = new Card[25];
    Card *cardPtr2 = new Card[25];
    int size = 5;
    
    CardDeck() = default;
    void setCards();
    void shuffle();
    void printDeck();
    Card* getNext();
    bool isEmpty() const;
    
public:
    Card& operator()(int i, int j);
    friend inline ostream& operator<<(ostream& oS, CardDeck& p);
    ~CardDeck();
    static CardDeck& make_CardDeck();
};

inline ostream& operator<<(ostream& oS, CardDeck& p){
    int size = 5;
    for (int i = 0; i< size; i++){
        for (int j = 0; j < size; j++){
            oS << p.cardPtr[i*size + j] << " ";
        }
        oS << endl;
    }
    return oS;
}


#endif /* CardDeck_h */
