#include "pawn.h"
#include "game.h"

using namespace std;

// constructor for Pawn
Pawn::Pawn(int row, char col, char id, Game *game)
          : Piece(row, col, id, game) {

}


// destructor for Pawn
Pawn::~Pawn() {
	setGame(NULL);
}


/********************* validMoves **********************
	Purpose: Return a single string of all valid moves.
*******************************************************/
string Pawn::validMoves() {
	// Create a char variable to help with col output.
	char colOutput = ' ';

	ostringstream ss;

	if (id == 'P') {
		if (row == 2) {
			// Check one square ahead.
			int rowForward = game->rowBToA(row + 1); // in array form
			int colForward = game->colBToA(col); // in array form
			char theID = (game->getPiece(rowForward, colForward)->getID());

			if (theID == ' ' || theID == '_') {
				ss << col << row + 1 << " ";

				// Check two square ahead.
				rowForward = game->rowBToA(row + 2); // in array form
				colForward = game->colBToA(col); // in array form
				theID = (game->getPiece(rowForward, colForward)->getID());

				if (theID == ' ' || theID == '_') {
					ss << col << row + 2 << " ";
				}
			}

			// Check the right diagonal forward.
			rowForward = game->rowBToA(row + 1); // in array form
			colForward = game->colBToA(col + 1); // in array form
			if ((colForward <= 7) && (colForward >= 0)) {
				if (game->bPiece(rowForward, colForward)) {
					colOutput = col + 1;
					ss << colOutput << row + 1 << " ";
				}
			}

			// Check the left diagonal forward.
			rowForward = game->rowBToA(row + 1); // in array form
			colForward = game->colBToA(col - 1); // in array form
			if ((colForward >= 0) && (colForward <= 7)) {
				if (game->bPiece(rowForward, colForward)) {
					colOutput = col - 1;
					ss << colOutput << row + 1 << " ";
				}
			}

		} else {
			if (row + 1 > 8) { // Not needed if there is promotion.
				return "";
			}

			// Check one square ahead.
			int rowForward = game->rowBToA(row + 1); // in array form
			int colForward = game->colBToA(col); // in array form
			char theID = (game->getPiece(rowForward, colForward)->getID());
			if (theID == ' ' || theID == '_') {
				ss << col << row + 1 << " ";
			}

			// Check the right diagonal forward.
			rowForward = game->rowBToA(row + 1); // in array form
			colForward = game->colBToA(col + 1); // in array form
			if ((colForward <= 7) && (colForward >= 0)) {
				if (game->bPiece(rowForward, colForward)) {
					colOutput = col + 1;
					ss << colOutput << row + 1 << " ";
				}
			}

			// Check the left diagonal forward.
			rowForward = game->rowBToA(row + 1); // in array form
			colForward = game->colBToA(col - 1); // in array form
			if ((colForward >= 0) && (colForward <= 7)) {
				if (game->bPiece(rowForward, colForward)) {
					colOutput = col - 1;
					ss << colOutput << row + 1 << " ";
				}
			}
		}

	} else if (id == 'p') {
		if (row == 7) {
			// Check one square ahead.
			int rowForward = game->rowBToA(row - 1); // in array form
			int colForward = game->colBToA(col); // in array form
			char theID = (game->getPiece(rowForward, colForward)->getID());

			if (theID == ' ' || theID == '_') {
				ss << col << row - 1 << " ";

				// Check two square ahead.
				rowForward = game->rowBToA(row - 2); // in array form
				colForward = game->colBToA(col); // in array form
				theID = (game->getPiece(rowForward, colForward)->getID());

				if (theID == ' ' || theID == '_') {
					ss << col << row - 2 << " ";
				}
			}

			// Check the right diagonal forward.
			rowForward = game->rowBToA(row - 1); // in array form
			colForward = game->colBToA(col - 1); // in array form
			if ((colForward >= 0) && (colForward <= 7)) {
				if (game->bPiece(rowForward, colForward)) {
					colOutput = col - 1;
					ss << colOutput << row - 1 << " ";
				}
			}

			// Check the left diagonal forward.
			rowForward = game->rowBToA(row - 1); // in array form
			colForward = game->colBToA(col + 1); // in array form
			if ((colForward >= 0) && (colForward <= 7)) {
				if (game->bPiece(rowForward, colForward)) {
					colOutput = col + 1;
					ss << colOutput << row - 1 << " ";
				}
			}

		} else {
			if (row - 1 < 1) { // Not needed if there is promotion.
				return "";
			}

			// Check one square ahead.
			int rowForward = game->rowBToA(row - 1); // in array form
			int colForward = game->colBToA(col); // in array form
			char theID = (game->getPiece(rowForward, colForward)->getID());
			if (theID == ' ' || theID == '_') {
				ss << col << row - 1 << " ";
			}

			// Check the right diagonal forward.
			rowForward = game->rowBToA(row - 1); // in array form
			colForward = game->colBToA(col - 1); // in array form
			if ((colForward >= 0) && (colForward <= 7)) {
				if (game->wPiece(rowForward, colForward)) {
					colOutput = col - 1;
					ss << colOutput << row - 1 << " ";
				}
			}

			// Check the left diagonal forward.
			rowForward = game->rowBToA(row - 1); // in array form
			colForward = game->colBToA(col + 1); // in array form
			if ((colForward <= 7) && (colForward >= 0)) {
				if (game->wPiece(rowForward, colForward)) {
					colOutput = col + 1;
					ss << colOutput << row - 1 << " ";
				}
			}
		}
	}

	string result = ss.str();

	return result;
}
