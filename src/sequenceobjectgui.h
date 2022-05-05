#ifndef SEQUENCEOBJECTGUI_H
#define SEQUENCEOBJECTGUI_H

#include "cls/UMLSeqClass.hpp"
#include <QGraphicsItem>

#define TOP_Y_COORD 30

class SequenceObjectGUI : public QGraphicsItem
{
public:
    SequenceObjectGUI(UMLSeqClass umlSeqClass);

    ~SequenceObjectGUI();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    UMLSeqClass umlSeqClass;

    QString objectName;

    /**
     * @brief variable storing, whether there is no background for this umlSeqClass (as umlclass) or there is
     */
    bool umlClassExists = true;

private:

    // variables for default coords of bounding rectangle
    int boundingX;
    int boundingY = TOP_Y_COORD;
    int boundingWidth;
    int boundingHeight;

};

#endif // SEQUENCEOBJECTGUI_H
