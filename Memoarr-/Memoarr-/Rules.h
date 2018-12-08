//
//  Rules.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-21.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef Rules_h
#define Rules_h
#include "Player.h"
#include "Game.h"

class Rules{
    int turn = 0;
    
public:
    Rules() = default;
    bool isValid(Game&);
    bool gameOver(Game&);
    bool roundOver(Game&);
    Player& getNextPlayer(Game&);
    Side getSideAtIndex(int i);
    void nextTurn();
};

#endif /* Rules_h */
