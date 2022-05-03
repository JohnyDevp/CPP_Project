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
    this->umlClass = umlClass;

    //turn off adding attributes if uml interface
    if (this->umlClass->isInterface){

    }
}

UMLClass * EditObjectDialog::getUpdatedUmlObject(){
    return this->umlClass;
}

void EditObjectDialog::on_btnRenameObject_clicked()
{
    QRegExp rx("^\\S+$"); //without whitespace
    rx.setPatternSyntax(QRegExp::Wildcard);

    //QString newName = ui->txtObjectName->toPlainText();
   //if (!rx.exactMatch(newName)) return; //there cant be whitespace

    //ask diagram interface whether exists object with new name

    //if no, then set name of this object to the new name
    //this->umlClass->setName(newName);

}


void EditObjectDialog::on_btnRemoveObject_clicked()
{
    //delete the class in diagraminterface and remove also object from


    //close this dialog
    this->close();
}

