#include "UMLAttribute.hpp"

UMLAttribute::UMLAttribute(QString name) : Element(name) {}
UMLAttribute::UMLAttribute(QString name, QString type) : Element(name), type(type) {}

bool UMLAttribute::operator==(const UMLAttribute &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other);
}

bool UMLAttribute::operator!=(const UMLAttribute &other) const
{
    return !(*this == other);
}

UMLAttribute::UMLAttribute(char modifier, QString name, QString type) : Element(name), type(type), modifier(modifier) {}

UMLAttribute::~UMLAttribute() {}

void UMLAttribute::write(QJsonObject &json) const
{
    // TODO: UMLAttribute read
}

void UMLAttribute::read(const QJsonObject &json)
{
    // TODO: UMAttribute read
}
