#ifndef GAME_QUEEN_H
#define GAME_QUEEN_H

#include "Unit.h"

class Queen : public Unit{
public:
    bool move(int x, int y) override;
    Queen(char color, fieldPtr field);
    std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) override;
};

#endif //GAME_QUEEN_H
