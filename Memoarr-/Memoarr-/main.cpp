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
#include <vector>
#include "Rules.h"
#include "Player.h"

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

int getNumPlayers(){
    int number_of_players;
    std::cout << "Please enter the number of players (2-4): ";
    std::cin >> number_of_players;
    std::cout << std::endl;
//    if(!std::cin.fail()){ CHECK IF NOT INT INPUTTED @TODO
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//        printErrorMessage();
//        std::cout << "Please enter the number of players (2-4): ";
//        std::cin >> number_of_players;
//        std::cout << std::endl;
    if(number_of_players > 4 || number_of_players < 2){
        printErrorMessage();
        getNumPlayers();
    }
    return number_of_players;
}

int main() {
    std::string version;
    int number_of_players;
    std::vector<std::string> player_names;
    std::vector<Player> players;
    

    //sstd::cout << r << std::endl; --> fix compiler error; https://stackoverflow.com/questions/41750143/c-linker-error-after-overloading-an-operator
    
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
    Game g;
    
    Board b;
    b.generateBoard();
    std::cout << b << std::endl;
    for(int i = 0; i < number_of_players; i++){
        Player p(player_names[i], getSideForInt(i));
        g.addPlayer(p);
        
    }
    
    // game loop
}



