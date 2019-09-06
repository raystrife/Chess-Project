#include "queen.h"
#include "game.h"

using namespace std;

// constructor for Queen
Queen::Queen(int row, char col, char id, Game *game)
          : Piece(row, col, id, game) {

}


// destructor for Queen
Queen::~Queen() {
	setGame(NULL);
}


/********************* validMoves **********************
	Purpose: Return a single string of all valid moves.
*******************************************************/
string Queen::validMoves() {
	ostringstream ss;

	// Check Up.
	for (int i = row + 1; i <= 8; i++) {
		int theRow = game->rowBToA(i); // in array form
		int theCol = game->colBToA(col); // in array form

		if (id == 'q') {
			if (game->wPiece(theRow, theCol)) {
				ss << col << i << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << col << i << " ";
			}
		} else if (id == 'Q') {
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

		if (id == 'q') {
			if (game->wPiece(theRow, theCol)) {
				ss << col << i << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << col << i << " ";
			}
		} else if (id == 'Q') {
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

		if (id == 'q') {
			if (game->wPiece(theRow, theCol)) {
				ss << i << row << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << i << row << " ";
			}
		} else if (id == 'Q') {
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

		if (id == 'q') {
			if (game->wPiece(theRow, theCol)) {
				ss << i << row << " ";
				break;
			} else if (game->bPiece(theRow, theCol)) {
				break;
			} else {
				ss << i << row << " ";
			}
		} else if (id == 'Q') {
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

	int newRow;
	char newCol;

	// Check Up-Right.
	newRow = row + 1;
	newCol = col + 1;
	while ((newRow <= 8) && (newCol <= 'h')) {
		int theRow = game->rowBToA(newRow); // in array form
		int theCol = game->colBToA(newCol); // in array form

		if (id == 'q') {
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
		} else if (id == 'Q') {
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

		if (id == 'q') {
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
		} else if (id == 'Q') {
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

		if (id == 'q') {
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
		} else if (id == 'Q') {
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

		if (id == 'q') {
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
		} else if (id == 'Q') {
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
