//
//  Player.h
//  Memoarr-
//
//  Created by Amro Ahmed on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef Player_h
#define Player_h
#include "Reward.h"
#include <iostream>
#include <string>

using namespace std;

enum Side{
    Left,
    Top,
    Right,
    Bottom,
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
    string getName() const;
    void setActive(bool);
    bool isActive();
    int getNRubies() const;
    void addReward(const Reward&);
    void setDisplayMode(bool endOfGame);
    Side getSlide();
    void setSide(Side);
    friend inline ostream& operator<<(ostream& oS, const Player& p);
    
};

inline ostream& operator<<(ostream& oS, const Player& p){

    if(p.end) oS << p.name << ":" << p.boardSide << "(Active)";
    else oS << p.name << ":" << p.boardSide << p.rubiesNum << " rubies";

    return oS;
}

#endif /* Player_h */
