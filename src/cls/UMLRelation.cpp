#include "UMLRelation.hpp"

UMLRelation::UMLRelation(std::string name) : Element(name), startX(-1.0), startY(-1.0), endX(-1.0), endY(-1.0) {}

UMLRelation::UMLRelation(std::string name,
                         UMLClassInterfaceTemplate relationFromObject,
                         UMLClassInterfaceTemplate relationToObject,
                         RelationType type) : Element(name),
                                              relationFromObject(relationFromObject),
                                              relationToObject(relationToObject),
                                              relationType(type) {}

UMLRelation::~UMLRelation()
{
}
