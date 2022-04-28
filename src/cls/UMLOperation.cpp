#include "UMLOperation.hpp"

#include <QJsonArray>

bool UMLOperation::addOperationParameter(UMLAttribute param)
{
    // if attribute has been find with desired name then fail
    auto pos = std::find(std::begin(parameterssOfOperationList), std::end(parameterssOfOperationList), param);
    if (pos != std::end(parameterssOfOperationList))
    {
        return false;
    }
    // parameter hasn't been set yet
    this->parameterssOfOperationList.push_back(param);
    return true;
}

UMLOperation::UMLOperation() : parameterssOfOperationList() {}

UMLOperation::UMLOperation(QString name) : UMLAttribute(name)
{
}
bool UMLOperation::operator==(const UMLOperation &other) const
{
    return static_cast<const UMLAttribute &>(*this) == static_cast<const UMLAttribute &>(other);
}
bool UMLOperation::operator!=(const UMLOperation &other) const
{
    return !(*this == other);
}
UMLOperation::UMLOperation(QString name, QString returnType, QChar modifier) : UMLAttribute(modifier, name, returnType), parameterssOfOperationList() {}

UMLOperation::~UMLOperation() {}

void UMLOperation::write(QJsonObject &json) const
{
    UMLAttribute::write(json);

    QJsonArray attrArray;
    for (const UMLAttribute &attr : parameterssOfOperationList)
    {
        QJsonObject attrObject;
        attr.write(attrObject);
        attrArray.append(attrObject);
    }

    json[parametersName] = attrArray;
}

void UMLOperation::read(const QJsonObject &json)
{
    UMLAttribute::read(json);

    if (json.contains(parametersName) && json[parametersName].isArray())
    {
        QJsonArray attrArray = json[parametersName].toArray();

        parameterssOfOperationList.clear();
        parameterssOfOperationList.reserve(attrArray.size());

        for (int i = 0; i < attrArray.size(); i++)
        {
            QJsonObject attrObject = attrArray[i].toObject();
            UMLAttribute attr;
            attr.read(attrObject);
            parameterssOfOperationList.append(attr);
        }
    }
}
