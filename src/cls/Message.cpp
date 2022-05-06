/**
 * @file Message.cpp
 * @author xzimol04
 * @brief Source file for Message.hpp
 * @date 2022-04-28
 * @sources: https://doc.qt.io/qt-5/qtcore-serialization-savegame-example.html
 * @copyright Copyright (c) 2022
 *
 */
#include "Message.hpp"

Message::Message() {}

Message::Message(int Ycoord, QString classSender, QString classReceiver, QString umlOperation, MessageType messageType) : Ycoord(Ycoord), classSender(classSender), operation(umlOperation), messageType(messageType){};

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
    // Writting like in the provided source
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
    // Reading like in the provided source
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
        // create Enum from int
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
