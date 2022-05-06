/**
 * @file UMLClass.hpp
 * @author xzimol04 and dr. Koci
 * @brief class representing UML class
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "UMLAttribute.hpp"
#include "UMLOperation.hpp"
#include <string>

using String = QString;

#define attributeListName "attributeListName"
#define operationListName "operationListName"
#define isInterfaceName "isInterfaceName"
#define xcoordeName "xcoordName"
#define ycoordeName "ycoordName"

class UMLClass : public Element
{
public:
    /**
     * @brief returns if all is correcly set from the view of the class
     *
     * @param cl
     * @return true
     * @return false
     */
    static bool isCorrect(const UMLClass &cl);

    bool isInterface = false;
    /**
     * @brief List of attributes of class
     *
     */
    QList<UMLAttribute> umlAttributesList;

    /**
     * @brief list of operations of class
     *
     */
    QList<UMLOperation> umlOperationsList;
    /**
     * @brief variable for storing X position of this class on pane
     *
     */
    double Xcoord = 0.0;
    /**
     * @brief variable for storing Y position of this class on pane
     *
     */
    double Ycoord = 0.0;

    bool addOperation(UMLOperation operation);
    /**
     * @brief delete operation by name
     *
     * @param name
     */
    void deleteOperation(UMLOperation operation);

    /**
     * @brief adding an attribute (which is parameter) of this class
     * checking whether theres no other attribute with same name
     * @param attr parameter represent the whole attribute
     * @return true or false according successfulness of this method
     * */
    bool addAttribute(UMLAttribute &attr);
    /**
     * deleting an attribute - returns nothing
     * @param name name of attribute for deletion
     * */
    void deleteAttribute(const String &name);
    /**
     * @brief Construct a new UMLClass object
     *
     * @param name
     */
    UMLClass(String name);
    /**
     * @brief Destroy the UMLClass object
     *
     */
    ~UMLClass();
    /**
     * @brief Default construct a new UMLClass object
     *
     */
    UMLClass();

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

    // Automaticly generated
    bool operator==(const UMLClass &other) const;
    bool operator!=(const UMLClass &other) const;
};
