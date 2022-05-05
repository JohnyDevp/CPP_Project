/**
 * @file diagraminterface.cpp
 * @author xholan11, xzimol04
 * @brief Interface for all data
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "diagraminterface.h"
#include "objectgui.h"
#include <QGraphicsScene>

DiagramInterface::~DiagramInterface()
{
    foreach (SequenceDiagramInterface *seqInt, sequenceDiagramInterfaceList)
    {
        delete seqInt;
    }

    foreach (ObjectGUI *obj, guiObjectList)
    {
        delete obj;
    }

    foreach (RelationGui *rel, relationList)

    {
        delete rel;
    }
}

/**
 * @brief DiagramInterface::DiagramInterface
 * interface for diagrams -> storing sequence diagrams, class diagram
 *                           gui objects lists, relations,...
 */
DiagramInterface::DiagramInterface(QGraphicsScene *scene)
    : classDiagram(QString("ClassDiagram"))
{
    this->scene = scene;
}

// DiagramInterface::DiagramInterface(QGraphicsScene *scene, DiagramInterface &inter)
//     : sequenceDiagramIndex(inter.sequenceDiagramIndex),
//       classDiagram(inter.classDiagram),
//       sequenceDiagrams(inter.sequenceDiagrams)
// {

// }

void DiagramInterface::updateUMLClass(QString oldName, UMLClass umlClass)
{
    //notify sequence diagrams about updates
    foreach(SequenceDiagramInterface * seqDiagInter, this->sequenceDiagramInterfaceList){
        seqDiagInter->notifyUmlClassUpdate(oldName, umlClass);
    }
    scene->update();
    classDiagram.updateClass(oldName, umlClass);
}

void DiagramInterface::updateRelation(UMLRelation relation)
{
    classDiagram.relationList[relation.index] = relation;
}

UMLClass DiagramInterface::getUMLClass(QString &name)
{
    return classDiagram.classList[name];
}

bool DiagramInterface::existsOperation(UMLClass &cl, UMLOperation &operation)
{

    // TODO:
    return classDiagram.classList[cl.name].umlOperationsList.contains(operation);
}

bool DiagramInterface::existsClass(UMLClass &umlClass)
{
    return classDiagram.existsClass(umlClass);
}

bool DiagramInterface::existsClass(QString &className)
{
    return classDiagram.existsClass(className);
}

