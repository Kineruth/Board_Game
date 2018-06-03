#include "Board.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
	Board board;
	cin >> board;
	string filename = board.draw(800);
	// cout << filename << endl;
}