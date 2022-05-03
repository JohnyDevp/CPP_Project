#include "relationgui.h"
#include "qbrush.h"
#include "qpainter.h"

RelationGui::RelationGui()
{
    setFlag(QGraphicsItem::ItemIsMovable);

}

QRectF RelationGui::boundingRect() const
{
    return QRectF(0, 0, 100, 100);
}

void RelationGui::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{


    // get bounding rect
    QRectF rec = boundingRect();
    QBrush brush(Qt::blue);

    painter->drawLine(0,0,100,100);


}
