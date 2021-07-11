#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include "typedefs.h"

class Field {
private:
    int x;
    int y;
    unitPtr unit;
    boardPtr board;

public:
    int getX() const;

    int getY() const;

    const unitPtr &getUnit() const;

    void setUnit(const unitPtr &unit);

    bool occupied() const;

    Field(int x, int y);

    std::string toString();
};


#endif //GAME_FIELD_H
