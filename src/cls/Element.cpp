

#include "Element.hpp"

Element::Element()
    : name(DEFAULT_NAME) {}

Element::Element(QString name) : name(name) {}

Element::~Element() {}

void Element::write(QJsonObject &json) const
{
    // TODO: Element write
}

void Element::read(const QJsonObject &json)
{
    // TODO: Element read
}

bool Element::operator==(const Element &other) const
{
    return name == other.name;
}

bool Element::operator!=(const Element &other) const
{
    return !(*this == other);
}
