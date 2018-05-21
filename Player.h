#pragma once
#include "Board.h"

class Player {
    
    public:
    
        char myChar;
        
        inline char getChar() const { return myChar; }
        virtual const string name() const;
        virtual const Coordinate play(const Board& board);
};