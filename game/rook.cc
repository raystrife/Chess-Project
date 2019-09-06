#include "rook.h"
#include "game.h"

using namespace std;

// constructor for Rook
Rook::Rook(int row, char col, char id, Game *game)
          : Piece(row, col, id, game) {

}


// destructor for Rook
Rook::~Rook() {
	setGame(NULL);
}


/********************* validMoves **********************
	Purpose: Return a single string of all valid moves.
*******************************************************/
string Rook::validMoves() {
	ostringstream ss;

	// Check Up.
	for (int i = row + 1; i <= 8; i++) {
		int theRow = game->rowBToA(i); // in array form
		int theCol = game->colBToA(col); // in array form

		if (id == 'r') {
			if (game->wPiece(theRow, theCol)) {
				ss << col << i << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << col << i << " ";
			}
		} else if (id == 'R') {
			if (game->bPiece(theRow, theCol)) {
				ss << col << i << " ";
				break;
			} else if (game->wPiece(theRow, theCol)) {
				break;
			} else {
				ss << col << i << " ";
			}
		}
	}

	// Check Down.
	for (int i = row - 1; i >= 1; i--) {
		int theRow = game->rowBToA(i); // in array form
		int theCol = game->colBToA(col); // in array form

		if (id == 'r') {
			if (game->wPiece(theRow, theCol)) {
				ss << col << i << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << col << i << " ";
			}
		} else if (id == 'R') {
			if (game->bPiece(theRow, theCol)) {
				ss << col << i << " ";
				break;
			} else if (game->wPiece(theRow, theCol)) {
				break;
			} else {
				ss << col << i << " ";
			}
		}
	}

	// Check Right.
	for (char i = col + 1; i <= 'h'; i++) {
		int theRow = game->rowBToA(row); // in array form
		int theCol = game->colBToA(i); // in array form

		if (id == 'r') {
			if (game->wPiece(theRow, theCol)) {
				ss << i << row << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << i << row << " ";
			}
		} else if (id == 'R') {
			if (game->bPiece(theRow, theCol)) {
				ss << i << row << " ";
				break;
			} else if (game->wPiece(theRow, theCol)) {
				break;
			} else {
				ss << i << row << " ";
			}
		}
	}

	// Check Left.
	for (char i = col - 1; i >= 'a'; i--) {
		int theRow = game->rowBToA(row); // in array form
		int theCol = game->colBToA(i); // in array form

		if (id == 'r') {
			if (game->wPiece(theRow, theCol)) {
				ss << i << row << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << i << row << " ";
			}
		} else if (id == 'R') {
			if (game->bPiece(theRow, theCol)) {
				ss << i << row << " ";
				break;
			} else if (game->wPiece(theRow, theCol)) {
				break;
			} else {
				ss << i << row << " ";
			}
		}
	}

	string result = ss.str();

	return result;
}
