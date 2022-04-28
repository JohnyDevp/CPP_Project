#ifndef OBJECTGUI_H
#define OBJECTGUI_H

#include "src/cls/UMLClassInterfaceTemplate.hpp"
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include "cls/UMLClass.hpp"

class ObjectGUI : public QGraphicsItem
{
public:
    /**
     * @brief ObjectGUI - constructor
     * @param umlClass
     */
    ObjectGUI(UMLClass umlClass);
    ~ObjectGUI();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief isSelected
     */
    bool isSelected = false;

    /**
     * @brief umlObject
     */
    UMLClassInterfaceTemplate umlObject;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
    //variables for default coords of bounding rectangle
    int boundingX;
    int boundingY;
    int boundingWidth;
    int boundingHeight;

    /**
     * @brief umlClass
     */
    UMLClass umlClass;

};

#endif // OBJECTGUI_H
