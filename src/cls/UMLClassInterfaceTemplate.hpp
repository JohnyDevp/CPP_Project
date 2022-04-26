#pragma once

#include <vector>
#include "UMLOperation.hpp"
#include <algorithm>

class UMLClassInterfaceTemplate : public Element
{
public:
    /**
     * @brief list of operations of class
     *
     */
    std::vector<UMLOperation> umlOperationsList;
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
    void deleteOperation(std::string name);
    /**
     * @brief Default Construct a new UMLClassInterfaceTemplate object
     *
     */
    UMLClassInterfaceTemplate();
    /**
     * @brief Construct a new UMLClassInterfaceTemplate object
     *
     * @param name
     */
    UMLClassInterfaceTemplate(std::string name);
    /**
     * @brief Destroy the UMLClassInterfaceTemplate object
     *
     */
    ~UMLClassInterfaceTemplate();
};
