#include "Bishop.h"
#include "Field.h"
#include "Board.h"

bool Bishop::move(int x, int y) {
    /*int dx = x - getField()->getX();
    int dy = y - getField()->getY();
    bool directionX, directionY;

    if (dx == 0 || dy == 0 || abs(dx) != abs(dy))
        return false;

    directionX = dx > 0;
    directionY = dy > 0;

    for (int i = 1, j = 1; i < dx; i += directionX, j += directionY) {
        if ((getField()->getBoard()->getField(getField()->getX() + i, getField()->getY() + j)) != nullptr)
            return false;
    }

    getField()->setUnit(nullptr);
    getField()->getBoard()->getField(x, y)->setUnit(shared_from_this());

    return true;*/
}

Bishop::Bishop(char colour, const fieldPtr &field) : Unit('B', colour, field) {}

std::vector<fieldPtr> Bishop::calculatePossibleMoves(boardPtr board) {
    std::vector<fieldPtr> fields;
    std::vector<fieldPtr> buff;


    buff = board->Raycast(getColour(),getField()->getX()+1, getField()->getY()+1, 1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX()-1, getField()->getY()+1, -1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX()+1, getField()->getY()-1, 1, -1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX()-1, getField()->getY()-1, -1, -1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    return fields;
}
