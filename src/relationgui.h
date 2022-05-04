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
     * @param umlObject - which object does the notification comes from
     * @param diffPoint - consists of difference X coord and difference Y coord - the value, by which has the object moved
     */
    void updatePosition(UMLClass umlObject, QPointF diffPoint);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief removeRelation - called when some of related objects is deleted
     * @param which object does send this message
     */
    void removeRelationNotification();

    ObjectGUI * objectStart;
    ObjectGUI * objectEnd;

    UMLRelation::RelationType relType;

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
