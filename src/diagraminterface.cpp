#include "diagraminterface.h"
#include "objectgui.h"
#include <QGraphicsScene>

/**
 * @brief DiagramInterface::DiagramInterface
 * interface for diagrams -> storing sequence diagrams, class diagram
 *                           gui objects lists, relations,...
 */
DiagramInterface::DiagramInterface(QGraphicsScene * scene)
    : classDiagram(QString("ClassDiagram"))
{
    this->scene = scene;
}

void DiagramInterface::updateUMLClass(QString oldName, UMLClass umlClass)
{
    scene->update();
    classDiagram.updateClass(oldName, umlClass);
}

void DiagramInterface::updateRelation(UMLRelation relation)
{
    classDiagram.relationList[relation.index] = relation;
}

UMLClass DiagramInterface::getUMLClass(QString &name)
{
    return classDiagram.classList[name];
}

bool DiagramInterface::existsClass(UMLClass &umlClass)
{
    return classDiagram.existsClass(umlClass);
}

bool DiagramInterface::existsClass(QString &className)
{
    return classDiagram.existsClass(className);
}

void DiagramInterface::updateSeqClass(SequenceDiagram dia, UMLSeqClass seqClass)
{
    sequenceDiagrams[dia.index].classes[seqClass.name] = seqClass;
}

void DiagramInterface::updateMessage(SequenceDiagram dia, Message message)
{
    sequenceDiagrams[dia.index].messages[message.index] = message;
}

bool DiagramInterface::createUMLClass(UMLClass &umlClass)
{
    return classDiagram.addClass(umlClass);
}

UMLRelation DiagramInterface::createRelation()
{
    return classDiagram.addRelation(tempRelation);
}

Message DiagramInterface::createMessage(SequenceDiagram dia, Message &message)
{
    return sequenceDiagrams[dia.index].createMessage(message);
}

void DiagramInterface::removeMessage(SequenceDiagram dia, Message &message)
{
    sequenceDiagrams[dia.index].messages.remove(message.index);
}

void DiagramInterface::removeSeqClass(SequenceDiagram dia, UMLSeqClass seqClass)
{
    sequenceDiagrams[dia.index].classes.remove(seqClass.name);
}

void DiagramInterface::removeUMLClass(UMLClass umlClass)
{
    classDiagram.classList.remove(umlClass.name);
}

void DiagramInterface::removeRelation(UMLRelation relation)
{
    classDiagram.relationList.remove(relation.index);
}

void DiagramInterface::write(QJsonObject &json) const
{
    // TODO:
}

void DiagramInterface::read(const QJsonObject &json)
{
    // TODO:
}

void DiagramInterface::addObjectToObjectGuiList(ObjectGUI *objectGui)
{
    this->guiObjectList.append(objectGui);
}

void DiagramInterface::removeObjectFromGuiList(ObjectGUI *objectGui){
    this->scene->removeItem(objectGui);

    this->guiObjectList.removeOne(objectGui);
}
