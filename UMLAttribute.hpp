#pragma once

#include <string>
#include "Element.hpp"

class UMLAttribute : public Element
{
public:
    /**
     * @brief name of the type
     *
     */
    std::string type;
    /**
     * @brief name of the modifier
     *
     */
    char modifier;

    /**
     * @brief Construct a new UMLAttribute object
     *
     * @param name
     */
    UMLAttribute(std::string name);
    /**
     * @brief Construct a new UMLAttribute object
     *
     * @param name
     * @param type
     */
    UMLAttribute(std::string name, std::string type);
    /**
     * @brief Construct a new UMLAttribute object
     *
     * @param modifier
     * @param name
     * @param type
     */
    UMLAttribute(char modifier, std::string name, std::string type);
    ~UMLAttribute();
    bool operator==(const UMLAttribute &other) const;
    bool operator!=(const UMLAttribute &other) const;
};