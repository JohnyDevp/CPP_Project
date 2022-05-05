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

class SequenceDiagramInterface
{
public:
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

    bool existsSeqClass(UMLSeqClass &seqClass);

    UMLSeqClass addSeqClas(UMLSeqClass &seqClass);

    void removeSeqClass(UMLSeqClass &seqClass);

    Message createMessage(Message &message);

    void updateMessage(Message &message);

    void removeMessage(Message &message);

    void sendUpdateNotification();

    void addNewSequenceObjectGUI(SequenceObjectGUI *seqObjGUI);

    void removeSequenceObjectGUI(SequenceObjectGUI *seqObjGUI);

    QList<SequenceObjectGUI *> sequenceObjectGUIList;
    QList<SequenceMessageGUI *> sequenceMessageGUIList;

    /**
     * @brief updateScene
     * triggering scene update (for this sequence diagram)
     */
    void updateScene();

    void setScene(QGraphicsScene * scene);

private:
    /**
     * @brief scene for this sequence diagram
     */
    QGraphicsScene *scene;
};

#endif // SEQUENCEDIAGRAMINTERFACE_H
