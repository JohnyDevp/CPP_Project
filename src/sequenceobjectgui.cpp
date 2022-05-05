#include "sequenceobjectgui.h"
#include "qfont.h"
#include "qfontmetrics.h"

SequenceObjectGUI::SequenceObjectGUI(UMLSeqClass umlSeqClass)
{
    //set up all coords
    this->boundingX = umlSeqClass.Xcoord;
    this->boundingY = TOP_Y_COORD;
    this->boundingWidth = 50;
    this->boundingHeight = 30;
}

QRectF SequenceObjectGUI::boundingRect() const {
    return QRectF(this->boundingX,this->boundingY,this->boundingWidth,this->boundingHeight);
}

void SequenceObjectGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QFont font("arial", 15);
    QFontMetrics metr(font);
    //plus one, because there is added ":"
    int width = metr.width(this->umlSeqClass.name) + 1;

    if (width > this->boundingWidth) boundingWidth = width;

}

SequenceObjectGUI::~SequenceObjectGUI(){
}
