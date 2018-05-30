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

string Board::draw(unsigned int pixels){
    static unsigned int file_id = 0;
    char* file_name;
    sprintf(file_name, "board number %d.ppm",file_id);
    
    ofstream imageFile(file_name, ios::out | ios::binary);
    
    imageFile << "P6" << endl << pixels <<" " << pixels << endl << 255 << endl;
    RGB image[pixels*pixels];
    drawOriginalBoard(image, pixels);
    drawBoard(image, pixels);
    
    //image processing
    imageFile.write(reinterpret_cast<char*>(&image), 3*pixels*pixels);
    imageFile.close(); 
}

void Board::drawOriginalBoard(RGB image[], unsigned int pixels){
    /* fill whole board with white */
    unsigned int i, j;
    for (i = 0; i < pixels; ++i)  {  // row
        for (j = 0; j < pixels; ++j) { // column
              image[i * pixels + j].red = 255;
                image[i * pixels + j].green = 255;
                image[i * pixels + j].blue = 255;
        }
    }
    /* draw y lines */
    for (i = 0; i < pixels; ++i)  {  // row
        for (j = 0; j < pixels; j+=(pixels/_size)) { // column
                image[i * pixels + j].red = 0;
                image[i * pixels + j].green = 0;
                image[i * pixels + j].blue = 0;
        }
    }
    /* draw x lines */
    for (i = 0; i < pixels; i+=(pixels/_size))  {  // row
        for (j = 0; j < pixels; ++j) { // column
                image[i * pixels + j].red = 0;
                image[i * pixels + j].green = 0;
                image[i * pixels + j].blue = 0;
        }
    }
}

void Board::drawBoard(RGB image[], unsigned int pixels){
    unsigned int i, j;
    for(i = 0; i < _size; i++){
        for(j = 0; j < _size; j++){
            if(board[i][j] == Symbol::X)
                drawX(image, pixels, i, j);
            else if(board[i][j] == Symbol::O)
                drawO(image, pixels, i, j);
        }
    }
}

void Board::drawX(RGB image[], unsigned int pixels, unsigned int index_i, unsigned int index_j){
    
    unsigned int i, k, vertex, row, column, jumps=(pixels/_size);
    
    row = index_i * jumps; //starting row of matrix
    column = index_j * jumps; //starting column of matrix
    
     for(k = 0; k < 300; k++){
        vertex = row * pixels + k + column;
        image[vertex].red = 0;
        image[vertex].green = 0;
        image[vertex].blue = 0;
        row++;
    }
    
    for(k = 0; k < 300; k++){
        vertex = row * pixels + k + column;
        image[vertex].red = 0;
        image[vertex].green = 0;
        image[vertex].blue = 0;
        row--;
    }
    
}

void Board::drawO(RGB image[], unsigned int pixels, unsigned int index_i, unsigned int index_j){

    unsigned int jumps=(pixels/_size), row, column, k, j, vertex;
    
    
    row = index_i * jumps + jumps * 0.25; 
    column = index_j * jumps + jumps * 0.25; 
    
    for(k = 0; k < (jumps/2); k++){
        for(j = 0; j < (jumps/2); j++){
            vertex = row * pixels + column + j;
            image[vertex].red = 205;
            image[vertex].green = 92;
            image[vertex].blue = 92;
        }
        row++;
    }
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
    string input;
    is >> input;
    
    int i, j;
    for(i = 0; i < input.length() && input[i] != '\n'; i++);
    
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