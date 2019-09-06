#include "game.h"

using namespace std;

const int GRID_SIZE = 8;

// constructor for Game
Game::Game() : theGrid(NULL), turn('W'), bWin(0), wWin(0),
               notification(NULL) {

}


// destructor for Game
Game::~Game() {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			delete theGrid[i][j];
		}
	}

	delete [] theGrid;
}


string Game::getPieceByID(char id) {
	ostringstream ss;

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (theGrid[i][j]->getID() == id) {
				ss << theGrid[i][j]->getCol() << theGrid[i][j]->getRow();
				break;
			}
		}
	}

	string result = ss.str();
	return result;
}


/******************* rowProcessor *********************
	Purpose: Process the user input to the correct row.
*******************************************************/
int Game::rowProcessor(string i) {
	if (i.substr(1, 1) == "8") {
		return 0;
	} else if (i.substr(1, 1) == "7") {
		return 1;
	} else if (i.substr(1, 1) == "6") {
		return 2;
	} else if (i.substr(1, 1) == "5") {
		return 3;
	} else if (i.substr(1, 1) == "4") {
		return 4;
	} else if (i.substr(1, 1) == "3") {
		return 5;
	} else if (i.substr(1, 1) == "2") {
		return 6;
	} else if (i.substr(1, 1) == "1") {
		return 7;
	} else {
		return -1;
	}
}


/******************* colProcessor *********************
	Purpose: Process the user input to the correct col.
*******************************************************/
int Game::colProcessor(string i) {
	if (i.substr(0, 1) == "a") {
		return 0;
	} else if (i.substr(0, 1) == "b") {
		return 1;
	} else if (i.substr(0, 1) == "c") {
		return 2;
	} else if (i.substr(0, 1) == "d") {
		return 3;
	} else if (i.substr(0, 1) == "e") {
		return 4;
	} else if (i.substr(0, 1) == "f") {
		return 5;
	} else if (i.substr(0, 1) == "g") {
		return 6;
	} else if (i.substr(0, 1) == "h") {
		return 7;
	} else {
		return -1;
	}
}


/********************** rowBToA ***********************
	Purpose: Process the user input to the correct row.
*******************************************************/
int Game::rowBToA(int row) {
	// Similar operation of Controller::rowProcessor
	if (row == 8) {
		return 0;
	} else if (row == 7) {
		return 1;
	} else if (row == 6) {
		return 2;
	} else if (row == 5) {
		return 3;
	} else if (row == 4) {
		return 4;
	} else if (row == 3) {
		return 5;
	} else if (row == 2) {
		return 6;
	} else if (row == 1) {
		return 7;
	} else {
		return -1;
	}
}


/********************** colBToA ***********************
	Purpose: Process the user input to the correct col.
*******************************************************/
int Game::colBToA(char col) {
	// Similar operation of Controller::colProcessor
	if (col == 'a') {
		return 0;
	} else if (col == 'b') {
		return 1;
	} else if (col == 'c') {
		return 2;
	} else if (col == 'd') {
		return 3;
	} else if (col == 'e') {
		return 4;
	} else if (col == 'f') {
		return 5;
	} else if (col == 'g') {
		return 6;
	} else if (col == 'h') {
		return 7;
	} else {
		return -1;
	}
}


/********************** rowAToB ***********************
	Purpose: Process the user input to the correct row.
*******************************************************/
int Game::rowAToB(int row) {
	// Reverse operation of Controller::rowProcessor
	if (row == 0) {
		return 8;
	} else if (row == 1) {
		return 7;
	} else if (row == 2) {
		return 6;
	} else if (row == 3) {
		return 5;
	} else if (row == 4) {
		return 4;
	} else if (row == 5) {
		return 3;
	} else if (row == 6) {
		return 2;
	} else if (row == 7) {
		return 1;
	} else {
		return -1;
	}
}


/********************** colAToB ***********************
	Purpose: Process the user input to the correct col.
*******************************************************/
char Game::colAToB(int col) {
	// Reverse operation of Controller::colProcessor
	if (col == 0) {
		return 'a';
	} else if (col == 1) {
		return 'b';
	} else if (col == 2) {
		return 'c';
	} else if (col == 3) {
		return 'd';
	} else if (col == 4) {
		return 'e';
	} else if (col == 5) {
		return 'f';
	} else if (col == 6) {
		return 'g';
	} else if (col == 7) {
		return 'h';
	} else {
		return -1;
	}
}


