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

    // Messages
    QJsonArray messagesJson;
    foreach (const Message &mes, messages)
    {
        QJsonObject mesObj;
        mes.write(mesObj);
        messagesJson.append(mesObj);
    }
}

void SequenceDiagram::read(const QJsonObject &json)
{
    // TODO: Sequence read
    if (json.contains(indexName) && json[indexName].isDouble())
    {
        index = json[indexName].toInt();
    }
    if (json.contains(messageIndexName) && json[messageIndexName].isDouble())
    {
        messageIndex = json[messageIndexName].toInt();
    }
    if (json.contains(lastTimeName) && json[lastTimeName].isDouble())
    {
        lastTimeStamp = json[lastTimeName].toInt();
    }

    // Read Classes
    if (json.contains(classesName) && json[classesName].isArray())
    {
        QJsonArray classArray = json[classesName].toArray();
        classes.clear();
        for (int classIndex = 0; classIndex < classArray.size(); classIndex++)
        {
            QJsonObject classObject = classArray[classIndex].toObject();
            UMLSeqClass cla;
            cla.read(classObject);
            classes[cla.name] = cla;
        }
    }

    // Read Messages
    if (json.contains(messagesName) && json[messagesName].isArray())
    {
        QJsonArray messageArray = json[messagesName].toArray();
        messages.clear();
        for (int messageIndex = 0; messageIndex < messageArray.size(); messageIndex++)
        {
            QJsonObject messObj = messageArray[messageIndex].toObject();
            Message mess;
            mess.read(messObj);
            messages[mess.index] = mess;
        }
    }
}

SequenceDiagram::SequenceDiagram()
    : lastTimeStamp(0), classes(), messages()
{
}

SequenceDiagram::~SequenceDiagram()
{
}