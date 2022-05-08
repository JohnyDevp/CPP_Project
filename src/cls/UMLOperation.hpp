/**
 * @file UMLOperation.hpp
 * @author xzimol04, xholan11, xholan11, dr. Koci
 * @brief Class for representing uml operation for both interface and class
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <algorithm>
#include "UMLAttribute.hpp"

#include <vector>
#include <string>

#define parametersName "parametersName"

class UMLOperation : public UMLAttribute
{
public:
    /**
     * @brief returns if all is correcly set from the view of the class
     *
     * @param op
     * @return true
     * @return false
     */
    static bool isCorrect(const UMLOperation &op);

    /**
     * @brief List of operation attributes
     *
     */
    QList<UMLAttribute> parameterssOfOperationList;

    /**
     * @brief adding parameter for this operation
     *
     * @param param UMLAttribute parameter of this operation
     * @return true success
     * @return false fail
     */
    bool addOperationParameter(UMLAttribute param);
    /**
     * @brief Construct a new UMLOperation object
     *
     * @param name
     */
    UMLOperation();
    /**
     * @brief Construct a new UMLOperation object
     *
     * @param name
     */
    UMLOperation(QString name);
    /**
     * @brief Construct a new UMLOperation object
     *
     * @param name
     * @param returnType
     * @param modifier
     */
    UMLOperation(QString name, QString returnType, QChar modifier);
    /**
     * @brief Destroy the UMLOperation object
     *
     */
    ~UMLOperation();

    /**
     * @brief converts object to json
     *
     * @param json
     */
    void write(QJsonObject &json) const;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

    // Automaticly generated
    bool operator==(const UMLOperation &other) const;
    bool operator!=(const UMLOperation &other) const;
    /**
     * @brief Conparison of UMLOperations
     *
     * @param uo
     * @return true
     * @return false
     */
    bool operator<(const UMLOperation &uo) const
    {
        QString thisText = this->modifier + this->name;
        foreach (UMLAttribute operationParam, this->parameterssOfOperationList)
        {
            thisText += operationParam.name + operationParam.type;
        }
        thisText += this->type;

        QString uoText = uo.modifier + uo.name;
        foreach (UMLAttribute operationParam, uo.parameterssOfOperationList)
        {
            uoText += uo.name + uo.type;
        }
        uoText += uo.type;
        return (thisText < uoText);
    }
};
