#include "editrelationdialog.h"
#include "ui_editrelationdialog.h"

EditRelationDialog::EditRelationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRelationDialog)
{
    ui->setupUi(this);
}

EditRelationDialog::~EditRelationDialog()
{
    delete ui;
}

void EditRelationDialog::init(UMLRelation *umlRelation)
{
    this->umlRelation = umlRelation;
}

UMLRelation *EditRelationDialog::getUpdatedUmlRelation()
{
    return this->umlRelation;
}

void EditRelationDialog::on_btnSetRelationName_clicked()
{
    QString txtName = ui->txtRelationName->toPlainText().trimmed();

    if (!txtName.isEmpty()){
        this->umlRelation->name = txtName;
    }
}


void EditRelationDialog::on_btnSetCardinalityEnd_clicked()
{
    QString txtCardinality = ui->txtCardinalityStart->toPlainText().trimmed();
    if (!txtCardinality.isEmpty()){
        this->umlRelation->cardinalityByToClass = txtCardinality;
    }
}


void EditRelationDialog::on_btnSetCardinalityStart_clicked()
{
    QString txtCardinality = ui->txtCardinalityStart->toPlainText().trimmed();
    if (!txtCardinality.isEmpty()){
        this->umlRelation->cardinalityByFromClass = txtCardinality;
    }
}


void EditRelationDialog::on_btnRemoveRelation_clicked()
{
    //set the uml relation to null -> indicates that it has been deleted
    this->umlRelation = NULL;

    //close the dialog
    this->close();
}

