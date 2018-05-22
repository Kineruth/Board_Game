#include "TicTacToe.h"


void TicTacToe::play(Player& xPlayer, Player& oPlayer){
    
    oPlayer.setChar(Symbol::O);
    xPlayer.setChar(Symbol::X);
    _winner = oPlayer;
    
    _board = Symbol::P; //reset board
    bool turn = true;
    
    while(!gameOver(xPlayer, oPlayer)){
        if(turn){
            try{
                _board[xPlayer.play(_board)] = xPlayer.getChar();
            } 
            catch(const IllegalCoordinateException ex){
                break;
            }    
            turn = false;
        }
        else{
            try{
                _board[oPlayer.play(_board)] = oPlayer.getChar();
            }
            catch(const IllegalCoordinateException ex){
                _winner = xPlayer;
                break;
            }    
            turn = true;
        }
    }
}

bool TicTacToe::gameOver(const Player& xPlayer, const Player& oPlayer){
    
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
                    _winner = xPlayer;
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
                    _winner = xPlayer;
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
                        _winner = xPlayer;
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
                        _winner = xPlayer;
                    return true;
                }
            }
        }
    }
    
    return false;
}
