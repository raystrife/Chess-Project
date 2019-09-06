#include "empty.h"

using namespace std;

// constructor for Empty
Empty::Empty(int row, char col, char id, Game *game)
          : Piece(row, col, id, game) {
    Empty::setID();
}


// destructor for Empty
Empty::~Empty() {
	setGame(NULL);
}


void Empty::setID() {
    if (col == 'a' || col == 'c' || col == 'e' || col == 'g') {
        if ((row % 2) == 0) {
            id = ' ';
        } else {
            id = '_';
        }
    } else {
        if((row % 2) == 0) {
            id = '_';
        } else {
            id = ' ';
        }
    }
}


/********************* validMoves **********************
    Purpose: Return a single string of all valid moves.
*******************************************************/
string Empty::validMoves() {
	string result = "";
	return result;
}
