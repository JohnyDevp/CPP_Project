/**
 * class representing element in string format - to be inherited
 * @author dr.Koci, rewritten to c++ by xzimol04
 * */
#pragma once

#define DEFAULT_NAME "default"
#define nameName "name"

#include "JsonPrintable.hpp"
#include <string>

class Element : public JsonPrintable
{
public:
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
    void write(QJsonObject &json) const override;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json) override;

    bool operator==(const Element &other) const;
    bool operator!=(const Element &other) const;
};