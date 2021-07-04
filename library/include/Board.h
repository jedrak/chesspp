#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "typedefs.h"
#include "Field.h"
#include <vector>
#include <memory>

class Board : public std::enable_shared_from_this<Board> {
private:
    std::vector<std::vector<fieldPtr>> array;
    //static boardPtr instance;

    //static boardPtr instance;
public:
    Board();
    //static boardPtr getInstance();
    virtual ~Board();

    const std::vector<std::vector<fieldPtr>> &getArray() const;

    fieldPtr getField(int x, int y);

    void display() const;
    //it returns all fields in specified direction
    std::vector<fieldPtr> Raycast(char color, int startX, int startY, int vX, int vY, int range=7);


};

#endif //GAME_BOARD_H
