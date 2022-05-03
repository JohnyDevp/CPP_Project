#include "SequenceDiagram.hpp"

// bool SequenceDiagram::addObject(UMLSeqClass umlSeqClass)
// {
//     if (std::find(listOfObjectParticipants.begin(), listOfObjectParticipants.end(), umlSeqClass) != listOfObjectParticipants.end())
//     {
//         return false;
//     }

//     listOfObjectParticipants.push_back(umlSeqClass);
// }

void SequenceDiagram::updateClass(UMLSeqClass seqClass)
{
    classes[seqClass.name] = seqClass;
}

Message SequenceDiagram::createMessage(Message &message)
{
    message.index = messageIndex;
    messages[message.index] = message;
    messageIndex++;
    return message;
}

void SequenceDiagram::deleteMessage(Message &message)
{
    messages.remove(message.index);
}

void SequenceDiagram::write(QJsonObject &json) const
{
    // TODO: Sequence write
    json[lastTimeName] = lastTimeStamp;

    json[messageIndexName] = messageIndex;

    json[indexName] = index;

    // Classes
    QJsonArray classesJson;
    foreach (const UMLSeqClass &cl, classes)
    {
        QJsonObject clObj;
        cl.write(clObj);
        classesJson.append(clObj);
    }
}

void SequenceDiagram::read(const QJsonObject &json)
{
    // TODO: Sequence read
}

SequenceDiagram::SequenceDiagram(QString name)
    : Element(name),
      lastTimeStamp(0), classes(), messages()
{
}

SequenceDiagram::~SequenceDiagram()
{
}