/********************** getPiece **********************
	Purpose: Return the piece at a specific square.
*******************************************************/
Piece* Game::getPiece(int row, int col) const {
	return theGrid[row][col];
}


/********************** setPiece **********************
	Purpose: Set the piece at a specific square.
*******************************************************/
void Game::setPiece(int row, int col, char id) {
	// The col must be converted into Array form.
	if (theGrid[row][col]) {
		delete theGrid[row][col];
	}

	int r = rowAToB(row);
	char c = colAToB(col);

	if (id == 'K') {
		theGrid[row][col] = new King(r, c, id, this);
	} else if (id == 'k') {
		theGrid[row][col] = new King(r, c, id, this);
	} else if (id == 'Q') {
		theGrid[row][col] = new Queen(r, c, id, this);
	} else if (id == 'q') {
		theGrid[row][col] = new Queen(r, c, id, this);
	} else if (id == 'R') {
		theGrid[row][col] = new Rook(r, c, id, this);
	} else if (id == 'r') {
		theGrid[row][col] = new Rook(r, c, id, this);
	} else if (id == 'N') {
		theGrid[row][col] = new Knight(r, c, id, this);
	} else if (id == 'n') {
		theGrid[row][col] = new Knight(r, c, id, this);
	} else if (id == 'B') {
		theGrid[row][col] = new Bishop(r, c, id, this);
	} else if (id == 'b') {
		theGrid[row][col] = new Bishop(r, c, id, this);
	} else if (id == 'P') {
		theGrid[row][col] = new Pawn(r, c, id, this);
	} else if (id == 'p') {
		theGrid[row][col] = new Pawn(r, c, id, this);
	} else if (id == 'e' || id == '_' || id == ' ') {
		theGrid[row][col] = new Empty(r, c, id, this);
	}

	// Notify the controller to change the view.
	notification->notify(row, col, theGrid[row][col]->getID());
}


/********************** getTurn ***********************
	Purpose: Return the turn.
*******************************************************/
char Game::getTurn() const {
	return turn;
}


/********************** getWWin ***********************
	Purpose: Return the number of white wins.
*******************************************************/
double Game::getWWin() const {
	return wWin;
}


/********************** getBWin ***********************
	Purpose: Return the number of black wins.
*******************************************************/
double Game::getBWin() const {
	return bWin;
}


/********************** setTurn ***********************
	Purpose: Set the turn.
*******************************************************/
void Game::setTurn(char theTurn) {
	turn = theTurn;
}


/*********************** init *************************
	Purpose: Initialize the board to its starting state.
*******************************************************/
void Game::init(GameNotification *gameNotification) {
	// Delete theGrid if it exists.
	if(theGrid) {
		for (int i = 0; i < GRID_SIZE; i++) {
			for (int j = 0; j < GRID_SIZE; j++) {
				delete theGrid[i][j];
			}
		}

		delete [] theGrid;
	}

	notification = gameNotification;
	theGrid = new Piece**[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++) {
		theGrid[i] = new Piece*[GRID_SIZE];
	}

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			theGrid[i][j] = NULL;
		}
	}

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (i == 0) {
				if (j == 0 || j == 7) {
					setPiece(i, j, 'r');
				} else if (j == 1 || j == 6) {
					setPiece(i, j, 'n');
				} else if (j == 2 || j == 5) {
					setPiece(i, j, 'b');
				} else if (j == 3) {
					setPiece(i, j, 'q');
				} else {
					setPiece(i, j, 'k');
				}
			} else if (i == 1) {
				setPiece(i, j, 'p');
			} else if (i == 6) {
				setPiece(i, j, 'P');
			} else if (i == 7) {
				if (j == 0 || j == 7) {
					setPiece(i, j, 'R');
				} else if (j == 1 || j == 6) {
					setPiece(i, j, 'N');
				} else if (j == 2 || j == 5) {
					setPiece(i, j, 'B');
				} else if (j == 3) {
					setPiece(i, j, 'Q');
				} else {
					setPiece(i, j, 'K');
				}
			} else if (i == 2) {
				setPiece(i, j, 'e');
			} else if (i == 3) {
				setPiece(i, j, 'e');
			} else if (i == 4) {
				setPiece(i, j, 'e');
			} else if (i == 5) {
				setPiece(i, j, 'e');
			}
		}
	}
}


