**Date: 30/4/2018**  
**Last Edit: 10/5/2018**

Board Game  
===  

Assignment 6 in a C++ course  

Authors:
--
Dvir Barzilay  
Kineret Ruth Nahary  

**Introduction**
==

About the assignment:
-- 
Create a class called Board that represent the game tic-tac-toe.  
The class is built by inputing it the board's size N * N.  
Every square has to have only: '.' \ 'X' \ 'O' - the dot char represents an empty square.  
The class has to support the operators: output, =, [].  
The class has to deal with exceptions: 
inputing an illegal char or trying to exceed the board's limits throws an exception according to the case.  
    
**File list:**  
--  

```  
.: 
.gitignore 
Board.cpp  
Board.hpp  
DerivedChar.cpp  
DerivedChar.h    
Coordinate.cpp  
Coordinate.h    
README.md  
main.cpp  
IllegalCoordinateException.cpp  
IllegalCharException.cpp 
Symbol.h  
Makefile  
```  
Further look into the classes:     
--  
1. **main.cpp** - This class has some examples to run and check the code with it.  
2. **Board.hpp** - This class represents a board game of tic-tac-toe. Its fields are :   
*size* - The board's size N * N.   
*board* - The board game itself, build by a matrix of DerivedChar size N * N.         
3. **Board.cpp** - The implementation of Board.hpp.   
4. **Coordinate.hpp** - This class represent a specific place in the matrix - board. Its fields are : X,Y.  
5. **Coordinate.cpp** -  The implementation of Coordinate.hpp.  
6. **DerivedChar.hpp** - This class represent a square in the matrix - board. Its field is a char c.   
7. **DerivedChar.cpp** - The implementation of DerivedChar.hpp.   
8. **IllegalCoordinateException.cpp** - This class represents an exception thrown when illegal coordinate values are given.  
9. **IllegalCharException.cpp** - This class represents an exception thrown when an illegal char is given as an input.  
The llegal chars in the game: '.', 'X', 'O' .  
10. **Symbol.h** -  This class represents the llegal chars in the game.  

Compile Command:  
--  
To compile all the files we have the file "Makefile" - converts all to binary type "file.o" files.  
In order to compile by using the Makefile file - we run the command "make".  
All the binary files will be created, and an "a.out" file to run the program with it.  
