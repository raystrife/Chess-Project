#ifndef ROOK_H
#define ROOK_H
#include "piece.h"

class Rook : public Piece {
	public:
		Rook(int, char, char, Game*);
		~Rook();
		virtual std::string validMoves();
};

#endif
