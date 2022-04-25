#include "ClassDiagram.hpp"

ClassDiagram::ClassDiagram(std::string name) : Element(name), umlList(), umlRelationList() {}

ClassDiagram::~ClassDiagram() {}

bool ClassDiagram::addClass(UMLClass &umlClass)
{
    auto pos = std::find_if(std::begin(umlList), std::end(umlList), [&umlClass](const UMLClassInterfaceTemplate &umlItem)
                            { return umlItem.name == umlClass.name; });
    if (pos != std::end(umlList))
    {
        // find it
        return false;
    }
    umlList.push_back(umlClass);
    return true;
}

bool ClassDiagram::addInterface(UMLInterface &umlInterface)
{
    auto pos = std::find_if(std::begin(umlList), std::end(umlList), [&umlInterface](const UMLClassInterfaceTemplate &umlItem)
                            { return umlItem.name == umlInterface.name; });
    if (pos != std::end(umlList))
    {
        // find it
        return false;
    }
    umlList.push_back(umlInterface);
    return true;
}

bool ClassDiagram::addRelation(UMLRelation &umlRelation)
{
    auto pos = std::find_if(std::begin(umlRelationList), std::end(umlRelationList), [&umlRelation](const UMLRelation &umlItem)
                            { return umlItem.name == umlRelation.name; });
    if (pos != std::end(umlRelationList))
    {
        // find it
        return false;
    }
    umlRelationList.push_back(umlRelation);
    return true;
}

UMLClass ClassDiagram::createClass(String &name)
{
    // auto pos = std::find_if(std::begin(umlList), std::end(umlList), [&name](const UMLClassInterfaceTemplate &umlItem)
    //                         { return name == umlItem.name; });
    // if (pos != std::end(umlList))
    // {
    //     // find it
    //     return nullptr;
    // }
    // umlList.emplace_back(name);
    // return umlList.back().um;
}

UMLInterface ClassDiagram::createInterface(String &name)
{
}

UMLRelation ClassDiagram::createRelation(String &name)
{
}

void ClassDiagram::deleteClass(UMLClass &umlClass)
{
}

void ClassDiagram::deleteInterface(UMLInterface &umlInterface)
{
}

void ClassDiagram::deleteObject(UMLClassInterfaceTemplate &umlObject)
{
}

UMLClassInterfaceTemplate ClassDiagram::findObject(Element &element)
{
}