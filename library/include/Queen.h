#ifndef GAME_QUEEN_H
#define GAME_QUEEN_H

#include "Unit.h"

class Queen : public Unit{
public:
    Queen(char color, fieldPtr field);
    std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) override;
};

#endif //GAME_QUEEN_H
