//
//  Board.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-21.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <string>
#include "Card.h"
#include <iostream>

#ifndef Board_h
#define Board_h
enum Number { One, Two, Three, Four, Five };
enum Letter { A, B, C, D, E };


class Board{
private:
    std::string out_board[19];
    Card* actual_board[5][5];
    bool face_board[5][5];
public:
    bool isFaceUp(const Letter&, const Number&);
    bool turnFaceUp(const Letter&, const Number&);
    bool turnFaceDown(const Letter&, const Number&);
    Card* getCard(const Letter&, const Number&);
    void setCard(const Letter&, const Number&, Card*);
    void reset();
    int getRow(const Letter&);
    int getCol(const Number&);
    void validateInput(int row, int col);
    friend std::ostream& operator<<(const std::ostream& os, const Board& b);
    std::string* getOutBoard();
    
};

#endif /* Board_h */
