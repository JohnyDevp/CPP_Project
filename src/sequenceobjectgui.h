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
#include <QGraphicsItem>

#define TOP_Y_COORD 30

class SequenceDiagramInterface;

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

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    qreal mousePrevSceneX;
    qreal mousePrevSceneY;

    QString objectName;

    // variables for default coords of bounding rectangle
    int boundingX;
    int boundingY = TOP_Y_COORD;
    int boundingWidth;
    int boundingHeight;

    SequenceDiagramInterface *seqDiagInterface;
};

#endif // SEQUENCEOBJECTGUI_H
