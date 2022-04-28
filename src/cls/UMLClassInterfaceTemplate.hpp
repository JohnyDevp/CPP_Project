#pragma once

#include <vector>
#include "UMLOperation.hpp"
#include <algorithm>

class UMLClassInterfaceTemplate : public Element
{
public:
  
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