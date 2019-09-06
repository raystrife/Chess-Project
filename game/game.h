#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <sstream>
#include "piece.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "pawn.h"
#include "empty.h"

class GameNotification {
public:
    virtual void notify(int, int, char) = 0;
};


class Game {
  Piece ***theGrid;
  char turn;
  double bWin;
  double wWin;
  GameNotification *notification;
  std::string getPieceByID(char);

  public:
    Game();
    ~Game();
    int rowProcessor(std::string);
    int colProcessor(std::string);
    int rowBToA(int);
    int colBToA(char);
    int rowAToB(int);
    char colAToB(int);
    Piece* getPiece(int, int) const;
    void setPiece(int, int, char);
    char getTurn() const;
    double getWWin() const;
    double getBWin() const;
    void setTurn(char);
    void setWWin(int);
    void setBWin(int);
    void init(GameNotification*);
    bool validBoard();
    bool wPiece(int, char);
    bool bPiece(int, char);
    bool wPiece(int, int);
    bool bPiece(int, int);
    bool wInCheck();
    bool bInCheck();
    bool wInCheckmate();
    bool bInCheckmate();
    bool stalemate();
    int numMoves(int, int);
    bool castling(int, int, int, int);
};

#endif
