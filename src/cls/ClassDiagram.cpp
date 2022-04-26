#include "ClassDiagram.hpp"

//ClassDiagram::ClassDiagram(std::string name) : Element(name), umlList(), umlRelationList() {}

ClassDiagram::~ClassDiagram() {}

//bool ClassDiagram::addClass(UMLClass &umlClass)
//{
//    auto pos = std::find(std::begin(umlList), std::end(umlList), umlClass);
//    if (pos != std::end(umlList))
//    {
//        // find it
//        return false;
//    }
//    umlList.push_back(umlClass);
//    return true;
//}

//bool ClassDiagram::addInterface(UMLInterface &umlInterface)
//{
//    auto pos = std::find(std::begin(umlList), std::end(umlList), umlInterface);
//    if (pos != std::end(umlList))
//    {
//        // find it
//        return false;
//    }
//    umlList.push_back(umlInterface);
//    return true;
//}

bool ClassDiagram::addRelation(UMLRelation &umlRelation)
{
    umlRelationList.push_back(umlRelation);
    return true;
}

bool ClassDiagram::operator==(const ClassDiagram &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other);
}

//bool ClassDiagram::operator!=(const ClassDiagram &other) const
//{
//    return !(*this == other);
//}

//void ClassDiagram::deleteClass(UMLClass &umlClass)
//{
//    auto pos = std::find(std::begin(umlList), std::end(umlList), umlClass);
//    if (pos != std::end(umlList))
//    {
//        // find it
//        umlList.erase(pos);
//    }
//}

//void ClassDiagram::deleteInterface(UMLInterface &umlInterface)
//{
//    auto pos = std::find(std::begin(umlList), std::end(umlList), umlInterface);
//    if (pos != std::end(umlList))
//    {
//        // find it
//        umlList.erase(pos);
//    }
//}

void ClassDiagram::deleteObject(UMLClassInterfaceTemplate &umlObject)
{
}

bool addObject(UMLClassInterfaceTemplate &umlObject)
{
}

UMLClassInterfaceTemplate ClassDiagram::findObject(Element &element)
{
}
