#include "sequenceobjectgui.h"

SequenceObjectGUI::SequenceObjectGUI()
{

}

QRectF SequenceObjectGUI::boundingRect() const {
    return QRectF(0,0,100,100);
}

void SequenceObjectGUI::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

}

SequenceObjectGUI::~SequenceObjectGUI(){
}
