#include "Unit.h"

#include <utility>

const fieldPtr &Unit::getField() const {
    return field;
}

char Unit::getType() const {
    return type;
}

char Unit::getColour() const {
    return colour;
}


void Unit::setField(const fieldPtr &field) {
    Unit::field = field;
}

Unit::Unit(char type, char colour, fieldPtr field) : type(type), colour(colour), field(std::move(field)) {}



