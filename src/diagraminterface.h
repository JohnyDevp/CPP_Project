/**
 * @file diagraminterface.h
 * @author xholan11, xzimol04
 * @brief Header file for diagraminterface.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "cls/ClassDiagram.hpp"
#include "cls/SequenceDiagram.hpp"
#include "cls/UMLRelation.hpp"
#include "cls/UMLSeqClass.hpp"
#include "objectgui.h"
#include "relationgui.h"
#include "sequencediagraminterface.h"

#include <iostream>
#include <vector>
#include <QMap>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QJsonDocument>

class ObjectGUI;
class RelationGui;
class SequenceDiagramInterface;

#define classDiagramName "classDiagram"
#define sequenceDiagramsName "sequenceDiagrams"

class DiagramInterface
{
public:
    ~DiagramInterface();
    DiagramInterface(QGraphicsScene *scene);

    void addObjectToObjectGuiList(ObjectGUI *objectGui);
    void removeObjectFromGuiList(ObjectGUI *objectGui);
    void removeRelationFromGuiList(RelationGui *relationGui);

    int sequenceDiagramIndex;

    /**
     * @brief used to createRelation
     */
    UMLRelation tempUmlRelation;

    bool isRelationCreating = false;

    ClassDiagram classDiagram;

    QList<SequenceDiagramInterface *> sequenceDiagramInterfaceList;

    // Interface functions for more cleaner code

    void updateUMLClass(QString oldName, UMLClass umlClass);

    void updateRelation(UMLRelation relation);

    /**
     * @brief returns UMLClass and assumes that you checked that it exists
     *
     * @param name
     * @return UMLClass
     */
    UMLClass getUMLClass(QString &name);

    bool existsOperation(UMLClass &cl, UMLOperation &operation);

    bool existsClass(QString &className);

    bool existsClass(UMLClass &umlClass);
    /**
     * @brief Create or update SeqClass
     *
     * @param dia
     * @param seqClass
     */
    void updateSeqClass(SequenceDiagram dia, UMLSeqClass seqClass);

    void updateMessage(SequenceDiagram dia, Message message);

    bool createUMLClass(UMLClass &umlClass);

    UMLRelation createRelation();

    Message createMessage(SequenceDiagram dia, Message &message);

    void removeMessage(SequenceDiagram dia, Message &message);

    void removeSeqClass(SequenceDiagram dia, UMLSeqClass seqClass);
    /**
     * @brief removeUMLClass
     * @param umlClass
     */
    void removeUMLClass(UMLClass umlClass);

    void removeRelation(UMLRelation relation);

    void updateSequenceDiagram(SequenceDiagram &dia);

    SequenceDiagram createSequenceDiagram(SequenceDiagram &dia);

    void addSequenceDiagramInterface(SequenceDiagramInterface *diaInter);

    void write(QJsonObject &json) const;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

    bool load(QString filepath);

    bool save(QString filepath);

    static bool isCorrect(const DiagramInterface &inter);
    bool isCorrect() const;

    QList<ObjectGUI *> guiObjectList;

    QList<RelationGui *> relationList;

    QGraphicsScene *scene;
};
