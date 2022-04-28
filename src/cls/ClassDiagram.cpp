/*
 * Filename: /home/musta-pollo/VUT/ICP_COL/CPP_Project/src/cls/ClassDiagram.cpp
 * Path: /home/musta-pollo/VUT/ICP_COL/CPP_Project/src/cls
 * Created Date: Wednesday, April 27th 2022, 7:17:44 pm
 * Author: Jan Zimola
 * Sources: https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
 * Copyright (c) 2022 Your Company
 */

#include "ClassDiagram.hpp"
#include <QJsonArray>

ClassDiagram::ClassDiagram(QString name) : Element(name), classList(), relationList() {}

ClassDiagram::~ClassDiagram() {}

void ClassDiagram::write(QJsonObject &json) const
{
    Element::write(json);

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
        relationList.reserve(array.size());
        for (int index = 0; index < array.size(); index++)
        {
            QJsonObject relJson = array[index].toObject();
            UMLRelation rel;
            rel.read(relJson);
            relationList.append(rel);
        }
    }
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

bool ClassDiagram::addRelation(UMLRelation &umlRelation)
{
    relationList.push_back(umlRelation);
    return true;
}
void ClassDiagram::removeRelation(UMLRelation &umlRelation)
{
    auto pos = std::find(std::begin(relationList), std::end(relationList), umlRelation);
    if (pos != std::end(relationList))
    {
        // find it
        relationList.erase(pos);
    }
}

bool ClassDiagram::operator==(const ClassDiagram &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other);
}

bool ClassDiagram::operator!=(const ClassDiagram &other) const
{
    return !(*this == other);
}