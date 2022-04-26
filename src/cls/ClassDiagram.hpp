
#pragma once
/**
 * class representing the whole class diagram with its items
 * @author xzimol04
 * */

#include "UMLClassInterfaceTemplate.hpp"
#include "UMLRelation.hpp"
#include "Element.hpp"
#include "UMLClass.hpp"
#include "UMLInterface.hpp"

class ClassDiagram : public Element
{
public:
    /**
     * @brief list of all classes and interfaces in class diagram
     *
     */
    std::vector<UMLClassInterfaceTemplate> umlList;
    /**
     * @brief list of all relations in this diagram
     *
     */
    std::vector<UMLRelation> umlRelationList;

    /**
     * Creates an instance of UML class and inserts it into diagram
     * If the name already exists returns null
     * @param name Name of the class
     * @return object representing class, if class already exists returns null
     */
    bool addObject(UMLClassInterfaceTemplate &umlClass);
    /**
     * @brief remove object representation from uml class diagram
     *
     * @param umlObject
     */
    void deleteObject(UMLClassInterfaceTemplate &umlObject);
    /**
     * @param o can be either name of object or object to found
     * @return found object or null if not found or bad object has been passed
     * */
    UMLClassInterfaceTemplate findObject(Element &element);
    /**
     * @param umlRelation relation object
     * @return boolean according success of adding operation
     */
    bool addRelation(UMLRelation &umlRelation);
    /**
     * @param umlRelation relation object to be removed
     * */
    void removeRelation(UMLRelation &umlRelation);

    /**
     * @brief Construct a new Class Diagram object
     *
     * @param name
     */
    ClassDiagram(std::string name);
    /**
     * @brief Destroy the Class Diagram object
     *
     */
    ~ClassDiagram();

    bool operator==(const ClassDiagram &other) const;
    bool operator!=(const ClassDiagram &other) const;
};