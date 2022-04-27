#include "UMLOperation.hpp"

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
UMLOperation::UMLOperation(QString name, QString returnType, char modifier) : UMLAttribute(modifier, name, returnType) {}

UMLOperation::~UMLOperation() {}

void UMLOperation::write(QJsonObject &json) const
{
    // TODO: UMLOperation write
}

void UMLOperation::read(const QJsonObject &json)
{
    // TODO: UMLOperation read
}
