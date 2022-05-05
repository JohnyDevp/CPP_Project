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

Message::Message(int Ycoord, QString umlClass, QString umlOperation, MessageType messageType) : Ycoord(Ycoord), className(umlClass), operationName(umlOperation), messageType(messageType){};

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

    json[umlClassName] = className;

    json[returnTextName] = returnText;

    json[argumentTextName] = argumentText;

    json[umlOperationName] = operationName;
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

    if (json.contains(umlClassName) && json[umlClassName].isObject())
    {
        className = json[umlClassName].toString();
    }

    if (json.contains(umlOperationName) && json[umlOperationName].isObject())
    {
        operationName = json[umlOperationName].toString();
    }
}
