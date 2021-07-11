#include "Field.h"
#include "Unit.h"
#include <string>
#include <sstream>

int Field::getX() const {
    return x;
}

int Field::getY() const {
    return y;
}

const unitPtr &Field::getUnit() const {
    return unit;
}

void Field::setUnit(const unitPtr &unit) {
    this->unit = unit;
}
bool Field::occupied() const
{
    if(unit != nullptr) {
        return true;
    }
    else
        return false;
    }

Field::Field(int x, int y) : x(x), y(y), unit(nullptr) {}

std::string Field::toString() {
    std::stringstream ss;
    ss << (char)(x+'a') << y+1;
    return ss.str();
}