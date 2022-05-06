/**
 * @file sequencemessagegui.h
 * @author xholan11
 * @brief Header file for sequencemessagegui.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#ifndef SEQUENCEMESSAGEGUI_H
#define SEQUENCEMESSAGEGUI_H

#include "cls/Message.hpp"
#include "sequenceobjectgui.h"
#include "sequencediagraminterface.h"
#include <QGraphicsLineItem>

class SequenceObjectGUI;

class SequenceMessageGUI : public QGraphicsLineItem
{
public:
    SequenceMessageGUI(Message umlSeqClass, SequenceDiagramInterface * seqDiagInterface);

    //QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    Message message;

    SequenceObjectGUI * seqSenderObjGui;
    SequenceObjectGUI * seqReceiverObjGui;

    QPointF qpointStart;
    QPointF qpointEnd;

    bool umlMessageExists = true;

    void updateXPosition(SequenceObjectGUI *seqObjGui, int diffX);

    ~SequenceMessageGUI();
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    int Ycoord;
    int X1coord;
    int X2coord;

    qreal mousePrevSceneX;
    qreal mousePrevSceneY;

    qreal mousePrevLocalY;

    SequenceDiagramInterface * seqDiagInterface;

};

#endif // SEQUENCEMESSAGEGUI_H
