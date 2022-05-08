/**
 * @file SequenceDiagram.hpp
 * @author xzimol04, xholan11
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

class SequenceDiagram : public Element
{

private:
    /**
     * @brief Index for Message when will be added
     *
     */
    int _messageIndex;

    /**
     * @brief Map of classes, key is their name
     *
     */
    QMap<QString, UMLSeqClass> _classes;

    /**
     * @brief Map of messages, key is their index created on their creation
     *
     */
    QMap<int, Message> _messages;

public:
    /**
     * @brief returns if all is correcly set from the view of the class
     *
     * @param seqDia
     * @return true
     * @return false
     */
    static bool isCorrect(const SequenceDiagram &seqDia);

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

    /**
     * @brief returns is UMLSeqClass exists
     *
     * @param cl
     * @return true
     * @return false
     */
    bool existsSeqClass(UMLSeqClass &cl);

    /**
     * @brief Updates message
     *
     * @param mes
     */
    void updateMessage(Message &mes);
    /**
     * @brief Deletes UMLSeqClass
     *
     * @param cl
     */
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
    /**
     * @brief Construct a new Sequence Diagram object
     *
     */
    SequenceDiagram();
    /**
     * @brief Destroy the Sequence Diagram object
     *
     */
    ~SequenceDiagram();

    QMap<QString, UMLSeqClass> classes() const { return _classes; }

    QMap<int, Message> messages() const { return _messages; }
};
