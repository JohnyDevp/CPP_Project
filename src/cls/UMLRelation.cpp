#include "UMLRelation.hpp"

UMLRelation::UMLRelation() {}

UMLRelation::UMLRelation(QString name) : Element(name), startX(-1.0), startY(-1.0), endX(-1.0), endY(-1.0) {}

UMLRelation::UMLRelation(QString name,
                         UMLClassInterfaceTemplate relationFromObject,
                         UMLClassInterfaceTemplate relationToObject,
                         RelationType type) : Element(name),
                                              relationFromObject(relationFromObject),
                                              relationToObject(relationToObject),
                                              relationType(type) {}

UMLRelation::~UMLRelation()
{
}

void UMLRelation::write(QJsonObject &json) const
{
    // TODO: UMLRelation write
}

void UMLRelation::read(const QJsonObject &json)
{
    // TODO: UMLRelation read
}
