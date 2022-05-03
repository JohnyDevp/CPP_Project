#pragma once
#ifndef DIAGRAMINTERFACE_H
#define DIAGRAMINTERFACE_H

#include "cls/ClassDiagram.hpp"
#include "cls/SequenceDiagram.hpp"
#include "cls/UMLRelation.hpp"
#include "cls/UMLSeqClass.hpp"
#include "objectgui.h"
#include "cls/JsonPrintable.hpp"
#include <iostream>
#include <vector>
#include <QMap>

class DiagramInterface : public JsonPrintable
{
public:
    DiagramInterface();
    void addObjectToObjectGuiList(ObjectGUI *objectGui);
    void removeObjectFromList();

    int relationIndex;
    int sequenceDiagramIndex;
    /**
     * @brief
     *
     */
    UMLRelation tempRelation;

    ClassDiagram classDiagram;

    QMap<int, SequenceDiagram> sequenceDiagrams;

    // Interface functions for more cleaner code

    void updateUMLClass(QString oldName, UMLClass umlClass);

    void updateRelation(UMLRelation relation);

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

    void removeUMLClass(UMLClass umlClass);

    void removeRelation(UMLRelation relation);

        /**
     * @brief converts object to json
     *
     * @param json
     */
    void write(QJsonObject &json) const override;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

private:
    /**
     * @brief guiObjectList
     */
    QList<ObjectGUI*> guiObjectList;
};

#endif // DIAGRAMINTERFACE_H
