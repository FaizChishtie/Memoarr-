//
//  Rules.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-21.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//
#include "game.h"
#ifndef Rules_h
#define Rules_h
class Rules{
    
public:
    bool isValid(const Game&);
    bool gameOver(const Game&);
    bool roundOver(const Game&);
    Player& getNextPlayer(const Game&) const;
    
    
}

#endif /* Rules_h */
