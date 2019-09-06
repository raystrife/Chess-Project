#include "knight.h"
#include "game.h"

using namespace std;

// constructor for Knight
Knight::Knight(int row, char col, char id, Game *game)
          : Piece(row, col, id, game) {

}


// destructor for Knight
Knight::~Knight() {
	setGame(NULL);
}


/********************* validMoves **********************
	Purpose: Return a single string of all valid moves.
*******************************************************/
string Knight::validMoves() {
	ostringstream ss;

	int cpRow = row;
	char cpCol = col;

	// Check for xo
	//           xx
	//           ox <- starting
	cpRow+=2;
	cpCol+=1;
	if (cpRow <= 8 && cpCol <= 'h') {
		int theRow = game->rowBToA(cpRow); // in array form
		int theCol = game->colBToA(cpCol); // in array form

		if (id == 'n') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		} else if (id == 'N') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		}
	}

	// Check for ox
	//           xx
	//           xo <- starting
	cpCol = col;
	cpCol-=1;
	if (cpRow <= 8 && cpCol >= 'a') {
		int theRow = game->rowBToA(cpRow); // in array form
		int theCol = game->colBToA(cpCol); // in array form

		if (id == 'n') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		} else if (id == 'N') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		}
	}

	// Check for xo <- starting
	//           xx
	//           ox
	cpRow = row;
	cpRow-=2;
	if (cpRow >= 1 && cpCol >= 'a') {
		int theRow = game->rowBToA(cpRow); // in array form
		int theCol = game->colBToA(cpCol); // in array form

		if (id == 'n') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		} else if (id == 'N') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		}
	}

	// Check for ox <- starting
	//           xx
	//           xo
	cpCol = col;
	cpCol+=1;
	if (cpRow >= 1 && cpCol <= 'h') {
		int theRow = game->rowBToA(cpRow); // in array form
		int theCol = game->colBToA(cpCol); // in array form

		if (id == 'n') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		} else if (id == 'N') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		}
	}

	// Check for xxo
	//           oxx <- starting
	cpRow = row;
	cpRow+=1;
	cpCol = col;
	cpCol+=2;
	if (cpRow <= 8 && cpCol <= 'h') {
		int theRow = game->rowBToA(cpRow); // in array form
		int theCol = game->colBToA(cpCol); // in array form

		if (id == 'n') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		} else if (id == 'N') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		}
	}

	// Check for oxx
	//           xxo <- starting
	cpCol = col;
	cpCol-=2;
	if (cpRow <= 8 && cpCol >= 'a') {
		int theRow = game->rowBToA(cpRow); // in array form
		int theCol = game->colBToA(cpCol); // in array form

		if (id == 'n') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		} else if (id == 'N') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		}
	}

	// Check for xxo <- starting
	//           oxx
	cpRow = row;
	cpRow-=1;
	if (cpRow >= 1 && cpCol >= 'a') {
		int theRow = game->rowBToA(cpRow); // in array form
		int theCol = game->colBToA(cpCol); // in array form

		if (id == 'n') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		} else if (id == 'N') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		}
	}

	// Check for oxx <- starting
	//           xxo
	cpCol = col;
	cpCol+=2;
	if (cpRow >= 1 && cpCol <= 'h') {
		int theRow = game->rowBToA(cpRow); // in array form
		int theCol = game->colBToA(cpCol); // in array form

		if (id == 'n') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		} else if (id == 'N') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << cpCol << cpRow << " ";
			}
		}
	}

	string result = ss.str();

	return result;
}
