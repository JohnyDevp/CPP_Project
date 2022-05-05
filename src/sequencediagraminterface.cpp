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

void SequenceDiagramInterface::updateSeqClass(SequenceDiagram dia, UMLSeqClass seqClass)
{
    sequenceDiagram.classes[seqClass.name] = seqClass;
}

void SequenceDiagramInterface::updateMessage(SequenceDiagram dia, Message message)
{
    sequenceDiagram.messages[message.index] = message;
}

Message SequenceDiagramInterface::createMessage(SequenceDiagram dia, Message &message)
{
    return sequenceDiagram.createMessage(message);
}

void SequenceDiagramInterface::removeMessage(SequenceDiagram dia, Message &message)
{
    sequenceDiagram.messages.remove(message.index);
}

void SequenceDiagramInterface::removeSeqClass(SequenceDiagram dia, UMLSeqClass seqClass)
{
    sequenceDiagram.classes.remove(seqClass.name);
}
