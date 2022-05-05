#include "sequencediagraminterface.h"

SequenceDiagramInterface::SequenceDiagramInterface(DiagramInterface *diagramInterface, SequenceDiagram sequenceDiagram) : sequenceDiagram(sequenceDiagram)
{
    this->diagramInterface = diagramInterface;
    this->sequenceDiagram = sequenceDiagram;
}

void SequenceDiagramInterface::addNewSequenceObjectGUIToList(SequenceObjectGUI *seqObjGUI)
{
    this->sequenceObjectGUIList.append(seqObjGUI);
}

void SequenceDiagramInterface::removeSequenceObjectGUIFromList(SequenceObjectGUI *seqObjGUI)
{
    this->sequenceObjectGUIList.removeOne(seqObjGUI);
}

void SequenceDiagramInterface::updateSeqClass(UMLSeqClass &seqClass)
{
    sequenceDiagram.updateSeqClass(seqClass);
}

bool SequenceDiagramInterface::existsSeqClass(UMLSeqClass &seqClass)
{
    return sequenceDiagram.existsSeqClass(seqClass);
}

UMLSeqClass SequenceDiagramInterface::addSeqClas(UMLSeqClass &seqClass)
{
    return sequenceDiagram.addSeqClass(seqClass);
}

void SequenceDiagramInterface::updateMessage(Message &message)
{
    sequenceDiagram.updateMessage(message);
}

Message SequenceDiagramInterface::createMessage(Message &message)
{
    return sequenceDiagram.createMessage(message);
}

void SequenceDiagramInterface::removeMessage(Message &message)
{
    sequenceDiagram.deleteMessage(message);
}

void SequenceDiagramInterface::removeSeqClass(UMLSeqClass &seqClass)
{
    sequenceDiagram.deleteUMLSeqClass(seqClass);
}
