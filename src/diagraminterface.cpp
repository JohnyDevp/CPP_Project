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
