//
//  Board.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <stdio.h>
#include "Board.h"
#include "Letter.h"
#include "Number.h"

class Card;

bool Board::isExpert(){
    return _expert;
}

void Board::setDifficulty(bool b){
    _expert = b;
}

static std::string determineFirstCharForRow(int i){
    std::string firstChar = "  ";
    switch (i) {
        case 1: firstChar = "A "; break;
        case 6: firstChar = "B "; break;
        case 11: firstChar = "C "; break;
        case 16: firstChar = "D "; break;
        case 21: firstChar = "E "; break;
    }
    return firstChar;
}

bool Board::isCenter(int i){
    switch (i) {
        case 1: return true;
        case 6: return true;
        case 11: return true;
        case 16: return true;
        case 21: return true;
    }
    return false;
}

int rowInStringBoard(const Letter& _l){
    switch(_l){
        case A: return 1;
        case B: return 6;
        case C: return 11;
        case D: return 16;
        case E: return 21;
    }
    return -1;
}


int colInStringBoard(const Number& _n){
    switch(_n){
        case One: return 3;
        case Two: return 7;
        case Three: return 11;
        case Four: return 15;
        case Five: return 19;
    }
    return -1;
}


void Board::generateBoard(){
    if(!_expert){
    for(int i = 0; i < 25; ++i){
        std::string firstChar = determineFirstCharForRow(i);
        out_board[i] = firstChar + std::string(20, ' ');
    }
    
    for(int i = 0; i < 25; ++i){
        if(isCenter(i)){ //centre row
            modifyCardFromCenter(i, 3, 'z', 'z');
            modifyCardFromCenter(i, 7, 'z', 'z');
            if(i!=11){
                modifyCardFromCenter(i, 11, 'z', 'z');
            }
            modifyCardFromCenter(i, 15, 'z', 'z');
            modifyCardFromCenter(i, 19, 'z', 'z');
        }
    }
    out_board[25] = std::string(22, ' ');
    out_board[25][3] = '1';
    out_board[25][7] = '2';
    out_board[25][11] = '3';
    out_board[25][15] = '4';
    out_board[25][19] = '5';
    }
    
}


int Board::getRow(const Letter& _l){
    int row = -1;
    switch(_l){
        case A: row = 0; break;
        case B: row = 1; break;
        case C: row = 2; break;
        case D: row = 3; break;
        case E: row = 4; break;
    }
    return row;
}
int Board::getCol(const Number& _n){
    int col = -1;
    switch(_n){
        case One: col = 0; break;
        case Two: col = 1; break;
        case Three: col = 2; break;
        case Four: col = 3; break;
        case Five: col = 4; break;
    }
    return col;
}

void Board::validateInput(int row, int col){
    if(row > 4 || row < 0){
        throw std::out_of_range("Row out of range");
    }
    if(col > 4 || col < 0){
        throw std::out_of_range("Col out of range");
    }
}

void Board::turnAllFaceDown(){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            face_board[i][j] = false;
        }
    }
}

void Board::disableCardForTurn(const Letter& l , const Number& n){
    turns_disabled = 2;
    disabledPos[0] = l;
    disabledPos[1] = n;
}

int Board::getTurnsDisabled(){
    return turns_disabled;
}
void Board::decrementTurnsDisabled(){
    turns_disabled -=1;
}

int* Board::getDisabledPos(){
    return disabledPos;
}

void Board::enableCard(){
    disabledPos[0] = -1;
    disabledPos[1] = -1;
}


bool Board::isFaceUp(const Letter& _l, const Number& _n){
    int row = getRow(_l);
    int col = getCol(_n);
    validateInput(row, col); //throws exception if out of range
    return face_board[row][col]; //true on up false on not
}


bool Board::turnFaceUp(const Letter& _l, const Number& _n){
    int row = getRow(_l);
    int col = getCol(_n);
    validateInput(row, col); //throws exception if out of range

    if(!isFaceUp(_l, _n)){
        face_board[row][col] = true;
        modifyCardFromCenter(rowInStringBoard(_l), colInStringBoard(_n),'a', 'B'); //TEMP TESTER GET FROM CARD
    }
    return true;
}


bool Board::turnFaceDown(const Letter& _l, const Number& _n){
    int row = getRow(_l);
    int col = getCol(_n);

    validateInput(row, col); //throws exception if out of range

    if(isFaceUp(_l, _n)){
        face_board[row][col] = false;
        modifyCardFromCenter(rowInStringBoard(_l), colInStringBoard(_n),'z', 'z');
        
    }

    return false;
}


void Board::modifyCardFromCenter(int i, int j, char background, char center){
    for(int y = -1; y < 2; ++y){
        for(int x = -1; x < 2; ++x){
            if(x==0 && y == 0){
                out_board[i+y][j+x] = center;
            }else{
                out_board[i+y][j+x] = background;
            }
        }
    }
    
}



Card* Board::getCard(const Letter& _l, const Number& _n){
    int row = getRow(_l);
    int col = getCol(_n);

    validateInput(row, col); //throws exception if out of range
    return actual_board[row][col];
}

void Board::setCard(const Letter& _l, const Number& _n, Card* _c){
    int row = getRow(_l);
    int col = getCol(_n);
    validateInput(row, col); //throws exception if out of range
    actual_board[row][col] = _c;
}

void Board::reset(){
    for (int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            face_board[i][j] = false;
            
        }
    }



}

//Board::~Board(){
//    for(int i = 0; i < 5; i++){
//        for(int j = 0; j < 5; j++){
//            delete actual_board[i][j];
//        }
//    }
//}

