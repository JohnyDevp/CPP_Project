#include "sequenceobjectgui.h"
#include "qfont.h"
#include "qfontmetrics.h"
#include "qpainter.h"

SequenceObjectGUI::SequenceObjectGUI(UMLSeqClass umlSeqClass)
{
    //set up all coords
    this->boundingX = umlSeqClass.Xcoord;
    this->boundingY = TOP_Y_COORD;
    this->boundingWidth = 50;
    this->boundingHeight = 30;

    //build displayed name
    //it is build from [name of instance][:][umlClassName]
    this->objectName = umlSeqClass.name + ":" + umlSeqClass.className;

    //set umlSeqClass
    this->umlSeqClass = umlSeqClass;
}

QRectF SequenceObjectGUI::boundingRect() const {
    return QRectF(this->boundingX,this->boundingY,this->boundingWidth,this->boundingHeight);
}

void SequenceObjectGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //variable for knowledge, if it is necessary to update bounding rectangle after this drawing
    bool widthChanged = false;

    //set font and measure its width
    QFont font("arial", 15);
    painter->setFont(font);
    QFontMetrics metr(font);
    int txtWidth = metr.width(objectName);

    if (txtWidth > this->boundingWidth) {
        boundingWidth = txtWidth;
        widthChanged = true;
    }

    //set pen according to whether the umlClass exists or not
    QColor color;
    if (umlClassExists) color = Qt::black;
    else color = Qt::red;

    //set pen for rectangle
    QPen penRect(color, 3);
    painter->setPen(penRect);

    //draw the rectangle
    QRectF rect = boundingRect();
    painter->drawRect(rect);

    //draw the text
    QPointF txtPoint(
                this->boundingX + this->boundingWidth / 2 - txtWidth/2,
                this->boundingY + this->boundingHeight / 2
                );
    painter->drawText(txtPoint, this->objectName);

    //set pen for line (dashed line)
    QPen penLine(color, 5, Qt::DashLine);
    painter->setPen(penLine);

    //draw the line
    QPointF lineStartPoint(
                this->boundingX + this->boundingWidth / 2,
                this->boundingY + this->boundingHeight
                );
    QPointF lineEndPoint(
                this->boundingX + this->boundingWidth / 2,
                this->boundingY + this->boundingHeight + 800
                );
    painter->drawLine(lineStartPoint, lineEndPoint);

    if (widthChanged) update();
}

SequenceObjectGUI::~SequenceObjectGUI(){
}
