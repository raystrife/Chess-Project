#ifndef KNIGHT_H
#define KNIGHT_H
#include "piece.h"

class Knight : public Piece {
	public:
		Knight(int, char, char, Game*);
		~Knight();
		virtual std::string validMoves();
};

#endif
