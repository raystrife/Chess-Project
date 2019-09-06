#ifndef EMPTY_H
#define EMPTY_H
#include "piece.h"

class Empty : public Piece {
	void setID ();
	
	public:
		Empty(int, char, char, Game*);
		~Empty();
		virtual std::string validMoves();
};

#endif
