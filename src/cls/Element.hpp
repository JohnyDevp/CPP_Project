/**
 * @file Element.hpp
 * @author Jan Zimola (xzimol04) and dr. Koci
 * @brief Class representing element in string format - to be inherited
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#define DEFAULT_NAME ""
#define nameName "name"

//#include "qlist.h"
#include <QList>
#include <string>
#include <QString>
#include <QJsonObject>
class Element
{
public:
    /**
     * @brief Checks if the name is not empty and do not contains spaces
     *
     * @param name
     * @return true
     * @return false
     */
    static bool validName(const QString &name);
    /**
     * @brief returns if all is correcly set from the view of the class
     *
     * @param el
     * @return true
     * @return false
     */
    static bool isCorrect(const Element &el);

    QString name;
    /**
     * @brief Default construct a new Element object
     *
     */
    Element();

    Element(QString name);
    /**
     * @brief Destroy the Element object
     *
     */
    ~Element();
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

    // Automaticly generated comparisons
    bool operator==(const Element &other) const;
    bool operator!=(const Element &other) const;
};
