#include "UMLClass.hpp"

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

UMLClass::~UMLClass() {}
