#include "UMLSeqClass.hpp"

UMLSeqClass::UMLSeqClass(QString name, double Xcoord) : Element(name), Xcoord(Xcoord) {}

UMLSeqClass::UMLSeqClass(UMLClass umlClass, double Xcoord) : Element(umlClass.name), umlClass(umlClass), Xcoord(Xcoord) {}

UMLSeqClass::~UMLSeqClass() {}

UMLSeqClass::UMLSeqClass() : Element(DEFAULT_NAME)
{
}

void UMLSeqClass::write(QJsonObject &json) const
{
    // TODO: UMLSeqClass write
}

void UMLSeqClass::read(const QJsonObject &json)
{
    // TODO: UMLSeqClass read
}
