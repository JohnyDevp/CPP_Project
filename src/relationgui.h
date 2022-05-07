/**
 * @file relationgui.h
 * @author xholan11
 * @brief Header file for relationgui.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

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

/**
 * @brief The RelationGui class
 * class for graphical representation of relation in class diagram
 */
class RelationGui : public QGraphicsLineItem
{
public:
    RelationGui(UMLRelation umlRelation, DiagramInterface *diagramInterface);

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

    /**
     * @brief objectStart pointer to the object, where the relation starts
     */
    ObjectGUI *objectStart;
    /**
     * @brief objectEnd pointer to the object, where the relation starts
     */
    ObjectGUI *objectEnd;

    /**
     * @brief relType type of the relation
     * it is here for purpose, when generalization functions of relation are controlled
     */
    UMLRelation::RelationType relType;

    /**
     * @brief umlRelation
     * inner representation of this relation
     */
    UMLRelation umlRelation;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    /**
     * @brief qpointStart
     * start point of this relation
     */
    QPointF qpointStart;
    /**
     * @brief qpointEnd
     * end point of this relation
     */
    QPointF qpointEnd;

    /**
     * @brief diagramInterface
     */
    DiagramInterface *diagramInterface;
};

#endif // RELATIONGUI_H
