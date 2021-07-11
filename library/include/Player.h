#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <string>
#include "typedefs.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"

class Player {
private:
    std::string name;
    gamePtr game;
    char color;
    unitPtr king;
    std::vector<unitPtr> pieces;
    std::vector<std::tuple<unitPtr, std::vector<fieldPtr>>> allPossibleMoves;
public:
    const std::vector<std::tuple<unitPtr, std::vector<fieldPtr>>> &getAllPossibleMoves() const;

public:
    const unitPtr &getKing() const;

public:
    Player(std::string name, gamePtr game, char color);

    std::string getName() const;

    void displayPossibleMoves();

    void calculatePossibleMoves();

    std::tuple<unitPtr, fieldPtr> getPossibleMoveFromString(const std::string&);

    std::tuple<unitPtr, fieldPtr, fieldPtr, unitPtr> makeMove(std::tuple<unitPtr, fieldPtr>, bool mock);

    void deleteIllegalMoves();

    void setup();

    bool isChecked();

    bool canMove(const fieldPtr& field);

    virtual ~Player();

    const gamePtr &getGame() const;

    playerPtr getOtherPlayer(std::string name);

    int getNumberOfMoves();

    int getPiecesNumber();

};

#endif //GAME_PLAYER_H
