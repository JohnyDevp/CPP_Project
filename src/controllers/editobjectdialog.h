/**
 * @file editobjectdialog.h
 * @author xholan11
 * @brief Header file for editobjectdialog.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef EDITOBJECTDIALOG_H
#define EDITOBJECTDIALOG_H

#include "diagraminterface.h"
#include <QDialog>

namespace Ui
{
    class EditObjectDialog;
}

/**
 * @brief The EditObjectDialog class
 * handle editting the object in class diagram - both interface and class
 */
class EditObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditObjectDialog(QWidget *parent = nullptr);
    ~EditObjectDialog();

    /**
     * @brief init initializes all comboboxes
     * @param diagramInterface
     * @param umlObject
     * @param gui
     */
    void init(DiagramInterface *diagramInterface, UMLClass *umlObject, ObjectGUI *gui);
    /**
     * @brief getUpdatedUmlObject
     * @return poiter to updated class by this dialog, when returned nullptr then it signs that this object has been removed
     */
    UMLClass *getUpdatedUmlObject();

    /**
     * @brief loadCmbAttributes loads combobox with attributes (already added)
     * called whenever new attribute is added
     */
    void loadCmbAttributes();

    /**
     * @brief loadCmbOperations loads combobox with operations (already added)
     * called whenever new operation is added
     */
    void loadCmbOperations();

private slots:
    void on_btnRenameObject_clicked();

    void on_btnRemoveObject_clicked();

    void on_btnDeleteAttribute_clicked();

    void on_btnDeleteOperation_clicked();

    void on_btnAddAttribute_clicked();

    void on_btnAddOperation_clicked();

    void on_btnAddAttributeToOperation_clicked();

    void on_btnClearAllOperationAttributes_clicked();

private:
    Ui::EditObjectDialog *ui;

    /**
     * @brief diagramInterface
     */
    DiagramInterface *diagramInterface;

    /**
     * @brief umlClass uml (intern) representation of currently edited object
     */
    UMLClass *umlObject;

    /**
     * @brief guiObject - graphical representation of currently edited object
     */
    ObjectGUI *guiObject;

    /**
     * @brief operationMapGUI
     * map for storing each operation and its string representation drawn in gui object
     */
    QMap<UMLOperation, QString> operationMapGUI;

    /**
     * @brief operationMapGUI
     * map for storing each newly created param (as attribute) of currently creating operation
     * and its string representation
     */
    QMap<UMLAttribute, QString> operationAttributesMapGUI;
    /**
     * @brief attributesMapGUI
     * map for storing each attribute and its string representation drawn in gui object
     */
    QMap<UMLAttribute, QString> attributesMapGUI;
};

#endif // EDITOBJECTDIALOG_H
