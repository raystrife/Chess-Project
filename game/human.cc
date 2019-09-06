#include "human.h"

using namespace std;

// constructor for Human
Human::Human(char colour, char type, Game *game)
              : Player(colour, type, game) {

}


// destructor for Human
Human::~Human() {
	game = NULL;
}


/********************* makeMove ***********************
	Purpose: Check if the move if valid.
			 If yes, make the move and return true.
			 If no, just return false.
*******************************************************/
bool Human::makeMove(string oldPos, string newPos, int oldRow, int oldCol, int newRow, int newCol) {
	// Check the user is not trying to move the opponents' pieces.
	if (colour == 'B') {
		if (game->wPiece(oldRow, oldCol)) {
			return false;
		}
	} else if (colour == 'W') {
		if (game->bPiece(oldRow, oldCol)) {
			return false;
		}
	}

	string possibleMoves[64] = {""};
	istringstream ss((game->getPiece(oldRow, oldCol))->validMoves());

	int counter = 0;
	while(ss >> possibleMoves[counter]) {
		counter++;
	}

	for (int i = 0; i < counter; i++) {
		if (possibleMoves[i] == newPos) {
			char theIDAtOldPos = (game->getPiece(oldRow, oldCol))->getID();
			char theIDAtNewPos = (game->getPiece(newRow, newCol))->getID();
			game->setPiece(oldRow, oldCol, 'e');
			game->setPiece(newRow, newCol, theIDAtOldPos);

			// Check the player is not putting their king in check.
			if (colour == 'B') {
				if (game->bInCheck()) {
					// Put the piece back to the original place.
					game->setPiece(oldRow, oldCol, theIDAtOldPos);
					game->setPiece(newRow, newCol, theIDAtNewPos);
					return false;
				}
			} else if (colour == 'W') {
				if (game->wInCheck()) {
					// Put the piece back to the original place.
					game->setPiece(oldRow, oldCol, theIDAtOldPos);
					game->setPiece(newRow, newCol, theIDAtNewPos);
					return false;
				}
			}

			return true;
		}
	}

	return false;
}


// Not for Human
void Human::makeMove() {

}
