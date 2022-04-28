/**
 * @file SequenceDiagram.hpp
 * @author Jan Zimola (xzimol04)
 * @brief Class that represents sequence diagram
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "Element.hpp"
#include "UMLSeqClass.hpp"
#include "Message.hpp"
#include <vector>

#define listPartiName "listPartiName"
#define messageListName "messageListName"
#define lastTimeName "lastTimeName"

class SequenceDiagram : public Element
{
public:
    QList<UMLSeqClass> listOfObjectParticipants;

    QList<Message> messageList;

    int lastTimeStamp;

    /**method for adding new participated class in sequence diagram
     * @param umlSeqClass class representing the object which takes part in the sequence diagram*/
    bool addObject(UMLSeqClass umlSewClass);

    /**adding message to specific position - rest of messages will move forward +1
     * @param messageType type of the message (sync, async, ...)
     * @param Ycoord Y coordination on timeline of object
     * @param umlClass class which is sending the message
     * @param umlOperation operation representing the method which is called*/
    Message createMessage(double Ycoord, UMLClass umlClass, UMLOperation umlOperation, Message::MessageType messageType);

    /**delete message from diagram
     * @param message message object to be deleted*/
    void deleteMessage(Message &message);

    /**
     * @brief converts object to json
     *
     * @param json
     */
    void write(QJsonObject &json) const override;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

    SequenceDiagram(QString name);
    ~SequenceDiagram();
};
