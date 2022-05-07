/**
 * @file Message.hpp
 * @author xzimol04
 * @brief Class that represents message in sequence diagram
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "UMLClass.hpp"

#define ycoordName "ycoordName"
#define recieverName "classReceiver"
#define senderName "classSender"
#define umlOperationName "operationName"
#define messageTypeName "messageTypeName"
#define messageIndexName "index"
#define argumentTextName "argumentText"
#define returnTextName "returnText"
class Message
{
public:
    /**
     * @brief Type of message
     *
     */
    enum MessageType
    {
        SYNC,
        ASYNC,
        RETURN,
        CREATE,
        DESTROY
    };
    /**
     * @brief Index of the message used to be uniqly identified
     *
     */
    int index;
    /**
     * @brief Y positions of the message
     *
     */
    int Ycoord;

    QString classReceiver;

    QString classSender;
    /**
     * @brief
     *
     */
    UMLOperation operation;

    MessageType messageType;

    /**
     * @brief Text used by RETURN type message
     *
     */
    QString returnText;
    /**
     * @brief User written arguments of functions
     *
     */
    QString argumentText;

    /**
     * @brief Default construct a new Message object
     *
     */
    Message();
    /**
     * @brief Construct a new Message object and custom messages set afterwards
     *
     * @param Ycoord
     * @param umlClass
     * @param umlOperation
     * @param messageType
     */
    Message(int Ycoord, QString classSender, QString classReceiver, QString operationName, MessageType messageType);
    /**
     * @brief Destroy the Message object
     *
     */
    ~Message();

    /**
     * @brief converts object to json
     *
     * @param json
     */
    void write(QJsonObject &json) const;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

    bool operator==(const Message &other) const;
    bool operator!=(const Message &other) const;
};
