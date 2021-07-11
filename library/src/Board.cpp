#include "Board.h"
#include "Field.h"
#include "Unit.h"
#include <memory>
#include <iostream>

using namespace std;

fieldPtr Board::getField(int x, int y) {
    return array[x][y];
}

Board::~Board() {
    array.clear();
}

Board::Board(){
    for (int i = 0; i < 8; i++) {
        vector<fieldPtr> v = std::vector<fieldPtr>();
        for (int j = 0; j < 8; j++) {
            v.push_back(make_shared<Field>(Field(i, j)));
        }
        array.push_back(v);
    }
}

std::vector<fieldPtr> Board::castRay(char color, int startX, int startY, int vX, int vY, int range) {
    std::vector<fieldPtr> fields;

    for(int i = startX, j = startY, counter = 0; i < 8 && i >= 0 && j < 8 && j >= 0 && counter < range; i += vX, j += vY, counter++) {
        fieldPtr current = this->getField(i,j);
        if (current->occupied())
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
    //if(buff) buff->setField(nullptr);
    to->setUnit(from->getUnit());

    from->getUnit()->setField(to);
    from->setUnit(nullptr);
    return buff;
}

void Board::display() const {
    cout << endl << "   a  b  c  d  e  f  g  h" << endl;
    cout << " -------------------------" << endl;
    for (int y = 7; y >= 0; y--) {
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