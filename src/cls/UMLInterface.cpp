#include "UMLInterface.hpp"

UMLInterface::UMLInterface() {}

UMLInterface::UMLInterface(QString name) : UMLClassInterfaceTemplate(name) {}

UMLInterface::~UMLInterface()
{
}

void UMLInterface::write(QJsonObject &json) const
{
    // TODO: UMLInterface write
}

void UMLInterface::read(const QJsonObject &json)
{
    // TODO: UMLInterface read
}

bool UMLInterface::operator==(const UMLInterface &other) const
{
    return static_cast<const UMLClassInterfaceTemplate &>(*this) == static_cast<const UMLClassInterfaceTemplate &>(other);
}

bool UMLInterface::operator!=(const UMLInterface &other) const
{
    return !(*this == other);
}
