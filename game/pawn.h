#ifndef PAWN_H
#define PAWN_H
#include "piece.h"

class Pawn : public Piece {
	public:
		Pawn(int, char, char, Game*);
		~Pawn();
		virtual std::string validMoves();
};

#endif
