#ifndef RELATIONGUI_H
#define RELATIONGUI_H

#include <QGraphicsItem>

class RelationGui : public QGraphicsItem
{
public:
    RelationGui();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // RELATIONGUI_H
