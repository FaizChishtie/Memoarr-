//
//  CardDeck.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-21.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include "Card.h"
#include "Deck.h"


#ifndef CardDeck_h
#define CardDeck_h
class CardDeck: public Deck<Card>{
    static Deck<Card> deck;
public:
    static CardDeck& make_cardDeck();
};


#endif /* CardDeck_h */
