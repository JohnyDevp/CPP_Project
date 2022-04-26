

#include "UMLClass.hpp"

Element::Element(std::string name) : name(name) {}

Element::~Element() {}

bool Element::operator==(const Element &other) const
{
    return name == other.name;
}

bool Element::operator!=(const Element &other) const
{
    return !(*this == other);
}
