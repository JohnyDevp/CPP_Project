#pragma once

#include <string>
#include "UMLClass.hpp"

class UMLSeqClass : public Element
{
    /**
     * @brief Xcoord
     *
     */
    double Xcoord;
    /**
     * @brief UMlClass instance
     *
     */
    UMLClass umlClass;

public:
    /**
     * @brief Construct a new UMLSeqClass object
     *
     * @param name
     * @param Xcoord
     */
    UMLSeqClass(QString name, double Xcoord);
    /**
     * @brief Construct a new UMLSeqClass object
     *
     * @param umlClass
     * @param Xcoord
     */
    UMLSeqClass(UMLClass umlClass, double Xcoord);
    /**
     * @brief Destroy the UMLSeqClass object
     *
     */
    ~UMLSeqClass();

    UMLSeqClass();

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
