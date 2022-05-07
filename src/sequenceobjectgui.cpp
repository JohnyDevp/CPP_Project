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

SequenceObjectGUI::SequenceObjectGUI(UMLSeqClass umlSeqClass, SequenceDiagramInterface *seqDiagInterface)
{
    // set up all coords
    this->boundingX = umlSeqClass.Xcoord;
    this->boundingY = TOP_Y_COORD;
    this->boundingWidth = 50;
    this->boundingHeight = 800;
    this->objectDestroyPoint = this->boundingHeight;

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);

    // set umlSeqClass
    this->umlSeqClass = umlSeqClass;

    // set sequence diagram interface
    this->seqDiagInterface = seqDiagInterface;

    setZValue(10);
}

QRectF SequenceObjectGUI::boundingRect() const
{
    return QRectF(this->boundingX, this->boundingY, this->boundingWidth, this->boundingHeight);
}

void SequenceObjectGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // note - number 50 here represents the height of text-background rectangle

    // build displayed name
    // it is build from [name of instance][:][umlClassName]
    this->objectName = umlSeqClass.name + ":" + umlSeqClass.className;

    // variable for knowledge, if it is necessary to update bounding rectangle after this drawing
    bool widthChanged = false;

    // set font and measure its width
    QFont font("arial", 10);
    painter->setFont(font);

    QFontMetrics metr(font);
    int txtWidth = metr.width(this->objectName);

    if (txtWidth > this->boundingWidth + 10)
    {
        boundingWidth = txtWidth + 10;
        widthChanged = true;
    }

    // set pen according to whether the umlClass exists or not
    QColor color;
    if (umlClassExists)
        color = Qt::black;
    else
        color = Qt::red;

    // set pen for rectangle
    QPen penRect(color, 3);
    painter->setPen(penRect);

    // draw and fill the background rectangle of the text
    painter->drawRect(this->boundingX, this->boundingY, this->boundingWidth, 50);
    painter->fillRect(this->boundingX, this->boundingY, this->boundingWidth, 50, QColor(200, 207, 230));

    // draw the text
    QPointF txtPoint(
        this->boundingX + this->boundingWidth / 2 - txtWidth / 2,
        this->boundingY + 50 / 2);
    painter->drawText(txtPoint, this->objectName);

    // set pen for line (dashed line)
    QPen penLine(color, 6, Qt::DashLine);
    painter->setPen(penLine);

    // draw the line
    QPointF lineStartPoint(
        this->boundingX + this->boundingWidth / 2,
        this->boundingY + 53 // some points correction to make line not overdrawing adge of rectangle background
    );
    QPointF lineEndPoint(
        this->boundingX + this->boundingWidth / 2,
        this->boundingY + this->objectDestroyPoint - this->boundingY);
    painter->drawLine(lineStartPoint, lineEndPoint);

    // draw all active rectangles
    updateActiveRectangles();
    foreach (QRectF rec, this->activeRectangles)
    {
        painter->fillRect(rec, QColor(85, 230, 237));
    }

    if (widthChanged)
        update();
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

    if (curX >= this->boundingX + this->boundingWidth / 2 - 3 &&
        curX <= this->boundingX + this->boundingWidth / 2 + 3 &&
        curY > this->boundingY + 50)
    {
        // if the click was on the class time-line

        AddMessageDialog *addMessageDlg = new AddMessageDialog();
        addMessageDlg->init(this, this->seqDiagInterface);
        addMessageDlg->exec();

        // get message
        if (!addMessageDlg->dataValid)
            return;

        // create message gui and add it to the sequence diagram interface
        Message newMsg = addMessageDlg->getCreatedMessage();
        newMsg.Ycoord = curY;
        this->seqDiagInterface->createMessage(newMsg);

        update();
    }
    else if (curY <= this->boundingY + 50)
    {
        // if the click was on the background rectangle
        // ask for delete

        QMessageBox msgBox;
        QPushButton *deleteButton = msgBox.addButton("Remove",QMessageBox::ActionRole);
        msgBox.setText("Remove class?");
        QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
        msgBox.exec();

        if (msgBox.clickedButton() == (QAbstractButton *)deleteButton)
        {
            this->seqDiagInterface->removeSeqClass(this->umlSeqClass);
            this->seqDiagInterface->removeSequenceObjectGUI(this);

            //go through all the messages and notify them about this removal
            foreach(SequenceMessageGUI *seqMsgGui, this->seqReceivingMsgGuiList){
                seqMsgGui->removeMessageNotification();
            }

            foreach(SequenceMessageGUI *seqMsgGui, this->seqSendingMsgGuiList){
                seqMsgGui->removeMessageNotification();
            }
        }
        else if (msgBox.clickedButton() == (QAbstractButton *)cancelButton)
        {
            // do nothing
            return;
        }
    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}

