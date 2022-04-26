#pragma once

#include "UMLClassInterfaceTemplate.hpp"
#include "UMLAttribute.hpp"
#include <string>

using String = std::string;
class UMLClass : public UMLClassInterfaceTemplate
{
public:
    /**
     * @brief List of attributes of class
     *
     */
    std::vector<UMLAttribute> umlAttributesList;
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

    bool operator==(const UMLClass &other) const;
    bool operator!=(const UMLClass &other) const;
};