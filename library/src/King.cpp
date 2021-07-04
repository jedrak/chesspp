#include "King.h"
#include "Field.h"
#include "Board.h"

bool King::move(int x, int y) {
    return false;
}

King::King(char color, fieldPtr field) : Unit('K', color, field){}

std::vector<fieldPtr> King::calculatePossibleMoves(boardPtr board) {
    std::vector<fieldPtr> fields;
    std::vector<fieldPtr> buff;
    //rook movement
    buff = board->Raycast(getColour(),getField()->getX()+1, getField()->getY(), 1, 0, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX()-1, getField()->getY(), -1, 0, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX(), getField()->getY()-1, 0, -1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX(), getField()->getY()+1, 0, 1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    //bishop movement
    buff = board->Raycast(getColour(),getField()->getX()+1, getField()->getY()+1, 1, 1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX()-1, getField()->getY()+1, -1, 1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX()+1, getField()->getY()-1, 1, -1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX()-1, getField()->getY()-1, -1, -1, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    return fields;
}
