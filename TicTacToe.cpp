#include "TicTacToe.h"

void TicTacToe::play(const Player& xPlayer, const Player& oPlayer){
    bool turn;
    if(oPlayer==Symbol.O){
        _winner = oPlayer;
        turn = true;
    }else{
        _winner = xPlayer;
        turn = false;
    }
    
    while(!gameOver(xPlayer, oPlayer)){
        if(turn){
            *_board[xPlayer.play()] = xPlayer.getChar();
            turn = false;
        }else{
            *_board[oPlayer.play()] = oPlayer.getChar();
            turn = true;
        }
    }
}

bool TicTacToe::gameOver(const Player& xPlayer, const Player& oPlayer){
    int i, j;
    int size = _board->size();
    
    //left diagonal
    if((Symbol symb = *_board[{0,size-1}]) != Symbol.P){
        for(i = 1; i < size; i++){
            if(*_board[{i, size-1-i}] != symb)
                break;
            if(i == size-1){
                if(symb == xPlayer.getChar())
                    _winner = xPlayer;
                return true;
            }
        }
    }
    
    //right diagonal
    if((Symbol symb = *_board[{0,0}]) != Symbol.P){
        for(i = 1; i < size; i++){
            if(*_board[{i, i}] != symb)
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
        if((Symbol symb = *_board[{0,j}]) != Symbol.P){
            for(i = 1; i<size; i++){
                if(*_board[{i, j}] != symb)
                    break;
                if(i == size-1){
                    if(xPlayer.getChar == symb)
                        _winner = xPlayer;
                    return true;
                }
            }
        }
    }
    
    //rows
    for(i = 0; i<size; i++){
        if((Symbol symb = *_board[{i,0}]) != Symbol.P){
            for(j = 1; j<size; j++){
                if(*_board[{i, j}] != symb)
                    break;
                if(j == size-1){
                    if(xPlayer.getChar == symb)
                        _winner = xPlayer;
                    return true;
                }
            }
        }
    }
    
    return false;
}
