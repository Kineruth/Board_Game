#include "Coordinate.h"

Coordinate::Coordinate(unsigned int x, unsigned int y) : x(x),y(y){}

Coordinate& Coordinate::operator= (const Coordinate& c){
  this->x = c.getX();
  this->y = c.getY();
  return *this;
}

unsigned int Coordinate::getX() const{
    return this->x;
}

unsigned int Coordinate::getY() const{
    return this->y;
}

Coordinate::~Coordinate() { }