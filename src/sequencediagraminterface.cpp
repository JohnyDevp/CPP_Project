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

    updateScene();
}

void SequenceDiagramInterface::addNewSequenceMessageGUI(SequenceMessageGUI *msgGui)
{

    this->scene->addItem(msgGui);
    this->sequenceMessageGUIList.append(msgGui);
    this->updateScene();
}

void SequenceDiagramInterface::removeSequenceMessageGUI(SequenceMessageGUI *msgGui)
{
    this->scene->removeItem(msgGui);
    this->sequenceMessageGUIList.removeOne(msgGui);
    updateScene();
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

    //loop through all messages and find whether they exists or not
    foreach (SequenceMessageGUI *seqMsgGui, this->sequenceMessageGUIList){
        //first check for RETURN MESSAGE, which is represented by empty uml operation - thus should be checked for first
        UMLOperation tmp("");
        if (seqMsgGui->message.operation == tmp) continue;

        //if the uml class doesnt exist, then set the message not exist
        if (seqMsgGui->seqReceiverObjGui->umlClassExists){
            //if the class exists, then loop through its operations and find whether this message's operation exist
            QString umlClsName = seqMsgGui->seqReceiverObjGui->umlSeqClass.className;
            //get the uml class from the receiver - and then its operations from it
            UMLClass umlClsFromReceiver = this->diagramInterface->getUMLClass(umlClsName);
            bool found = umlClsFromReceiver.umlOperationsList.contains(seqMsgGui->message.operation);
            if (found){
                seqMsgGui->umlMessageExists = true;
            } else {
                seqMsgGui->umlMessageExists = false;
            }
        } else {
            seqMsgGui->umlMessageExists = false;
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

    //loop through all messages and find whether they exists or not
    foreach (SequenceMessageGUI *seqMsgGui, this->sequenceMessageGUIList){
        //first check for RETURN MESSAGE, which is represented by empty uml operation - thus should be checked for first
        UMLOperation tmp("");
        if (seqMsgGui->message.operation == tmp) continue;

        //if the uml class doesnt exist, then set the message not exist
        if (seqMsgGui->seqReceiverObjGui->umlClassExists){
            //if the class exists, then loop through its operations and find whether this message's operation exist
            QString umlClsName = seqMsgGui->seqReceiverObjGui->umlSeqClass.className;
            //get the uml class from the receiver - and then its operations from it
            UMLClass umlClsFromReceiver = this->diagramInterface->getUMLClass(umlClsName);
            bool found = umlClsFromReceiver.umlOperationsList.contains(seqMsgGui->message.operation);
            if (found){
                seqMsgGui->umlMessageExists = true;
            } else {
                seqMsgGui->umlMessageExists = false;
            }
        } else {
            seqMsgGui->umlMessageExists = false;
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
    SequenceMessageGUI *seqMsgGUI = new SequenceMessageGUI(message, this);

    // loop through all the sequence object gui and find the ones, which are related
    //  and set them to the message
    foreach (SequenceObjectGUI *seqObjGui, this->sequenceObjectGUIList)
    {
        // if it found message receiver
        if (message.classReceiver == seqObjGui->umlSeqClass.getUniqueName())
        {
            seqMsgGUI->seqReceiverObjGui = seqObjGui;
        }
        // if it found message sender
        if (message.classSender == seqObjGui->umlSeqClass.getUniqueName())
        {
            seqMsgGUI->seqSenderObjGui = seqObjGui;
        }
    }

    // add the message gui to the list in both related classes gui objects
    seqMsgGUI->seqReceiverObjGui->addRelatedReceivingMessage(seqMsgGUI);
    seqMsgGUI->seqSenderObjGui->addRelatedSendingMessage(seqMsgGUI);

    // add the message gui to the scene and interface
    addNewSequenceMessageGUI(seqMsgGUI);

    return sequenceDiagram.createMessage(message);
}

void SequenceDiagramInterface::removeMessage(Message &message)
{
    sequenceDiagram.deleteMessage(message);
}

void SequenceDiagramInterface::load()
{

    // Load UMLSeqClasses into GUI
    foreach (UMLSeqClass cl, sequenceDiagram.classes())
    {
        SequenceObjectGUI *sequenceObjectGUI = new SequenceObjectGUI(cl, this);

        // this method also add the gui to the scene
        addNewSequenceObjectGUI(sequenceObjectGUI);
    }

    // Load Messages into GUI
    foreach (Message mes, sequenceDiagram.messages())
    {
        SequenceMessageGUI *seqMsgGUI = new SequenceMessageGUI(mes, this);

        // loop through all the sequence object gui and find the ones, which are related
        //  and set them to the message
        foreach (SequenceObjectGUI *seqObjGui, this->sequenceObjectGUIList)
        {
            // if it found message receiver
            if (mes.classReceiver == seqObjGui->umlSeqClass.getUniqueName())
            {
                seqMsgGUI->seqReceiverObjGui = seqObjGui;
            }

            // if it found message sender
            if (mes.classSender == seqObjGui->umlSeqClass.getUniqueName())
            {
                seqMsgGUI->seqSenderObjGui = seqObjGui;
            }
        }

        // add the message gui to the list in both related classes gui objects
        seqMsgGUI->seqReceiverObjGui->addRelatedReceivingMessage(seqMsgGUI);
        seqMsgGUI->seqSenderObjGui->addRelatedSendingMessage(seqMsgGUI);

        // add the message gui to the scene and interface
        addNewSequenceMessageGUI(seqMsgGUI);
    }

    updateEverything();
    updateScene();
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
