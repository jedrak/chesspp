#include "Unit.h"

const fieldPtr &Unit::getField() const {
    return field;
}

char Unit::getType() const {
    return type;
}

char Unit::getColour() const {
    return colour;
}


bool Unit::setField(const fieldPtr &field) {
    Unit::field = field;
}

Unit::Unit(char type, char colour, const fieldPtr &field) : type(type), colour(colour), field(field) {}

Unit::Unit() {}

