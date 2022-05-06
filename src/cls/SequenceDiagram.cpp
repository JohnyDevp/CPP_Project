/**
 * @file SequenceDiagram.cpp
 * @author xzimol04
 * @brief Source file for SequenceDiagram.hpp
 * @date 2022-04-28
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

UMLSeqClass SequenceDiagram::addSeqClass(UMLSeqClass &umlSewClass)
{
    classes[umlSewClass.getUniqueName()] = umlSewClass;
    return umlSewClass;
}

void SequenceDiagram::updateSeqClass(UMLSeqClass &seqClass)
{
    classes[seqClass.getUniqueName()] = seqClass;
}

Message SequenceDiagram::createMessage(Message &message)
{
    message.index = messageIndex;
    messages[message.index] = message;
    messageIndex++;
    return message;
}

bool SequenceDiagram::existsSeqClass(UMLSeqClass &cl)
{
    return classes.contains(cl.getUniqueName());
}

void SequenceDiagram::updateMessage(Message &mes)
{
    messages[mes.index] = mes;
}

void SequenceDiagram::deleteUMLSeqClass(UMLSeqClass &cl)
{
    classes.remove(cl.getUniqueName());
}

void SequenceDiagram::deleteMessage(Message &message)
{
    messages.remove(message.index);
}

void SequenceDiagram::write(QJsonObject &json) const
{
    // Writting like in the provided source
    //  Classes
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
    // Reading like in the provided source
    //  Read Classes
    if (json.contains(classesName) && json[classesName].isArray())
    {
        QJsonArray classArray = json[classesName].toArray();

        classes.clear();

        for (int i = 0; i < classArray.size(); i++)
        {
            QJsonObject classObject = classArray[i].toObject();
            UMLSeqClass cla;
            cla.read(classObject);
            classes[cla.getUniqueName()] = cla;
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