#pragma once

#include "UMLClassInterfaceTemplate.hpp"

class UMLInterface : public UMLClassInterfaceTemplate, JsonPrintable
{
public:
    /**
     * default constructor
     * Creating an instance of interface representing interface in UML diagram
     * @param name name of element
     */
    UMLInterface();
    /**
     * constructor
     * Creating an instance of interface representing interface in UML diagram
     * @param name name of element
     */
    UMLInterface(QString name);
    /**
     * @brief Destroy the UMLInterface object
     *
     */
    ~UMLInterface();

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

    bool operator==(const UMLInterface &other) const;
    bool operator!=(const UMLInterface &other) const;
};
