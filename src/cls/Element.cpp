

#include "Element.hpp"

Element::Element() {}

Element::Element(QString name) : name(name) {}

Element::~Element() {}

void Element::write(QJsonObject &json) const
{
    // set name
    json[nameName] = name;
}

void Element::read(const QJsonObject &json)
{
    // Read name
    if (json.contains(nameName) && json[nameName].isString())
        name = json[nameName].toString();
}

bool Element::operator==(const Element &other) const
{
    return name == other.name;
}

bool Element::validName(const QString &name)
{
    if (name.isEmpty())
        return false;

    QRegExp rx("(\\s+)");
    if (name.contains(rx))
    {
        return false;
    }
    return true;
}

bool Element::isCorrect(const Element &el)
{
    if (!Element::validName(el.name))
        return false;
    return true;
}

bool Element::operator!=(const Element &other) const
{
    return !(*this == other);
}
