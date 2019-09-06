#include "king.h"
#include "game.h"

using namespace std;

// constructor for King
King::King(int row, char col, char id, Game *game)
          : Piece(row, col, id, game) {

}


// destructor for King
King::~King() {
	setGame(NULL);
}


/********************* validMoves **********************
	Purpose: Return a single string of all valid moves.
*******************************************************/
string King::validMoves() {
	// Create a char variable to help with col output.
	char colOutput = ' ';

	ostringstream ss;

	// Check Up.
	if (row + 1 <= 8) {
		int theRow = game->rowBToA(row + 1); // in array form
		int theCol = game->colBToA(col); // in array form

		if (id == 'k') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << col << row + 1 << " ";
			}
		} else if (id == 'K') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << col << row + 1 << " ";
			}
		}
	}

	// Check Up-Right.
	if ((row + 1 <= 8) && (col + 1 <= 'h')) {
		int theRow = game->rowBToA(row + 1); // in array form
		int theCol = game->colBToA(col + 1); // in array form

		if (id == 'k') {
			if (!(game->bPiece(theRow, theCol))) {
				colOutput = col + 1;
				ss << colOutput << row + 1 << " ";
			}
		} else if (id == 'K') {
			if (!(game->wPiece(theRow, theCol))) {
				colOutput = col + 1;
				ss << colOutput << row + 1 << " ";
			}
		}
	}

	// Check Right.
	if (col + 1 <= 'h') {
		int theRow = game->rowBToA(row); // in array form
		int theCol = game->colBToA(col + 1); // in array form

		if (id == 'k') {
			if (!(game->bPiece(theRow, theCol))) {
				colOutput = col + 1;
				ss << colOutput << row << " ";
			}
		} else if (id == 'K') {
			if (!(game->wPiece(theRow, theCol))) {
				colOutput = col + 1;
				ss << colOutput << row << " ";
			}
		}
	}

	// Check Down-Right.
	if ((row - 1 >= 1) && (col + 1 <= 'h')) {
		int theRow = game->rowBToA(row - 1); // in array form
		int theCol = game->colBToA(col + 1); // in array form

		if (id == 'k') {
			if (!(game->bPiece(theRow, theCol))) {
				colOutput = col + 1;
				ss << colOutput << row - 1 << " ";
			}
		} else if (id == 'K') {
			if (!(game->wPiece(theRow, theCol))) {
				colOutput = col + 1;
				ss << colOutput << row - 1 << " ";
			}
		}
	}

	// Check Down.
	if (row - 1 >= 1) {
		int theRow = game->rowBToA(row - 1); // in array form
		int theCol = game->colBToA(col); // in array form

		if (id == 'k') {
			if (!(game->bPiece(theRow, theCol))) {
				ss << col << row - 1  << " ";
			}
		} else if (id == 'K') {
			if (!(game->wPiece(theRow, theCol))) {
				ss << col << row - 1 << " ";
			}
		}
	}

	// Check Down-Left.
	if ((row - 1 >= 1) && (col - 1 >= 'a')) {
		int theRow = game->rowBToA(row - 1); // in array form
		int theCol = game->colBToA(col - 1); // in array form

		if (id == 'k') {
			if (!(game->bPiece(theRow, theCol))) {
				colOutput = col - 1;
				ss << colOutput << row - 1 << " ";
			}
		} else if (id == 'K') {
			if (!(game->wPiece(theRow, theCol))) {
				colOutput = col - 1;
				ss << colOutput << row - 1 << " ";
			}
		}
	}

	// Check Left.
	if (col - 1 >= 'a') {
		int theRow = game->rowBToA(row); // in array form
		int theCol = game->colBToA(col - 1); // in array form

		if (id == 'k') {
			if (!(game->bPiece(theRow, theCol))) {
				colOutput = col - 1;
				ss << colOutput << row << " ";
			}
		} else if (id == 'K') {
			if (!(game->wPiece(theRow, theCol))) {
				colOutput = col - 1;
				ss << colOutput << row << " ";
			}
		}
	}

	// Check Up-Left.
	if ((row + 1 <= 8) && (col - 1 >= 'a')) {
		int theRow = game->rowBToA(row + 1); // in array form
		int theCol = game->colBToA(col - 1); // in array form

		if (id == 'k') {
			if (!(game->bPiece(theRow, theCol))) {
				colOutput = col - 1;
				ss << colOutput << row + 1 << " ";
			}
		} else if (id == 'K') {
			if (!(game->wPiece(theRow, theCol))) {
				colOutput = col - 1;
				ss << colOutput << row + 1 << " ";
			}
		}
	}

	string result = ss.str();

	return result;
}
