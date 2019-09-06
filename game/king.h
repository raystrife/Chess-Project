#ifndef KING_H
#define KING_H
#include "piece.h"

class King : public Piece {
	public:
		King(int, char, char, Game*);
		~King();
		virtual std::string validMoves();
};

#endif
