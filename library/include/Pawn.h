#ifndef GAME_PAWN_H
#define GAME_PAWN_H

#include "Unit.h"

class Pawn : public Unit {
public:
    Pawn(char color, fieldPtr field);
    bool promotion(unitPtr &unit);
    std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) override;
};

#endif //GAME_PAWN_H