/********************** setWWin ***********************
	Purpose: Set the number of white wins.
*******************************************************/
void Game::setWWin(int w) {
	wWin = w;
}


/********************** setBWin ***********************
	Purpose: Set the number of black wins.
*******************************************************/
void Game::setBWin(int w) {
	bWin = w;
}


/******************** validBoard *********************
	Purpose: Check the setip of the board is valid.
*******************************************************/
bool Game::validBoard() {
	int numWKing = 0, numWQueen = 0, numWPawn = 0,
	    numWRook = 0, numWKnight = 0, numWBishop = 0;
	int numBKing = 0, numBQueen = 0, numBPawn = 0,
	    numBRook = 0, numBKnight = 0, numBBishop = 0;

	// Count all pieces.
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (i == 0 || i == 7) {
				if (theGrid[i][j]->getID() == 'p' ||
					theGrid[i][j]->getID() == 'P') {
					return false;
				}
			}

			if (theGrid[i][j]->getID() == 'k') {
				numBKing++;
			} else if (theGrid[i][j]->getID() == 'K') {
				numWKing++;
			} else if (theGrid[i][j]->getID() == 'q') {
				numBQueen++;
			} else if (theGrid[i][j]->getID() == 'Q') {
				numWQueen++;
			} else if (theGrid[i][j]->getID() == 'r') {
				numBRook++;
			} else if (theGrid[i][j]->getID() == 'R') {
				numWRook++;
			} else if (theGrid[i][j]->getID() == 'n') {
				numBKnight++;
			} else if (theGrid[i][j]->getID() == 'N') {
				numWKnight++;
			} else if (theGrid[i][j]->getID() == 'b') {
				numBBishop++;
			} else if (theGrid[i][j]->getID() == 'B') {
				numWBishop++;
			} else if (theGrid[i][j]->getID() == 'p') {
				numBPawn++;
			} else if (theGrid[i][j]->getID() == 'P') {
				numWPawn++;
			}
		}
	}

	if (numWKing == 1 && numWQueen <= 1 && numWPawn <= 8 &&
		numWRook <= 2 && numWKnight <= 2 && numWBishop <= 2 &&
		numBKing == 1 && numBQueen <= 1 && numBPawn <= 8 &&
		numBRook <= 2 && numBKnight <= 2 && numBBishop <= 2 &&
		!wInCheck() && !bInCheck()) {
		return true;
	} else {
		return false;
	}
}


/*********************** wPiece ***********************
	Purpose: Check if a piece belongs to the white side.
*******************************************************/
bool Game::wPiece(int row, char col) {
	// This function takes in the board form of the coordinates.
	char id = theGrid[rowBToA(row)][rowBToA(col)]->getID();

	if (id == 'K' || id == 'Q' || id == 'B' ||
		id == 'R' || id == 'N' || id == 'P') {
		return true;
	} else {
		return false;
	}
}


/*********************** bPiece ***********************
	Purpose: Check if a piece belongs to the black side.
*******************************************************/
bool Game::bPiece(int row, char col) {
	// This function takes in the board form of the coordinates.
	char id = theGrid[rowBToA(row)][rowBToA(col)]->getID();

	if (id == 'k' || id == 'q' || id == 'b' ||
		id == 'r' || id == 'n' || id == 'p') {
		return true;
	} else {
		return false;
	}
}


/*********************** wPiece ***********************
	Purpose: Check if a piece belongs to the white side.
*******************************************************/
bool Game::wPiece(int row, int col) {
	// This function takes in the array form of the coordinates.
	char id = theGrid[row][col]->getID();

	if (id == 'K' || id == 'Q' || id == 'B' ||
		id == 'R' || id == 'N' || id == 'P') {
		return true;
	} else {
		return false;
	}
}


