#include "TicTacToe.h"

/*
need to throw a Coordinate Exception for player 3 & 4: 
player 3 - throws illegal coordinate exception.
player 4 - throws string exception.
*/
void TicTacToe::play(Player& xPlayer, Player& oPlayer){
    
    xPlayer.setChar(Symbol::X);
    oPlayer.setChar(Symbol::O);
    _winner = &oPlayer;
    
    _board = Symbol::P; //reset board
    bool turn = true;
    int i, numOfSquares = _board.size()*_board.size();
    
    for(i = 0; i < numOfSquares && !gameOver(xPlayer, oPlayer); i++){
        if(turn){
            try{
                // _board[xPlayer.play(_board)] = xPlayer.getChar(); //need to check if it's a point
                Coordinate c = xPlayer.play(_board);
                _board[c] == Symbol::P ? _board[c] = xPlayer.getChar() : throw IllegalCoordinateException(c);
            } 
            catch(const IllegalCoordinateException ex){
                break;
            } 
            catch(const string& ex){
                break;
            }
            turn = false;
        }
        else{
            try{
               // _board[oPlayer.play(_board)] = oPlayer.getChar();
               Coordinate c = oPlayer.play(_board);
              _board[c] == Symbol::P ? _board[c] = oPlayer.getChar() : throw IllegalCoordinateException(c);
            }
            catch(const IllegalCoordinateException ex){
                _winner = &xPlayer;
                break;
            }   
            catch(const string& ex){
                _winner = &xPlayer;
                break;
            }
            turn = true;
        }
    }
}

bool TicTacToe::gameOver(Player& xPlayer, Player& oPlayer){
    
    unsigned int i, j;
    unsigned int size = _board.size();
    Symbol symb = _board[{0,size-1}];
    
    //left diagonal
    if(symb != Symbol::P){
        for(i = 1; i < size; i++){
            if(_board[{i, size-1-i}] != symb)
                break;
            if(i == size-1){
                if(symb == xPlayer.getChar())
                    _winner = &xPlayer;
                return true;
            }
        }
    }
    
    symb = _board[{0,0}];
    //right diagonal
    if(symb != Symbol::P){
        for(i = 1; i < size; i++){
            if(_board[{i, i}] != symb)
                break;
            if(i == size-1){
                if(symb == xPlayer.getChar())
                    _winner = &xPlayer;
                return true;
            }
        }
    }
    
    //columns
    for(j = 0; j<size; j++){
        symb = _board[{0,j}];
        if(symb != Symbol::P){
            for(i = 1; i<size; i++){
                if(_board[{i, j}] != symb)
                    break;
                if(i == size-1){
                    if(xPlayer.getChar() == symb)
                        _winner = &xPlayer;
                    return true;
                }
            }
        }
    }
    
    //rows
    for(i = 0; i<size; i++){
        symb = _board[{i,0}];
        if(symb != Symbol::P){
            for(j = 1; j<size; j++){
                if(_board[{i, j}] != symb)
                    break;
                if(j == size-1){
                    if(xPlayer.getChar() == symb)
                        _winner = &xPlayer;
                    return true;
                }
            }
        }
    }
    
    return false;
}
