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

    bool existsClass(QString &className);

    bool existsClass(UMLClass &umlClass);
    /**
     * Creates an instance of UML class and inserts it into diagram
     * If the name already exists returns null
     * @param name Name of the class
     * @return object representing class, if class already exists returns null
     */
    bool addClass(UMLClass &umlClass);

    void updateClass(QString oldName, UMLClass &umlClass);

    /**
     * @param umlRelation relation object
     * @return boolean according success of adding operation
     */
    UMLRelation addRelation(UMLRelation &umlRelation);
    /**
     * @param umlRelation relation object to be removed
     * */
    void removeRelation(UMLRelation &umlRelation);

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