QVariant SequenceObjectGUI::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange)
    {
        qreal diffX = scenePos().x() - this->mousePrevSceneX;
        this->mousePrevSceneX = scenePos().x();

        //this->boundingX += pos().x();
        this->prevMouseLocalX = pos().x();

        // load the new coords to the umlseq class and upload it
        //this->umlSeqClass.Xcoord += diffX;
        this->umlSeqClass.Xcoord = value.toPointF().x();
        this->seqDiagInterface->updateSeqClass(this->umlSeqClass);

        // set coordination for messages
        this->lineXCoord = this->umlSeqClass.Xcoord + this->boundingWidth / 2 + 5;

        update();

        this->seqDiagInterface->updateScene();

        return QPointF(value.toPointF().x(), pos().y());
    }
    return QGraphicsItem::itemChange(change, value);
}

void SequenceObjectGUI::updateActiveRectangles()
{
    // clear all rectangles
    this->activeRectangles.clear();


    // firstly build all activated objects
    foreach (SequenceMessageGUI *seqMsgGui, this->seqReceivingMsgGuiList)
    {
        if (seqMsgGui->isDeactivatingReceiver &&
            seqMsgGui->message.messageType == Message::DESTROY)
        {
            this->objectDestroyPoint = seqMsgGui->message.Ycoord;
        }

        if (!seqMsgGui->isDeactivatingReceiver)
        {
            QRectF rec(this->boundingX + this->boundingWidth / 2 - 6, seqMsgGui->message.Ycoord, 10, this->objectDestroyPoint - seqMsgGui->message.Ycoord);
            this->activeRectangles.append(rec);
        }
    }

    foreach (SequenceMessageGUI *seqMsgGui, this->seqSendingMsgGuiList)
    {
        if (!seqMsgGui->isDeactivatingSender)
        {
            QRectF rec(this->boundingX + this->boundingWidth / 2 - 6, seqMsgGui->message.Ycoord, 10, this->objectDestroyPoint - seqMsgGui->message.Ycoord);
            this->activeRectangles.append(rec);
        }
    }

     //then shortened already build rectangles to the deactivating points
    foreach (SequenceMessageGUI * seqMsgGui, this->seqReceivingMsgGuiList){
        if(seqMsgGui->isDeactivatingReceiver){
            foreach(QRectF rec, this->activeRectangles){
                if (seqMsgGui->message.Ycoord > rec.y() &&
                    seqMsgGui->message.Ycoord < rec.y()+rec.height()){
                    //update this rectangle (its height)
                    this->activeRectangles.removeOne(rec);
                    rec.setHeight(seqMsgGui->message.Ycoord - rec.y());
                    this->activeRectangles.append(rec);
                }
            }

        }
    }

    foreach (SequenceMessageGUI * seqMsgGui, this->seqSendingMsgGuiList){
        if(seqMsgGui->isDeactivatingSender){
            foreach(QRectF rec, this->activeRectangles){
                if (seqMsgGui->message.Ycoord > rec.y() &&
                    seqMsgGui->message.Ycoord < rec.y()+rec.height()){
                    //update this rectangle (its height)
                    this->activeRectangles.removeOne(rec);
                    rec.setHeight(seqMsgGui->message.Ycoord - rec.y());
                    this->activeRectangles.append(rec);
                }
            }

        }
    }
}

void SequenceObjectGUI::addRelatedReceivingMessage(SequenceMessageGUI *seqMsgGui)
{
    this->seqReceivingMsgGuiList.append(seqMsgGui);
    updateActiveRectangles();
}

void SequenceObjectGUI::addRelatedSendingMessage(SequenceMessageGUI *seqMsgGui)
{
    this->seqSendingMsgGuiList.append(seqMsgGui);
    updateActiveRectangles();
}

void SequenceObjectGUI::removeRelatedReceivingMessage(SequenceMessageGUI *seqMsgGui){
    this->seqReceivingMsgGuiList.removeOne(seqMsgGui);
    update();
}

void SequenceObjectGUI::removeRelatedSendingMessage(SequenceMessageGUI *seqMsgGui){
    this->seqSendingMsgGuiList.removeOne(seqMsgGui);
    update();
}

SequenceObjectGUI::~SequenceObjectGUI()
{
}
