#include "editobjectdialog.h"
#include "ui_editobjectdialog.h"
#include "errors.h"

EditObjectDialog::EditObjectDialog(QWidget *parent) : QDialog(parent),
                                                      ui(new Ui::EditObjectDialog)
{
    ui->setupUi(this);
}

EditObjectDialog::~EditObjectDialog()
{
    delete ui;
}

void EditObjectDialog::init(DiagramInterface *diagramInterface, UMLClass *umlClass)
{
    this->diagramInterface = diagramInterface;
    this->umlObject = umlClass;

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
        foreach (UMLAttribute operationParam, umlOperation.parameterssOfOperationList)
        {
            operationText += operationParam.name + ":" + operationParam.type;
        }
        operationText += ") : " + umlOperation.type;

        // add to the map
        this->operationMapGUI.insert(umlOperation, operationText);
    }

    loadCmbOperations();

    // load operations modifiers
    ui->cmbOperationModifier->addItems(modifiers);
    // load operations attributes modifiers
    ui->cmbAttrForOperationModifier->addItems(modifiers);
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
    // if (!rx.exactMatch(newName)) return; //there cant be whitespace

    // ask diagram interface whether exists object with new name
    UMLClass tmp(newName);
    if (diagramInterface->existsClass(tmp))
    {
        Errors().raiseError("Class with that name already exists");
        return;
    }
    else
    {
        // if the class with that name doesnt exist yet then rename
        this->umlObject->name = newName;
    }
}

void EditObjectDialog::on_btnRemoveObject_clicked()
{
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
    QChar operationModifier = ui->cmbAttrForOperationModifier->currentText()[0];

    // create new uml operation
    UMLOperation newUmlOperation(operationName, operationType, operationModifier);
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
    QChar attrModifier = ui->cmbAttrForOperationModifier->currentText()[0];

    // if some of txt fields is empty then return
    if (attrName == "" || attrType == "")
        return;

    // create uml attribute
    UMLAttribute newUmlAttr(attrModifier, attrName, attrType);
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
    // if ok then add it to the operation attribute map
    // the text serves for possible writeout to the listview of attributes of operation
    QString attrText = newUmlAttr.modifier + newUmlAttr.name + " : " + newUmlAttr.type;
    this->operationAttributesMapGUI.insert(newUmlAttr, attrText);
}

void EditObjectDialog::on_btnClearAllOperationAttributes_clicked()
{
    this->operationAttributesMapGUI.clear();
}
