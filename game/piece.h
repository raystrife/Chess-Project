#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <sstream>

class Game;

class Piece {
	protected:
		int row;
		char col;
		char id;
		Game *game;

	public:
		Piece(int, char, char, Game*);
		virtual ~Piece();
		virtual std::string validMoves() = 0;
		int getRow() const;
		char getCol() const;
		char getID() const;
		void setGame(Game*);
};

#endif
