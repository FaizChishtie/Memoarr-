//
//  Board.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-21.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <string>
#include "Card.h"
#include "Number.h"
#include "Letter.h"
#include <iostream>

#ifndef Board_h
#define Board_h


class Board{
private:
    std::string out_board[26];
    Card* actual_board[5][5];
    bool face_board[5][5];
public:
    void defaultCardToBoardFromCenter(int i, int j);
    void generateBoard();
    bool isFaceUp(const Letter&, const Number&);
    bool turnFaceUp(const Letter&, const Number&);
    bool turnFaceDown(const Letter&, const Number&);
    Card* getCard(const Letter&, const Number&);
    void setCard(const Letter&, const Number&, Card*);
    void reset();
    int getRow(const Letter&);
    int getCol(const Number&);
    void validateInput(int row, int col);
    friend inline std::ostream& operator<<(std::ostream&, const Board&);
    std::string* getOutBoard();
    //~Board();
    
};

inline std::ostream& operator<<(std::ostream& _os, const Board& b){
    for(int i = 0; i < 26; ++i){
        _os << b.out_board[i] << std::endl;
    }
    return _os;
}
#endif /* Board_h */
