#include "UMLAttribute.hpp"

UMLAttribute::UMLAttribute(std::string name) : Element(name)
{
}
UMLAttribute::UMLAttribute(std::string name, std::string type) : UMLAttribute(name)
{
    this->type = type;
}

UMLAttribute::UMLAttribute(char modifier, std::string name, std::string type) : Element(name), type(type), modifier(modifier) {}

UMLAttribute::~UMLAttribute() {}

inline bool UMLAttribute::operator==(const UMLAttribute &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other) && type == other.type && modifier == other.modifier;
}

inline bool UMLAttribute::operator!=(const UMLAttribute &other) const
{
    return !(*this == other);
}
