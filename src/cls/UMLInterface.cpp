#include "UMLInterface.hpp"

UMLInterface::UMLInterface(std::string name) : UMLClassInterfaceTemplate(name) {}

UMLInterface::~UMLInterface()
{
}

bool UMLInterface::operator==(const UMLInterface &other) const
{
    return static_cast<const UMLClassInterfaceTemplate &>(*this) == static_cast<const UMLClassInterfaceTemplate &>(other);
}

bool UMLInterface::operator!=(const UMLInterface &other) const
{
    return !(*this == other);
}
