#ifndef GAME_KNIGHT_H
#define GAME_KNIGHT_H

#include "Unit.h"

class Knight : public Unit {
    std::vector<fieldPtr> knightPossibleMovesCase(boardPtr board, int dx, int dy);
public:
    Knight(char color, fieldPtr field);
    std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) override;
    bool move(int x, int y) override;

};

#endif //GAME_KNIGHT_H
