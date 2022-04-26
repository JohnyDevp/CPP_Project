//#pragma once

#ifndef _UML_RELATION_HPP
#define _UML_RELATION_HPP

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
    std::string cardinalityByFromClass;
    std::string cardinalityByToClass;

    // graphical points
    double startX, startY;
    double endX, endY;

    UMLRelation(std::string name);
    UMLRelation(std::string name,
                UMLClassInterfaceTemplate relationFromObject,
                UMLClassInterfaceTemplate relationToObject,
                RelationType type);
    ~UMLRelation();
};

#endif
