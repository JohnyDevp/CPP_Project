#include "addsequenceclassdialog.h"
#include "ui_addsequenceclassdialog.h"
#include "errors.h"

AddSequenceClassDialog::AddSequenceClassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSequenceClassDialog)
{
    ui->setupUi(this);
}

void AddSequenceClassDialog::init(SequenceDiagramInterface *seqDiagInterface){
    this->seqDiagInterface = seqDiagInterface;

    // collect name of all classes
    QStringList listOfClasses;
    foreach (UMLClass umlClass, this->seqDiagInterface->diagramInterface->classDiagram.classList)
    {
        if (!umlClass.isInterface){
            listOfClasses << umlClass.name;
        }
    }

    //load the list of classes into the combobox
    ui->cmbClassName->addItems(listOfClasses);

    //when there is nothing to be chosen - disable button box
    if (ui->cmbClassName->count() == 0) {
        ui->buttonBox->setEnabled(false);
    }
}

AddSequenceClassDialog::~AddSequenceClassDialog()
{
    delete ui;
}

void AddSequenceClassDialog::on_buttonBox_accepted()
{
    QString umlClassName = ui->cmbClassName->currentText();
    QString instanceName = ui->txtInstanceName->toPlainText();

    // if the class has been chosen then find class according to the chosen name
    UMLClass umlClass = this->seqDiagInterface->diagramInterface->getUMLClass(umlClassName);

    // and create umlseqclass with instance name
    UMLSeqClass umlSeqClass(instanceName, umlClass.name, 10);

    //check whether it is unique (the seqCLass)
    if(this->seqDiagInterface->sequenceDiagram.existsSeqClass(umlSeqClass)){
        //if it exists then alert and invalid
        Errors().raiseWarning("Name of class instance is already used!");
        this->dataValid = false;
    } else {
        this->umlSeqClass = umlSeqClass;
        this->dataValid = true;
    }
}

UMLSeqClass AddSequenceClassDialog::getUmlSeqClass(){
    return this->umlSeqClass;
}
