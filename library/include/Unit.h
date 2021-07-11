#ifndef GAME_UNIT_H
#define GAME_UNIT_H

#include "typedefs.h"
#include <memory>
#include "Board.h"

class Unit : public std::enable_shared_from_this<Unit> {
private:
    char type;
    char colour;
    fieldPtr field;

public:
    Unit(char type, char colour, fieldPtr field);

    virtual std::vector<fieldPtr> calculatePossibleMoves(boardPtr board) = 0;

    const fieldPtr &getField() const;

    char getType() const;

    char getColour() const;

    void setField(const fieldPtr &field);

};

#endif //GAME_UNIT_H
