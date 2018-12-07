//
//  Letter.h
//  Memoarr-
//
//  Created by Faizaan Chishtie on 2018-12-05.
//  Copyright © 2018 Faizaan Chishtie. All rights reserved.
//

#ifndef Letter_h
#define Letter_h

enum Letter { A, B, C, D, E };

inline Letter intToLetter(int _i){
    Letter s;
    switch(_i){
        case 0: s = A; break;
        case 1: s = B; break;
        case 2: s = C; break;
        case 3: s = D; break;
        case 4: s = E; break;
    }
    return s;
}

inline Letter charToLetter(char _c){
    Letter l;
    switch(_c){
        case 'A': l = A; break;
        case 'B': l = B; break;
        case 'C': l = C; break;
        case 'D': l = D; break;
        case 'E': l = E; break;
    }
    return l;
}

#endif /* Letter_h */
