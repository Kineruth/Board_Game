#pragma once

#include <string>
#include "Coordinate.h"

using namespace std;

class IllegalCoordinateException {
  private:
    const Coordinate& c;
    
  public:
      IllegalCoordinateException(const Coordinate& c): c(c) { }
      
      string theCoordinate() const{
          return string(to_string(c.getX()) + "," + to_string(c.getY()));
      }  
};