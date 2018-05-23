#pragma once
#include "DerivedChar.h"
#include "IllegalCoordinateException.h"

class Board{
    private:
        DerivedChar** board;
        int _size;
    
    public:
        Board(int _size);
        Board(const Board& b);
        int size() const;
        Board& operator=(const Board& b);
        Board& operator= (const char c);
        DerivedChar& operator[] (const Coordinate& c) const;
        friend ostream& operator<< (ostream& os, const Board& b);
        ~Board();
};
