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


//bool Rules::roundOver(const Game& game){
//    for(int i = 0; i < )
//    Player& p = game.getPlayer();
//    //iterate through players and get if active
//    return p.isActive();
//
////}
//
//Player& Rules::getNextPlayer(const Game& game) const{
//
//    
//}
