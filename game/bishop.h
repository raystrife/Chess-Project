#ifndef BISHOP_H
#define BISHOP_H
#include "piece.h"

class Bishop : public Piece {
	public:
		Bishop(int, char, char, Game*);
		~Bishop();
		virtual std::string validMoves();
};

#endif
