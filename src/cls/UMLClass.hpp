#pragma once

#include "UMLClassInterfaceTemplate.hpp"
#include "UMLAttribute.hpp"
#include <string>

using String = QString;

#define attributeListName "attributeListName"
#define isInterfaceName "isInterfaceName"

class UMLClass : public UMLClassInterfaceTemplate
{
public:
    bool isInterface = false;
    /**
     * @brief List of attributes of class
     *
     */
    QList<UMLAttribute> umlAttributesList;
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