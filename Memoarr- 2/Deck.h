//
//  Deck.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef Deck_h
#define Deck_h
#include <iostream>
using namespace std;

template<class C> class Deck{
public:
    virtual void shuffle() = 0;
    virtual C* getNext() = 0;
    virtual bool isEmpty() const = 0;
};


#endif /* Deck_h */

