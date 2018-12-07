//
//  Number.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef Number_h
#define Number_h

enum Number { One, Two, Three, Four, Five };

inline Number intToNumber(int _i){
    Number s;
    switch(_i){
        case 0: s = One; break;
        case 1: s = Two; break;
        case 2: s = Three; break;
        case 3: s = Four; break;
        case 4: s = Five; break;
    }
    return s;
}

inline Number charToNumber(char _c){
    Number l;
    switch(_c){
        case '1': l = One; break;
        case '2': l = Two; break;
        case '3': l = Three; break;
        case '4': l = Four; break;
        case '5': l = Five; break;
    }
    return l;
}

#endif /* Number_h */
