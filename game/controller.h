#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "game.h"
#include "computer.h"
#include "human.h"
#include "textdisplay.h"

class Controller : public GameNotification {
    View *td; // The text display.
    //View *gd; // The graphic display.
    Game *game;
    Player *wPlayer, *bPlayer;
    bool gameInProgress;
    bool bKing, wKing, bRook, wRook;
    void setup(std::istream&, Game&);
    bool checkWin() const;
    int rowProcessor(std::string);
    int colProcessor(std::string);

    public:
        Controller();
        ~Controller();
        void play();
        virtual void notify(int, int, char);
	void setBool(char);
};

#endif
