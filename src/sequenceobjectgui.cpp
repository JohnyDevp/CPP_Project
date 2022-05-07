/**
 * @file sequenceobjectgui.cpp
 * @author xholan11
 * @brief Represents class in sequence diagram
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "sequenceobjectgui.h"
#include "controllers/addmessagedialog.h"
#include "qabstractbutton.h"
#include "qfont.h"
#include "qfontmetrics.h"
#include "qgraphicssceneevent.h"
#include "qmessagebox.h"
#include "qpainter.h"
#include <iostream>

SequenceObjectGUI::SequenceObjectGUI(UMLSeqClass umlSeqClass, SequenceDiagramInterface * seqDiagInterface)
{
    //set up all coords
    this->boundingX = umlSeqClass.Xcoord;
    this->boundingY = TOP_Y_COORD;
    this->boundingWidth = 50;
    this->boundingHeight = 800;
    this->objectDestroyPoint = this->boundingHeight;

    setFlag(QGraphicsItem::ItemIsMovable);
    //setFlag(QGraphicsItem::ItemPositionChange);

    //set umlSeqClass
    this->umlSeqClass = umlSeqClass;

    //set sequence diagram interface
    this->seqDiagInterface = seqDiagInterface;

    setZValue(10);
}

QRectF SequenceObjectGUI::boundingRect() const {
    return QRectF(this->boundingX,this->boundingY,this->boundingWidth,this->boundingHeight);
}

void SequenceObjectGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //note - number 50 here represents the height of text-background rectangle

    //build displayed name
    //it is build from [name of instance][:][umlClassName]
    this->objectName = umlSeqClass.name + ":" + umlSeqClass.className;

    //variable for knowledge, if it is necessary to update bounding rectangle after this drawing
    bool widthChanged = false;

    //set font and measure its width
    QFont font("arial", 10);
    painter->setFont(font);

    QFontMetrics metr(font);
    int txtWidth = metr.width(this->objectName);

    if (txtWidth > this->boundingWidth + 10) {
        boundingWidth = txtWidth + 10;
        widthChanged = true;
    }

    //set pen according to whether the umlClass exists or not
    QColor color;
    if (umlClassExists) color = Qt::black;
    else color = Qt::red;

    //set pen for rectangle
    QPen penRect(color, 3);
    painter->setPen(penRect);

    //draw and fill the background rectangle of the text
    painter->drawRect(this->boundingX, this->boundingY, this->boundingWidth, 50);
    painter->fillRect(this->boundingX,this->boundingY,this->boundingWidth,50,QColor(200, 207, 230));

    //draw the text
    QPointF txtPoint(
                this->boundingX + this->boundingWidth / 2 - txtWidth/2,
                this->boundingY + 50/2
                );
    painter->drawText(txtPoint, this->objectName);


    //set pen for line (dashed line)
    QPen penLine(color, 6, Qt::DashLine);
    painter->setPen(penLine);

    //draw the line
    QPointF lineStartPoint(
                this->boundingX + this->boundingWidth / 2,
                this->boundingY + 53 //some points correction to make line not overdrawing adge of rectangle background
                );
    QPointF lineEndPoint(
                this->boundingX + this->boundingWidth / 2,
                this->boundingY + this->boundingHeight
                );
    painter->drawLine(lineStartPoint, lineEndPoint);

    if (widthChanged) update();
}

void SequenceObjectGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->mousePrevSceneX = event->scenePos().x();
    this->prevMouseLocalX = event->pos().x();

    QGraphicsItem::mousePressEvent(event);
}

void SequenceObjectGUI::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qreal curX = event->pos().x();
    qreal curY = event->pos().y();

    if (curX >= this->boundingX+this->boundingWidth/2 - 3 &&
        curX <= this->boundingX+this->boundingWidth/2 + 3 &&
        curY >  this->boundingY + 50){
        //if the click was on the class time-line

        AddMessageDialog * addMessageDlg = new AddMessageDialog();
        addMessageDlg->init(this, this->seqDiagInterface);
        addMessageDlg->exec();

        //get message
        if (!addMessageDlg->dataValid) return;

        //create message gui and add it to the sequence diagram interface
        Message newMsg = addMessageDlg->getCreatedMessage();
        newMsg.Ycoord = curY;
        this->seqDiagInterface->createMessage(newMsg);

        update();
    } else if (curY <= this->boundingY + 50){
        //if the click was on the background rectangle
        //ask for delete

        QMessageBox msgBox;
        QPushButton *deleteButton = nullptr;
        msgBox.setText("Remove class?");
        QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
        msgBox.exec();

        if (msgBox.clickedButton() == (QAbstractButton*)deleteButton) {
            this->seqDiagInterface->removeSeqClass(this->umlSeqClass);
            this->seqDiagInterface->removeSequenceObjectGUI(this);
        } else if (msgBox.clickedButton() == (QAbstractButton*)cancelButton) {
            //do nothing
            return;
        }
    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}

void SequenceObjectGUI::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qreal diffX = event->scenePos().x() - this->mousePrevSceneX;
    this->mousePrevSceneX = event->scenePos().x();

    this->boundingX += event->pos().x() - this->prevMouseLocalX;
    this->prevMouseLocalX = event->pos().x();

    //load the new coords to the umlseq class and upload it
    this->umlSeqClass.Xcoord += diffX;
    this->seqDiagInterface->updateSeqClass(this->umlSeqClass);

    //set coordination for messages
    this->lineXCoord = this->umlSeqClass.Xcoord + this->boundingWidth / 2;

    update();

    this->seqDiagInterface->updateScene();

    QGraphicsItem::mouseMoveEvent(event);

}

QVariant SequenceObjectGUI::itemChange(GraphicsItemChange change, const QVariant &value)
 {
//     if (change == ItemPositionChange && scene()) {
//         // value is the new position.
//         QPointF newPos = value.toPointF();
//         QRectF rect = scene()->sceneRect();
//         rect.setWidth(rect.width() - boundingRect().width());
//         rect.setHeight(0);
//         if (!rect.contains(newPos)) {
//             // Keep the item inside the scene rect.
//             //newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
//             newPos.setY (this->pos().y());
//             return newPos;
//         }
//     }
     return QGraphicsItem::itemChange(change, value);
 }

void SequenceObjectGUI::updateActiveRectangles(){
    //clear all rectangles
    this->activeRectangles.clear();

    //firstly build all activated objects
    foreach (SequenceMessageGUI * seqMsgGui, this->seqReceivingMsgGuiList){
        if(!seqMsgGui->isDeactivatingReceiver){

        }
    }

    foreach (SequenceMessageGUI * seqMsgGui, this->seqSendingMsgGuiList){
        if(!seqMsgGui->isDeactivatingReceiver){

        }
    }
}

void SequenceObjectGUI::addRelatedReceivingMessage(SequenceMessageGUI * seqMsgGui){
    this->seqReceivingMsgGuiList.append(seqMsgGui);
    updateActiveRectangles();
}

void SequenceObjectGUI::addRelatedSendingMessage(SequenceMessageGUI * seqMsgGui){
    this->seqSendingMsgGuiList.append(seqMsgGui);
    updateActiveRectangles();
}

SequenceObjectGUI::~SequenceObjectGUI(){
}
