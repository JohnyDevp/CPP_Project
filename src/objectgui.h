#pragma once

#ifndef OBJECTGUI_H
#define OBJECTGUI_H

#include "cls/UMLClass.hpp"
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include "cls/UMLClass.hpp"
#include "diagraminterface.h"
#include "relationgui.h"

class RelationGui;
class DiagramInterface;

class ObjectGUI : public QGraphicsItem
{
public:
    /**
     * @brief ObjectGUI - constructor
     * @param umlClass
     */
    ObjectGUI(UMLClass umlClass, DiagramInterface * diagramInterface);
    ~ObjectGUI();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void addRelatedRelation(RelationGui * relation);

    /**
     * @brief isSelected - whether the class is selected or not
     */
    bool isSelected = false;

    /**
     * @brief initGui
     */
    void initGui();

    /**
     * @brief objectName
     */
    QString objectName;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int prevMouseX;
    int prevMouseY;
    // variables for default coords of bounding rectangle
    int boundingX;
    int boundingY;
    int boundingWidth;
    int boundingHeight;


    /**
     * @brief isInterface - defined, whether this object represents an interface or not
     */
    bool isInterface = false;

    /**
     * @brief umlObject - storing uml representation of this gui
     */
    UMLClass umlObject;

    /**
     * @brief operationMapGUI
     * map for storing each operation and its string representation drawn in gui object
     */
    QMap<UMLOperation, QString> operationMapGUI;

    /**
     * @brief overrideOperations
     * list of operation that are overrided from any of class, related to this class by generalization
     */
    QList<UMLOperation> overrideOperations;

    /**
     * @brief attributesMapGUI
     * map for storing each attribute and its string representation drawn in gui object
     */
    QMap<UMLAttribute, QString> attributesMapGUI;

    /**
     * @brief diagramInterface
     * pointer to middle part of program between inner and gui representation
     */
    DiagramInterface * diagramInterface;

    /**
     * @brief relatedRelation
     * list of relations which there started or ended
     */
    QList<RelationGui*> relatedRelations;
};

#endif // OBJECTGUI_H
