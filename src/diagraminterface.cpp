#include "diagraminterface.h"
#include "objectgui.h"
#include <QGraphicsScene>

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

bool DiagramInterface::existsClass(UMLClass &umlClass)
{
    return classDiagram.existsClass(umlClass);
}

bool DiagramInterface::existsClass(QString &className)
{
    return classDiagram.existsClass(className);
}

void DiagramInterface::updateSeqClass(SequenceDiagram dia, UMLSeqClass seqClass)
{
    sequenceDiagrams[dia.index].classes[seqClass.name] = seqClass;
}

void DiagramInterface::updateMessage(SequenceDiagram dia, Message message)
{
    sequenceDiagrams[dia.index].messages[message.index] = message;
}

bool DiagramInterface::createUMLClass(UMLClass &umlClass)
{
    return classDiagram.addClass(umlClass);
}

UMLRelation DiagramInterface::createRelation()
{
    //create gui for the relation
    RelationGui * newRelGui = new RelationGui(tempUmlRelation, this);

    //bound related objects to this relation
    foreach(ObjectGUI * obj, this->guiObjectList){
        if (obj->objectName == tempUmlRelation.relationFrom){
            obj->addRelatedRelation(newRelGui);
            newRelGui->objectStart = obj;
        } else if (obj->objectName == tempUmlRelation.relationTo){
            obj->addRelatedRelation(newRelGui);
            newRelGui->objectEnd = obj;
        }
    }

    //check for override of operation
    newRelGui->objectStart->checkForOverrideOperationsNotification();

    //add the relation gui to the scene and to the list of relations
    this->relationList.append(newRelGui);
    this->scene->addItem(newRelGui);

    return classDiagram.addRelation(tempUmlRelation);
}

Message DiagramInterface::createMessage(SequenceDiagram dia, Message &message)
{
    return sequenceDiagrams[dia.index].createMessage(message);
}

void DiagramInterface::removeMessage(SequenceDiagram dia, Message &message)
{
    sequenceDiagrams[dia.index].messages.remove(message.index);
}

void DiagramInterface::removeSeqClass(SequenceDiagram dia, UMLSeqClass seqClass)
{
    sequenceDiagrams[dia.index].classes.remove(seqClass.name);
}

void DiagramInterface::removeUMLClass(UMLClass umlClass)
{
    classDiagram.classList.remove(umlClass.name);
}

void DiagramInterface::removeRelation(UMLRelation relation)
{
    classDiagram.relationList.remove(relation.index);
}

void DiagramInterface::updateSequenceDiagram(SequenceDiagram &dia)
{
    sequenceDiagrams[dia.index] = dia;
}

SequenceDiagram DiagramInterface::createSequenceDiagram(SequenceDiagram &dia)
{
    dia.index = sequenceDiagramIndex;
    sequenceDiagrams[dia.index] = dia;
    sequenceDiagramIndex++;
    return dia;
}

void DiagramInterface::write(QJsonObject &json) const
{
    QJsonArray sequenceDiaArray;

    for (const SequenceDiagram &dia : sequenceDiagrams)
    {
        QJsonObject diaObject;
        dia.write(diaObject);
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
        sequenceDiagrams.clear();

        // Store sequenceDiagramIndex
        sequenceDiagramIndex = seqDiaArray.size();

        for (int i = 0; i < seqDiaArray.size(); i++)
        {
            QJsonObject seqObj = seqDiaArray[i].toObject();
            SequenceDiagram seq;
            seq.read(seqObj);
            // Add index
            seq.index = i;
            sequenceDiagrams[i] = seq;
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
    foreach (const SequenceDiagram &dia, sequenceDiagrams)
    {
        if (!SequenceDiagram::isCorrect(dia))
            return false;
    }

    if (!ClassDiagram::isCorrect(classDiagram))
        return false;

    return true;
}

bool DiagramInterface::isCorrect(const DiagramInterface &inter)
{
    foreach (const SequenceDiagram &dia, inter.sequenceDiagrams)
    {
        if (!SequenceDiagram::isCorrect(dia))
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
