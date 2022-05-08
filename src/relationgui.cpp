/**
 * @file relationgui.cpp
 * @author xholan11
 * @brief   Represents Relation in Class diagram
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "relationgui.h"
#include "controllers/editrelationdialog.h"
#include "qbrush.h"
#include "qgraphicsscene.h"
#include "qmath.h"
#include "qpainter.h"
#include <iostream>

RelationGui::RelationGui(UMLRelation umlRelation, DiagramInterface *diagramInterface)
{
    setFlag(QGraphicsLineItem::ItemIsSelectable, true);

    // set points of begin and end
    qpointStart.setX(umlRelation.startX);
    qpointStart.setY(umlRelation.startY);
    qpointEnd.setX(umlRelation.endX);
    qpointEnd.setY(umlRelation.endY);

    setLine(this->qpointStart.x(), this->qpointStart.y(), this->qpointEnd.x(), this->qpointEnd.y());

    // set the Z value -> not overdrawing the other objects
    setZValue(5);

    // set uml relation
    this->umlRelation = umlRelation;

    // set relation type
    this->relType = this->umlRelation.relationType;

    // set pointer to diagram interface
    this->diagramInterface = diagramInterface;
}

void RelationGui::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // set current font
    QFont font("arial", 13); //-> for text length measure
    painter->setFont(font);

    // set the design of the relation
    QBrush brush(Qt::black);
    QPen penLine(brush, 5);
    QPen penArrow(brush, 2);
    painter->setPen(penLine);

    // create line at current point
    setLine(this->qpointStart.x(), this->qpointStart.y(), this->qpointEnd.x(), this->qpointEnd.y());
    // draw the line set above
    painter->drawLine(line());

    // computed values for choose the right place on the relation line for the text label
    // used parametric representation of line
    double lineLength = qSqrt(qPow((this->qpointStart.y() - this->qpointEnd.y()), 2) + qPow((this->qpointStart.x() - this->qpointEnd.x()), 2));
    double u1 = this->qpointEnd.x() - this->qpointStart.x();
    double u2 = this->qpointEnd.y() - this->qpointStart.y();
    double Ax = this->qpointEnd.x();
    double Ay = this->qpointEnd.y();
    double slope = (this->qpointStart.y() - this->qpointEnd.y()) / (this->qpointStart.x() - this->qpointEnd.x());
    double lineAngle = qAtan(slope);
    double arrowAngle, arrowLength, arrowWide;

    // this place choosing coordinates at the specific point at the line
    double resultX;
    double resultY;

    // set color for painting labels of relation - blue
    painter->setPen(QColor(73, 112, 230));

    // set name of relation
    if (!this->umlRelation.name.isEmpty())
    {
        resultX = Ax - u1 * (0.5);
        resultY = Ay - u2 * (0.5);
        painter->drawText(resultX, resultY, this->umlRelation.name);
    }

    // set the cardinality by start object
    if (!this->umlRelation.cardinalityByFromClass.isEmpty())
    {
        resultX = Ax - u1 * ((lineLength - 20) / lineLength);
        resultY = Ay - u2 * ((lineLength - 20) / lineLength);
        painter->drawText(resultX, resultY, this->umlRelation.cardinalityByFromClass);
    }

    // set the cardinality by end object
    if (!this->umlRelation.cardinalityByToClass.isEmpty())
    {
        resultX = Ax - u1 * (40 / lineLength);
        resultY = Ay - u2 * (20 / lineLength);
        painter->drawText(resultX, resultY, this->umlRelation.cardinalityByToClass);
    }

    // set pen color to black
    painter->setPen(Qt::black);

    // draw the arrow
    QPolygonF relLineEnd;
    QLineF line1;
    QLineF line2;
    QPainterPath path;

    switch (this->umlRelation.relationType)
    {
    case UMLRelation::RelationType::AGGREGATION:
        arrowAngle = this->qpointStart.x() > this->qpointEnd.x() ? qDegreesToRadians(45.0) : -qDegreesToRadians(225.0);
        arrowLength = 17;
        arrowWide = 13;
        resultX = Ax - u1 * (30 / lineLength);
        resultY = Ay - u2 * (30 / lineLength);
        // the aim
        relLineEnd << QPointF(this->qpointEnd.x(), this->qpointEnd.y());
        // left corner
        relLineEnd << QPointF(arrowLength * qCos(lineAngle - arrowAngle) + this->qpointEnd.x(),
                              arrowWide * qSin(lineAngle - arrowAngle) + this->qpointEnd.y());
        // the last point
        relLineEnd << QPointF(resultX, resultY);
        // right corner
        relLineEnd << QPointF(arrowLength * qCos(lineAngle + arrowAngle) + this->qpointEnd.x(),
                              arrowWide * qSin(lineAngle + arrowAngle) + this->qpointEnd.y());

        // draw the end
        path.addPolygon(relLineEnd);
        painter->fillPath(path, Qt::black);
        painter->setPen(penArrow);
        painter->drawPath(path);

        break;

    case UMLRelation::RelationType::ASSOCIATION:
        arrowAngle = this->qpointStart.x() > this->qpointEnd.x() ? qDegreesToRadians(45.0) : (-1) * qDegreesToRadians(225.0);
        arrowLength = 30;
        arrowWide = 14;

        line1.setP1(QPointF(
            arrowLength * qCos(lineAngle - arrowAngle) + this->qpointEnd.x(),
            arrowWide * qSin(lineAngle - arrowAngle) + this->qpointEnd.y()));
        line1.setP2(QPointF(
            this->qpointEnd.x(),
            this->qpointEnd.y()));
        line2.setP1(QPointF(
            arrowLength * qCos(lineAngle + arrowAngle) + this->qpointEnd.x(),
            arrowWide * qSin(lineAngle + arrowAngle) + this->qpointEnd.y()));
        line2.setP2(QPointF(
            this->qpointEnd.x(),
            this->qpointEnd.y()));

        painter->setPen(penLine);
        painter->drawLine(line1);
        painter->drawLine(line2);

        break;

    case UMLRelation::RelationType::GENERALIZATION:
        arrowAngle = this->qpointStart.x() > this->qpointEnd.x() ? qDegreesToRadians(45.0) : -qDegreesToRadians(225.0);
        arrowLength = 30;
        // the aim
        relLineEnd << QPointF(this->qpointEnd.x(), this->qpointEnd.y());
        // left corner
        relLineEnd << QPointF(arrowLength * qCos(lineAngle - arrowAngle) + this->qpointEnd.x(),
                              arrowLength * qSin(lineAngle - arrowAngle) + this->qpointEnd.y());
        // right corner
        relLineEnd << QPointF(arrowLength * qCos(lineAngle + arrowAngle) + this->qpointEnd.x(),
                              arrowLength * qSin(lineAngle + arrowAngle) + this->qpointEnd.y());

        // draw the end
        path.addPolygon(relLineEnd);
        painter->fillPath(path, Qt::white);
        painter->setPen(penArrow);
        painter->drawPolygon(relLineEnd);
        break;

    case UMLRelation::RelationType::COMPOSITION:
        arrowAngle = this->qpointStart.x() > this->qpointEnd.x() ? qDegreesToRadians(45.0) : -qDegreesToRadians(225.0);
        arrowLength = 17;
        arrowWide = 13;
        resultX = Ax - u1 * (30 / lineLength);
        resultY = Ay - u2 * (30 / lineLength);
        // the aim
        relLineEnd << QPointF(this->qpointEnd.x(), this->qpointEnd.y());
        // left corner
        relLineEnd << QPointF(arrowLength * qCos(lineAngle - arrowAngle) + this->qpointEnd.x(),
                              arrowWide * qSin(lineAngle - arrowAngle) + this->qpointEnd.y());
        // the last point
        relLineEnd << QPointF(resultX, resultY);
        // right corner
        relLineEnd << QPointF(arrowLength * qCos(lineAngle + arrowAngle) + this->qpointEnd.x(),
                              arrowWide * qSin(lineAngle + arrowAngle) + this->qpointEnd.y());

        // draw the end
        path.addPolygon(relLineEnd);
        painter->fillPath(path, Qt::white);
        painter->setPen(penArrow);
        painter->drawPolygon(relLineEnd);

        break;
    }

}

void RelationGui::removeRelationNotification()
{
    // remove relation from scene and from the class diagram
    this->diagramInterface->removeRelation(this->umlRelation);
    this->diagramInterface->removeRelationFromGuiList(this);

    // send message about deletion to both related objects
    this->objectStart->removeRelatedRelation(this);
    this->objectEnd->removeRelatedRelation(this);
}

void RelationGui::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

    // raise a dialog
    EditRelationDialog *editRelationDlg = new EditRelationDialog();
    editRelationDlg->init(&this->umlRelation);
    editRelationDlg->exec();

    if (editRelationDlg->getUpdatedUmlRelation() == NULL)
    {
        // if the relation was deleted
        // remove it from scene and from the class diagram
        this->diagramInterface->removeRelation(this->umlRelation);
        this->diagramInterface->removeRelationFromGuiList(this);

        // send message about deletion to both related objects
        this->objectStart->removeRelatedRelation(this);
        this->objectEnd->removeRelatedRelation(this);
    }
    else
    {
        this->umlRelation = *editRelationDlg->getUpdatedUmlRelation();
        this->diagramInterface->updateRelation(this->umlRelation);

        update();
    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}

void RelationGui::updatePosition(UMLClass umlObject, QPointF diffPoint)
{
    // find which end of the relation should be updated nad update
    if (umlObject.name == this->umlRelation.relationFrom)
    {
        this->qpointStart.setX(this->qpointStart.x() + diffPoint.x());
        this->qpointStart.setY(this->qpointStart.y() + diffPoint.y());
    }
    else
    {
        this->qpointEnd.setX(this->qpointEnd.x() + diffPoint.x());
        this->qpointEnd.setY(this->qpointEnd.y() + diffPoint.y());
    }

    setLine(this->qpointStart.x(), this->qpointStart.y(), this->qpointEnd.x(), this->qpointEnd.y());

    // save new coords to the umlRelation
    this->umlRelation.startX = this->qpointStart.x();
    this->umlRelation.startY = this->qpointStart.y();
    this->umlRelation.endX = this->qpointEnd.x();
    this->umlRelation.endY = this->qpointEnd.y();
    this->diagramInterface->updateRelation(this->umlRelation);

    // repaint gui of relation
    update();
}
