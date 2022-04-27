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

ClassDiagram::ClassDiagram(QString name) : Element(name), classList(), interfaceList(), relationList() {}

ClassDiagram::~ClassDiagram() {}

void ClassDiagram::write(QJsonObject &json) const
{
    json[nameName] = name;

    QJsonArray interfaceJsonList;
    for (const UMLInterface &uml : interfaceList)
    {
        QJsonObject umlObject;
        uml.write(umlObject);
        interfaceJsonList.append(umlObject);
    }
    json[interfaceListName] = interfaceJsonList;

    QJsonArray classJsonList;
    for (const UMLClass &uml : classList)
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

// TODO: Class::read
void ClassDiagram::read(const QJsonObject &json)
{
    // Read name
    if (json.contains(nameName) && json[nameName].isString())
        name = json[nameName].toString();
    // Read UMLClass objects
    if (json.contains(classListName) && json[classListName].isArray())
    {
        QJsonArray classArray = json[classListName].toArray();
        classList.clear();
        classList.reserve(classArray.size());
        for (int classIndex = 0; classIndex < classArray.size(); classIndex++)
        {
            QJsonObject classObject = classArray[classIndex].toObject();
            UMLClass cla;
            cla.read(classObject);
            classList.append(cla);
        }
    }
    // Read UMLInterface objects
    if (json.contains(interfaceListName) && json[interfaceListName].isArray())
    {
        QJsonArray interfaceArray = json[interfaceListName].toArray();
        interfaceList.clear();
        interfaceList.reserve(interfaceArray.size());
        for (int interfaceIndex = 0; interfaceIndex < interfaceArray.size(); interfaceIndex++)
        {
            QJsonObject classObject = interfaceArray[interfaceIndex].toObject();
            UMLInterface in;
            in.read(classObject);
            interfaceList.append(in);
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


void ClassDiagram::deleteObject(UMLClassInterfaceTemplate &umlObject)
{
    auto pos = std::find(std::begin(umlList), std::end(umlList), umlObject);
    if (pos != std::end(umlList))
    {
        // find it
        umlList.erase(pos);
    }
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

bool ClassDiagram::findObject(UMLClassInterfaceTemplate &umlObject)
{
    auto pos = std::find(std::begin(umlList), std::end(umlList), umlObject);
    if (pos != std::end(umlList))
    {
        // find it
        return true;
    }
    return false;
}

bool ClassDiagram::operator==(const ClassDiagram &other) const
{
    return static_cast<const Element &>(*this) == static_cast<const Element &>(other);
}

bool ClassDiagram::operator!=(const ClassDiagram &other) const
{
    return !(*this == other);
}