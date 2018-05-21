#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
    
    unsigned int i, j, size = board.size();
    
    if(board[{0,size-1}] == Symbol::P)
        return Coordinate{0,size-1};
    
    if(board[{size-1,0}] == Symbol::P)
        return Coordinate{size-1,0};
    
    for(i = 1; i < size-1; i++){
        if(board[{i,size-1-i}] == Symbol::P)
            return Coordinate{i,size-1-i};
    }
    
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(board[{i,j}] == Symbol::P)
                return Coordinate{i, j};
        }
    }
    
    //Will never happen 
    //Full board!!! game over already;
}