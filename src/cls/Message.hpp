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
#define umlClassName "umlClassName"
#define umlOperationName "umlOperationName"
#define messageTypeName "messageTypeName"

class Message : public JsonPrintable
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

    double Ycoord;
    UMLClass umlClass;
    UMLOperation umlOperation;
    MessageType messageType;

    /**
     * @brief Construct a new Message object
     *
     * @param Ycoord
     * @param umlClass
     * @param umlOperation
     * @param messageType
     */
    Message(double Ycoord, UMLClass umlClass, UMLOperation umlOperation, MessageType messageType);
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
    void write(QJsonObject &json) const override;
    /**
     * @brief reads object from json
     *
     * @param json
     */
    void read(const QJsonObject &json);

    bool operator==(const Message &other) const;
    bool operator!=(const Message &other) const;
};
