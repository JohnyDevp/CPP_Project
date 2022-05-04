#include "editrelationdialog.h"
#include "ui_editrelationdialog.h"
#include "errors.h"

EditRelationDialog::EditRelationDialog(QWidget *parent) : QDialog(parent),
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

    if (!txtName.isEmpty())
    {
        this->umlRelation->name = txtName;
    }
}

void EditRelationDialog::on_btnSetCardinalityEnd_clicked()
{
    QString txtCardinality = ui->txtCardinalityEnd->toPlainText().trimmed();

    if (UMLRelation::isCardinalityCorrect(txtCardinality))
    {
        this->umlRelation->cardinalityByToClass = txtCardinality;
    }
    else
    {
        Errors().raiseError("Invalid cardinality.");
    }
}

void EditRelationDialog::on_btnSetCardinalityStart_clicked()
{
    QString txtCardinality = ui->txtCardinalityStart->toPlainText().trimmed();
    if (UMLRelation::isCardinalityCorrect(txtCardinality))
    {
        this->umlRelation->cardinalityByFromClass = txtCardinality;
    }
    else
    {
        Errors().raiseError("Invalid cardinality.");
    }
}

void EditRelationDialog::on_btnRemoveRelation_clicked()
{
    // set the uml relation to null -> indicates that it has been deleted
    this->umlRelation = NULL;

    // close the dialog
    this->close();
}
