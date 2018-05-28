#include "Board.h"

Board::Board(int size) : _size(size){
    if(_size > 0){
        this->board = new DerivedChar*[_size];
        int i;
        for(i = 0; i < _size; i++)
            this->board[i] = new DerivedChar[_size];
    }
}

Board::Board(const Board& b){
    this->_size = b._size;
    this->board = new DerivedChar*[this->_size];
    int i, j;
    for(i = 0; i < this->_size; i++){
        this->board[i] = new DerivedChar[this->_size];
        for(j = 0; j < this->_size; j++){
            this->board[i][j] = b.board[i][j];
        }
    }
}

int Board::size() const{
    return this->_size;
}

Board& Board::operator= (const char c){
    DerivedChar dc(c);
    int i, j;
    for(i = 0; i < this->_size; i++)
        for(j = 0; j < this->_size; j++)
            this->board[i][j] = dc;
    return *this;
}

Board& Board::operator= (const Board& b){
    this->~Board();
    this->_size = b._size;
    this->board = new DerivedChar*[this->_size];
    int i, j;
    for(i = 0; i < this->_size; i++){
        this->board[i] = new DerivedChar[this->_size];
        for(j = 0; j < this->_size; j++){
            this->board[i][j] = b.board[i][j];
        }
    }
    return *this;
}

DerivedChar& Board::operator[] (const Coordinate& c) const{
    if(c.getX() < _size && c.getX() >= 0 && c.getY() < _size && c.getY() >= 0)
        return board[c.getX()][c.getY()]; //&& board[c.getX()][c.getY()] == Symbol::P
    throw IllegalCoordinateException(c);
}

ostream& operator<< (ostream& os, const Board& b){
    int i, j;
    for(i = 0; i < b._size; i++){
        for(j = 0; j < b._size; j++)
            os << b.board[i][j];
        os << endl;
    }
    return os;
}

istream& operator>> (istream& is, Board& b){
    char* input;
    is >> input;
    
    int i, j;
    for(i = 0; i < strlen(input) && input[i] != '\n'; i++);
    
    Board tmp(i);
    int size = tmp.size(), ptr = 0;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            tmp.board[i][j] = input[ptr++];
        }
        ptr++;
    }
    
    b = tmp;
    return is;
}

Board::~Board(){
    int i;
    for(i = 0; i< this->_size; i++)
    	delete[] board[i]; //This part was allocated with new[], so we use delete[]
    delete[] board;
}