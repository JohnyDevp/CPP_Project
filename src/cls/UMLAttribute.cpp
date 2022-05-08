/**
 * @file UMLAttribute.cpp
 * @author xzimol04, xholan11
 * @brief Source file for UMLAttribute.hpp
 * @date 2022-04-28
 * @sources: https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
 * @copyright Copyright (c) 2022
 *
 */

#include "UMLAttribute.hpp"

UMLAttribute::UMLAttribute(QString name) : Element(name) {}
bool UMLAttribute::isCorrect(const UMLAttribute &attr)
{
    if (!Element::isCorrect(attr))
        return false;
    if (attr.type.isEmpty())
        return false;

    QRegExp rx("(\\s+)");
    QRegExp modifierRegex("([\\#\\+\\-\\~])");

    // check if the type contains spaces
    if (attr.type.contains(rx))
    {
        return false;
    }
    // check if the modifier is one of: #, +, -, ~
    if (!QString(attr.modifier).contains(modifierRegex))
    {
        return false;
    }

    return true;
}

UMLAttribute::UMLAttribute() {}

UMLAttribute::UMLAttribute(QString name, QString type) : Element(name), type(type) {}

UMLAttribute::UMLAttribute(QChar modifier, QString name, QString type) : Element(name), type(type), modifier(modifier) {}

UMLAttribute::~UMLAttribute() {}

void UMLAttribute::write(QJsonObject &json) const
{
    // Writting like in the provided source
    Element::write(json);

    json[typeName] = type;

    json[modifierName] = QString(modifier);
}

bool UMLAttribute::operator==(const UMLAttribute &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other) && type == other.type && modifier == other.modifier;
}

bool UMLAttribute::operator!=(const UMLAttribute &other) const
{
    return !(*this == other);
}

void UMLAttribute::read(const QJsonObject &json)
{
    // Reading like in the provided source
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
