/**
 * @file sequenceobjectgui.h
 * @author xholan11
 * @brief Header file for sequenceobjectgui.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef SEQUENCEOBJECTGUI_H
#define SEQUENCEOBJECTGUI_H

#include "cls/UMLSeqClass.hpp"
#include "sequencediagraminterface.h"
#include "diagraminterface.h"
#include "sequencemessagegui.h"
#include <QGraphicsItem>

#define TOP_Y_COORD 30

class SequenceDiagramInterface;
class SequenceMessageGUI;

/**
 * @brief The SequenceObjectGUI class
 * class representing the sequence object gui of its inner representation (umlseqclass)
 */
class SequenceObjectGUI : public QGraphicsItem
{
public:
    SequenceObjectGUI(UMLSeqClass umlSeqClass, SequenceDiagramInterface *seqDiagInterface);

    ~SequenceObjectGUI();

    QRectF boundingRect() const;
    /**
     * @brief paint
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief umlSeqClass inner representation of this gui sequence object
     */
    UMLSeqClass umlSeqClass;

    /**
     * @brief variable storing, whether there is no background for this umlSeqClass (as umlclass) or there is
     */
    bool umlClassExists = true;

    /**
     * @brief objectName - build object name, ready to be displayed
     */
    QString objectName;

    /**
     * @brief lineXCoord coord, that is used by all related messages for know, where they should start or end
     */
    qreal lineXCoord;

    /**
     * @brief updateActiveRectangles
     * loops through all messages, checked whether they activating or deactivating this object and
     * create according this active rectangles
     */
    void updateActiveRectangles();
    /**
     * @brief addRelatedReceivingMessage for adding related messages, which are received by this obejct
     * @param seqMsgGui
     */
    void addRelatedReceivingMessage(SequenceMessageGUI *seqMsgGui);
    /**
     * @brief addRelatedSendingMessage for adding related messages, which are sent by this obejct
     * @param seqMsgGui
     */
    void addRelatedSendingMessage(SequenceMessageGUI *seqMsgGui);

    void removeRelatedReceivingMessage(SequenceMessageGUI *seqMsgGui);
    void removeRelatedSendingMessage(SequenceMessageGUI *seqMsgGui);
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    // void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    /**
     * @brief prevMouseLocalX for info check objectgui.h
     */
    qreal prevMouseLocalX;
    /**
     * @brief prevMouseLocalY for info check objectgui.h
     */
    qreal prevMouseLocalY;
    /**
     * @brief mousePrevSceneX for info check objectgui.h
     */
    qreal mousePrevSceneX;
    /**
     * @brief mousePrevSceneY for info check objectgui.h
     */
    qreal mousePrevSceneY;

    // variables for default coords of bounding rectangle
    int boundingX;
    int boundingY = TOP_Y_COORD;
    int boundingWidth;
    int boundingHeight;

    SequenceDiagramInterface *seqDiagInterface;

    QList<SequenceMessageGUI *> seqReceivingMsgGuiList;
    QList<SequenceMessageGUI *> seqSendingMsgGuiList;

    /**
     * @brief activeRectangles list for computed recatngles representing active parts of the life-line of the object
     */
    QList<QRectF> activeRectangles;

    /**
     * @brief itemChange handles change in only Xaxis of this object
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    /**
     * @brief objectDestroyPoint represents point, where this object ends
     */
    qreal objectDestroyPoint;
};

#endif // SEQUENCEOBJECTGUI_H
