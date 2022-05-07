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
    setFlag(QGraphicsLineItem::ItemIsMovable, true);

    this->message = message;

    this->seqDiagInterface = seqDiagInterface;

    setLine(0, this->message.Ycoord, 0, this->message.Ycoord);

    // set the Z value -> not overdrawing the other objects
    setZValue(13);

    //set activating/deactivating attributes
    if (message.messageType == Message::RETURN){
        this->isDeactivatingSender = true;
    } else if (message.messageType == Message::DESTROY) {
        this->isDeactivatingReceiver = true;
    }
}

void SequenceMessageGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //this lines serves, when the message is send to object itself -
    // so diff of lineXcoord is 0, and there has to be some piece of line
    int same_sender_const = 0;
    if (seqSenderObjGui == seqReceiverObjGui) same_sender_const = 45;

    //set font
    QFont font("arial", 13); //-> for text length measure
    font.setBold(true);
    painter->setFont(font);
    QFontMetrics metr(font);

    // set the design of the relation
    //set pen according to whether the umlClass exists or not
    QColor color;
    if (umlMessageExists) color = Qt::black;
    else color = Qt::red;

    QPen pen(color, 3);
    painter->setPen(pen);

    if (message.messageType == Message::RETURN) painter->setPen(QPen(color, 3, Qt::DashLine));
    // create line at current point
    setLine(this->seqSenderObjGui->lineXCoord - same_sender_const, this->message.Ycoord,
            this->seqReceiverObjGui->lineXCoord, this->message.Ycoord);
    // draw the line set above
    painter->drawLine(line());
    painter->setPen(pen); //return back normal pen, if set for dash line when RETURN type


    // computed line length for choosing the right place for text and arrow
    double lineLength = qAbs(this->seqReceiverObjGui->lineXCoord - this->seqSenderObjGui->lineXCoord - same_sender_const);

    //draw the text
    //draw create or destroy tag, if message type fits
    QString msgText = this->message.operation.name + " (" + this->message.argumentText + ") : " + this->message.operation.type;
    if (message.messageType == Message::CREATE) {
        msgText += "<<create>>";
    } else if (message.messageType == Message::DESTROY){
        msgText += "<<destroy>>";
    }

    qreal msgLeftX = this->seqSenderObjGui->lineXCoord < this->seqReceiverObjGui->lineXCoord ?
                        this->seqSenderObjGui->lineXCoord : this->seqReceiverObjGui->lineXCoord;
    QPointF textPoint(msgLeftX + lineLength/2 - metr.width(msgText)/2,
                      this->message.Ycoord - 26);
    painter->drawText(textPoint, msgText);

    // draw the arrow
    QPolygonF relLineEnd;
    QLineF line1;
    QLineF line2;
    QPainterPath path;

    double arrowAngle, arrowLength, arrowWide;

    if (this->message.messageType == Message::RETURN){
        //draw empty arrow
        arrowAngle = this->seqSenderObjGui->lineXCoord > this->seqReceiverObjGui->lineXCoord ? qDegreesToRadians(45.0) : -qDegreesToRadians(225.0);
        arrowLength = 15;
        arrowWide = 7;

        line1.setP1(QPointF(
            arrowLength * qCos(- arrowAngle) + this->seqReceiverObjGui->lineXCoord - 5,
            arrowWide * qSin(- arrowAngle) + this->message.Ycoord - 7));
        line1.setP2(QPointF(
            this->seqReceiverObjGui->lineXCoord,
            this->message.Ycoord));
        line2.setP1(QPointF(
            arrowLength * qCos(arrowAngle) + this->seqReceiverObjGui->lineXCoord - 5,
            arrowWide * qSin(arrowAngle) + this->message.Ycoord + 7));
        line2.setP2(QPointF(
            this->seqReceiverObjGui->lineXCoord,
            this->message.Ycoord));

        painter->setPen(pen);
        painter->drawLine(line1);
        painter->drawLine(line2);

    } else if (message.messageType == Message::ASYNC) {
        //draw empty arrow
        arrowAngle = this->seqSenderObjGui->lineXCoord > this->seqReceiverObjGui->lineXCoord ? qDegreesToRadians(45.0) : -qDegreesToRadians(225.0);
        arrowLength = 15;
        arrowWide = 7;

        line1.setP1(QPointF(
            arrowLength * qCos( - arrowAngle) + this->seqReceiverObjGui->lineXCoord - 5,
            arrowWide * qSin(- arrowAngle) + this->message.Ycoord - 7));
        line1.setP2(QPointF(
            this->seqReceiverObjGui->lineXCoord,
            this->message.Ycoord));
        line2.setP1(QPointF(
            arrowLength * qCos(arrowAngle) + this->seqReceiverObjGui->lineXCoord - 5,
            arrowWide * qSin(arrowAngle) + this->message.Ycoord + 7));
        line2.setP2(QPointF(
            this->seqReceiverObjGui->lineXCoord,
            this->message.Ycoord));

        painter->setPen(pen);
        painter->drawLine(line1);
        painter->drawLine(line2);

    }else { //draw full arrow //SYNC CREATE DESTROY
        arrowAngle = this->seqSenderObjGui->lineXCoord > this->seqReceiverObjGui->lineXCoord ? qDegreesToRadians(45.0) : -qDegreesToRadians(225.0);
        arrowLength = 15;
        // the aim
        relLineEnd << QPointF(this->seqReceiverObjGui->lineXCoord, this->message.Ycoord);
        // left corner
        relLineEnd << QPointF(arrowLength * qCos(- arrowAngle) + this->seqReceiverObjGui->lineXCoord,
                              arrowLength * qSin(- arrowAngle) + this->message.Ycoord);
        // right corner
        relLineEnd << QPointF(arrowLength * qCos(arrowAngle) + this->seqReceiverObjGui->lineXCoord,
                              arrowLength * qSin(arrowAngle) + this->message.Ycoord);

        // draw the end
        path.addPolygon(relLineEnd);
        painter->setPen(pen);
        painter->drawPolygon(relLineEnd);
        painter->fillPath(path, color);
    }

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
        //trigger removeMessageNotification()
        this->removeMessageNotification();

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

void SequenceMessageGUI::removeMessageNotification(){
    //remove this message from sequence diagram and also its gui
    this->seqDiagInterface->removeMessage(this->message);
    this->seqDiagInterface->removeSequenceMessageGUI(this);

    //notify both related classes about deletion
    this->seqReceiverObjGui->removeRelatedReceivingMessage(this);
    this->seqSenderObjGui->removeRelatedSendingMessage(this);
}

SequenceMessageGUI::~SequenceMessageGUI(){

}



