#include "piece.h"

using namespace std;

// constructor for Piece
Piece::Piece(int row, char col, char id, Game *game)
            : row(row), col(col), id(id), game(game) {

}


// destructor for Piece
Piece::~Piece() {
	setGame(NULL);
}


/********************** getRow ************************
	Purpose: Return the row.
*******************************************************/
int Piece::getRow() const {
	return row;
}


/********************** getCol ************************
	Purpose: Return the col.
*******************************************************/
char Piece::getCol() const {
	return col;
}


/********************** getID *************************
	Purpose: Return the ID.
*******************************************************/
char Piece::getID() const {
	return id;
}


/********************** setGame *************************
	Purpose: Set the Game pointer.
*******************************************************/
void Piece::setGame(Game* theGame) {
	game = theGame;
}
