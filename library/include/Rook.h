#ifndef GAME_ROOK_H
#define GAME_ROOK_H

#include "Unit.h"

class Rook : public Unit {
public:
    Rook(char color, fieldPtr field);
    std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) override;
};

#endif //GAME_ROOK_H
