#include "Pawn.h"
#include "Unit.h"
bool Pawn::move(int x, int y) {
    bool validMove = false;
    int allowableMove1 = 1;
    int allowableMove2 = 2;


    if(getColour() == 'b')
    {
        allowableMove1 = -1;
        allowableMove2 = -2;
    }



    if (x == getField()->getX() + allowableMove1 && y == getField()->getY()) {
        validMove = true;
    }




    return true;
}

bool Pawn::promotion(unitPtr &unit) {
    return false;
}

Pawn::Pawn(char color, fieldPtr field) : Unit('p', color, field){}

std::vector<fieldPtr> Pawn::calculatePossibleMoves(boardPtr board) {
    std::vector<fieldPtr> fields;
    int x = getField()->getX();
    int y = getField()->getY();

    if(getColour() == 'W' && y<7)
    {   //first moves
        if(y==1 && !board->getField(x, y+2)->occupied()) fields.push_back(board->getField(x, y+2));
        //normal moves
        if(!board->getField(x, y+1)->occupied()) fields.push_back(board->getField(x, y+1));
        //taking
        if(x < 7 && board->getField(x+1, y+1)->occupied()) fields.push_back(board->getField(x+1, y+1));
        if(x > 0 && board->getField(x-1, y+1)->occupied()) fields.push_back(board->getField(x-1, y+1));
    }else
    {
        if(y>0)
        {

            if(y==6 && !board->getField(x, y-2)->occupied()) fields.push_back(board->getField(x, y-2));
            if(!board->getField(x, y-1)->occupied()) fields.push_back(board->getField(x, y-1));
            //taking
            if(x < 7 && board->getField(x+1, y-1)->occupied()) fields.push_back(board->getField(x+1, y-1));
            if(x > 0 && board->getField(x-1, y-1)->occupied()) fields.push_back(board->getField(x-1, y-1));
        }

    }



    return fields;
}
