#include "Player.h"
#include "DummyPlayers.h"

class TicTacToe {
    
    private:
    
        Board* _board;
        Player* _winner;
        bool gameOver(const Player& xPlayer, const Player& oPlayer);
        
    public:
    
        // TicTacToe(int size) : _board(size), _winner(0) {}
        TicTacToe(int size);
        void play(Player& xPlayer, Player& oPlayer);
        inline const Player& winner() const { return *_winner; }
        inline Board& board() const { return *_board; }
};