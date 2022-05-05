/**
 * @file UMLSeqClass.hpp
 * @author Jan Zimola (xzimol04)
 * @brief Class that represents class in Sequence Diagram
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <string>
#include "UMLClass.hpp"

#define classNameName "className"
#define xcoordName "Xcoord"

class UMLSeqClass : public Element
{
public:
    static bool isCorrect(const UMLSeqClass &cl);

    int Xcoord;
    /**
     * @brief UMlClass instance
     *
     */
    QString className;

    /**
     * @brief Construct a new UMLSeqClass object
     *
     * @param name
     * @param Xcoord
     */
    UMLSeqClass(QString name, QString className, int Xcoord);
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
    void write(QJsonObject &json) const;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);
};
