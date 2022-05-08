#pragma once

/**
 * @file undo.h
 * @author xzimol04, xholan11, xholan11
 * @brief Header for Undo.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "objectgui.h"

class Undo
{
public:
    enum UndoOperation
    {
        RENAMEOBJECT,
        ADDATTRIBUTE,
        ADDOPERATION,
        REMOVEATTRIBUTE,
        REMOVEOPERATION,
        REMOVEOBJECT,
        ADDOBJECT,
    };

private:
    // type of operation to be undone
    UndoOperation operationType;

    // gui object where the Undo operation will take place
    // gui methods for adding also handling adding to inner representation of object (either umlclass or umlinterface)
    ObjectGUI *guiObject;

    DiagramInterface *diagraminterface;

    // variables storing the old values (which will be reset to current objects if Undo)
    QString prevObjectName;
    UMLOperation umlOperation;
    UMLAttribute umlAttribute;
    UMLClass umlClass;

public:
    Undo(UndoOperation operationType, DiagramInterface *interface, ObjectGUI *guiObject, QString prevObjectName);

    /**
     * constructor - adding or removing attribute
     * */
    Undo(UndoOperation operationType, DiagramInterface *interface, ObjectGUI *guiObject, UMLAttribute umlAttribute);

    /**
     * constructor - adding or removing operation
     * */
    Undo(UndoOperation operationType, DiagramInterface *interface, ObjectGUI *guiObject, UMLOperation umlOperation);

    /**
     * constructor - adding or removing UMLClasss
     * */
    Undo(UndoOperation operationType, DiagramInterface *interface, ObjectGUI *guiObject, UMLClass umlClass);
    /**
     * @brief Process undo
     *
     * @return true
     * @return false
     */
    bool doUndo();

    ~Undo();

private:
    bool doUndoRenameObject();

    /**
     * method for adding attribute, that has been removed
     * @return if operation could have been done
     */

    bool doUndoAddRemovedAttribute();
    /**
     * method for removing attribute, that has been added
     * @return if operation could have been done
     */

    bool doUndoRemoveAddedAttribute();

    /**
     * method for adding operation, that has been removed
     * @return if operation could have been done
     */

    bool doUndoAddRemovedOperation();

    /**
     * method for removing operation, that has been previously addded
     * @return if operation could have been done
     */

    bool doUndoRemoveAddedOperation();

    /**
     * method for adding class, that has been removed
     * @return if class could have been done
     */

    bool doUndoAddRemovedClass();

    /**
     * method for removing class, that has been previously addded
     * @return if class could have been done
     */

    bool doUndoRemoveAddedClass();

    /**
     * @brief Updates UI and Interface
     *
     */
    void update();
};
