CCX = g++ -std=c++11


a.out:  TicTacToe.o Champion.o DummyPlayers.o Board.o Coordinate.o DerivedChar.o
		$(CCX) main.cpp *.o

TicTacToe.o: TicTacToe.cpp TicTacToe.h
		$(CCX) -c TicTacToe.cpp

Champion.o: Champion.cpp Champion.h
		$(CCX) -c Champion.cpp

DummyPlayers.o: DummyPlayers.cpp DummyPlayers.h
		$(CCX) -c DummyPlayers.cpp
		
Board.o: Board.cpp Board.h
		$(CCX) -c Board.cpp
		
Coordinate.o: Coordinate.cpp Coordinate.h
		$(CCX) -c Coordinate.cpp
		
DerivedChar.o: DerivedChar.cpp DerivedChar.h
		$(CCX) -c DerivedChar.cpp

Clean:
		rm *.o a.out