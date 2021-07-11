#ifndef GAME_KNIGHT_H
#define GAME_KNIGHT_H

#include "Unit.h"

class Knight : public Unit {
public:
    Knight(char color, fieldPtr field);
    std::vector<fieldPtr> knightPossibleMovesCase(boardPtr board, int dx, int dy);
    std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) override;
};

#endif //GAME_KNIGHT_H
