/**
 * @file Message.hpp
 * @author Jan Zimola (xzimol04)
 * @brief Class that represents message in sequence diagram
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "UMLClass.hpp"

#define ycoordName "ycoordName"
#define umlClassName "className"
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
    int index;
    int Ycoord;
    QString className;
    QString operationName;
    MessageType messageType;

    // TODO: Support return type

    QString returnText;
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
    Message(int Ycoord, QString className, QString operationName, MessageType messageType);
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
