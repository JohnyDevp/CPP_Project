/**
 * @file UMLRelation.cpp
 * @author xzimol04, xholan11
 * @brief Source file for UMLRelation.hpp
 * @date 2022-04-28
 * @sources: https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
 * @copyright Copyright (c) 2022
 *
 */

#include "UMLRelation.hpp"

bool UMLRelation::isCardinalityCorrect(QString cardi)
{
    // Regex that represents correct cardinality
    QRegExp relReg("([0-9]+[\\.][\\.][0-9]+|[0-9]+[\\.][\\.][\\*]|[\\*]|[0-9]+)");

    // Check if the cardinality is incorrect
    if (!relReg.exactMatch(cardi) && !cardi.isEmpty())
    {
        return false;
    }
    return true;
}

bool UMLRelation::isCorrect(const UMLRelation &rel)
{
    if (!UMLRelation::isCardinalityCorrect(rel.cardinalityByFromClass))
        return false;
    if (!UMLRelation::isCardinalityCorrect(rel.cardinalityByToClass))
    {
        return false;
    }

    return true;
}

UMLRelation::UMLRelation()
{
}

UMLRelation::UMLRelation(QString name) : Element(name), startX(-1.0), startY(-1.0), endX(-1.0), endY(-1.0) {}

UMLRelation::UMLRelation(QString name,
                         QString relationFrom,
                         QString relationToName,
                         RelationType type) : Element(name),
                                              relationFrom(relationFrom),
                                              relationTo(relationToName),
                                              relationType(type) {}

UMLRelation::~UMLRelation()
{
}

void UMLRelation::write(QJsonObject &json) const
{
    // Writting like in the provided source

    Element::write(json);

    json[relFromName] = relationFrom;
    json[relToName] = relationTo;
    json[relTypeName] = relationType;
    json[cardiFromName] = cardinalityByFromClass;
    json[cardiToName] = cardinalityByToClass;

    json[startXName] = startX;
    json[startYName] = startY;
    json[endXName] = endX;
    json[endYName] = endY;
}

void UMLRelation::read(const QJsonObject &json)
{
    // Reading like in the provided source

    if (json.contains(relFromName) && json[relFromName].isString())
    {
        relationFrom = json[relFromName].toString();
    }

    if (json.contains(relToName) && json[relToName].isString())
    {
        relationTo = json[relToName].toString();
    }

    if (json.contains(relTypeName) && json[relTypeName].isDouble())
    {
        relationType = static_cast<RelationType>(json[relTypeName].toInt());
    }

    if (json.contains(cardiFromName) && json[cardiFromName].isString())
    {
        cardinalityByFromClass = json[cardiFromName].toString();
    }

    if (json.contains(cardiToName) && json[cardiToName].isString())
    {
        cardinalityByToClass = json[cardiToName].toString();
    }

    if (json.contains(startXName) && json[startXName].isDouble())
    {
        startX = json[startXName].toDouble();
    }

    if (json.contains(startYName) && json[startYName].isDouble())
    {
        startY = json[startYName].toDouble();
    }

    if (json.contains(endXName) && json[endXName].isDouble())
    {
        endX = json[endXName].toDouble();
    }

    if (json.contains(endYName) && json[endYName].isDouble())
    {
        endY = json[endYName].toDouble();
    }
}
