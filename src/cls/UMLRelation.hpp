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

private:

    UMLClassInterfaceTemplate relationFromObject;
    UMLClassInterfaceTemplate relationToObject;
    RelationType relationType;
    std::string cardinalityByFromClass;
    std::string cardinalityByToClass;

    // graphical points
    double startX, startY;
    double endX, endY;

    UMLRelation(std::string name);

    UMLRelation(std::string name,
                UMLClassInterfaceTemplate relationFromObject,
                UMLClassInterfaceTemplate relationToObject, RelationType type);
    ~UMLRelation();
};
