#include "Knight.h"

Knight::Knight(char color, fieldPtr field) : Unit('k', color, field){}



std::vector<fieldPtr> Knight::calculatePossibleMoves(boardPtr board) {
    std::vector<fieldPtr> fields;
    std::vector<fieldPtr> buff;
    buff = knightPossibleMovesCase(board, 2, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = knightPossibleMovesCase(board, -2, 1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = knightPossibleMovesCase(board, 2, -1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = knightPossibleMovesCase(board, -2, -1);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = knightPossibleMovesCase(board, 1, 2);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = knightPossibleMovesCase(board, -1, 2);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = knightPossibleMovesCase(board, 1, -2);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    buff = knightPossibleMovesCase(board, -1, -2);
    fields.insert(fields.end(), buff.begin(), buff.end());
    buff.clear();
    return fields;
}

std::vector<fieldPtr> Knight::knightPossibleMovesCase(boardPtr board, int dx, int dy) {
    std::vector<fieldPtr> fields;
    fieldPtr field;
    int x = getField()->getX();
    int y = getField()->getY();
    if(x+dx < 7 && y+dy < 7 && x+dx >= 0 && y+dy >= 0)
    {
        field = board->getField(x+dx, y+dy);
        if(field->occupied())
        {
            if(field->getUnit()->getColour() != getColour()) fields.push_back(field);
        }
        else
        {
            fields.push_back(field);
        }
    }
    return fields;
}
