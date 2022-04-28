#include "SequenceDiagram.hpp"

// bool SequenceDiagram::addObject(UMLSeqClass umlSeqClass)
// {
//     if (std::find(listOfObjectParticipants.begin(), listOfObjectParticipants.end(), umlSeqClass) != listOfObjectParticipants.end())
//     {
//         return false;
//     }

//     listOfObjectParticipants.push_back(umlSeqClass);
// }

Message SequenceDiagram::createMessage(double Ycoord, UMLClass umlClass, UMLOperation umlOperation, Message::MessageType messageType)
{

    return Message(Ycoord, umlClass, umlOperation, messageType);
}

void SequenceDiagram::deleteMessage(Message &message)
{
    auto pos = std::find(messageList.begin(), messageList.end(), message);
    if (pos != messageList.end())
    {
        // listOfObjectParticipants.erase(pos);
    }
}

void SequenceDiagram::write(QJsonObject &json) const
{
    // TODO: Sequence write
    json[lastTimeName] = lastTimeStamp;
}

void SequenceDiagram::read(const QJsonObject &json)
{
    // TODO: Sequence read
}

SequenceDiagram::SequenceDiagram(QString name)
    : Element(name),
      lastTimeStamp(0)
{
}

SequenceDiagram::~SequenceDiagram()
{
}