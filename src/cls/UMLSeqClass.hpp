/**
 * @file UMLSeqClass.hpp
 * @author xzimol04, xholan11
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
    /**
     * @brief returns if all is correcly set from the view of the class
     *
     * @param cl
     * @return true
     * @return false
     */
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
     * @param name - serves only if there is an instance
     * @param className - the uml class representation - the "root"
     * @param Xcoord
     */
    UMLSeqClass(QString name, QString className, int Xcoord);
    /**
     * @brief Destroy the UMLSeqClass object
     *
     */
    ~UMLSeqClass();

    /**
     * @brief Get the Unique Name object
     *
     * @return true
     * @return false
     */
    QString getUniqueName();

    /**
     * @brief Default construct a new UMLSeqClass object
     *
     */
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
