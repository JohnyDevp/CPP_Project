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
     * @brief Default Construct a new UMLClassInterfaceTemplate object
     *
     */
    UMLClassInterfaceTemplate();
    /**
     * @brief Construct a new UMLClassInterfaceTemplate object
     *
     * @param name
     */
    UMLClassInterfaceTemplate(QString name);
    /**
     * @brief Destroy the UMLClassInterfaceTemplate object
     *
     */
    ~UMLClassInterfaceTemplate();

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
};