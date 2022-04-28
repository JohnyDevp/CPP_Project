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

UMLAttribute::UMLAttribute(QChar modifier, QString name, QString type) : Element(name), type(type), modifier(modifier) {}

UMLAttribute::~UMLAttribute() {}

void UMLAttribute::write(QJsonObject &json) const
{ // TODO: UMLAttribute write
    json[nameName] = name;

    json[typeName] = type;

    json[modifierName] = QString(modifier);
}

void UMLAttribute::read(const QJsonObject &json)
{
    // TODO: UMLAttribute read
    if (json.contains(nameName) && json[nameName].isString())
    {
        name = json[nameName].toString();
    }

    if (json.contains(typeName) && json[typeName].isString())
    {
        type = json[typeName].toString();
    }

    if (json.contains(modifierName) && json[modifierName].isString())
    {
        modifier = json[modifierName].toString().at(0);
    }
