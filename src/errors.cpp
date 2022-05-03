#include "errors.h"
#include <QMessageBox>

Errors::Errors()
{

}

void Errors::raiseWarning(QString alertText){
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText(alertText);
    msgBox.exec();
}

void Errors::raiseError(QString alertText){
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText(alertText);
    msgBox.exec();
}

void Errors::raiseInformation(QString alertText){
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(alertText);
    msgBox.exec();
}
