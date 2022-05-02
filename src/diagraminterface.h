#pragma once
#ifndef DIAGRAMINTERFACE_H
#define DIAGRAMINTERFACE_H

#include "cls/ClassDiagram.hpp"
#include "objectgui.h"
#include <iostream>
#include <vector>

class ObjectGUI;

class DiagramInterface
{
public:
    DiagramInterface();
    void addObjectToObjectGuiList(ObjectGUI *objectGui);
    bool addObjectToClassDiagram(UMLClass umlClass);
    void removeObjectFromList();

private:
    /**
     * @brief classDiagram
     */
    ClassDiagram *classDiagram;
    /**
     * @brief guiObjectList
     */
    QList<ObjectGUI*> guiObjectList;
};

#endif // DIAGRAMINTERFACE_H
