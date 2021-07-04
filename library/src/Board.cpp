#include "Board.h"
#include "Field.h"
#include "Unit.h"
#include <iostream>
#include <memory>

using namespace std;

const std::vector<std::vector<fieldPtr>> &Board::getArray() const {
    return array;
}

fieldPtr Board::getField(int x, int y) {
    return array[x][y];
}

void Board::display() const {
    cout << endl << "   a  b  c  d  e  f  g  h" << endl;
    cout << " -------------------------" << endl;
    for (int y = 8 - 1; y >= 0; y--) {
        cout << y + 1;
        for (int x = 0; x < 8; x++) {
            cout << "|";
            if (array[x][y]->occupied())
                cout << array[x][y]->getUnit()->getColour() << array[x][y]->getUnit()->getType();
            else
                cout << "  ";
        }
        cout << "|" << y + 1 << endl << " -------------------------" << endl;
    }
    cout << "   a  b  c  d  e  f  g  h" << endl << endl;

}

//Board::Board(const vector<std::vector<fieldPtr>> &array) : array(array) {
//    for (int i = 0; i < 8; i++)
//    {
//        for (int j = 0; j < 8; j++)
//        {
//            array[i][j] = new array(i, j);
//        }
//    }}

Board::~Board() {
    array.clear();
}

Board::Board(){

    for (int i = 0; i < 8; i++) {
        vector<fieldPtr> v = std::vector<fieldPtr>();
        for (int j = 0; j < 8; j++) {
            fieldPtr buff = make_shared<Field>(Field(i, j));
            v.push_back(buff);
        }
        array.push_back(v);
    }
}

std::vector<fieldPtr> Board::Raycast(char color, int startX, int startY, int vX, int vY, int range) {
    std::vector<fieldPtr> fields;

    for(int i = startX, j = startY, counter=0; i<8 && i>=0 && j<8 && j>=0 && counter < range; i+=vX, j+=vY, counter++){
        //std::cout<<this->getField(i, j)->toString();
        fieldPtr current = this->getField(i,j);
        if(current->occupied())
        {
            if(current->getUnit()->getColour() == color)
            {
                return fields;
            }
            else
            {
                fields.push_back(this->getField(i, j));
                return fields;
            }
        }
        fields.push_back(this->getField(i, j));
    }
    return fields;
}

unitPtr Board::move(fieldPtr from, fieldPtr to) {
    unitPtr buff = to->getUnit();
    to->setUnit(from->getUnit());
    from->getUnit()->setField(to);
    from->setUnit(nullptr);
    return buff;
}
