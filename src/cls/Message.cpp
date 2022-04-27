#include "Message.hpp"

Message::Message(double Ycoord, UMLClass umlClass, UMLOperation umlOperation, MessageType messageType) : Ycoord(Ycoord), umlClass(umlClass), umlOperation(umlOperation), messageType(messageType){};

Message::~Message() {}
void Message::write(QJsonObject &json) const
{
    // TODO: Message write
}
void Message::read(const QJsonObject &json)
{
    // TODO: Message read
}
bool Message::operator==(const Message &other) const
{
    return umlClass == other.umlClass && umlOperation == other.umlOperation && messageType == other.messageType;
}

bool Message::operator!=(const Message &other) const
{
    return !(*this == other);
}
