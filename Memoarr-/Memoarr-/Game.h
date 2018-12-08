//
//  Game.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef Game_h
#define Game_h
#include "Board.h"
#include "Player.h"
#include <cstdlib>
#include <iostream>
#include <vector>


class Game{
private:
    Board *board;
    int round = 0;
    std::vector<Player> players;
    Card *previousCard;
    Card *currentCard;
    
public:
    void enableCard();
    void decrementDisabledTurnsRemaining();
    int getDisabledTurnsRemaining();
    int getRound() const;
    void nextRound();
    void addPlayer( const Player& );
    Player& getPlayer(Side);
    Card* getPreviousCard();
    Card* getCurrentCard();
    void setCurrentCard( Card*);
    Card* getCard( const Letter&, const Number& );
    void setCard( const Letter&, const Number&, Card* );
    int getNumPlayers();
    Player& returnFirstValidPlayer();
    Player& getWinner();
    ~Game();
    bool getUniqueAbility(Card* card, int x, int y, int cardNum, Board& board);
    friend inline  std::ostream& operator<<(std::ostream&, const Game&);
};

inline std::ostream& operator<<(std::ostream& _os, const Game& game){
    _os << *game.board;
    for(int i = 0; i < game.players.size(); ++i){
        _os << game.players[i];
    }
    return _os;
}


#endif /* Game_h */
