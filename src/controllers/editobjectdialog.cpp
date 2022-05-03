#include "editobjectdialog.h"
#include "ui_editobjectdialog.h"

EditObjectDialog::EditObjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditObjectDialog)
{
    ui->setupUi(this);
}

EditObjectDialog::~EditObjectDialog()
{
    delete ui;
}

void EditObjectDialog::init(DiagramInterface * diagramInterface, UMLClass * umlClass){
    this->diagramInterface = diagramInterface;
    this->umlObject = umlClass;

    //turn off adding attributes if uml interface
    if (this->umlObject->isInterface){
        ui->cmbAttributes->setEnabled(false);
        ui->btnAddAttribute->setEnabled(false);
    } else {
        //otherwise load list of
        foreach (UMLAttribute umlAttribute, this->umlObject->umlAttributesList)
        {
            QString attrText = umlAttribute.modifier + umlAttribute.name + " : " + umlAttribute.type;
            // add to the map
            this->attributesMapGUI.insert(umlAttribute, attrText);
        }

        loadCmbAttributes();
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

}

void EditObjectDialog::loadCmbAttributes(){
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

void EditObjectDialog::loadCmbOperations(){
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

UMLClass * EditObjectDialog::getUpdatedUmlObject(){
    return this->umlObject;
}

void EditObjectDialog::on_btnRenameObject_clicked()
{
    QRegExp rx("^\\S+$"); //without whitespace
    rx.setPatternSyntax(QRegExp::Wildcard);

    QString newName = ui->txtObjectName->toPlainText();

    //if (!rx.exactMatch(newName)) return; //there cant be whitespace

    //ask diagram interface whether exists object with new name
    UMLClass tmp(newName);
    if (diagramInterface->existsClass(tmp)){
        std::cout << "class with that name already exists" << std::endl;
        return;
    } else {
        //if the class with that name doesnt exist yet then rename
        this->umlObject->name = newName;
    }

}

void EditObjectDialog::on_btnRemoveObject_clicked()
{
    this->umlObject = NULL;

    //close this dialog
    this->close();
}


void EditObjectDialog::on_btnDeleteAttribute_clicked()
{
    QString selectedAttr = ui->cmbAttributes->currentText();
    if (selectedAttr == "") return;

    UMLAttribute uaToBeRemoved;
    //iterate through attributes and find the text
    QMapIterator<UMLAttribute, QString> attrMap(this->attributesMapGUI);
    while (attrMap.hasNext())
    {
        // get next attribute
        attrMap.next();

        //attr text comparison
        if (attrMap.value() == selectedAttr){
            uaToBeRemoved = attrMap.key();
        }
    }

    //remove found attribute from umlclass and list
    this->umlObject->deleteAttribute(uaToBeRemoved.name);
    this->attributesMapGUI.remove(uaToBeRemoved);
    //reload cmb
    loadCmbAttributes();
}


void EditObjectDialog::on_btnDeleteOperation_clicked()
{
    QString selectedOperation = ui->cmbOperations->currentText();
    if (selectedOperation == "") return;

    UMLOperation uoToBeRemoved;
    //iterate through attributes and find the text
    QMapIterator<UMLOperation, QString> operationMap(this->operationMapGUI);
    while (operationMap.hasNext())
    {
        // get next attribute
        operationMap.next();

        //attr text comparison
        if (operationMap.value() == selectedOperation){
            uoToBeRemoved = operationMap.key();
        }
    }

    //remove found attribute from umlclass and list
    this->umlObject->deleteOperation(uoToBeRemoved);
    this->operationMapGUI.remove(uoToBeRemoved);
    //reload cmb
    loadCmbOperations();
}

