#include "UMLClass.hpp"
#include <QJsonArray>

bool UMLClass::addAttribute(UMLAttribute &attr)
{
    if (std::find(umlAttributesList.begin(), umlAttributesList.end(), attr) != umlAttributesList.end())
    {
        // if exists
        return false;
    }
    // if not exists
    umlAttributesList.push_back(attr);
    return true;
}
void UMLClass::deleteAttribute(const String &name)
{
    auto pos = std::find_if(std::begin(umlAttributesList), std::end(umlAttributesList), [&name](UMLAttribute &attr)
                            { return name == attr.name; });
    if (pos != std::end(umlAttributesList))
    {
        umlAttributesList.erase(pos);
    }
}

bool UMLClass::operator==(const UMLClass &other) const
{
    return static_cast<const UMLClassInterfaceTemplate &>(*this) == static_cast<const UMLClassInterfaceTemplate &>(other);
}

bool UMLClass::operator!=(const UMLClass &other) const
{
    return !(*this == other);
}

UMLClass::UMLClass(String name) : UMLClassInterfaceTemplate(name) {}
UMLClass::UMLClass() : UMLClassInterfaceTemplate(QString(DEFAULT_NAME)) {}

void UMLClass::write(QJsonObject &json) const
{
    json[nameName] = name;

    json[isInterfaceName] = isInterface;

    QJsonArray attributesJsonList;
    for (const UMLAttribute &attr : umlAttributesList)
    {
        QJsonObject attrObject;
        attr.write(attrObject);
        attributesJsonList.append(attrObject);
    }
    json[attributeListName] = attributesJsonList;
}

void UMLClass::read(const QJsonObject &json)
{
    if (json.contains(nameName) && json[nameName].isString())
    {
        name = json[nameName].toString();
    }

    if (json.contains(isInterfaceName) && json[isInterfaceName].isBool())
    {
        isInterface = json[isInterfaceName].toBool();
    }

    if (json.contains(attributeListName) && json[attributeListName].isArray())
    {
        QJsonArray attrArray = json[attributeListName].toArray();
        umlAttributesList.clear();
        umlAttributesList.reserve(attrArray.size());
        for (int i = 0; i < attrArray.size(); i++)
        {
            QJsonObject attrObject = attrArray[i].toObject();
            UMLAttribute attr;
            attr.read(attrObject);
            umlAttributesList.append(attr);
        }
    }
}

UMLClass::~UMLClass() {}
