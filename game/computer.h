#ifndef COMPUTER_H
#define COMPUTER_H
#include <cstdlib>
#include "player.h"

class Computer : public Player {
	std::string level;
	int assignScore(std::string, std::string);

	public:
		Computer(char, char, Game*, std::string);
		~Computer();
		virtual bool makeMove(std::string, std::string, int, int, int, int);
		virtual void makeMove();
};

#endif
