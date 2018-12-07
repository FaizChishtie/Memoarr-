//
//  Player.h
//  Memoarr-
//
//  Created by Amro Ahmed on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include <iostream>
#include <string>
#include <fstream>

class Reward;

using namespace std;

enum Side{
    Left,
    Top,
    Right,
    Bottom
};


class Player{
    string name;
    Side boardSide;
    int rubiesNum=0;
    bool active = false;
    bool end = false;
    
public:
    
    Player(string _name, Side _side): name{_name} , boardSide{_side} {}
    Player(const Player& oS);
    Player& operator= (const Player& oS);
    
    friend inline ostream& operator<<(ostream& oS, const Player& p);
    
    string getName() const;
    void setActive(bool);
    bool isActive();
    int getNRubies() const;
    void addReward(const Reward&);
    void setDisplayMode(bool endOfGame);
    Side getSide();
    void setSide(Side);
    
};

inline ostream& operator<<(ostream& oS, const Player& p){
    std::string out_boardSide;
    
    switch(p.boardSide){
        case Left: out_boardSide = "Left"; break;
        case Top: out_boardSide = "Top"; break;
        case Right: out_boardSide = "Right"; break;
        case Bottom: out_boardSide = "Bottom"; break;
    }
    
    if(p.end) oS << p.name << ":" << p.boardSide << "(Active)";
    else oS << "Player: " << p.name << " on " << out_boardSide << " side has " << p.rubiesNum << " rubies";
    
    return oS;
}

#endif /* Player_h */
