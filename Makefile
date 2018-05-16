CCX=g++ -std=c++11


a.out: DummyPlayers.o Board.o Coordinate.o DerivedChar.o IllegalCharException.o IllegalCoordinateException.o
		$(CCX) main.cpp *.o

DummyPlayers.o: DummyPlayers.cpp DummyPlayers.h
		$(CCX) -c DummyPlayers.cpp
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Coordinate.o: Coordinate.cpp Coordinate.h
		$(CCX) -c Coordinate.cpp
		
DerivedChar.o: DerivedChar.cpp DerivedChar.h
		$(CCX) -c DerivedChar.cpp

# Symbol.o: Symbol.h
# 		$(CCX) -c Symbol.h

IllegalCharException.o: IllegalCharException.cpp
		$(CCX) -c IllegalCharException.cpp

IllegalCoordinateException.o: IllegalCoordinateException.cpp
		$(CCX) -c IllegalCoordinateException.cpp
		
Clean:
		rm *.o a.out