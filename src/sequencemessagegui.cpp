/**
 * @file sequencemessagegui.cpp
 * @author xholan11
 * @brief Represents Message in Sequence diagram
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sequencemessagegui.h"
#include "qbrush.h"
#include "qfont.h"
#include "qgraphicssceneevent.h"
#include "qmath.h"
#include "qmessagebox.h"
#include "qpainter.h"
#include "qpen.h"

SequenceMessageGUI::SequenceMessageGUI(Message message, SequenceDiagramInterface * seqDiagInterface)
{
    //setFlag(QGraphicsLineItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemIsMovable);
    //setFlag(QGraphicsLineItem::ItemIsMovable, true);

    this->message = message;

    this->seqDiagInterface = seqDiagInterface;

    //reset all X coords
    this->X1coord = 0;
    this->X2coord = 0;
    this->Ycoord = this->message.Ycoord;

    setLine(0, this->message.Ycoord, 0, this->message.Ycoord);

    // set the Z value -> not overdrawing the other objects
    setZValue(5);
}

//QRectF SequenceMessageGUI::boundingRect() const {
//    return QRectF(X1coord,this->Ycoord,
//                  X2coord - X1coord,30);
//}

void SequenceMessageGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    // create line at current point
//        setLine(this->seqSenderObjGui->lineXCoord, this->message.Ycoord,
//                this->seqReceiverObjGui->lineXCoord, this->message.Ycoord);
    // draw the line set above
    //painter->drawLine(line());

    QFont font("arial", 13); //-> for text length measure
    painter->setFont(font);
    QFontMetrics metr(font);

    // set the design of the relation
    //set pen according to whether the umlClass exists or not
    QColor color;
    if (umlMessageExists) color = Qt::black;
    else color = Qt::red;

    QPen pen(color, 2);
    painter->setPen(pen);

    // create line at current point
    setLine(this->seqSenderObjGui->lineXCoord, this->message.Ycoord,
            this->seqReceiverObjGui->lineXCoord, this->message.Ycoord);
    // draw the line set above
    painter->drawLine(line());
//    painter->drawLine(X1coord, Ycoord,
//                       X2coord, Ycoord);

    // computed values for choose the right place on the relation line for the text label
    // used parametric representation of line
//    double lineLength = qAbs(X2coord - X1coord);
//    double lineAngle = qAtan(0);
//    double arrowAngle, arrowLength, arrowWide;
//    // set color for painting labels of relation - blue
//    painter->setPen(QColor(73, 112, 230));

    // set text of message
//    QString msgText = this->message.argumentText;
//    QPointF textPoint(X1coord + lineLength/2 - metr.width(msgText),
//                      Ycoord);
//    painter->drawText(textPoint, msgText);

    // draw the arrow
//    QPolygonF relLineEnd;
//    QLineF line1;
//    QLineF line2;
//    QPainterPath path;

//    if (this->message.messageType == Message::RETURN){
//        //draw empty arrow
//        arrowAngle = this->qpointStart.x() > this->qpointEnd.x() ? qDegreesToRadians(45.0) : (-1) * qDegreesToRadians(225.0);
//        arrowLength = 30;
//        arrowWide = 14;

//        line1.setP1(QPointF(
//            arrowLength * qCos(lineAngle - arrowAngle) + this->qpointEnd.x(),
//            arrowWide * qSin(lineAngle - arrowAngle) + this->qpointEnd.y()));
//        line1.setP2(QPointF(
//            this->qpointEnd.x(),
//            this->qpointEnd.y()));
//        line2.setP1(QPointF(
//            arrowLength * qCos(lineAngle + arrowAngle) + this->qpointEnd.x(),
//            arrowWide * qSin(lineAngle + arrowAngle) + this->qpointEnd.y()));
//        line2.setP2(QPointF(
//            this->qpointEnd.x(),
//            this->qpointEnd.y()));

//        painter->setPen(pen);
//        painter->drawLine(line1);
//        painter->drawLine(line2);

//    } else { //draw full arrow
//        arrowAngle = X1coord > X2coord ? qDegreesToRadians(45.0) : -qDegreesToRadians(225.0);
//        arrowLength = 30;
//        // the aim
//        relLineEnd << QPointF(X2coord, Ycoord);
//        // left corner
//        relLineEnd << QPointF(arrowLength * qCos(lineAngle - arrowAngle) + X2coord,
//                              arrowLength * qSin(lineAngle - arrowAngle) + Ycoord);
//        // right corner
//        relLineEnd << QPointF(arrowLength * qCos(lineAngle + arrowAngle) + X2coord,
//                              arrowLength * qSin(lineAngle + arrowAngle) + Ycoord);

//        // draw the end
//        path.addPolygon(relLineEnd);
//        painter->fillPath(path, Qt::black);
//        painter->setPen(pen);
//        painter->drawPolygon(relLineEnd);
//    }

    //this->seqDiagInterface->updateScene(); */
}

void SequenceMessageGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->mousePrevSceneY = event->scenePos().y();

    QGraphicsItem::mousePressEvent(event);
}

void SequenceMessageGUI::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

    //ask for delete
    QMessageBox msgBox;
    QPushButton *deleteButton = msgBox.addButton("Delete",QMessageBox::ActionRole);
    msgBox.setText("Remove message?");
    QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
    msgBox.exec();

    if (msgBox.clickedButton() == (QAbstractButton*)deleteButton) {
        this->seqDiagInterface->removeMessage(this->message);
        this->seqDiagInterface->removeSequenceMessageGUI(this);
    } else if (msgBox.clickedButton() == (QAbstractButton*)cancelButton) {
        //do nothing
        return;
    }


    QGraphicsItem::mouseDoubleClickEvent(event);
}

void SequenceMessageGUI::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qreal diffY = event->scenePos().y() - this->mousePrevSceneY;

    this->mousePrevSceneY = event->scenePos().y();

    this->message.Ycoord += diffY;

    //load the new coords to the message and upload it
    this->seqDiagInterface->updateMessage(this->message);

    update();
    this->seqDiagInterface->updateScene();

    //do not trigger the normall-mouseMoveEvent (it will do mistakes!!!)
    //QGraphicsItem::mouseMoveEvent(event);

}

void SequenceMessageGUI::updateXPosition(SequenceObjectGUI * seqObjGui, int diffX){
    if(this->seqSenderObjGui->objectName == seqObjGui->objectName){
        this->X1coord += diffX;
    } else if (this->seqReceiverObjGui->objectName == seqObjGui->objectName){
        this->X2coord += diffX;
    }
    update();
}

SequenceMessageGUI::~SequenceMessageGUI(){

}



