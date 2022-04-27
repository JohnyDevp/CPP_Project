#pragma once

#include <QJsonObject>

class JsonPrintable
{
public:
    virtual void read(const QJsonObject &json) = 0;
    virtual void write(QJsonObject &json) const = 0;
};