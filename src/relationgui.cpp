#include "relationgui.h"
#include "qbrush.h"
#include "qpainter.h"
#include <iostream>

RelationGui::RelationGui()
{
    setFlag(QGraphicsItem::ItemIsMovable);
    qpointStart.setX(0);
    qpointStart.setY(0);
    qpointEnd.setX(100);
    qpointEnd.setY(100);

    setZValue(100);

}

QRectF RelationGui::boundingRect() const
{
    QPoint corner;
    if (this->qpointStart.x() < this->qpointEnd.x()){
        corner.setX(this->qpointStart.x());
    } else {corner.setX(this->qpointEnd.x());}

    if (this->qpointStart.y() < this->qpointEnd.y()){
        corner.setY(this->qpointStart.y());
    } else {corner.setY(this->qpointEnd.y());}

    int width = this->qpointStart.x() - this->qpointEnd.x();
    width = width<0 ? width*-1 : width;

    int height = this->qpointStart.y() - this->qpointEnd.y();
    height = height<0 ? height*-1 : height;

    return QRectF(corner.x(),corner.y(), width, height);
}

void RelationGui::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    // get bounding rect
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);
    rec.translate()
    painter->drawLine(qpointStart,qpointEnd);
    painter->drawRect(rec);

}

void RelationGui::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    //this->qpointStart.setX(qpointStart.x() + 20);
    std::cout << "double click" << std::endl;
    QGraphicsItem::mouseDoubleClickEvent(event);
}

