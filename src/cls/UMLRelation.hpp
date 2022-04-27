#pragma once

#include <string>
#include "UMLClassInterfaceTemplate.hpp"

/**
 * type accesible through all classes to determine type of relation
 * */

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

    UMLClassInterfaceTemplate relationFromObject;
    UMLClassInterfaceTemplate relationToObject;
    RelationType relationType;
    QString cardinalityByFromClass;
    QString cardinalityByToClass;

    // graphical points
    double startX, startY;
    double endX, endY;

    /**
     * @brief Default construct a new UMLRelation object
     *
     */
    UMLRelation();

    UMLRelation(QString name);
    UMLRelation(QString name,
                UMLClassInterfaceTemplate relationFromObject,
                UMLClassInterfaceTemplate relationToObject, RelationType type);

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