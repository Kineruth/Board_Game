#pragma once
#include "Board.h"

class Player {
        
    public:
        Symbol myChar;
        
        inline char getChar() const { return myChar; }
        inline void setChar(const Symbol symb) { myChar = symb; }
        virtual const string name() const { return ""; };
        virtual const Coordinate play(const Board& board) { };
};