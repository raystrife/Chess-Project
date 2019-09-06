#include "player.h"

// constructor for Player
Player::Player(char colour, char type, Game *game)
              : colour(colour), type(type), game(game) {

}


// destructor for Player
Player::~Player() {
	game = NULL;
}


/********************* getColour **********************
	Purpose: Return the colour.
*******************************************************/
char Player::getColour() const {
	return colour;
}


/********************** getType ***********************
	Purpose: Return the type
*******************************************************/
char Player::getType() const {
	return type;
}
