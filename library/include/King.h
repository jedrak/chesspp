#ifndef GAME_KING_H
#define GAME_KING_H

#include "Unit.h"

class King : public Unit {
public:
    King(char color, fieldPtr field);
    std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) override;
};

#endif //GAME_KING_H