/*********************** bPiece ***********************
	Purpose: Check if a piece belongs to the black side.
*******************************************************/
bool Game::bPiece(int row, int col) {
	// This function takes in the array form of the coordinates.
	char id = theGrid[row][col]->getID();

	if (id == 'k' || id == 'q' || id == 'b' ||
		id == 'r' || id == 'n' || id == 'p') {
		return true;
	} else {
		return false;
	}
}


/********************** wInCheck **********************
	Purpose: Check if the white king is in check.
*******************************************************/
bool Game::wInCheck() {
	string possibleMoves[1024] = {""};
	int counter = 0;

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (bPiece(i, j)) {
				istringstream ss(theGrid[i][j]->validMoves());
				while(ss >> possibleMoves[counter]) {
					counter++;
				}
			}
		}
	}

	int k = 0;
	while(k < counter) {
		if (getPieceByID('K') == possibleMoves[k]) {
			return true;
		}
		k++;
	}

	return false;
}


/********************** bInCheck **********************
	Purpose: Check if the black king is in check.
*******************************************************/
bool Game::bInCheck() {
	string possibleMoves[1024] = {""};
	int counter = 0;

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (wPiece(i, j)) {
				istringstream ss(theGrid[i][j]->validMoves());
				while(ss >> possibleMoves[counter]) {
					counter++;
				}
			}
		}
	}

	int k = 0;
	while(k < counter) {
		if (getPieceByID('k') == possibleMoves[k]) {
			return true;
		}
		k++;
	}

	return false;
}


/******************** wInCheckmate ********************
	Purpose: Check if the white king is in checkmate.
*******************************************************/
bool Game::wInCheckmate() {
	if (wInCheck()) {

		string wKingPossibleMoves[64] = {""};
		int counter = 0;

		int whiteKingRow = rowProcessor(getPieceByID('K'));
		int whiteKingCol = colProcessor(getPieceByID('K'));

		istringstream ss(theGrid[whiteKingRow][whiteKingCol]->validMoves());
		while (ss >> wKingPossibleMoves[counter]) {
			counter++;
		}

		for (int i = 0; i < counter; i++) {
			int newRow = rowProcessor(wKingPossibleMoves[i]);
			int newCol = colProcessor(wKingPossibleMoves[i]);
			char theID = theGrid[newRow][newCol]->getID();

			// Move the white king to see what happen
			setPiece(whiteKingRow, whiteKingCol, 'e');
			setPiece(newRow, newCol, 'K');

			// If the white king is still in check after one move
			// (all of them), it's white in checkmate.
			if (wInCheck()) {
				// Put the piece back to the original place.
				setPiece(whiteKingRow, whiteKingCol, 'K');
				setPiece(newRow, newCol, theID);
			} else {
				// If the white king escapes after one move,
				// put the piece back to the original place and
				// return false.
				setPiece(whiteKingRow, whiteKingCol, 'K');
				setPiece(newRow, newCol, theID);
				return false;
			}
		}

		return true;

	} else {
		return false;
	}
}


/******************** bInCheckmate ********************
	Purpose: Check if the black king is in checkmate.
*******************************************************/
bool Game::bInCheckmate() {
	if (bInCheck()) {

		string bKingPossibleMoves[64] = {""};
		int counter = 0;

		int blackKingRow = rowProcessor(getPieceByID('k'));
		int blackKingCol = colProcessor(getPieceByID('k'));

		istringstream ss(theGrid[blackKingRow][blackKingCol]->validMoves());
		while (ss >> bKingPossibleMoves[counter]) {
			counter++;
		}

		for (int i = 0; i < counter; i++) {
			int newRow = rowProcessor(bKingPossibleMoves[i]);
			int newCol = colProcessor(bKingPossibleMoves[i]);
			char theID = theGrid[newRow][newCol]->getID();

			// Move the black king to see what happen
			setPiece(blackKingRow, blackKingCol, 'e');
			setPiece(newRow, newCol, 'k');

			// If the black king is still in check after one move
			// (all of them), it's black in checkmate.
			if (bInCheck()) {
				// Put the piece back to the original place.
				setPiece(blackKingRow, blackKingCol, 'k');
				setPiece(newRow, newCol, theID);
			} else {
				// If the black king escapes after one move,
				// put the piece back to the original place and
				// return false.
				setPiece(blackKingRow, blackKingCol, 'k');
				setPiece(newRow, newCol, theID);
				return false;
			}
		}

		return true;

	} else {
		return false;
	}
}


