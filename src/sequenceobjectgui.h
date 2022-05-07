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

class SequenceObjectGUI : public QGraphicsItem
{
public:
    SequenceObjectGUI(UMLSeqClass umlSeqClass, SequenceDiagramInterface *seqDiagInterface);

    ~SequenceObjectGUI();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    UMLSeqClass umlSeqClass;

    /**
     * @brief variable storing, whether there is no background for this umlSeqClass (as umlclass) or there is
     */
    bool umlClassExists = true;

    /**
     * @brief objectName - build object name, ready to be displayed
     */
    QString objectName;

    qreal lineXCoord;

    void updateActiveRectangles();
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    qreal prevMouseLocalX;

    qreal mousePrevSceneX;
    qreal mousePrevSceneY;

    // variables for default coords of bounding rectangle
    int boundingX;
    int boundingY = TOP_Y_COORD;
    int boundingWidth;
    int boundingHeight;

    SequenceDiagramInterface *seqDiagInterface;

    QList<SequenceMessageGUI*> seqReceivingMsgGuiList;
    QList<SequenceMessageGUI*> seqSendingMsgGuiList;

    QList<QRectF> activeRectangle;
};

#endif // SEQUENCEOBJECTGUI_H
