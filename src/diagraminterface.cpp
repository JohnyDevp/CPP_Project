#include "diagraminterface.h"
#include "objectgui.h"

/**
 * @brief DiagramInterface::DiagramInterface
 * interface for diagrams -> storing sequence diagrams, class diagram
 *                           gui objects lists, relations,...
 */
DiagramInterface::DiagramInterface()
{
    //FIXME
    this->classDiagram = new ClassDiagram("tmpName");
}

void DiagramInterface::addObjectToObjectGuiList(ObjectGUI *objectGui){
    this->guiObjectList.append(objectGui);
}

bool DiagramInterface::addObjectToClassDiagram(UMLClass umlClass){
    return this->classDiagram->addClass(umlClass);
}
