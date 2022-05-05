#include "sequencediagraminterface.h"

SequenceDiagramInterface::SequenceDiagramInterface(DiagramInterface * diagramInterface, SequenceDiagram &sequenceDiagram) : sequenceDiagram()
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

void DiagramInterface::updateSeqClass(SequenceDiagram dia, UMLSeqClass seqClass)
{
    sequenceDiagrams[dia.index].classes[seqClass.name] = seqClass;
}

void DiagramInterface::updateMessage(SequenceDiagram dia, Message message)
{
    sequenceDiagrams[dia.index].messages[message.index] = message;
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
