#include "relationgui.h"
#include "controllers/editrelationdialog.h"
#include "qbrush.h"
#include "qmath.h"
#include "qpainter.h"
#include <iostream>

RelationGui::RelationGui(UMLRelation umlRelation)
{
    setFlag(QGraphicsLineItem::ItemIsSelectable, true);

    //set points of begin and end
    qpointStart.setX(umlRelation.startX);
    qpointStart.setY(umlRelation.startY);
    qpointEnd.setX(umlRelation.endX);
    qpointEnd.setY(umlRelation.endY);

    //set the Z value -> not overdrawing the other objects
    setZValue(100);

    //set uml relation
    this->umlRelation = umlRelation;

}

void RelationGui::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //set the design of the relation
    QBrush brush(Qt::blue);
    QPen pen(brush, 5);
    painter->setPen(pen);

    //create line at current point
    setLine(this->qpointStart.x(), this->qpointStart.y(), this->qpointEnd.x(), this->qpointEnd.y());
    //draw the line set above
    painter->drawLine(line());

    //draw text name
    //computed values for choose the right place on the relation line for the text label
    //used parametric representation of line
    double lineLength =  qSqrt(qPow((this->qpointStart.y() - this->qpointEnd.y()), 2) + qPow((this->qpointStart.x() - this->qpointEnd.x()),2));
    double u1 = this->qpointEnd.x() - this->qpointStart.x();
    double u2 = this->qpointEnd.y() - this->qpointStart.y();
    double Ax = this->qpointEnd.x();
    double Ay = this->qpointEnd.y();

    //this place choosing coordinates at the specific point at the line
    double resultX;
    double resultY;

    //set name of relation
    resultX = Ax - u1*(0.5);
    resultY = Ay - u2*(0.5);
    painter->drawText(resultX, resultY, this->umlRelation.name);

    //set the cardinality by start object
    resultX = Ax - u1*((lineLength-20)/lineLength);
    resultY = Ay - u2*((lineLength-20)/lineLength);
    painter->drawText(resultX, resultY, this->umlRelation.cardinalityByFromClass);

    //set the cardinality by end object
    resultX = Ax - u1*(40/lineLength);
    resultY = Ay - u2*(20/lineLength);
    painter->drawText(resultX, resultY, this->umlRelation.cardinalityByToClass);

    //draw the arrow

}

void RelationGui::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    //raise a dialog
    EditRelationDialog * editRelationDlg = new EditRelationDialog();
    editRelationDlg->init(this->)

    QGraphicsItem::mouseDoubleClickEvent(event);
}

