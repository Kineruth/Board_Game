#include "Player.h"

class TicTacToe {
    
    private:
    
        Board _board;
        Player _winner;
        bool gameOver(const Player& xPlayer, const Player& oPlayer);
        
    public:
    
        TicTacToe(int size) : _board(size) {}
        //TicTacToe(int size);
        void play(Player& xPlayer, Player& oPlayer);
        inline const Player& winner() const { return _winner; }
        inline const Board& board() const { return _board; }
};