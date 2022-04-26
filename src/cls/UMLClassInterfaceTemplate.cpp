#include "UMLClassInterfaceTemplate.hpp"

UMLClassInterfaceTemplate::UMLClassInterfaceTemplate(std::string name) : Element(name) {}

UMLClassInterfaceTemplate::~UMLClassInterfaceTemplate() {}

bool UMLClassInterfaceTemplate::addOperation(UMLOperation operation)
{
    // operation can exists with same name but not with same return type
    if (std::find(umlOperationsList.begin(), umlOperationsList.end(), operation) != umlOperationsList.end())
    {
        // list already contains the attribute
        return false;
    }
    else
    {
        for (UMLOperation &umlOperation : umlOperationsList)
        {
            // same name but different type - error
            if (!(umlOperation.type == operation.type && umlOperation.name == (operation.name)))
            {
                return false;
            }

            // everything same - error (checking each param)
            if ((umlOperation.type == operation.type) && (umlOperation.name == operation.name))
            {
                for (UMLAttribute &operAttr : operation.parameterssOfOperationList)
                {
                    for (UMLAttribute &thisOperAttr : umlOperation.parameterssOfOperationList)
                    {
                        if ((operAttr.name == thisOperAttr.name) && (operAttr.type == thisOperAttr.type))
                        {
                            return false;
                        }
                    }
                }
                // when there are no params but same names and types
                if (operation.parameterssOfOperationList.empty() && umlOperation.parameterssOfOperationList.empty())
                    return false;
            }

            // added operation differs at least in one parameter against other operations, or is whole the same as one of others-
            // then adding will fail
            // TODO: Ask how he means it
            umlOperationsList.push_back(operation);
            return true;
        }
    }
}
void UMLClassInterfaceTemplate::deleteOperation(std::string name)
{
    auto pos = std::find_if(std::begin(umlOperationsList), std::end(umlOperationsList), [&](const UMLOperation &op)
                            { return op.name == name; });
    if (pos != std::end(umlOperationsList))
    {
        umlOperationsList.erase(pos);
    }
}
