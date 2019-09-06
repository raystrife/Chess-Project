#ifndef QUEEN_H
#define QUEEN_H
#include "piece.h"

class Queen : public Piece {
	public:
		Queen(int, char, char, Game*);
		~Queen();
		virtual std::string validMoves();
};

#endif
