/**
 * @file JsonPrintable.hpp
 * @author Jan Zimola (xzimol04)
 * @brief Abstract Class that declares read and write functions
 * that are used to convert to json and from json
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include <QJsonObject>

class JsonPrintable
{
public:
    virtual void read(const QJsonObject &json) = 0;
    virtual void write(QJsonObject &json) const = 0;
};