/**
 * @file UMLAttribute.hpp
 * @author Jan Zimola (xzimol04) and dr.Koci
 * @brief Class representing uml attribute
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <string>
#include "Element.hpp"

#define typeName "typeName"
#define modifierName "modifierName"

class UMLAttribute : public Element
{
public:
    QString type;
    QChar modifier;

    /**
     * @brief Default construct a new UMLAttribute object
     *
     */
    UMLAttribute();

    /**
     * @brief Construct a new UMLAttribute object
     *
     * @param name
     */
    UMLAttribute(QString name);
    /**
     * @brief Construct a new UMLAttribute object
     *
     * @param name
     * @param type
     */
    UMLAttribute(QString name, QString type);
    /**
     * @brief Construct a new UMLAttribute object
     *
     * @param modifier
     * @param name
     * @param type
     */
    UMLAttribute(QChar modifier, QString name, QString type);
    ~UMLAttribute();

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

    bool operator==(const UMLAttribute &other) const;
    bool operator!=(const UMLAttribute &other) const;
};