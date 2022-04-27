#pragma once

#include <algorithm>
#include "UMLAttribute.hpp"

/**
 * class for representing uml operation for both interface and class
 * @author xzimol04
 * */

#include <vector>
#include <string>

class UMLOperation : public UMLAttribute
{
public:
    /**
     * @brief list of all parameters of this operation
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
    UMLOperation(QString name);
    /**
     * @brief Construct a new UMLOperation object
     *
     * @param name
     * @param returnType
     * @param modifier
     */
    UMLOperation(QString name, QString returnType, char modifier);
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
    void write(QJsonObject &json) const override;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

    bool operator==(const UMLOperation &other) const;
    bool operator!=(const UMLOperation &other) const;
};