bool DiagramInterface::createUMLClass(UMLClass &umlClass)
{
    bool success = classDiagram.addClass(umlClass);

<<<<<<< HEAD
    //notify sequence diagrams about updates - if the operation was successfull
    if (success) {
        foreach(SequenceDiagramInterface * seqDiagInter, this->sequenceDiagramInterfaceList){
=======
    // notify sequence diagrams about updates - if the operation was successfull
    if (success)
    {
        foreach (SequenceDiagramInterface *seqDiagInter, this->sequenceDiagramInterfaceList)
        {
>>>>>>> sequence2
            seqDiagInter->updateEverything();
        }
    }

    return success;
}

UMLRelation DiagramInterface::createRelation()
{
    // create gui for the relation
    RelationGui *newRelGui = new RelationGui(tempUmlRelation, this);

    // bound related objects to this relation
    foreach (ObjectGUI *obj, this->guiObjectList)
    {
        if (obj->objectName == tempUmlRelation.relationFrom)
        {
            obj->addRelatedRelation(newRelGui);
            newRelGui->objectStart = obj;
        }
        else if (obj->objectName == tempUmlRelation.relationTo)
        {
            obj->addRelatedRelation(newRelGui);
            newRelGui->objectEnd = obj;
        }
    }

    // check for override of operation
    newRelGui->objectStart->checkForOverrideOperationsNotification();

    // add the relation gui to the scene and to the list of relations
    this->relationList.append(newRelGui);
    this->scene->addItem(newRelGui);

    // reset newRelGui umlRelation
    newRelGui->umlRelation = classDiagram.addRelation(tempUmlRelation);

    // TODO -> not necessary to return anything
    return newRelGui->umlRelation;
}

void DiagramInterface::removeUMLClass(UMLClass umlClass)
{
    classDiagram.classList.remove(umlClass.name);

<<<<<<< HEAD
    //notify sequence diagrams about updates
    foreach(SequenceDiagramInterface * seqDiagInter, this->sequenceDiagramInterfaceList){
=======
    // notify sequence diagrams about updates
    foreach (SequenceDiagramInterface *seqDiagInter, this->sequenceDiagramInterfaceList)
    {
>>>>>>> sequence2
        seqDiagInter->updateEverything();
    }
}

void DiagramInterface::removeRelation(UMLRelation relation)
{
    classDiagram.relationList.remove(relation.index);
}

void DiagramInterface::addSequenceDiagramInterface(SequenceDiagramInterface *diaInter)
{
    sequenceDiagramInterfaceList.append(diaInter);
}

void DiagramInterface::write(QJsonObject &json) const
{
    QJsonArray sequenceDiaArray;

    for (SequenceDiagramInterface *dia : sequenceDiagramInterfaceList)
    {
        QJsonObject diaObject;
        dia->sequenceDiagram.write(diaObject);
        sequenceDiaArray.append(diaObject);
    }
    json[sequenceDiagramsName] = sequenceDiaArray;

    QJsonObject classDiaObject;
    classDiagram.write(classDiaObject);

    json[classDiagramName] = classDiaObject;
}

void DiagramInterface::read(const QJsonObject &json)
{
    if (json.contains(sequenceDiagramsName) && json[sequenceDiagramsName].isArray())
    {
        QJsonArray seqDiaArray = json[sequenceDiagramsName].toArray();
        sequenceDiagramInterfaceList.clear();

        for (int i = 0; i < seqDiaArray.size(); i++)
        {
            QJsonObject seqObj = seqDiaArray[i].toObject();
            SequenceDiagram seq;
            seq.read(seqObj);
            SequenceDiagramInterface *seqInter = new SequenceDiagramInterface(this, seq);
            addSequenceDiagramInterface(seqInter);
        }
    }

    if (json.contains(classDiagramName) && json[classDiagramName].isObject())
    {
        QJsonObject clObj = json[classDiagramName].toObject();
        classDiagram.read(clObj);
    }
}

bool DiagramInterface::load(QString filepath)
{
    QFile loadFile(filepath);
    if (!loadFile.open(QIODevice::ReadOnly))
    {
        return false;
    }

    QByteArray loadedData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadedData));

    read(loadDoc.object());

    return true;
}

bool DiagramInterface::save(QString filepath)
{
    QFile saveFile(filepath);
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        return false;
    }

    QJsonObject dataObj;
    write(dataObj);
    saveFile.write(QJsonDocument(dataObj).toJson());

    return true;
}

bool DiagramInterface::isCorrect() const
{
    foreach (const SequenceDiagramInterface *dia, sequenceDiagramInterfaceList)
    {
        if (!SequenceDiagram::isCorrect(dia->sequenceDiagram))
            return false;
    }

    if (!ClassDiagram::isCorrect(classDiagram))
        return false;

    return true;
}

bool DiagramInterface::isCorrect(const DiagramInterface &inter)
{
    foreach (const SequenceDiagramInterface *dia, inter.sequenceDiagramInterfaceList)
    {
        if (!SequenceDiagram::isCorrect(dia->sequenceDiagram))
            return false;
    }

    if (!ClassDiagram::isCorrect(inter.classDiagram))
        return false;

    return true;
}

void DiagramInterface::addObjectToObjectGuiList(ObjectGUI *objectGui)
{
    this->guiObjectList.append(objectGui);
}

void DiagramInterface::removeObjectFromGuiList(ObjectGUI *objectGui)
{
    this->scene->removeItem(objectGui);

    this->guiObjectList.removeOne(objectGui);

    this->scene->update();
}

void DiagramInterface::removeRelationFromGuiList(RelationGui *relationGui)
{
    this->scene->removeItem(relationGui);
    this->relationList.removeOne(relationGui);

    this->scene->update();
}
