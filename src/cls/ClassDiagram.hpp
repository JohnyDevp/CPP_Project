/**
 * @file ClassDiagram.hpp
 * @author Jan Zimola (xzimol04)
 * @brief Class representing the whole class diagram with its items
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "UMLRelation.hpp"
#include "Element.hpp"
#include "UMLClass.hpp"
#include "qmap.h"

#define classListName "umlClassList"
#define interfaceListName "umlInterfaceList"
#define relationListName "umlRelationList"
#define isInterfaceName "isInterfaceName"
#define relationIndexName "relationIndex"

class ClassDiagram : public Element
{

public:
    static bool isCorrect(const ClassDiagram &dia);

    /**
     * @brief Keep track of index that will have a new UMLRelation
     *
     */
    int relationIndex = 0;
    /**
     * @brief list of all classes for diagram
     *
     */
    QMap<QString, UMLClass> classList;
    /**
     * @brief list of all relations in this diagram
     *
     */
    QMap<int, UMLRelation> relationList;

    /**
     * @brief Returns if UMLClass exists using name
     *
     * @param className
     * @return true
     * @return false
     */
    bool existsClass(QString &className);

    /**
     * @brief Returns if UMLClass exists UMLClass instance
     *
     * @param umlClass
     * @return true
     * @return false
     */
    bool existsClass(UMLClass &umlClass);
    /**
     * Creates an instance of UML class and inserts it into diagram
     * @param name Name of the class
     * @return bool if the class was added
     */
    bool addClass(UMLClass &umlClass);

    /**
     * @brief If the class changed name, it deletes the previeos map instance and creates new one using the new
     * name as a key
     *
     * @param oldName
     * @param umlClass
     */
    void updateClass(QString oldName, UMLClass &umlClass);

    /**
     * @brief Adds relation to the relatinList map and returns updates instance with
     * correct index
     *
     * @param umlRelation
     * @return UMLRelation
     */
    UMLRelation addRelation(UMLRelation &umlRelation);
    /**
     * @param umlRelation relation object to be removed
     * */
    void removeRelation(UMLRelation &umlRelation);

    /**
     * @brief Default Construct a new Class Diagram object
     *
     */
    ClassDiagram();
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
    void write(QJsonObject &json) const;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

    // Automacly generated comparisons using name

    bool operator==(const ClassDiagram &other) const;
    bool operator!=(const ClassDiagram &other) const;
};
