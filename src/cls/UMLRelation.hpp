#pragma once

#include <string>
#include "UMLClass.hpp"

/**
 * type accesible through all classes to determine type of relation
 * */

#define relFromName "relFromName"
#define relToName "relToName"
#define relTypeName "relTypeName"
#define cardiFromName "cardiFromName"
#define cardiToName "cardiToName"

#define startXName "startXName"
#define startYName "startYName"

#define endXName "endXName"
#define endYName "endYName"

class UMLRelation : public Element
{
public:
    enum RelationType
    {
        ASSOCIATION,
        AGGREGATION,
        GENERALIZATION,
        COMPOSITION
    };

    QString relationFrom;
    QString relationTo;
    RelationType relationType;
    QString cardinalityByFromClass;
    QString cardinalityByToClass;

    // graphical points
    double startX, startY;
    double endX, endY;

    /**
     * @brief Default construct a new UMLRelation object
     *UMLClQass
     */
    UMLRelation();

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
    void write(QJsonObject &json) const override;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);
};