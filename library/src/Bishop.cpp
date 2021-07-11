#include "Bishop.h"
#include "Field.h"
#include "Board.h"

Bishop::Bishop(char colour, const fieldPtr &field) : Unit('B', colour, field) {}

std::vector<fieldPtr> Bishop::calculatePossibleMoves(boardPtr board) {
    std::vector<fieldPtr> fields;
    std::vector<fieldPtr> buff;


    buff = board->castRay(getColour(),getField()->getX()+1, getField()->getY()+1, 1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->castRay(getColour(),getField()->getX()-1, getField()->getY()+1, -1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->castRay(getColour(),getField()->getX()+1, getField()->getY()-1, 1, -1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->castRay(getColour(),getField()->getX()-1, getField()->getY()-1, -1, -1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    return fields;
}