
#include "ClassDiagram.hpp"

ClassDiagram::ClassDiagram(std::string name) : Element(name), umlList(), umlRelationList() {}

ClassDiagram::~ClassDiagram() {}

bool ClassDiagram::addObject(UMLClassInterfaceTemplate &umlObject)
{
    auto pos = std::find(std::begin(umlList), std::end(umlList), umlObject);
    if (pos != std::end(umlList))
    {
        // find it
        return false;
    }
    umlList.push_back(umlObject);
    return true;
}

void ClassDiagram::deleteObject(UMLClassInterfaceTemplate &umlObject)
{
    auto pos = std::find(std::begin(umlList), std::end(umlList), umlObject);
    if (pos != std::end(umlList))
    {
        // find it
        umlList.erase(pos);
    }
}

bool ClassDiagram::addRelation(UMLRelation &umlRelation)
{
    umlRelationList.push_back(umlRelation);
    return true;
}
void ClassDiagram::removeRelation(UMLRelation &umlRelation)
{
    auto pos = std::find(std::begin(umlRelationList), std::end(umlRelationList), umlRelation);
    if (pos != std::end(umlRelationList))
    {
        // find it
        umlRelationList.erase(pos);
    }
}

bool ClassDiagram::operator==(const ClassDiagram &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other);
}

bool ClassDiagram::operator!=(const ClassDiagram &other) const
{
    return !(*this == other);
}