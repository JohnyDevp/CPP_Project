/**
 * @file sequencediagraminterface.h
 * @author xholan11, xzimol04
 * @brief Header file for sequencediagraminterface.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef SEQUENCEDIAGRAMINTERFACE_H
#define SEQUENCEDIAGRAMINTERFACE_H

#include "cls/SequenceDiagram.hpp"
#include "diagraminterface.h"
#include "qgraphicsscene.h"
#include "relationgui.h"
#include "sequencemessagegui.h"
#include "sequenceobjectgui.h"

class SequenceObjectGUI;
class SequenceMessageGUI;

/**
 * @brief The SequenceDiagramInterface class
 * interface for communication between inner and outer(gui) of sequence diagram
 * also handles notification comming from class diagram interface (meaning its objects)
 */
class SequenceDiagramInterface
{
public:
    ~SequenceDiagramInterface();
    SequenceDiagramInterface(DiagramInterface *diagramInterface, SequenceDiagram sequenceDiagram);

    /**
     * @brief pointer to interface for class diagram
     * for possibllities of check whether umloperation or umlclass exists or not
     */
    DiagramInterface *diagramInterface;

    /**
     * @brief sequenceDiagram for this interface and controller
     */
    SequenceDiagram sequenceDiagram;

    /**
     * @brief Create or update SeqClass
     *
     * @param dia
     * @param seqClass
     */
    void updateSeqClass(UMLSeqClass &seqClass);

    /**
     * @brief existsSeqClass
     * @param seqClass
     * @return true or false whether the sequence class exists or not
     */
    bool existsSeqClass(UMLSeqClass &seqClass);

    /**
     * @brief addSeqClas
     * @param seqClass
     * @return uml seq class added to the sequence diagram
     */
    UMLSeqClass addSeqClas(UMLSeqClass &seqClass);

    /**
     * @brief removeSeqClass
     * @param seqClass
     */
    void removeSeqClass(UMLSeqClass &seqClass);

    Message createMessage(Message &message);

    void updateMessage(Message &message);

    void removeMessage(Message &message);

    /**
     * @brief sendUpdateNotification called from classdiagraminterface
     * it checked existing of class that is updated and is in sequence diagram
     * and also check all messages (operations which they representing)
     */
    void sendUpdateNotification();

    /**
     * @brief Used to load all data into GUI objects
     *
     */
    void load();

    /**
     * @brief addNewSequenceObjectGUI adds newly created sequence object to the list of gui objects
     * and also to the scene
     * @param seqObjGUI
     */
    void addNewSequenceObjectGUI(SequenceObjectGUI *seqObjGUI);

    void removeSequenceObjectGUI(SequenceObjectGUI *seqObjGUI);

    QList<SequenceObjectGUI *> sequenceObjectGUIList;
    QList<SequenceMessageGUI *> sequenceMessageGUIList;

    /*updates receiving from classdiagraminterface======================================*/
    // communication from diagramInterface -> SequenceDiagramInterface
    /**
     * @brief notifyUmlClassUpdate called from classdiagraminterface
     * it checked existing of class that is updated and is in sequence diagram
     * and also check all messages (operations which they representing)
     */
    void notifyUmlClassUpdate(QString classOldName, UMLClass updatedClass);

    /**
     * @brief updateEverything
     * loops through all the objects and also through all messages in sequence diagram
     * and checked whether they exists or not
     */
    void updateEverything();
    /*================================*/

    /**
     * @brief updateScene
     * triggering scene update (for this sequence diagram)
     */
    void updateScene();

    void setScene(QGraphicsScene *scene);

    void addNewSequenceMessageGUI(SequenceMessageGUI *msgGui);
    void removeSequenceMessageGUI(SequenceMessageGUI *msgGui);

private:
    /**
     * @brief scene for this sequence diagram
     */
    QGraphicsScene *scene;
};

#endif // SEQUENCEDIAGRAMINTERFACE_H
