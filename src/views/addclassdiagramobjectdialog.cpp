/**
 * @file addclassdiagramobjectdialog.cpp
 * @author xholan11
 * @brief Dialog for adding a new class
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "addclassdiagramobjectdialog.h"
#include "ui_addclassdiagramobjectdialog.h"

AddClassDiagramObjectDialog::AddClassDiagramObjectDialog(QWidget *parent) : QDialog(parent),
                                                                            ui(new Ui::AddClassDiagramObjectDialog)
{
    ui->setupUi(this);
}

AddClassDiagramObjectDialog::~AddClassDiagramObjectDialog()
{
    delete ui;
}

QString AddClassDiagramObjectDialog::getObjectName()
{
    return ui->txtObjectName->toPlainText();
}

bool AddClassDiagramObjectDialog::getIsInterface()
{
    return ui->checkBoxIsInterface->isChecked();
}

void AddClassDiagramObjectDialog::on_buttonBox_accepted()
{
    this->isValid = true;
}
