/**
 * @file Message.cpp
 * @author Jan Zimola (xzimol04)
 * @brief
 * @date 2022-05-05
 * @sources: https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
 * @copyright Copyright (c) 2022
 *
 */
#include "Message.hpp"

Message::Message() {}

Message::Message(int Ycoord, QString classSender, QString umlOperation, MessageType messageType) : Ycoord(Ycoord), classSender(classSender), operation(umlOperation), messageType(messageType){};

Message::~Message() {}
bool Message::operator==(const Message &other) const
{
    return index == other.index;
}
bool Message::operator!=(const Message &other) const
{
    return !(*this == other);
}
void Message::write(QJsonObject &json) const
{
    json[ycoordName] = Ycoord;

    json[messageTypeName] = messageType;

    json[recieverName] = classReceiver;

    json[senderName] = classSender;

    json[returnTextName] = returnText;

    json[argumentTextName] = argumentText;

    QJsonObject operObj;
    operation.write(operObj);
    json[umlOperationName] = operObj;
}
void Message::read(const QJsonObject &json)
{
    if (json.contains(returnTextName) && json[returnTextName].isString())
    {
        returnText = json[returnTextName].toString();
    }

    if (json.contains(argumentTextName) && json[argumentTextName].isString())
    {
        argumentText = json[argumentTextName].toString();
    }

    if (json.contains(ycoordName) && json[ycoordName].isDouble())
    {
        Ycoord = json[ycoordName].toInt();
    }

    // TODO: Not sure about isDouble() but isInt() is not
    if (json.contains(messageTypeName) && json[messageTypeName].isDouble())
    {
        messageType = static_cast<MessageType>(json[messageTypeName].toInt());
    }

    if (json.contains(senderName) && json[senderName].isString())
    {
        classSender = json[senderName].toString();
    }

    if (json.contains(recieverName) && json[recieverName].isString())
    {
        classReceiver = json[recieverName].toString();
    }

    if (json.contains(umlOperationName) && json[umlOperationName].isObject())
    {
        QJsonObject operObj = json[umlOperationName].toObject();
        operation.read(operObj);
    }
}
