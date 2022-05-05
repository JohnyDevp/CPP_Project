#include "sequenceobjectgui.h"
#include "qfont.h"

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
    QFont font("arial")
}

SequenceObjectGUI::~SequenceObjectGUI(){
}
