#include "UMLClass.hpp"
#include <QJsonArray>

void UMLClass::deleteOperation(UMLOperation operation)
{
    auto pos = std::find(std::begin(umlOperationsList), std::end(umlOperationsList), operation);
    if (pos != std::end(umlOperationsList))
    {
        umlOperationsList.erase(pos);
    }
}

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

bool UMLClass::isCorrect(const UMLClass &cl)
{
    if (!Element::isCorrect(cl))
        return false;

    foreach (const UMLOperation &op, cl.umlOperationsList)
    {
        if (!UMLOperation::isCorrect(op))
            return false;
    }

    foreach (const UMLAttribute &atr, cl.umlAttributesList)
    {
        if (!UMLAttribute::isCorrect(atr))
            return false;
    }

    return true;
}

bool UMLClass::addOperation(UMLOperation operation)
{
    if (std::find(umlOperationsList.begin(), umlOperationsList.end(), operation) != umlOperationsList.end())
    {
        // if exists
        return false;
    }
    // if not exists
    umlOperationsList.push_back(operation);
    return true;
}

UMLClass::UMLClass(String name) : Element(name), umlAttributesList(), umlOperationsList() {}
UMLClass::UMLClass() {}

void UMLClass::write(QJsonObject &json) const
{
    Element::write(json);

    json[isInterfaceName] = isInterface;
    json[xcoordeName] = Xcoord;
    json[ycoordeName] = Ycoord;

    QJsonArray attributesJsonList;
    for (const UMLAttribute &attr : umlAttributesList)
    {
        QJsonObject attrObject;
        attr.write(attrObject);
        attributesJsonList.append(attrObject);
    }
    json[attributeListName] = attributesJsonList;

    QJsonArray operationJsonList;
    for (const UMLOperation &oper : umlOperationsList)
    {
        QJsonObject operObject;
        oper.write(operObject);
        operationJsonList.append(operObject);
    }
    json[operationListName] = operationJsonList;
}

void UMLClass::read(const QJsonObject &json)
{
    Element::read(json);

    if (json.contains(isInterfaceName) && json[isInterfaceName].isBool())
    {
        isInterface = json[isInterfaceName].toBool();
    }

    if (json.contains(xcoordeName) && json[xcoordeName].isDouble())
    {
        Xcoord = json[xcoordeName].toDouble();
    }

    if (json.contains(ycoordeName) && json[ycoordeName].isDouble())
    {
        Ycoord = json[ycoordeName].toDouble();
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

    if (json.contains(operationListName) && json[operationListName].isArray())
    {
        QJsonArray operArray = json[operationListName].toArray();
        umlOperationsList.clear();
        umlOperationsList.reserve(operArray.size());
        for (int i = 0; i < operArray.size(); i++)
        {
            QJsonObject operationObject = operArray[i].toObject();
            UMLOperation oper;
            oper.read(operationObject);
            umlOperationsList.append(oper);
        }
    }
}

bool UMLClass::operator==(const UMLClass &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other);
}

bool UMLClass::operator!=(const UMLClass &other) const
{
    return !(*this == other);
}

UMLClass::~UMLClass() {}
