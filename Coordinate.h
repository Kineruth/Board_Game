#pragma once

class Coordinate{
    private:
        unsigned int x, y;  
    
    public:
        Coordinate(unsigned int x, unsigned int y);
        Coordinate& operator= (const Coordinate& c);
        unsigned int getX() const;
        unsigned int getY() const;
        ~Coordinate();
};