/**
 * @file Undo.cpp
 * @author Jan Zimola (xzimol04)
 * @brief Handles UNDO operations
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "undo.h"

bool Undo::doUndo()
{
    // check whether the object gui still exists in diagram
    if (!diagraminterface->existsClass(guiObject->objectName))
    {
        return false;
    }

    switch (operationType)
    {
    case RENAMEOBJECT:
        return doUndoRenameObject();
    case ADDATTRIBUTE:
        return doUndoRemoveAddedAttribute();
    case REMOVEATTRIBUTE:
        return doUndoAddRemovedAttribute();
    case ADDOPERATION:
        return doUndoRemoveAddedOperation();
    case REMOVEOPERATION:
        return doUndoAddRemovedOperation();
    }

    return false; // when operation is unknown
}

Undo::~Undo()
{
}

/**
 * method for renaming object
 * @return if operation could have been done
 */
bool Undo::doUndoRenameObject()
{
    if (!diagraminterface->existsClass(prevObjectName))
    {
        // if not update the class
        QString newName = guiObject->umlObject.name;
        guiObject->umlObject.name = prevObjectName;
        diagraminterface->updateUMLClass(newName, guiObject->umlObject);
        // init gui
        guiObject->initGui();
        guiObject->update();
        return true;
    }

    return false;
}

bool Undo::doUndoAddRemovedAttribute()
{
    // Add the attribute and update the ui if not exists
    if (guiObject->umlObject.addAttribute(this->umlAttribute))
    {
        update();
        return true;
    }

    return false;
}

bool Undo::doUndoRemoveAddedAttribute()
{

    // Try to delete
    if (guiObject->umlObject.umlAttributesList.removeOne(umlAttribute))
    {
        update();
        return true;
    }

    return false;
}

bool Undo::doUndoAddRemovedOperation()
{

    // Add the attribute and update the ui if not exists
    if (guiObject->umlObject.addOperation(umlOperation))
    {
        update();
        return true;
    }

    return false;
}

bool Undo::doUndoRemoveAddedOperation()
{
    // Try to delete
    if (guiObject->umlObject.umlOperationsList.removeOne(umlOperation))
    {
        update();
        return true;
    }

    return false;
}

/**
 * @brief Updates the data in the interface
 *
 */
void Undo::update()
{
    diagraminterface->updateUMLClass(guiObject->umlObject.name, guiObject->umlObject);
    // init gui
    guiObject->initGui();
    guiObject->update();
}

Undo::Undo(UndoOperation operationType, DiagramInterface *interface, ObjectGUI *guiObject, QString prevObjectName)
    : operationType(operationType),
      guiObject(guiObject),
      diagraminterface(interface),
      prevObjectName(prevObjectName)
{
}

Undo::Undo(UndoOperation operationType, DiagramInterface *interface, ObjectGUI *guiObject, UMLAttribute attr)
    : operationType(operationType),
      guiObject(guiObject),
      diagraminterface(interface),
      umlAttribute(attr)
{
}

Undo::Undo(UndoOperation operationType, DiagramInterface *interface, ObjectGUI *guiObject, UMLOperation oper)
    : operationType(operationType),
      guiObject(guiObject),
      diagraminterface(interface),
      umlOperation(oper)
{
}

Undo::Undo(UndoOperation operationType, DiagramInterface *interface, ObjectGUI *guiObject, UMLClass classObject)
    : operationType(operationType),
      guiObject(guiObject),
      diagraminterface(interface),
      umlClass(classObject)
{
}
