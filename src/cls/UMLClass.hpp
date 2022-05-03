/**
 * @file UMLClass.hpp
 * @author Jan Zimola (xzimol04) and dr. Koci
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
    void deleteOperation(QString name);

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
    virtual void write(QJsonObject &json) const override;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    virtual void read(const QJsonObject &json);

    bool operator==(const UMLClass &other) const;
    bool operator!=(const UMLClass &other) const;
};
