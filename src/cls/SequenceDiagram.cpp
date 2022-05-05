/**
 * @file SequenceDiagram.cpp
 * @author Jan Zimola (xzimol04)
 * @brief
 * @date 2022-05-05
 * @sources: https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
 * @copyright Copyright (c) 2022
 *
 */
#include "SequenceDiagram.hpp"

bool SequenceDiagram::isCorrect(const SequenceDiagram &seqDia)
{
    foreach (const UMLSeqClass &cl, seqDia.classes)
    {
        if (!UMLSeqClass::isCorrect(cl))
            return false;
    }
    return true;
}

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

        messageIndex = messageArray.size();

        for (int i = 0; i < messageArray.size(); i++)
        {
            QJsonObject messObj = messageArray[i].toObject();
            Message mess;
            mess.read(messObj);
            mess.index = i;
            messages[i] = mess;
        }
    }
}

SequenceDiagram::SequenceDiagram()
    : classes(), messages(), messageIndex(0)
{
}

SequenceDiagram::~SequenceDiagram()
{
}