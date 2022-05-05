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
#include <QMap>
#include <QJsonArray>

#define classesName "classes"
#define messagesName "messages"
#define messageIndexName "messageIndex"

class SequenceDiagram : public Element
{
public:
    /**
     * @brief returns if all is correcly set from the view of the class
     *
     * @param seqDia
     * @return true
     * @return false
     */
    static bool isCorrect(const SequenceDiagram &seqDia);

    int messageIndex;

    QMap<QString, UMLSeqClass> classes;

    QMap<int, Message> messages;

    /**method for adding new participated class in sequence diagram
     * @param umlSeqClass class representing the object which takes part in the sequence diagram*/
    UMLSeqClass addSeqClass(UMLSeqClass &umlSewClass);

    /**
     * @brief Updae Seq Class or create new one
     *
     * @param name
     */
    void updateSeqClass(UMLSeqClass &seqClass);

    /**adding message to specific position - rest of messages will move forward +1
     * @param messageType type of the message (sync, async, ...)
     * @param Ycoord Y coordination on timeline of object
     * @param umlClass class which is sending the message
     * @param umlOperation operation representing the method which is called*/
    Message createMessage(Message &message);

    bool existsSeqClass(UMLSeqClass &cl);

    void updateMessage(Message &mes);

    void deleteUMLSeqClass(UMLSeqClass &cl);
    /**delete message from diagram
     * @param message message object to be deleted*/
    void deleteMessage(Message &message);

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

    SequenceDiagram();
    ~SequenceDiagram();
};
