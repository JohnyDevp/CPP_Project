/**
 * @file UMLRelation.hpp
 * @author xzimol04, xholan11
 * @brief  Class that defines relationship between UML classes
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <string>
#include "UMLClass.hpp"

#define relFromName "relFromName"
#define relToName "relToName"
#define relTypeName "relTypeName"
#define cardiFromName "cardiFromName"
#define cardiToName "cardiToName"

#define startXName "startXName"
#define startYName "startYName"

#define endXName "endXName"
#define endYName "endYName"

#define indexName "index"

class UMLRelation : public Element
{
public:
    int index;
    enum RelationType
    {
        ASSOCIATION,
        AGGREGATION,
        GENERALIZATION,
        COMPOSITION
    };
    /**
     * @brief Name of UMLClass at the start of relation
     *
     */
    QString relationFrom;
    /**
     * @brief Name of UMLClass at the end of relation
     *
     */
    QString relationTo;

    RelationType relationType;

    // Cardinalities at the sides of the relation
    QString cardinalityByFromClass;
    QString cardinalityByToClass;

    // graphical points
    double startX, startY;
    double endX, endY;

    /**
     * @brief Checks if cardinality is correctly entered
     *
     * @param cardi
     * @return true
     * @return false
     */
    static bool isCardinalityCorrect(QString cardi);
    /**
     * @brief returns if all is correcly set from the view of the class
     *
     * @param rel
     * @return true
     * @return false
     */
    static bool isCorrect(const UMLRelation &rel);

    /**
     * @brief Default construct a new UMLRelation object
     *UMLClQass
     */
    UMLRelation();
    // Constructors
    UMLRelation(QString name);
    UMLRelation(QString name,
                QString relationFrom,
                QString relationToName, RelationType type);

    ~UMLRelation();
    /**
     * @brief converts object to json
     *
     * @param json
     */
    void write(QJsonObject &json) const;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);
};