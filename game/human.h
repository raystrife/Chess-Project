#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human : public Player {
	public:
		Human(char, char, Game*);
		~Human();
		virtual bool makeMove(std::string, std::string, int, int, int, int);
		virtual void makeMove();
};

#endif
