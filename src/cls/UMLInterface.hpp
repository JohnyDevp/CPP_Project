#pragma once

#include "UMLClassInterfaceTemplate.hpp"

class UMLInterface : public UMLClassInterfaceTemplate
{
public:
    /**
     * constructor
     * Creating an instance of interface representing interface in UML diagram
     * @param name name of element
     */
    UMLInterface(std::string name);
    /**
     * @brief Destroy the UMLInterface object
     *
     */
    ~UMLInterface();

    bool operator==(const UMLInterface &other) const;
    bool operator!=(const UMLInterface &other) const;
};
