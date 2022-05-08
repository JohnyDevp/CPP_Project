/**
 * @file editobjectdialog.cpp
 * @author xholan11
 * @brief Dialog used for editing object
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "editobjectdialog.h"
#include "qmessagebox.h"
#include "ui_editobjectdialog.h"
#include "errors.h"
#include "undo.h"

EditObjectDialog::EditObjectDialog(QWidget *parent) : QDialog(parent),
                                                      ui(new Ui::EditObjectDialog)
{
    ui->setupUi(this);
}

EditObjectDialog::~EditObjectDialog()
{
    delete ui;
}

void EditObjectDialog::init(DiagramInterface *diagramInterface, UMLClass *umlClass, ObjectGUI *gui)
{
    this->diagramInterface = diagramInterface;
    this->umlObject = umlClass;
    this->guiObject = gui;

    // make list of modifiers -> they will be load into comboboxes for modifiers
    QStringList modifiers;
    modifiers << "+"
              << "-"
              << "~"
              << "#";

    // turn off adding attributes if uml interface
    if (this->umlObject->isInterface)
    {
        ui->cmbAttributes->setEnabled(false);
        ui->btnAddAttribute->setEnabled(false);
    }
    else
    {
        // otherwise map list of attributes
        foreach (UMLAttribute umlAttribute, this->umlObject->umlAttributesList)
        {
            QString attrText = umlAttribute.modifier + umlAttribute.name + " : " + umlAttribute.type;
            // add to the map
            this->attributesMapGUI.insert(umlAttribute, attrText);
        }
        loadCmbAttributes();

        // load attributes modifiers
        ui->cmbAttributeModifier->addItems(modifiers);
    }

    // set all operations (both class and interface)
    foreach (UMLOperation umlOperation, this->umlObject->umlOperationsList)
    {
        // build the operation text
        QString operationText = umlOperation.modifier + umlOperation.name + "(";
        bool first = true; //solve adding comma befor each operation param except the first one
        foreach (UMLAttribute operationParam, umlOperation.parameterssOfOperationList)
        {
            if (first) operationText += ", ";
            else first = false;
            operationText += operationParam.name + ":" + operationParam.type;
        }
        operationText += ") : " + umlOperation.type;

        // add to the map
        this->operationMapGUI.insert(umlOperation, operationText);
    }

    loadCmbOperations();

    // load operations modifiers
    ui->cmbOperationModifier->addItems(modifiers);
}

void EditObjectDialog::loadCmbAttributes()
{
    ui->cmbAttributes->clear();

    // add attributes
    QMapIterator<UMLAttribute, QString> attrMap(this->attributesMapGUI);
    while (attrMap.hasNext())
    {
        // get next attribute
        attrMap.next();
        ui->cmbAttributes->addItem(attrMap.value());
    }
}

void EditObjectDialog::loadCmbOperations()
{
    ui->cmbOperations->clear();
    // add attributes
    QMapIterator<UMLOperation, QString> operationMap(this->operationMapGUI);
    while (operationMap.hasNext())
    {
        // get next attribute
        operationMap.next();
        ui->cmbOperations->addItem(operationMap.value());
    }
}

UMLClass *EditObjectDialog::getUpdatedUmlObject()
{
    return this->umlObject;
}

void EditObjectDialog::on_btnRenameObject_clicked()
{
    QString newName = ui->txtObjectName->toPlainText().trimmed();

    if (!Element::validName(newName))
    {
        Errors().raiseError("Invalid name.");
        return;
    }

    //check for inconsistencies in sequence diagrams
    // and if found, raise msgdialog
    bool inconsistencyFound = false;
    foreach(SequenceDiagramInterface * seqDiagInterface, diagramInterface->sequenceDiagramInterfaceList){
        foreach( UMLSeqClass seqCls, seqDiagInterface->sequenceDiagram.classes()){
            if (seqCls.className == this->guiObject->umlObject.name){
                inconsistencyFound = true;
            }
        }
    }
    if (inconsistencyFound){
        QMessageBox msgBox;
        msgBox.setText("Inconsistencies in sequence diagram found, proceed?");
        QPushButton *proceedButton = msgBox.addButton("Proceed",QMessageBox::ActionRole);
        QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
        msgBox.exec();

        if (msgBox.clickedButton() == (QAbstractButton *)cancelButton)
        {
            return;
        }
    }

    // ask diagram interface whether exists object with new name
    UMLClass tmp(newName);
    if (diagramInterface->existsClass(tmp))
    {
        Errors().raiseError("Class with that name already exists");
        return;
    }
    else
    {
        // create Undo
        Undo newUndo = Undo(Undo::RENAMEOBJECT, diagramInterface, guiObject, this->umlObject->name);
        // Store undo
        diagramInterface->listOfUndos.append(newUndo);

        // if the class with that name doesnt exist yet then rename
        this->umlObject->name = newName;
    }
}

void EditObjectDialog::on_btnRemoveObject_clicked()
{
    //check for inconsistencies in sequence diagrams
    // and if found, raise msgdialog
    bool inconsistencyFound = false;
    foreach(SequenceDiagramInterface * seqDiagInterface, diagramInterface->sequenceDiagramInterfaceList){
        foreach( UMLSeqClass seqCls, seqDiagInterface->sequenceDiagram.classes()){
            if (seqCls.className == this->guiObject->umlObject.name){
                inconsistencyFound = true;
            }
        }
    }
    if (inconsistencyFound){
        QMessageBox msgBox;
        msgBox.setText("Inconsistencies in sequence diagram found, proceed?");
        QPushButton *proceedButton = msgBox.addButton("Proceed",QMessageBox::ActionRole);
        QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
        msgBox.exec();

        if (msgBox.clickedButton() == (QAbstractButton *)cancelButton)
        {
            return;
        }
    }

    this->umlObject = NULL;

    // close this dialog
    this->close();
}

void EditObjectDialog::on_btnDeleteAttribute_clicked()
{
    QString selectedAttr = ui->cmbAttributes->currentText();
    if (selectedAttr == "")
        return;

    UMLAttribute uaToBeRemoved;
    // iterate through attributes and find the text
    QMapIterator<UMLAttribute, QString> attrMap(this->attributesMapGUI);
    while (attrMap.hasNext())
    {
        // get next attribute
        attrMap.next();

        // attr text comparison
        if (attrMap.value() == selectedAttr)
        {
            uaToBeRemoved = attrMap.key();
        }
    }

    // create undo
    Undo newUndo = Undo(Undo::REMOVEATTRIBUTE, diagramInterface, guiObject, uaToBeRemoved);
    // Store undo
    diagramInterface->listOfUndos.append(newUndo);

    // remove found attribute from umlclass and list
    this->umlObject->deleteAttribute(uaToBeRemoved.name);
    this->attributesMapGUI.remove(uaToBeRemoved);
    // reload cmb
    loadCmbAttributes();
}

void EditObjectDialog::on_btnDeleteOperation_clicked()
{
    QString selectedOperation = ui->cmbOperations->currentText();
    if (selectedOperation == "")
        return;

    UMLOperation uoToBeRemoved;
    // iterate through attributes and find the text
    QMapIterator<UMLOperation, QString> operationMap(this->operationMapGUI);
    while (operationMap.hasNext())
    {
        // get next attribute
        operationMap.next();

        // attr text comparison
        if (operationMap.value() == selectedOperation)
        {
            uoToBeRemoved = operationMap.key();
        }
    }

    //check for inconsistencies in sequence diagrams
    // and if found, raise msgdialog
    bool inconsistencyFound = false;
    foreach(SequenceDiagramInterface * seqDiagInterface, diagramInterface->sequenceDiagramInterfaceList){
        foreach( Message msg, seqDiagInterface->sequenceDiagram.messages()){
            if (msg.operation == uoToBeRemoved){
                inconsistencyFound = true;
            }
        }
    }
    if (inconsistencyFound){
        QMessageBox msgBox;
        msgBox.setText("Inconsistencies in sequence diagram found, proceed?");
        QPushButton *proceedButton = msgBox.addButton("Proceed",QMessageBox::ActionRole);
        QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);
        msgBox.exec();

        if (msgBox.clickedButton() == (QAbstractButton *)cancelButton)
        {
            return;
        }
    }

    // create undo
    Undo newUndo = Undo(Undo::REMOVEOPERATION, diagramInterface, guiObject, uoToBeRemoved);
    // Store undo
    diagramInterface->listOfUndos.append(newUndo);

    // remove found attribute from umlclass and list
    this->umlObject->deleteOperation(uoToBeRemoved);
    this->operationMapGUI.remove(uoToBeRemoved);
    // reload cmb
    loadCmbOperations();
}

void EditObjectDialog::on_btnAddAttribute_clicked()
{
    QString attrName = ui->txtAttrName->toPlainText();
    QString attrType = ui->txtAttrType->toPlainText();
    QChar attrModifier = ui->cmbAttributeModifier->currentText()[0];

    // create uml attribute
    UMLAttribute newUmlAttr(attrModifier, attrName, attrType);

    if (!UMLAttribute::isCorrect(newUmlAttr))
    {
        Errors().raiseError("Invalid attribute.");
        return;
    }
    // try to add it
    if (this->umlObject->addAttribute(newUmlAttr))
    {

        // create undo
        Undo newUndo = Undo(Undo::ADDATTRIBUTE, diagramInterface, guiObject, newUmlAttr);
        // Store undo
        diagramInterface->listOfUndos.append(newUndo);

        // add it to the map and refresh
        QString attrText = newUmlAttr.modifier + newUmlAttr.name + " : " + newUmlAttr.type;
        this->attributesMapGUI.insert(newUmlAttr, attrText);
        loadCmbAttributes();
    }
    else
    {
        Errors().raiseError("Failed adding attribute.");
    }
}

void EditObjectDialog::on_btnAddOperation_clicked()
{
    QString operationName = ui->txtOperationName->toPlainText();
    QString operationType = ui->txtOperationType->toPlainText();
    QString operationModifier = ui->cmbOperationModifier->currentText();

    // create new uml operation
    UMLOperation newUmlOperation(operationName, operationType, operationModifier[0]);
    // add all its attributes (previously added to the map)
    QMapIterator<UMLAttribute, QString> attrMap(this->operationAttributesMapGUI);
    while (attrMap.hasNext())
    {
        // get next attribute
        attrMap.next();
        // add the attribute to the operation and just for assuring check
        if (!newUmlOperation.addOperationParameter(attrMap.key()))
        {
            Errors().raiseError("Failed adding operation (due to bad attributes)");
            return;
        }
    }

    if (!UMLOperation::isCorrect(newUmlOperation))
    {
        Errors().raiseError("Invalid Operation.");
        return;
    }
    // try to add this operation to the class object
    // and check
    if (!this->umlObject->addOperation(newUmlOperation))
    {
        Errors().raiseError("Failed adding operation (due to bad its modifier/name/type).");
        return;
    }

    // create undo
    Undo newUndo = Undo(Undo::ADDOPERATION, diagramInterface, guiObject, newUmlOperation);
    // Store undo
    diagramInterface->listOfUndos.append(newUndo);

    // add the operation to the map and refresh
    //  build the operation text
    QString operationText = newUmlOperation.modifier + newUmlOperation.name + "(";
    foreach (UMLAttribute operationParam, newUmlOperation.parameterssOfOperationList)
    {
        operationText += operationParam.name + ":" + operationParam.type;
    }
    operationText += ") : " + newUmlOperation.type;

    // add to the map
    this->operationMapGUI.insert(newUmlOperation, operationText);

    // remove all attributes
    this->operationAttributesMapGUI.clear();

    // refresh combobox
    loadCmbOperations();
}

void EditObjectDialog::on_btnAddAttributeToOperation_clicked()
{
    QString attrName = ui->txtAttrForOperationName->toPlainText();
    QString attrType = ui->txtAttrForOperationType->toPlainText();
    QChar implicitAttr = '+'; //this serves for possible for check - because operation param doesnt have any modifier

    // if some of txt fields is empty then return
    if (attrName == "" || attrType == "")
        return;

    // create uml attribute
    UMLAttribute newUmlAttr(implicitAttr,attrName, attrType);
    // try to add it to the list of current operation

    if (!UMLAttribute::isCorrect(newUmlAttr))
    {
        Errors().raiseError("Invalid attribute.");
        return;
    }

    // check all already added attributes
    QMapIterator<UMLAttribute, QString> attrMap(this->operationAttributesMapGUI);
    while (attrMap.hasNext())
    {
        // get next attribute
        attrMap.next();
        // if same name as by the created one, then return
        if (attrMap.value() == attrName)
        {
            Errors().raiseError("failed adding attribute to operation");
            return;
        }
    }

    //  if ok then add it to the operation attribute map
    //  the text serves for possible writeout to the listview of attributes of operation
    QString attrText = newUmlAttr.name + " : " + newUmlAttr.type;
    this->operationAttributesMapGUI.insert(newUmlAttr, attrText);
}

void EditObjectDialog::on_btnClearAllOperationAttributes_clicked()
{
    this->operationAttributesMapGUI.clear();
}
