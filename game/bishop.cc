#include "bishop.h"
#include "game.h"

using namespace std;

// constructor for Bishop
Bishop::Bishop(int row, char col, char id, Game *game)
          : Piece(row, col, id, game) {

}


// destructor for Bishop
Bishop::~Bishop() {
	setGame(NULL);
}


/********************* validMoves **********************
	Purpose: Return a single string of all valid moves.
*******************************************************/
string Bishop::validMoves() {
	ostringstream ss;

	int newRow;
	char newCol;

	// Check Up-Right.
	newRow = row + 1;
	newCol = col + 1;
	while ((newRow <= 8) && (newCol <= 'h')) {
		int theRow = game->rowBToA(newRow); // in array form
		int theCol = game->colBToA(newCol); // in array form

		if (id == 'b') {
			if (game->wPiece(theRow, theCol)) {
				ss << newCol << newRow << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << newCol << newRow << " ";
				newRow++;
				newCol++;
			}
		} else if (id == 'B') {
			if (game->bPiece(theRow, theCol)) {
				ss << newCol << newRow << " ";
				break;
			} else if (game->wPiece(theRow, theCol)) {
				break;
			} else {
				ss << newCol << newRow << " ";
				newRow++;
				newCol++;
			}
		}
	}

	// Check Up-Left.
	newRow = row + 1;
	newCol = col - 1;
	while ((newRow <= 8) && (newCol >= 'a')) {
		int theRow = game->rowBToA(newRow); // in array form
		int theCol = game->colBToA(newCol); // in array form

		if (id == 'b') {
			if (game->wPiece(theRow, theCol)) {
				ss << newCol << newRow << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << newCol << newRow << " ";
				newRow++;
				newCol--;
			}
		} else if (id == 'B') {
			if (game->bPiece(theRow, theCol)) {
				ss << newCol << newRow << " ";
				break;
			} else if (game->wPiece(theRow, theCol)) {
				break;
			} else {
				ss << newCol << newRow << " ";
				newRow++;
				newCol--;
			}
		}
	}

	// Check Down-Right.
	newRow = row - 1;
	newCol = col + 1;
	while ((newRow >= 1) && (newCol <= 'h')) {
		int theRow = game->rowBToA(newRow); // in array form
		int theCol = game->colBToA(newCol); // in array form

		if (id == 'b') {
			if (game->wPiece(theRow, theCol)) {
				ss << newCol << newRow << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << newCol << newRow << " ";
				newRow--;
				newCol++;
			}
		} else if (id == 'B') {
			if (game->bPiece(theRow, theCol)) {
				ss << newCol << newRow << " ";
				break;
			} else if (game->wPiece(theRow, theCol)) {
				break;
			} else {
				ss << newCol << newRow << " ";
				newRow--;
				newCol++;
			}
		}
	}

	// Check Down-Left.
	newRow = row - 1;
	newCol = col - 1;
	while ((newRow >= 1) && (newCol >= 'a')) {
		int theRow = game->rowBToA(newRow); // in array form
		int theCol = game->colBToA(newCol); // in array form

		if (id == 'b') {
			if (game->wPiece(theRow, theCol)) {
				ss << newCol << newRow << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << newCol << newRow << " ";
				newRow--;
				newCol--;
			}
		} else if (id == 'B') {
			if (game->bPiece(theRow, theCol)) {
				ss << newCol << newRow << " ";
				break;
			} else if (game->wPiece(theRow, theCol)) {
				break;
			} else {
				ss << newCol << newRow << " ";
				newRow--;
				newCol--;
			}
		}
	}

	string result = ss.str();

	return result;
}
