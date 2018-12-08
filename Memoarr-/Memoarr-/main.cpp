//
//  main.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-21.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Rules.h"
#include "Player.h"
#include "CardDeck.h"
#include "RewardDeck.h"

enum Side;

void printErrorMessage(){
    std::cout << "Invalid input, please try again." << std::endl;
}

Side getSideForInt(int _i){
    Side s;
    switch(_i){
        case 0: s = Left; break;
        case 1: s = Top; break;
        case 2: s = Right; break;
        case 3: s = Bottom; break;
    }
    return s;
}

void clear() {
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
}

void pauseProgram(){
    std::string c;
    std::cout << "Press 'c' to continue... ";
    std::cin >> c;
}

int getNumPlayers(){
    int number_of_players;
    std::cout << "Please enter the number of players (2-4): ";
    std::cin >> number_of_players;
    std::cout << std::endl;
    if(number_of_players > 4 || number_of_players < 2){
        printErrorMessage();
        getNumPlayers();
    }
    return number_of_players;
}

std::string getCardRevealed(int m){
    std::string cardRevealed;
    std::cout << "Enter card #" << m+1 << " to be revealed: ";
    std::cin >> cardRevealed;
    std::cout << std::endl;
    return cardRevealed;
}


int main() {
    srand(time(NULL));
    std::string version;
    int number_of_players;
    std::vector<std::string> player_names;
    std::vector<Player> players;
    
    std::cout << "Welcome to Memoarr! By Amro and Faizaan" << std::endl;
    while(true){
        std::cout << "Please select game version [Base/Expert is (B/E)]: ";
        std::cin >> version;
        std::cout << std::endl;
    
        if(version != "B" && version != "E"){
            printErrorMessage();
        } else{
            break;
        }
    }
    //validate input
    
    number_of_players = getNumPlayers();
    
    
    for(int i = 0; i < number_of_players; ++i){
        std::string player_name;
        std::cout << "Please enter the name for Player " << i << ": ";
        std::cin >> player_name;
        //validate input
        player_names.push_back(player_name);
    }
    
    // create players, game, rules, cards, board
    
    // CREATE GAME HERE
    Game game;
    
    for(int i = 0; i < number_of_players; i++){
        Player p(player_names[i], getSideForInt(i));
        game.addPlayer(p);
        
    }
    Board board;
    board.enableCard(); //set disabled card to -1 -1 
    Rules rules;
    CardDeck cardDeck =  CardDeck::make_CardDeck();
    RewardDeck rewardDeck = RewardDeck::make_RewardDeck();
    Reward* rewardAtRound = rewardDeck.returnReward();
    board.getCardsForGame(cardDeck);
    
    if(version == "B"){
        board.setDifficulty(false); // not expert
    }
    if(version == "E"){
        board.setDifficulty(true);
    }
    
    board.generateBoard();
    clear();
    clear();
    std::cout <<"************* STARTING GAME ************* "<< std::endl;
    std::cout <<"************* DIFFICULTY (" << version  << ") ************* "<< std::endl;
    while (!rules.gameOver(game)){
        //update all cards face down
        for(int i = 0; i < number_of_players; i++){ // update all players as active
            Player& p = game.getPlayer(getSideForInt(i));
            p.setActive(true);
        }
        pauseProgram();
        clear();
        if(!board.isExpert()){
        std::cout <<"************* EMPTY BOARD BEFORE REVEAL ************* "<< std::endl;
        board.generateBoard();
        std::cout << board << std::endl;
        std::cout <<"************* REVEALING BOARD FOR PLAYERS ************* "<< std::endl;
        pauseProgram();
        for(int i = 0; i < number_of_players; i++){ // show cards and rotate
            clear();
            Player& p = rules.getNextPlayer(game);
            for(int j = 0; j < 3; ++j){
                int _x = rand()%4;
                int _y = rand()%4;
                while(_x == 2 && _y == 2){
                    _x = rand()%4;
                    _y = rand()%4;
                }
                Letter l = intToLetter(_x);
                Number n = intToNumber(_y);
                
                board.turnFaceUp(l, n); // 3 cards face up
            }
            std::cout << board << std::endl;
            std::cout << p.getName() << "'s Reveal" << std::endl;
            board.turnAllFaceDown();
            board.generateBoard();
            pauseProgram();
        }
        }
        clear();
        clear();
        std::cout <<"************* BEGIN ROUND " << game.getRound() + 1 << " *************" << std::endl;
        while(!rules.roundOver(game)){
            
            Player& p = rules.getNextPlayer(game);
            std::cout << p.getName() << "'s Turn" << std::endl;
            pauseProgram();
            Letter selectionL[2];
            Number selectionN[2];
            for(int m = 0; m < 2; ++m){
                if(!board.isExpert()){
                    clear();
                    std::cout << board << std::endl;
                }
                std::string cardRevealed = getCardRevealed(m);
                //validate input
                char c_letter = cardRevealed[0];
                char c_number = cardRevealed[1];
                Letter letter = charToLetter(c_letter);
                Number number = charToNumber(c_number);
                while(board.isFaceUp(letter, number)){
                    std::cout << "Selection is already face up! Please try again" << std::endl;
                    cardRevealed = getCardRevealed(m);
                    char c_letter = cardRevealed[0];
                    char c_number = cardRevealed[1];
                    letter = charToLetter(c_letter);
                    number = charToNumber(c_number);
                }
                while (letter == board.getDisabledPos()[0] && number == board.getDisabledPos()[1]){
                    std::cout << "Selection is already disabled! Please try again" << std::endl;
                    cardRevealed = getCardRevealed(m);
                    char c_letter = cardRevealed[0];
                    char c_number = cardRevealed[1];
                    letter = charToLetter(c_letter);
                    number = charToNumber(c_number);
                }
                if(board.isExpert()){
                    bool t = game.getUniqueAbility(board.getCard(letter,number), letter, number, m, board);
                    if(t){
                        rules.nextTurn();
                    }
                }
                selectionL[m] = letter;
                selectionN[m] = number;
                board.turnFaceUp(letter, number);
                Card* card = board.getCard(letter, number);
                game.setCurrentCard(card);
                if(!board.isExpert()){
                    clear();
                    std::cout << board << std::endl;
                }
            }
            pauseProgram();
            if (!rules.isValid(game)){
                board.turnFaceDown(selectionL[0], selectionN[0]);
                board.turnFaceDown(selectionL[1], selectionN[1]);
                clear();
                clear();
                clear();
                p.setActive(false);
                std::cout << "************ " << p.getName() << " ELIMINATED FROM THIS ROUND! ************" << std::endl;
                pauseProgram();
            }
            clear();
            clear();
            if(!board.isExpert()){
                std::cout << board << std::endl;
                std::cout << std::endl;
            }else{
                board.printAllValidCards();
            }
        }
        clear();
        clear();
        
        Player& winnerOfRound = game.returnFirstValidPlayer();
        winnerOfRound.addReward(*(rewardAtRound++));
        std::cout <<"Winner of round " << game.getRound() + 1 << " is: " << winnerOfRound.getName() << std::endl;
        std::cout <<"************* END ROUND " << game.getRound() + 1 << " *************" << std::endl;
        
        game.nextRound();
    }
    clear();
    clear();
    std::cout <<  "************ ROUNDS ARE OVER ************"  << std::endl;
    pauseProgram();
    clear();
    clear();
    clear();
    Player& winner = game.getWinner();
    std::cout << "Winner: " << winner.getName() << " with " << winner.getNRubies() << " rubies!" << std::endl;
    std::cout <<"*******************************************************************" << std::endl;
    std::cout <<"*                         !   GAME OVER   !                       *" << std::endl;
    std::cout <<"*                    Thanks for playing MEMOARR!                  *" << std::endl;
    std::cout <<"*                     Written by Faiz and Amro                    *" << std::endl;
    std::cout <<"*******************************************************************" << std::endl;
    
}





