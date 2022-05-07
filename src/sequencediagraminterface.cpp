/**
 * @file sequencediagraminterface.cpp
 * @author xholan11, xzimol04
 * @brief Interface specific for Sequence diagram
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sequencediagraminterface.h"

SequenceDiagramInterface::~SequenceDiagramInterface()
{
    foreach (SequenceObjectGUI *obj, sequenceObjectGUIList)
    {
        delete obj;
    }

    foreach (SequenceMessageGUI *mes, sequenceMessageGUIList)
    {
        delete mes;
    }
}

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

void SequenceDiagramInterface::addNewSequenceMessageGUI(SequenceMessageGUI * msgGui){

    this->scene->addItem(msgGui);
    this->sequenceMessageGUIList.append(msgGui);

}

void SequenceDiagramInterface::removeSequenceMessageGUI(SequenceMessageGUI * msgGui){
    this->scene->removeItem(msgGui);
    this->sequenceMessageGUIList.removeOne(msgGui);
}

void SequenceDiagramInterface::notifyUmlClassUpdate(QString classOldName, UMLClass updatedClass)
{
    // loop through sequence gui objects and look at their classes, whether they fit to this name or not
    foreach (SequenceObjectGUI *seqObjGUI, this->sequenceObjectGUIList)
    {
        // update seq class of that object
        if (seqObjGUI->umlSeqClass.className == classOldName)
        {
            // update the umlclass name stored in umlSeqClass for the new one
            seqObjGUI->umlSeqClass.className = updatedClass.name;
            // update the seq class in the sequence diagram
            this->sequenceDiagram.updateSeqClass(seqObjGUI->umlSeqClass);
            // update the gui
            seqObjGUI->update();
        }
    }
}

void SequenceDiagramInterface::updateEverything()
{
    // check all sequence gui objects
    foreach (SequenceObjectGUI *seqObjGUI, this->sequenceObjectGUIList)
    {
        // check for existing in class diagram
        if (!this->diagramInterface->existsClass(seqObjGUI->umlSeqClass.className))
        {
            // class doesnt exists in class diagram
            //->notify sequence gui object and all related messages
            seqObjGUI->umlClassExists = false;

            // TODO - notify messages

            // update gui
            seqObjGUI->update();
        }
        else
        {
            // if the class exists, set it in seq obj gui
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
    SequenceMessageGUI * seqMsgGUI = new SequenceMessageGUI(message, this);

    //loop through all the sequence object gui and find the ones, which are related
    // and set them to the message
    foreach(SequenceObjectGUI * seqObjGui, this->sequenceObjectGUIList){
        //if it found message receiver
        if (message.classReceiver == seqObjGui->umlSeqClass.getUniqueName()){
            seqMsgGUI->seqReceiverObjGui = seqObjGui;
            seqMsgGUI->updateXPosition(seqObjGui, seqObjGui->lineXCoord);
        }

        //if it found message sender
        if (message.classSender == seqObjGui->umlSeqClass.getUniqueName()){
            seqMsgGUI->seqSenderObjGui = seqObjGui;
            seqMsgGUI->updateXPosition(seqObjGui, seqObjGui->lineXCoord);
        }
    }

    //add the message gui to the scene and interface
    addNewSequenceMessageGUI(seqMsgGUI);

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

void SequenceDiagramInterface::updateScene()
{
    this->scene->update();
}

void SequenceDiagramInterface::setScene(QGraphicsScene *scene)
{
    this->scene = scene;
}
