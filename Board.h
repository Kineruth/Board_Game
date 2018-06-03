#pragma once
#include "DerivedChar.h"
#include "IllegalCoordinateException.h"
#include "RGB.h"

#include <fstream>
#include <string.h>
#include <chrono>

using namespace std;
using namespace chrono;

class Board{
    private:
        DerivedChar** board;
        int _size;
    
    public:
        Board();
        Board(int size);
        Board(const Board& b);
        int size() const;
        string draw(unsigned int pixels);
        void drawOriginalBoard(RGB image[], unsigned int pixels);
        void drawBoard(RGB image[], unsigned int pixels);
        void drawX(RGB image[], unsigned int pixels, unsigned int index_i, unsigned int index_j);
        void drawO(RGB image[], unsigned int pixels, unsigned int index_i, unsigned int index_j);
        
        Board& operator= (const char c);
        Board& operator= (const Board& b);
        DerivedChar& operator[] (const Coordinate& c) const;
        friend ostream& operator<< (ostream& os, const Board& b);
        friend istream& operator>> (istream& is, Board& b);
        ~Board();
};
