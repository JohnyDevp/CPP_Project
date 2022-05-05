#include "sequenceobjectgui.h"
#include "qfont.h"
#include "qfontmetrics.h"
#include "qgraphicssceneevent.h"
#include "qpainter.h"
#include <iostream>

SequenceObjectGUI::SequenceObjectGUI(UMLSeqClass umlSeqClass, SequenceDiagramInterface * seqDiagInterface)
{
    //set up all coords
    this->boundingX = umlSeqClass.Xcoord;
    this->boundingY = TOP_Y_COORD;
    this->boundingWidth = 50;
    this->boundingHeight = 800;

    setFlag(QGraphicsItem::ItemIsMovable);

    //build displayed name
    //it is build from [name of instance][:][umlClassName]
    this->objectName = umlSeqClass.name + ":" + umlSeqClass.className;

    //set umlSeqClass
    this->umlSeqClass = umlSeqClass;

    //set sequence diagram interface
    this->seqDiagInterface = seqDiagInterface;
}

QRectF SequenceObjectGUI::boundingRect() const {
    return QRectF(this->boundingX,this->boundingY,this->boundingWidth,this->boundingHeight);
}

void SequenceObjectGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //note - number 50 here represents the height of text-background rectangle

    //variable for knowledge, if it is necessary to update bounding rectangle after this drawing
    bool widthChanged = false;

    //set font and measure its width
    QFont font("arial", 10);
    painter->setFont(font);

    QFontMetrics metr(font);
    int txtWidth = metr.width(objectName);

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

    //do not draw the bounding rectangle !!!! -> it is just for "bounds"
    //QRectF rect = boundingRect();
    //painter->drawRect(rect);

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

    QGraphicsItem::mousePressEvent(event);
}

void SequenceObjectGUI::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    qreal curX = event->scenePos().x();
    qreal curY = event->scenePos().y();

    //if the click was on the line
    if (curX >= this->boundingX+this->boundingWidth/2 - 3 &&
        curX <= this->boundingX+this->boundingWidth/2 + 3 &&
        curY >  this->boundingY + 50){

        std::cout << "line click" << std::endl;
    }

    QGraphicsItem::mouseDoubleClickEvent(event);
}


void SequenceObjectGUI::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qreal diffX = event->scenePos().x() - this->mousePrevSceneX;

    this->mousePrevSceneX = event->scenePos().x();

    this->boundingX += diffX;

    update();
    this->seqDiagInterface->updateScene();

    //do not trigger the normall-mouseMoveEvent (it will do mistakes!!!)
    //QGraphicsItem::mouseMoveEvent(event);

}

SequenceObjectGUI::~SequenceObjectGUI(){
}
