#include "sequencediagraminterface.h"

SequenceDiagramInterface::SequenceDiagramInterface(DiagramInterface *diagramInterface, SequenceDiagram sequenceDiagram) : sequenceDiagram(sequenceDiagram)
{
    this->diagramInterface = diagramInterface;
    this->sequenceDiagram = sequenceDiagram;
}

void SequenceDiagramInterface::addNewSequenceObjectGUI(SequenceObjectGUI *seqObjGUI)
{
    this->scene->addItem(seqObjGUI);

    this->sequenceObjectGUIList.append(seqObjGUI);
}

void SequenceDiagramInterface::removeSequenceObjectGUI(SequenceObjectGUI *seqObjGUI)
{
    this->scene->removeItem(seqObjGUI);

    this->sequenceObjectGUIList.removeOne(seqObjGUI);
}

void SequenceDiagramInterface::notifyUmlClassUpdate(QString classOldName, UMLClass updatedClass)
{
    //loop through sequence gui objects and look at their classes, whether they fit to this name or not
    foreach(SequenceObjectGUI * seqObjGUI, this->sequenceObjectGUIList){
        //update seq class of that object
        if (seqObjGUI->umlSeqClass.className == classOldName){
            //update the umlclass name stored in umlSeqClass for the new one
            seqObjGUI->umlSeqClass.className = updatedClass.name;
            //update the seq class in the sequence diagram
            this->sequenceDiagram.updateSeqClass(seqObjGUI->umlSeqClass);
            //update the gui
            seqObjGUI->update();
        }
    }
}

void SequenceDiagramInterface::updateEverything()
{
    //check all sequence gui objects
    foreach(SequenceObjectGUI * seqObjGUI, this->sequenceObjectGUIList){
        //check for existing in class diagram
        if(!this->diagramInterface->existsClass(seqObjGUI->umlSeqClass.className)){
            //class doesnt exists in class diagram
            //->notify sequence gui object and all related messages
            seqObjGUI->umlClassExists = false;

            //TODO - notify messages

            //update gui
            seqObjGUI->update();
        } else {
            //if the class exists, set it in seq obj gui
            seqObjGUI->umlClassExists = true;
        }
    }
}

void SequenceDiagramInterface::updateSeqClass(UMLSeqClass &seqClass)
{
    sequenceDiagram.updateSeqClass(seqClass);
}

bool SequenceDiagramInterface::existsSeqClass(UMLSeqClass &seqClass)
{
    return sequenceDiagram.existsSeqClass(seqClass);
}

UMLSeqClass SequenceDiagramInterface::addSeqClas(UMLSeqClass &seqClass)
{
    return sequenceDiagram.addSeqClass(seqClass);
}

void SequenceDiagramInterface::updateMessage(Message &message)
{
    sequenceDiagram.updateMessage(message);
}

Message SequenceDiagramInterface::createMessage(Message &message)
{
    return sequenceDiagram.createMessage(message);
}

void SequenceDiagramInterface::removeMessage(Message &message)
{
    sequenceDiagram.deleteMessage(message);
}

void SequenceDiagramInterface::removeSeqClass(UMLSeqClass &seqClass)
{
    sequenceDiagram.deleteUMLSeqClass(seqClass);
}

void SequenceDiagramInterface::updateScene(){
    this->scene->update();
}

void SequenceDiagramInterface::setScene(QGraphicsScene *scene)
{
    this->scene = scene;
}
