#include "Player.h"

class Champion : public Player {
    
    public:
    
        const string name() const override { return "Dvir Barzilay & Kineret Ruth Nahary"; }
        const Coordinate play(const Board& board) override;
};