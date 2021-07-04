#include "Queen.h"

bool Queen::move(int x, int y) {
    return false;
}

Queen::Queen(char color, fieldPtr field) : Unit('Q', color, field){}

std::vector<fieldPtr> Queen::calculatePossibleMoves(boardPtr board) {
    std::vector<fieldPtr> fields;
    std::vector<fieldPtr> buff;
    //rook movement
    buff = board->Raycast(getColour(),getField()->getX()+1, getField()->getY(), 1, 0);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX()-1, getField()->getY(), -1, 0);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX(), getField()->getY()-1, 0, -1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = board->Raycast(getColour(),getField()->getX(), getField()->getY()+1, 0, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    //bishop movement
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
