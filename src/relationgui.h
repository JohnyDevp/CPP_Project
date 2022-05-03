#ifndef RELATIONGUI_H
#define RELATIONGUI_H

#include "qwidget.h"
#include <QGraphicsItem>

class RelationGui : public QGraphicsItem
{
public:
    RelationGui();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPoint qpointStart;
    QPoint qpointEnd;

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

};

#endif // RELATIONGUI_H
