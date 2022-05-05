
/**
 * @file UMLSeqClass.cpp
 * @author Jan Zimola (xzimol04)
 * @brief Source file for UMLSeqClass.hpp
 * @date 2022-04-28
 * @sources: https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
 * @copyright Copyright (c) 2022
 *
 */
#include "UMLSeqClass.hpp"

bool UMLSeqClass::isCorrect(const UMLSeqClass &cl)
{
    if (!Element::isCorrect(cl))
        return false;

    if (cl.className.isEmpty())
        return false;

    QRegExp rx("(\\s+)");
    if (cl.className.contains(rx))
    {
        return false;
    }
    return true;
}

UMLSeqClass::UMLSeqClass(QString name, QString className, int Xcoord) : Element(name), className(className), Xcoord(Xcoord) {}

UMLSeqClass::~UMLSeqClass() {}

UMLSeqClass::UMLSeqClass() : Element(DEFAULT_NAME) {
}

void UMLSeqClass::write(QJsonObject &json) const
{
    Element::write(json);

    json[classNameName] = className;

    json[xcoordName] = Xcoord;
}

void UMLSeqClass::read(const QJsonObject &json)
{

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
