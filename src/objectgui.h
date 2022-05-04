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

    /**
     * @brief add newly created realtion to the list of relations related to this object
     * @param relation - newly created relation gui
     */
    void addRelatedRelation(RelationGui * relation);
    void removeRelatedRelation(RelationGui * relation);

    /**
     * @brief function for check whether some of related objects by generalization doesnt include same operation as
     * this operation, if so, then that operation is added to the list of overriden operations
     * @param operationsForCheck
     */
    void checkForOverrideOperationsNotification();

    /**
     * @brief initGui
     * this function initialize all the lists of attributes, operations (build them to the strings), sets coords,...
     */
    void initGui();

    /**
     * @brief objectName
     */
    QString objectName;

    /**
     * @brief operationMapGUI
     * map for storing each operation and its string representation drawn in gui object
     */
    QMap<UMLOperation, QString> operationMapGUI;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    qreal prevMouseLocalX;
    qreal prevMouseLocalY;

    qreal prevMouseSceneX;
    qreal prevMouseSceneY;

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
