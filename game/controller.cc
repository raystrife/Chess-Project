#include "controller.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int GRID_SIZE = 8;

// constructor for Controller
Controller::Controller() {
	wPlayer = NULL;
	bPlayer = NULL;
	game = new Game();
	td = new TextDisplay();
	gameInProgress = false;
	bKing = true;
	wKing = true;
	bRook = true;
	wRook = true;
}


// destructor for Controller
Controller::~Controller() {
	delete td;
	delete game;

	if (wPlayer) {
		delete wPlayer;
	}

	if (bPlayer) {
		delete bPlayer;
	}
}


/******************* rowProcessor *********************
	Purpose: Process the user input to the correct row.
*******************************************************/
int Controller::rowProcessor(string i) {
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
int Controller::colProcessor(string i) {
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


/*********************** setup ************************
	Purpose: Enter the setup mode of the game.
*******************************************************/
void Controller::setup(std::istream& input, Game& g) {
	cout << endl << "******** Setup Mode ********" << endl;

	// Initialize the board to the beginning
	g.init(this);
	td->print(cout, g.getTurn());

	string cmd;

	while (true) {
		input >> cmd;

		if (cmd == "+") {
			char p;
			string pos;
			input >> p;
			input >> pos;

			int theRow = rowProcessor(pos);
			int theCol = colProcessor(pos);

			g.setPiece(theRow, theCol, p);
			td->print(cout, g.getTurn());

		} else if (cmd == "-") {
			string pos;
			input >> pos;

			int theRow = rowProcessor(pos);
			int theCol = colProcessor(pos);

			// If there is a piece on the square, remove it.
			if (!((g.getPiece(theRow, theCol))->getID() == '_' ||
				  (g.getPiece(theRow, theCol))->getID() == ' ')) {
				g.setPiece(theRow, theCol, 'e');
				td->print(cout, g.getTurn());	
			} else {
				td->print(cout, g.getTurn());
			}

		} else if (cmd == "=") {
			string colour;
			input >> colour;
			if (colour == "black") {
				g.setTurn('B');
				td->print(cout, g.getTurn());
			} else if (colour == "white") {
				g.setTurn('W');
				td->print(cout, g.getTurn());
			} else {
				cerr << "Invalid Colour" << endl;
			}
		} else if (cmd == "done") {
			if (g.validBoard()) {
				cout << endl << "Exiting Setup Mode..." << endl << endl;
				break;
			} else {
				cerr << "Invalid Setup" << endl << endl;
				td->print(cout, g.getTurn());
			}
		}
	}

	cout << "Please enter the next command:" << endl << endl;
}


/************************ play ************************
	Purpose: Start taking in user inputs(commands)
*******************************************************/
void Controller::play() {
	bool boardInitialized = false;
	string cmd;

	while (cin >> cmd) {
		if (cmd == "game") {
			if (gameInProgress == false) {

				if (bPlayer) {
					delete bPlayer;
				}

				if (wPlayer) {
					delete wPlayer;
				}

				gameInProgress = true;
				string theWPlayer, theBPlayer;
				cin >> theWPlayer;
				cin >> theBPlayer;

				if ((theWPlayer == "human" ||
					(theWPlayer.length() == 9 && theWPlayer.substr(0, 8) == "computer")) &&
					(theBPlayer == "human" ||
					(theBPlayer.length() == 9 && theBPlayer.substr(0, 8) == "computer"))) {

					if (theWPlayer == "human") {
						wPlayer = new Human('W', 'H', game);
					} else {
						wPlayer = new Computer('W', 'C', game, theWPlayer.substr(8, 1));
					}

					if (theBPlayer == "human") {
						bPlayer = new Human('B', 'H', game);
					} else {
						bPlayer = new Computer('B', 'C', game, theBPlayer.substr(8, 1));
					}

					cout << endl << "Starting a new game..." << endl << endl;
					if (boardInitialized == false) {
						game->init(this);
					}
					td->print(cout, game->getTurn());

				} else {
					cerr << "Invalid Player Input" << endl;
				}
			} else {
				cerr << "Please finish this game first!" << endl;
			}

		} else if (cmd == "resign") {
			if (gameInProgress) {
				gameInProgress = false;

				if (game->getTurn() == 'W') {
					game->setBWin(game->getBWin() + 1);
					cout << endl << "Black Wins!" << endl;
				} else {
					game->setWWin(game->getWWin() + 1);
					cout << endl << "White Wins!" << endl;
				}
			} else {
				cerr << "No game has been created yet!" << endl;
			}
		} else if (cmd == "move") {
			if (gameInProgress) {
				if (wPlayer && bPlayer) {
					if (game->getTurn() == 'W') {

						if (wPlayer->getType() == 'H') {
							string oldPos, newPos;
							cin >> oldPos;
							cin >> newPos;
							int oldRow = rowProcessor(oldPos);
							int oldCol = colProcessor(oldPos);
							int newRow = rowProcessor(newPos);
							int newCol = colProcessor(newPos);

							if (wPlayer->makeMove(oldPos, newPos, oldRow, oldCol, newRow, newCol)) {
								game->setTurn('B');
								setBool(game->getPiece(newRow, newCol)->getID());

								if (game->getPiece(oldRow, oldCol)->getID() == 'P' && newRow == 0) {
									char pawnPromotion;
									cin >> pawnPromotion;
									game->setPiece(newRow, newCol, pawnPromotion);
								}

								td->print(cout, game->getTurn());
							} else {
								cerr << endl << "Invalid Move" << endl << endl;
								td->print(cout, game->getTurn());
							}
						} else {
							wPlayer->makeMove();
							game->setTurn('B');
							td->print(cout, game->getTurn());
						}

					} else {

						if (bPlayer->getType() == 'H') {
							string oldPos, newPos;
							cin >> oldPos;
							cin >> newPos;
							int oldRow = rowProcessor(oldPos);
							int oldCol = colProcessor(oldPos);
							int newRow = rowProcessor(newPos);
							int newCol = colProcessor(newPos);

							if (bPlayer->makeMove(oldPos, newPos, oldRow, oldCol, newRow, newCol)) {
								game->setTurn('W');
								setBool(game->getPiece(newRow, newCol)->getID());

								if (game->getPiece(oldRow, oldCol)->getID() == 'p' && newRow == 7) {
									char pawnPromotion;
									cin >> pawnPromotion;
									game->setPiece(newRow, newCol, pawnPromotion);
								}

								td->print(cout, game->getTurn());
							} else {
								cerr << endl << "Invalid Move" << endl << endl;
								td->print(cout, game->getTurn());
							}
						} else {
							bPlayer->makeMove();
							game->setTurn('W');
							td->print(cout, game->getTurn());
						}
					}
					
					if (game->bInCheckmate()) {
						cout << "Checkmate! White wins!" << endl << endl;
						game->setWWin(game->getWWin() + 1);
						boardInitialized = false;
						gameInProgress = false;
					} else if (game->wInCheckmate()) {
						cout << "Checkmate! Black wins!" << endl << endl;
						game->setBWin(game->getBWin() + 1);
						boardInitialized = false;
						gameInProgress = false;
					} else if (game->wInCheck()) {
						cout << "White is in check" << endl << endl;
					} else if (game->bInCheck()) {
						cout << "Black is in check" << endl << endl;
					} else if (game->stalemate()) {
						cout << "Stalemate!" << endl << endl;
						game->setWWin(game->getWWin() + 0.5);
						game->setBWin(game->getBWin() + 0.5);
						boardInitialized = false;
						gameInProgress = false;
					}
					
					
				} else {
					cerr << "No player has been created yet" << endl;
				}
			} else {
				cerr << "No game is in progress." << endl;
			}

        } else if (cmd == "castling") {                                       
                        if (gameInProgress) {
                                if (wPlayer && bPlayer) {
                                                string rookPos, kingPos;
                                                cin >> kingPos;
                                                cin >> rookPos;
                                                int rookRow = rowProcessor(rookPos);
                                                int rookCol = colProcessor(rookPos);
                                                int kingRow = rowProcessor(kingPos);
                                                int kingCol = colProcessor(kingPos);

                                        if (game->getTurn() == 'W') {
                                                if (wKing && wRook) {
                                                        if ((game->wPiece(rookRow, rookCol)) && (game->wPiece(kingRow, kingCol))) {
                                                                if (game->castling(kingRow, kingCol, rookRow, rookCol)) {
                                                                        game->setTurn('B');
                                                                        td->print(cout, game->getTurn());
                                                                }
                                                        } else {
                                                                cerr << endl << "Castling failed" << endl;
                                                        }
                                                } else {
                                                        cerr << endl << "Castling failed" << endl;
                                                }
                                        } else if (game->getTurn() == 'B') {
                                                if (bKing && bRook) {
                                                        if ((game->bPiece(rookRow, rookCol)) && (game->bPiece(kingRow, kingCol))) {
                                                                if (game->castling(kingRow, kingCol, rookRow, rookCol)) {
                                                                        game->setTurn('W');
                                                                        td->print(cout, game->getTurn());
                                                                }
                                                        } else {
                                                                cerr << endl << "Castling failed" << endl;
                                                        }
                                                } else {
                                                        cerr << endl << "Castling failed" << endl;
                                                }
                                        }
                     
                                } else {
                                        cerr << "No player has been created yet" << endl;
                                }
                        } else {
                                cerr << "No game is in progress." << endl;
                        }

		} else if (cmd == "setup") {
			if (gameInProgress == false) {
				setup(cin, *game);
				boardInitialized = true;
			} else {
				cerr << "CANNOT enter Setup Mode when a game is in progress" << endl;
			}
		} else {
			// Read from the file.
			string fileName = cmd;
			ifstream file(fileName.c_str());

			if (file.good()) {
				game->init(this);

				for (int i = 0; i < GRID_SIZE; i++) {
					for (int j = 0; j < GRID_SIZE; j++) {
						char pieceFromFile;
						file >> pieceFromFile;

						if (pieceFromFile != 'K' && pieceFromFile != 'k' &&
							pieceFromFile != 'Q' && pieceFromFile != 'q' &&
							pieceFromFile != 'B' && pieceFromFile != 'b' &&
							pieceFromFile != 'N' && pieceFromFile != 'n' &&
							pieceFromFile != 'R' && pieceFromFile != 'r' &&
							pieceFromFile != 'P' && pieceFromFile != 'p') {

							pieceFromFile = 'e';
						}

						game->setPiece(i, j, pieceFromFile);
					}
				}

				char turnFromFile;
				file >> turnFromFile;
				game->setTurn(turnFromFile);

				file.close();

				if (game->validBoard()) {
					boardInitialized = true;
					td->print(cout, game->getTurn());
				} else {
					boardInitialized = false;
					cerr << endl << "Invalid Setup" << endl << endl;
				}
			} else {
				cerr << endl << "File does not exist or is not readable!" << endl << endl;
			}
		}
	}

	// Print the final score.
	cout << endl << "Final Score:" << endl;
	cout << "White: " << game->getWWin() << endl;
	cout << "Black: " << game->getBWin() << endl;
}


/********************** notify ************************
	Purpose: Notify the View(s) to change the view.
*******************************************************/
void Controller::notify(int row, int col, char change) {
	td->notify(row, col, change);
}


/********************* setBool ***************************************          
Purpose: set bool to false if King and Rook have moved for first time
*********************************************************************/
void Controller::setBool(char id) {
        if (id == 'k') {
                bKing = false;
        } else if (id == 'K') {
                wKing = false;
        } else if (id == 'r') {
                bRook = false;
        } else if (id == 'R') {
                wRook = false;
        }
}
