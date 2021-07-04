#ifndef GAME_BISHOP_H
#define GAME_BISHOP_H

#include "Unit.h"
#include <cstdlib>

class Bishop : public Unit {
public:
    bool move(int x, int y) override;
    std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) override;
    Bishop(char colour, const fieldPtr &field);
};


#endif //GAME_BISHOP_H
