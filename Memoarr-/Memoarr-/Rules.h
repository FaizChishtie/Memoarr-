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
    /*
     
     In this version, the cards or rather have some added meaning. When an octopus card is turned over, the
     card is exchanging position with an adjacent card in the same row or the same column (4-neighbourhood).
     The adjacent card may be face up or down and will remain unchanged. If a player turns over a penguin,
     then this player is allowed to turn a face-up card face-down. If the penguin is the first card turned up, no
     special action will take place. The walrus enables a player to block a face down card for the next player
     and hence the next player must choose another location. The player who turns over a crab card must
     immediately turn over another card. If that card does not fit, the player loses the current round. Finally,
     with the turtle the next player in the current round is skipped, i.e., the next player will not turn over a card
     and will not lose in the next step.
     
     */
    
};

#endif /* Rules_h */
