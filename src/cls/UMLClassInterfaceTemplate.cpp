#include "UMLClassInterfaceTemplate.hpp"

UMLClassInterfaceTemplate::UMLClassInterfaceTemplate(QString name) : Element(name) {}

// TODO: Maybe needs fixing
UMLClassInterfaceTemplate::UMLClassInterfaceTemplate() : Element(DEFAULT_NAME) {}

UMLClassInterfaceTemplate::~UMLClassInterfaceTemplate() {}

void UMLClassInterfaceTemplate::write(QJsonObject &json) const
{
    // TODO: UMLClassInterface write
}

void UMLClassInterfaceTemplate::read(const QJsonObject &json)
{
    // TODO: UMLClassInterface read
}

// TODO: FIX me maybe
bool UMLClassInterfaceTemplate::addOperation(UMLOperation operation)
{
    for (UMLOperation umlOperation : umlOperationsList)
    {
        // different name -> continue
        if (!(umlOperation.name == operation.name))
        {
            continue;
        }

        // each param is the same in order (considering adding operation and some of existing operations) - error
        // loop through params in operation and test for conformity

        // test for size of both lists - if different, continue (no error then)
        if (operation.parameterssOfOperationList.size() != umlOperation.parameterssOfOperationList.size())
        {
            continue;
        }

        bool error = true;
        for (int index = 0; index < operation.parameterssOfOperationList.size(); index++)
        {
            // get first param of adding operation
            UMLAttribute paramFromOpForAdding = operation.parameterssOfOperationList.at(index);
            UMLAttribute paramFromOperationFromList = umlOperation.parameterssOfOperationList.at(index);
            // different type -> continue
            if (!(paramFromOpForAdding.name == paramFromOperationFromList.name))
            {
                error = false;
                break;
            }
        }
        // same name and same parameters - error
        if (error)
        {
            return false;
        }
    }

    // added operation differs at least in one parameter against other operations, or is whole the same as one of others-
    // then adding will fail
    umlOperationsList.push_back(operation);
    return true;
}
void UMLClassInterfaceTemplate::deleteOperation(QString name)
{
    auto pos = std::find_if(std::begin(umlOperationsList), std::end(umlOperationsList), [&](const UMLOperation &op)
                            { return op.name == name; });
    if (pos != std::end(umlOperationsList))
    {
        umlOperationsList.erase(pos);
    }
}