/******************** stalemate ********************
	Purpose: Check if the board is in stalemate.
*******************************************************/
bool Game::stalemate() {
	string wPossibleMoves[1024];
	int wCounter = 0;

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (wPiece(i, j)) {
				istringstream ss(theGrid[i][j]->validMoves());
				while(ss >> wPossibleMoves[wCounter]) {
					wCounter++;
				}
			}
		}
	}

	if (wCounter == 0 && !wInCheck()) {
		return true;
	}


	string bPossibleMoves[1024];
	int bCounter = 0;

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (bPiece(i, j)) {
				istringstream ss(theGrid[i][j]->validMoves());
				while(ss >> bPossibleMoves[wCounter]) {
					bCounter++;
				}
			}
		}
	}

	if (bCounter == 0 && !bInCheck()) {
		return true;
	}

	return false;
}


int Game::numMoves(int row, int col) {
	int counter = 0;
	string possibleMoves[64] = {""};
	istringstream ss(theGrid[row][col]->validMoves());

	while (ss >> possibleMoves[counter]) {
		counter++;
	}

	return counter;
}


/******************** castling **************************                      
        Purpose: Initiate castling in chess
*********************************************************/
bool Game::castling(int kingrow, int kingcol, int rookrow, int rookcol) {

        char kingid = theGrid[kingrow][kingcol]->getID();
        char rookid = theGrid[rookrow][rookcol]->getID();

                if (rookcol > kingcol) {
                        if (((kingid == 'K') && (rookid == 'R')) || ((kingid == 'k') && (rookid == 'r'))) {

                                for(int tmp = rookcol-1; tmp > kingcol; --tmp) {
                                        char id = theGrid[kingrow][tmp]->getID();
                                        if (id == '_' || id == ' ') {
                                                continue;
                                        } else {
                                                cerr << "Castling failed" << endl;
                                                return false;
                                        }
                                }

                                if (bInCheck() || wInCheck()) {
                                                cerr << "Castling failed" << endl;
                                                return false;
                                }

                                for(int n = 1; n <= 2; ++n) {
                                        setPiece(kingrow, kingcol+n-1, 'e');
                                        setPiece(kingrow, kingcol+n, kingid);

                                        if(wInCheck() || bInCheck()){
                                                setPiece(kingrow, kingcol, kingid);
                                                setPiece(kingrow, kingcol+n, kingid);

                                                cerr << "Castling failed" << endl;
                                                return false;
                                        }
                                }


                                setPiece(rookrow, rookcol, 'e');
                                setPiece(rookrow, rookcol-2, rookid);
                        } else {
                                cerr << "Castling failed" << endl;
                                return false;
                        }
                } else if (rookcol < kingcol) {
                        if (((kingid == 'K') && (rookid == 'R')) || ((kingid == 'k') && (rookid == 'r'))) {
                                for(int tmp = rookcol+1; tmp < kingcol; ++tmp) {
                                        char id = theGrid[kingrow][tmp]->getID();
                                        if (id == '_' || id == ' ') {
                                                continue;
                                        } else {
                                                cerr << "Castling failed" << endl;
                                                return false;
                                        }
                                }
                                for(int n = 1; n <= 2; ++n) {
                                        setPiece(kingrow, kingcol-n+1, 'e');
                                        setPiece(kingrow, kingcol-n, kingid);
                                        if(wInCheck() || bInCheck()){
                                                setPiece(kingrow, kingcol, kingid);
                                                setPiece(kingrow, kingcol-n, 'e');
                                                cerr << "Castling failed" << endl;
                                                return false;
                                        }
                                }

                                if (bInCheck() || wInCheck()) {
                                        cerr << "Castling failed" << endl;
                                        return false;
                                }
                                setPiece(rookrow, rookcol, 'e');
                                setPiece(rookrow, rookcol+3, rookid);
                        } else {
                                cerr << "Castling failed" << endl;
                                return false;
                        }
                }
        return true;
}
