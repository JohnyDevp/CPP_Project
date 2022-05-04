#include "UMLAttribute.hpp"

UMLAttribute::UMLAttribute(QString name) : Element(name) {}
bool UMLAttribute::validate(UMLAttribute &attr)
{
    if (attr.name.isEmpty())
        return false;
    if (attr.type.isEmpty())
        return false;
}
UMLAttribute::UMLAttribute() {}
UMLAttribute::UMLAttribute(QString name, QString type) : Element(name), type(type) {}

bool UMLAttribute::operator==(const UMLAttribute &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other);
}

bool UMLAttribute::operator!=(const UMLAttribute &other) const
{
    return !(*this == other);
}

UMLAttribute::UMLAttribute(QChar modifier, QString name, QString type) : Element(name), type(type), modifier(modifier) {}

UMLAttribute::~UMLAttribute() {}

void UMLAttribute::write(QJsonObject &json) const
{
    Element::write(json);

    json[typeName] = type;

    json[modifierName] = QString(modifier);
}

void UMLAttribute::read(const QJsonObject &json)
{
    Element::read(json);

    if (json.contains(typeName) && json[typeName].isString())
    {
        type = json[typeName].toString();
    }

    if (json.contains(modifierName) && json[modifierName].isString())
    {
        modifier = json[modifierName].toString().at(0);
    }
}