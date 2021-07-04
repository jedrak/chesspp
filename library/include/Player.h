#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include "typedefs.h"
#include <Pawn.h>
#include <Rook.h>
#include <Queen.h>
#include <Bishop.h>
#include <Knight.h>
#include <King.h>

class Player {
private:
    Player(std::string name);

    std::string _name;
    gamePtr game;
    char color;
    //pieces
    std::vector<unitPtr> pieces;
    std::vector<std::tuple<unitPtr, std::vector<fieldPtr>>> allPossibleMoves;
public:
    std::string getName() const;
    void displayPossibleMoves();
    Player(std::string name, gamePtr game, char color);
    void calculatePossibleMoves();
    std::tuple<unitPtr, fieldPtr> getPossibleMoveFromString(const std::string&);
    void makeMove(std::tuple<unitPtr, fieldPtr>);
    void setup();

    ~Player();

    void makeMove();

    bool inCheck();

    bool isWhite() const;

    const gamePtr &getGame() const;

    void makeMove(std::string move);

};

#endif //GAME_PLAYER_H
