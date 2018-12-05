//
//  main.cpp
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-11-21.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
//#include "Rules.h"

int main() {
    std::string version;
    int number_of_players;
    std::vector<std::string> players;
    

    //sstd::cout << r << std::endl; --> fix compiler error; https://stackoverflow.com/questions/41750143/c-linker-error-after-overloading-an-operator
    
    std::cout << "Welcome to Memoarr! By Amro and Faizaan" << std::endl;
    
    std::cout << "Please select game version (Base/Expert): ";
    std::cin >> version;
    std::cout << std::endl;
    //validate input
    
    std::cout << "Please enter the number of players (2-4): ";
    std::cin >> number_of_players;
    std::cout << std::endl;
    //validate input
    
    for(int i = 0; i < number_of_players; ++i){
        std::string player_name;
        std::cout << "Please enter the name for Player " << i << ": ";
        std::cin >> player_name;
        //validate input
        players.push_back(player_name);
    }
    
    
    // game loop
}
