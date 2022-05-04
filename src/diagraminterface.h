#pragma once

#include "cls/ClassDiagram.hpp"
#include "cls/SequenceDiagram.hpp"
#include "cls/UMLRelation.hpp"
#include "cls/UMLSeqClass.hpp"
#include "objectgui.h"
#include "cls/JsonPrintable.hpp"
#include <iostream>
#include <vector>
#include <QMap>
#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QJsonDocument>

class ObjectGUI;

#define classDiagramName "classDiagram"
#define sequenceDiagramsName "sequenceDiagrams"

class DiagramInterface : public JsonPrintable
{
public:
    DiagramInterface(QGraphicsScene *scene);

    // DiagramInterface(QGraphicsScene *scene, DiagramInterface &inter);

    void addObjectToObjectGuiList(ObjectGUI *objectGui);
    void removeObjectFromGuiList(ObjectGUI *objectGui);

    int sequenceDiagramIndex;
    /**
     * @brief used to createRelation
     *
     */
    UMLRelation tempRelation;

    ClassDiagram classDiagram;

    QMap<int, SequenceDiagram> sequenceDiagrams;

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

    void write(QJsonObject &json) const override;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

    bool load(QString filepath);

    bool save(QString filepath);

    static bool isCorrect(const DiagramInterface &inter);

    QList<ObjectGUI *> guiObjectList;

    QGraphicsScene *scene;
};
