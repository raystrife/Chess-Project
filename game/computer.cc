#include "computer.h"
#include <time.h>

using namespace std;

const int GRID_SIZE = 8;

// constructor for Computer
Computer::Computer(char colour, char type, Game *game, string level)
              : Player(colour, type, game), level(level) {

}


// destructor for Computer
Computer::~Computer() {
	game = NULL;
}


// Not for Computer
bool Computer::makeMove(string, string, int, int, int, int) {
	return false;
}


/********************* makeMove ***********************
	Purpose: Make a move based on the level.
*******************************************************/
void Computer::makeMove() {
	// Count the total number of valid moves.
	string possibleMoves[1028] = {""};
	string correspondPiece[1028]  = {""};
	int counter = 0;

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (colour == 'B') {
				if (game->bPiece(i, j)) {
					if (game->numMoves(i, j) > 0) {
						istringstream ss((game->getPiece(i, j))->validMoves());
						while (ss >> possibleMoves[counter]) {

							stringstream build;

							build << (game->getPiece(i, j))->getCol()
					      		  << (game->getPiece(i, j))->getRow();

							correspondPiece[counter] = build.str();

							counter++;
						}
					}
				}
			} else if (colour == 'W') {
				if (game->wPiece(i, j)) {
					if (game->numMoves(i, j) > 0) {
						istringstream ss((game->getPiece(i, j))->validMoves());
						while (ss >> possibleMoves[counter]) {

							stringstream build;

							build << (game->getPiece(i, j))->getCol()
					      		  << (game->getPiece(i, j))->getRow();

							correspondPiece[counter] = build.str();

							counter++;
						}
					}
				}
			}
		}
	}

	// Create variables to store all the values required
    // to move a piece.
	int targetRow, targetCol;
	int newRow, newCol;
	char theID;
	string oldPos, newPos;

	if (level == "1") {

		while (true) {
			// Generate a random move index.
			srand(time(NULL));
			int randomMove = rand() % counter;

			oldPos = correspondPiece[randomMove];
			newPos = possibleMoves[randomMove];

			if (assignScore(oldPos, newPos) >= 0) {
				targetRow = game->rowProcessor(oldPos);
				targetCol = game->colProcessor(oldPos);
				newRow = game->rowProcessor(newPos);
				newCol = game->colProcessor(newPos);
				theID = (game->getPiece(targetRow, targetCol))->getID();
				break;
			}
		}

		game->setPiece(targetRow, targetCol, 'e');
		game->setPiece(newRow, newCol, theID);
	} else {

		int currentScore = -1;

		for (int i = 0; i < counter; i++) {
			int newScore = assignScore(correspondPiece[i], possibleMoves[i]);
			if (newScore > currentScore) {
				currentScore = newScore;
				oldPos = correspondPiece[i];
				newPos = possibleMoves[i];

				targetRow = game->rowProcessor(oldPos);
				targetCol = game->colProcessor(oldPos);
				newRow = game->rowProcessor(newPos);
				newCol = game->colProcessor(newPos);
				theID = (game->getPiece(targetRow, targetCol))->getID();

			} else if (newScore == currentScore) {
				srand(time(NULL));
				int change = rand() % 2;

				if (change == 0) {
					oldPos = correspondPiece[i];
					newPos = possibleMoves[i];

					targetRow = game->rowProcessor(oldPos);
					targetCol = game->colProcessor(oldPos);
					newRow = game->rowProcessor(newPos);
					newCol = game->colProcessor(newPos);
					theID = (game->getPiece(targetRow, targetCol))->getID();
				}
			}
		}

		game->setPiece(targetRow, targetCol, 'e');
		game->setPiece(newRow, newCol, theID);
	}
}


/******************* assignScore **********************
	Purpose: Assign a score to a move.
*******************************************************/
int Computer::assignScore(string oldPos, string newPos) {
	// Okay to assume the move is valid
	// but still need to check the king is not in check.

	int score = 0;

	// Store the piece information at oldPos
	int oldRow = game->rowProcessor(oldPos);
	int oldCol = game->colProcessor(oldPos);
	char pieceAtOldPos = (game->getPiece(oldRow, oldCol))->getID();

	// Store the piece information at newPos
	int newRow = game->rowProcessor(newPos);
	int newCol = game->colProcessor(newPos);
	char pieceAtNewPos = (game->getPiece(newRow, newCol))->getID();

	if (level == "1") {

		// Make the move to see what happens
		game->setPiece(oldRow, oldCol, 'e');
		game->setPiece(newRow, newCol, pieceAtOldPos);

		if (colour == 'W') {
			if (game->wInCheck()) {
				score = -1;
			} else if (game->bInCheck()) {
				score = 1;
			}
		} else {
			if (game->bInCheck()) {
				score = -1;
			} else if (game->wInCheck()) {
				score = 1;
			}
		}

		// Put the piece back to the original place
		game->setPiece(oldRow, oldCol, pieceAtOldPos);
		game->setPiece(newRow, newCol, pieceAtNewPos);

	} else if (level == "2") {

		if (colour == 'W') {
			if (game->bPiece(newRow, newCol)) {
				score++;
			}
		} else {
			if (game->wPiece(newRow, newCol)) {
				score++;
			}
		}

		// Make the move to see what happens
		game->setPiece(oldRow, oldCol, 'e');
		game->setPiece(newRow, newCol, pieceAtOldPos);

		if (colour == 'W') {
			if (game->wInCheck()) {
				score = score - 100;
			} else if (game->bInCheck()) {
				score = score + 5;
			}
		} else {
			if (game->bInCheck()) {
				score = score - 100;
			} else if (game->wInCheck()) {
				score = score + 5;
			}
		}

		// Put the piece back to the original place.
		game->setPiece(oldRow, oldCol, pieceAtOldPos);
		game->setPiece(newRow, newCol, pieceAtNewPos);
	} else {
		if (colour == 'W') {
			if (game->bPiece(newRow, newCol)) {
				score++;
			}
		} else {
			if (game->wPiece(newRow, newCol)) {
				score++;
			}
		}

		// Make the move to see what happens
		game->setPiece(oldRow, oldCol, 'e');
		game->setPiece(newRow, newCol, pieceAtOldPos);

		if (colour == 'W') {
			if (game->wInCheck()) {
				score = score - 100;
			} else if (game->bInCheck()) {
				score = score + 5;
			}
		} else {
			if (game->bInCheck()) {
				score = score - 100;
			} else if (game->wInCheck()) {
				score = score + 5;
			}
		}

		// Put the piece back to the original place.
		game->setPiece(oldRow, oldCol, pieceAtOldPos);
		game->setPiece(newRow, newCol, pieceAtNewPos);

		// Check if the piece is threatened.
		if (colour == 'W') {
			string possibleMoves[1028] = {""};

			int counter = 0;

			for (int i = 0; i < GRID_SIZE; i++) {
				for (int j = 0; j < GRID_SIZE; j++) {
					if (game->bPiece(i, j)) {
						istringstream ss(game->getPiece(i, j)->validMoves());
						while(ss >> possibleMoves[counter]) {
							counter++;
						}
					}
				}
			}

			int k = 0;
			while(k < counter) {
				if (oldPos == possibleMoves[k]) {
					score = score + 10;
					break;
				}
				k++;
			}
		}
	}

	return score;
}
