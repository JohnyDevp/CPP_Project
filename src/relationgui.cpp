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
    setZValue(-1);

    //set uml relation
    this->umlRelation = umlRelation;

}

void RelationGui::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //set the design of the relation
    QBrush brush(Qt::black);
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
    double slope = (this->qpointStart.y() - this->qpointEnd.y()) / (this->qpointStart.x() - this->qpointEnd.x());
    double lineAngle = qAtan(slope);
    double arrowAngle, arrowLength, arrowWide;

    //this place choosing coordinates at the specific point at the line
    double resultX;
    double resultY;

    //set name of relation
    if (!this->umlRelation.name.isEmpty()){
        resultX = Ax - u1*(0.5);
        resultY = Ay - u2*(0.5);
        painter->drawText(resultX, resultY, this->umlRelation.name);
    }

    //set the cardinality by start object
    if (!this->umlRelation.cardinalityByFromClass.isEmpty()){
        resultX = Ax - u1*((lineLength-20)/lineLength);
        resultY = Ay - u2*((lineLength-20)/lineLength);
        painter->drawText(resultX, resultY, this->umlRelation.cardinalityByFromClass);
    }

    //set the cardinality by end object
    if (!this->umlRelation.cardinalityByToClass.isEmpty()){
        resultX = Ax - u1*(40/lineLength);
        resultY = Ay - u2*(20/lineLength);
        painter->drawText(resultX, resultY, this->umlRelation.cardinalityByToClass);
    }

    //draw the arrow
    QPolygonF relLineEnd;

    switch(this->umlRelation.relationType){
        case UMLRelation::RelationType::AGGREGATION:

            break;
        case UMLRelation::RelationType::ASSOCIATION:
            break;
        case UMLRelation::RelationType::GENERALIZATION:
            arrowAngle = this->qpointStart.x() > this->qpointEnd.x() ? qDegreesToRadians(45.0) : -qDegreesToRadians(225.0);
            arrowLength = 20;
            //the aim
            relLineEnd << QPointF(this->qpointEnd.x(), this->qpointEnd.y());
            //left corner
            relLineEnd << QPointF(arrowLength * qCos(lineAngle-arrowAngle) + this->qpointEnd.x(),
                                  arrowLength * qSin(lineAngle-arrowAngle) + this->qpointEnd.y());
            //right corner
            relLineEnd << QPointF(arrowLength * qCos(lineAngle+arrowAngle) + this->qpointEnd.x(),
                                  arrowLength * qSin(lineAngle+arrowAngle) + this->qpointEnd.y());

            painter->drawPolygon(relLineEnd);
            break;
        case UMLRelation::RelationType::COMPOSITION:
            break;
    }

}

void RelationGui::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event){
    //raise a dialog
    EditRelationDialog * editRelationDlg = new EditRelationDialog();
    editRelationDlg->init(&this->umlRelation);
    editRelationDlg->exec();


    QGraphicsItem::mouseDoubleClickEvent(event);
}

