#include "UMLOperation.hpp"

bool UMLOperation::addOperationParameter(UMLAttribute param)
{
    auto pos = std::find_if(std::begin(parameterssOfOperationList), std::end(parameterssOfOperationList), [&](UMLAttribute atr)
                            { return atr.name == param.name; });
    // if attribute has been find with desired name then fail
    if (pos != std::end(parameterssOfOperationList))
    {
        return false;
    }
    // parameter hasn't been set yet
    this->parameterssOfOperationList.push_back(param);
    return true;
}

UMLOperation::UMLOperation(std::string name) : UMLAttribute(name)
{
}
UMLOperation::UMLOperation(std::string name, std::string returnType, char modifier) : UMLAttribute(modifier, name, returnType)
{
}

UMLOperation::~UMLOperation()
{
}
