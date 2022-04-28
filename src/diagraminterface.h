#ifndef DIAGRAMINTERFACE_H
#define DIAGRAMINTERFACE_H

#include "src/cls/ClassDiagram.hpp"
#include "src/objectgui.h"
#include <iostream>
#include <vector>

class DiagramInterface
{
public:
    DiagramInterface();

private:
    /**
     * @brief classDiagram
     */
    ClassDiagram *classDiagram;
    /**
     * @brief guiObjectList
     */
    QList<ObjectGUI> guiObjectList;
};

#endif // DIAGRAMINTERFACE_H
