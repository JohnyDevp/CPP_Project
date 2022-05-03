#include "Message.hpp"

Message::Message() {}

Message::Message(double Ycoord, UMLClass umlClass, UMLOperation umlOperation, MessageType messageType) : Ycoord(Ycoord), umlClass(umlClass), umlOperation(umlOperation), messageType(messageType){};

Message::~Message() {}
void Message::write(QJsonObject &json) const
{
    json[ycoordName] = Ycoord;

    json[messageIndexName] = index;

    json[messageTypeName] = messageType;

    QJsonObject classObject;
    umlClass.write(classObject);
    json[umlClassName] = classObject;

    QJsonObject operationObject;
    umlOperation.write(operationObject);
    json[umlOperationName] = operationObject;
}
void Message::read(const QJsonObject &json)
{
    if (json.contains(ycoordName) && json[ycoordName].isDouble())
    {
        Ycoord = json[ycoordName].toDouble();
    }

    if (json.contains(messageIndexName) && json[messageIndexName].isDouble())
    {
        index = json[messageIndexName].toInt();
    }
    // TODO: Not sure about isDouble() but isInt() is not
    if (json.contains(messageTypeName) && json[messageTypeName].isDouble())
    {
        messageType = static_cast<MessageType>(json[messageTypeName].toInt());
    }

    if (json.contains(umlClassName) && json[umlClassName].isObject())
    {
        QJsonObject classObject = json[umlClassName].toObject();
        umlClass.read(classObject);
    }

    if (json.contains(umlOperationName) && json[umlOperationName].isObject())
    {
        QJsonObject operationObject = json[umlOperationName].toObject();
        umlOperation.read(operationObject);
    }
}
bool Message::operator==(const Message &other) const
{
    return umlClass == other.umlClass && umlOperation == other.umlOperation && messageType == other.messageType;
}

bool Message::operator!=(const Message &other) const
{
    return !(*this == other);
}
