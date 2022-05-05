#include "sequencediagraminterface.h"

SequenceDiagramInterface::SequenceDiagramInterface(DiagramInterface * diagramInterface) : sequenceDiagram()
{
    this->diagramInterface = diagramInterface;
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
