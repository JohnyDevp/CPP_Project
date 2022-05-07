
/**
 * @file UMLSeqClass.cpp
 * @author xzimol04
 * @brief Source file for UMLSeqClass.hpp
 * @date 2022-04-28
 * @sources: https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
 * @copyright Copyright (c) 2022
 *
 */
#include "UMLSeqClass.hpp"

bool UMLSeqClass::isCorrect(const UMLSeqClass &cl)
{
    // In addiction can be empty
    if (!Element::isCorrect(cl) && !cl.name.isEmpty())
        return false;

    if (cl.className.isEmpty())
        return false;

    // Check if the class name does not contains spaces
    QRegExp rx("(\\s+)");
    if (cl.className.contains(rx))
    {
        return false;
    }
    return true;
}

UMLSeqClass::UMLSeqClass(QString name, QString className, int Xcoord) : Element(name), className(className), Xcoord(Xcoord) {}

UMLSeqClass::~UMLSeqClass() {}

QString UMLSeqClass::getUniqueName()
{
    return name + className;
}

UMLSeqClass::UMLSeqClass() : Element(DEFAULT_NAME) {}

void UMLSeqClass::write(QJsonObject &json) const
{
    // Writting like in the provided source

    Element::write(json);

    json[classNameName] = className;

    json[xcoordName] = Xcoord;
}

void UMLSeqClass::read(const QJsonObject &json)
{
    // Reading like in the provided source

    Element::read(json);

    if (json.contains(classNameName) && json[classNameName].isString())
    {
        className = json[classNameName].toString();
    }

    if (json.contains(xcoordName) && json[xcoordName].isDouble())
    {
        Xcoord = json[xcoordName].toInt();
    }
}
