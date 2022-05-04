#pragma once
#ifndef RELATIONGUI_H
#define RELATIONGUI_H

#include "cls/UMLRelation.hpp"
#include "diagraminterface.h"
//#include "objectgui.h"
#include "qwidget.h"
#include <QGraphicsItem>

class DiagramInterface;
class ObjectGUI;

class RelationGui : public QGraphicsLineItem
{
public:
    RelationGui(UMLRelation umlRelation, DiagramInterface * diagramInterface);

    /**
     * @brief updatePosition
     * @param umlObject
     * @param diffPoint
     */
    void updatePosition(UMLClass umlObject, QPointF diffPoint);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    ObjectGUI * objectStart;
    ObjectGUI * objectEnd;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    /**
     * @brief qpointStart
     */
    QPointF qpointStart;
    /**
     * @brief qpointEnd
     */
    QPointF qpointEnd;


    /**
     * @brief umlRelation
     */
    UMLRelation umlRelation;

    /**
     * @brief diagramInterface
     */
    DiagramInterface * diagramInterface;
};

#endif // RELATIONGUI_H
