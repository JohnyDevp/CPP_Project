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
    foreach (const UMLSeqClass &cl, seqDia._classes)
    {
        if (!UMLSeqClass::isCorrect(cl))
            return false;
    }
    return true;
}

UMLSeqClass SequenceDiagram::addSeqClass(UMLSeqClass &umlSewClass)
{
    _classes[umlSewClass.getUniqueName()] = umlSewClass;
    return umlSewClass;
}

void SequenceDiagram::updateSeqClass(UMLSeqClass &seqClass)
{
    _classes[seqClass.getUniqueName()] = seqClass;
}

Message SequenceDiagram::createMessage(Message &message)
{
    message.index = _messageIndex;
    _messages[message.index] = message;
    _messageIndex++;
    return message;
}

bool SequenceDiagram::existsSeqClass(UMLSeqClass &cl)
{
    return _classes.contains(cl.getUniqueName());
}

void SequenceDiagram::updateMessage(Message &mes)
{
    _messages[mes.index] = mes;
}

void SequenceDiagram::deleteUMLSeqClass(UMLSeqClass &cl)
{
    _classes.remove(cl.getUniqueName());
}

void SequenceDiagram::deleteMessage(Message &message)
{
    _messages.remove(message.index);
}

void SequenceDiagram::write(QJsonObject &json) const
{
    // Writting like in the provided source
    //  Classes
    QJsonArray classesJson;
    foreach (const UMLSeqClass &cl, _classes)
    {
        QJsonObject clObj;
        cl.write(clObj);
        classesJson.append(clObj);
    }

    json[classesName] = classesJson;

    // Messages
    QJsonArray messagesJson;
    foreach (const Message &mes, _messages)
    {
        QJsonObject mesObj;
        mes.write(mesObj);
        messagesJson.append(mesObj);
    }

    json[messagesName] = messagesJson;
}

void SequenceDiagram::read(const QJsonObject &json)
{
    // Reading like in the provided source
    //  Read Classes
    if (json.contains(classesName) && json[classesName].isArray())
    {
        QJsonArray classArray = json[classesName].toArray();

        _classes.clear();

        for (int i = 0; i < classArray.size(); i++)
        {
            QJsonObject classObject = classArray[i].toObject();
            UMLSeqClass cla;
            cla.read(classObject);
            _classes[cla.getUniqueName()] = cla;
        }
    }

    // Read Messages
    if (json.contains(messagesName) && json[messagesName].isArray())
    {
        QJsonArray messageArray = json[messagesName].toArray();
        _messages.clear();

        _messageIndex = messageArray.size();

        for (int i = 0; i < messageArray.size(); i++)
        {
            QJsonObject messObj = messageArray[i].toObject();
            Message mess;
            mess.read(messObj);
            mess.index = i;
            _messages[i] = mess;
        }
    }
}

SequenceDiagram::SequenceDiagram()
    : _classes(), _messages(), _messageIndex(0)
{
}

SequenceDiagram::~SequenceDiagram()
{
}
