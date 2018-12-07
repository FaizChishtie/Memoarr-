//
//  Rules.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <stdio.h>
#include "Rules.h"
#include "Player.h"


bool Rules::isValid(Game& game){
    return game.getPreviousCard() == game.getCurrentCard();

}
bool Rules::gameOver(Game& game){
    return game.getRound() == 6;
}


bool Rules::roundOver(Game& game){
    int count = 0;
    for(int i = 0; i < game.getNumPlayers(); ++i){
        Side s = getSideAtIndex(i);
        Player& p = game.getPlayer(s);
        if(p.isActive()){
            count++;
        }
    }
    return count==1; //if 1 then change round
}


Side Rules::getSideAtIndex(int i){
    Side s;
    switch(i){
        case 0: s = Left; break;
        case 1: s = Top; break;
        case 2: s = Right; break;
        case 3: s = Bottom; break;
    }
    return s;
}


Player& Rules::getNextPlayer(Game& game){
    int num_players = game.getNumPlayers();
    if(num_players == (turn-1)){
        turn = 0;
    }else{
        ++turn;
    }
    return game.getPlayer(getSideAtIndex(turn));
}
