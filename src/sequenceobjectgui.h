#ifndef SEQUENCEOBJECTGUI_H
#define SEQUENCEOBJECTGUI_H

#include "cls/UMLSeqClass.hpp"
#include <QGraphicsItem>

class SequenceObjectGUI : public QGraphicsItem
{
public:
    SequenceObjectGUI();

    ~SequenceObjectGUI();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    UMLSeqClass umlSeqClass;

private:

};

#endif // SEQUENCEOBJECTGUI_H
