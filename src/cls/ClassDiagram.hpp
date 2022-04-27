
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

#define classListName "umlClassList"
#define interfaceListName "umlInterfaceList"
#define relationListName "umlRelationList"

class ClassDiagram : public Element
{

public:
    /**
     * @brief list of all classes for diagram
     *
     */
    QList<UMLClass> classList;
    /**
     * @brief list of all classes for diagram
     *
     */
    QList<UMLInterface> interfaceList;
    /**
     * @brief list of all relations in this diagram
     *
     */
    QList<UMLRelation> relationList;

    /**
     * Creates an instance of UML class and inserts it into diagram
     * If the name already exists returns null
     * @param name Name of the class
     * @return object representing class, if class already exists returns null
     */
    bool addClass(UMLClass &umlClass);

    void updateClass(QString oldName, UMLClass &umlClass);

    void updateInterface(QString oldName, UMLInterface &umlInterface);

    bool addInterface(UMLInterface &UMLInterface);
    /**
     * @param o  object to found
     * @return if the object of found
     * */
    bool findObject(UMLClassInterfaceTemplate &umlObject);
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
    ClassDiagram(QString name);
    /**
     * @brief Destroy the Class Diagram object
     *
     */
    ~ClassDiagram();

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

    bool operator==(const ClassDiagram &other) const;
    bool operator!=(const ClassDiagram &other) const;
};