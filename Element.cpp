

#include "UMLClass.hpp"

Element::Element(std::string name) : name(name) {}

Element::~Element() {}

inline bool Element::operator==(const Element &other) const
{
    return name == other.name;
}
