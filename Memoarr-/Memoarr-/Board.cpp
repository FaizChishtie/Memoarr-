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

void Board::generateBoard(){
    for(int i = 0; i < 25; ++i){
        std::string firstChar = determineFirstCharForRow(i);
        out_board[i] = firstChar + std::string(20, ' ');
        if(firstChar != "  "){ //centre row
            defaultCardToBoardFromCenter(i, 3);
            defaultCardToBoardFromCenter(i, 7);
            if(firstChar != "C "){
            defaultCardToBoardFromCenter(i, 11);
            }
            defaultCardToBoardFromCenter(i, 15);
            defaultCardToBoardFromCenter(i, 19);
        }
    }
    
    out_board[25] = std::string(22, ' ');
    out_board[25][3] = '1';
    out_board[25][7] = '2';
    out_board[25][11] = '3';
    out_board[25][15] = '4';
    out_board[25][19] = '5';
}

void Board::defaultCardToBoardFromCenter(int i, int j){
    for(int y = -1; y < 2; ++y){
        for(int x = -1; x < 2; ++x){
            out_board[i+y][j+x] = 'z';
        }
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
        //SHOULD MODIFY STRING ARRAY TO PRINT CARD !! INSERT HERE
    }
    return true;
}


bool Board::turnFaceDown(const Letter& _l, const Number& _n){
    int row = getRow(_l);
    int col = getCol(_n);

    validateInput(row, col); //throws exception if out of range

    if(!isFaceUp(_l, _n)){
        face_board[row][col] = false;
        //SHOULD MODIFY STRING ARRAY TO PRINT CARD !! INSERT HERE
    }

    return false;
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

