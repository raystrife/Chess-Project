#include "textdisplay.h"

using namespace std;

const int GRID_SIZE = 8;

// constructor for TextDisplay
TextDisplay::TextDisplay() {
	display = new char*[GRID_SIZE];

	for (int i = 0; i < GRID_SIZE; i++) {
		display[i] = new char[GRID_SIZE];
	}

	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			display[i][j] = 'u';
		}
	}
}


// destructor for TextDisplay
TextDisplay::~TextDisplay() {
	
	for (int i = 0; i < GRID_SIZE; i++) {
		delete [] display[i];
	}

	delete [] display;
}


/********************** notify ************************
	Purpose: Called by Game to change the view.
*******************************************************/
// The col must be converted into Array form.
void TextDisplay::notify(int row, int col, char change) {
	display[row][col] = change;
}


/*********************** print ************************
	Purpose: Print the game grid.
*******************************************************/
void TextDisplay::print(ostream &out, char turn) const {
	out << endl;

	int rowNum = 8;
	for (int i = 0; i < GRID_SIZE; i++) {
		out << rowNum << " ";
		
		for (int j = 0; j < GRID_SIZE; j++) {
			out << display[i][j];
		}
		out << endl;
		rowNum--;
	}

	out << "  abcdefgh" << endl << endl;

	string theTurn;

	if (turn == 'B') {
		theTurn = "Black";
	} else {
		theTurn = "White";
	}

	out << "Turn: " << theTurn << endl << endl;
}
