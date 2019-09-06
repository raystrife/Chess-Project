#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"
#include <string>
#include <sstream>

class Player {
	protected:
		char colour;
		char type;
		Game *game;

	public:
		Player(char, char, Game*);
		virtual ~Player();
		virtual bool makeMove(std::string, std::string, int, int, int, int) = 0;
		virtual void makeMove() = 0;
		char getColour() const;
		char getType() const;
};

#endif
