#ifndef RELATIONGUI_H
#define RELATIONGUI_H

#include "cls/UMLRelation.hpp"
#include "qwidget.h"
#include <QGraphicsItem>

class RelationGui : public QGraphicsLineItem
{
public:
    RelationGui(UMLRelation umlRelation);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPoint qpointStart;
    QPoint qpointEnd;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    UMLRelation umlRelation;
};

#endif // RELATIONGUI_H
