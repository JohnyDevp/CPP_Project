#include "addclassdiagramobjectdialog.h"
#include "ui_addclassdiagramobjectdialog.h"

AddClassDiagramObjectDialog::AddClassDiagramObjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClassDiagramObjectDialog)
{
    ui->setupUi(this);
}

AddClassDiagramObjectDialog::~AddClassDiagramObjectDialog()
{
    delete ui;
}

QString AddClassDiagramObjectDialog::getObjectName(){
    return ui->txtObjectName->toPlainText();
}

bool AddClassDiagramObjectDialog::getIsInterface(){
    return ui->checkBoxIsInterface->isChecked();
}

void AddClassDiagramObjectDialog::on_buttonBox_accepted()
{
    this->isValid = true;
}

