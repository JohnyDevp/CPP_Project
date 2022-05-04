
#include "ClassDiagram.hpp"
#include <QJsonArray>

ClassDiagram::ClassDiagram() : classList(), relationList() {}
ClassDiagram::ClassDiagram(QString name) : Element(name), classList(), relationList() {}

ClassDiagram::~ClassDiagram() {}

void ClassDiagram::write(QJsonObject &json) const
{
    Element::write(json);

    json[relationIndexName] = relationIndex;

    QJsonArray classJsonList;

    foreach (const UMLClass &uml, classList)
    {
        QJsonObject umlObject;
        uml.write(umlObject);
        classJsonList.append(umlObject);
    }
    json[classListName] = classJsonList;

    QJsonArray relationJsonList;
    for (const UMLRelation &relation : relationList)
    {
        QJsonObject umlRelation;
        relation.write(umlRelation);
        relationJsonList.append(umlRelation);
    }
    json[relationListName] = relationJsonList;
}

void ClassDiagram::read(const QJsonObject &json)
{
    Element::read(json);

    if (json.contains(relationIndexName) && json[relationIndexName].isDouble())
    {
        relationIndex = json[relationIndexName].toInt();
    }

    // Read UMLClass objects
    if (json.contains(classListName) && json[classListName].isArray())
    {
        QJsonArray classArray = json[classListName].toArray();
        classList.clear();

        for (int classIndex = 0; classIndex < classArray.size(); classIndex++)
        {
            QJsonObject classObject = classArray[classIndex].toObject();
            UMLClass cla;
            cla.read(classObject);
            classList[cla.name] = cla;
        }
    }
    // Read UMLRelation objects
    if (json.contains(relationListName) && json[relationListName].isArray())
    {
        QJsonArray array = json[interfaceListName].toArray();
        relationList.clear();

        relationIndex = array.size();

        for (int index = 0; index < array.size(); index++)
        {
            QJsonObject relJson = array[index].toObject();
            UMLRelation rel;
            rel.read(relJson);
            rel.index = index;
            relationList[index] = rel;
        }
    }
}

bool ClassDiagram::existsClass(UMLClass &umlClass)
{
    return classList.contains(umlClass.name);
}

bool ClassDiagram::isCorrect(const ClassDiagram &dia)
{
    if (!Element::isCorrect(dia))
        return false;

    foreach (const UMLRelation &rel, dia.relationList)
    {
        if (!UMLRelation::isCorrect(rel))
            return false;
    }
    foreach (const UMLClass &cl, dia.classList)
    {
        if (!UMLClass::isCorrect(cl))
            return false;
    }

    return true;
}

bool ClassDiagram::existsClass(QString &className)
{
    return classList.contains(className);
}

bool ClassDiagram::addClass(UMLClass &umlClass)
{
    if (classList.contains(umlClass.name))
        return false;
    classList[umlClass.name] = umlClass;
    return true;
}

void ClassDiagram::updateClass(QString oldName, UMLClass &umlClass)
{
    if (classList.contains(oldName))
        classList.remove(oldName);

    classList[umlClass.name] = umlClass;
}

UMLRelation ClassDiagram::addRelation(UMLRelation &umlRelation)
{
    umlRelation.index = relationIndex;
    relationList[umlRelation.index] = umlRelation;
    relationIndex++;

    return umlRelation;
}
void ClassDiagram::removeRelation(UMLRelation &umlRelation)
{
    relationList.remove(umlRelation.index);
}

bool ClassDiagram::operator==(const ClassDiagram &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other);
}

bool ClassDiagram::operator!=(const ClassDiagram &other) const
{
    return !(*this == other);
}