//
//  Rules.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-21.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//
#include "Game.h"
#include "Player.h"
#ifndef Rules_h
#define Rules_h
class Rules{
    int turn = 0;
    
public:
    bool isValid(Game&);
    bool gameOver(Game&);
    bool roundOver(Game&);
    Player& getNextPlayer(Game&);
    Side getSideAtIndex(int i);
    
    
};

#endif /* Rules_h */
