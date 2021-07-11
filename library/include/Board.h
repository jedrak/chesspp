#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "typedefs.h"
#include "Field.h"
#include <vector>
#include <memory>

class Board : public std::enable_shared_from_this<Board> {
private:
    std::vector<std::vector<fieldPtr>> array;

public:
    Board();

    virtual ~Board();

    fieldPtr getField(int x, int y);

    std::vector<fieldPtr> castRay(char color, int startX, int startY, int vX, int vY, int range=7);

    unitPtr move(fieldPtr from, fieldPtr to);


    void display() const;
};

#endif //GAME_BOARD_H
