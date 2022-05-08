/********************************************************************************
** Form generated from reading UI file 'addsequenceclassdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSEQUENCECLASSDIALOG_H
#define UI_ADDSEQUENCECLASSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddSequenceClassDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *cmbClassName;
    QTextEdit *txtInstanceName;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AddSequenceClassDialog)
    {
        if (AddSequenceClassDialog->objectName().isEmpty())
            AddSequenceClassDialog->setObjectName(QString::fromUtf8("AddSequenceClassDialog"));
        AddSequenceClassDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddSequenceClassDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        cmbClassName = new QComboBox(AddSequenceClassDialog);
        cmbClassName->setObjectName(QString::fromUtf8("cmbClassName"));
        cmbClassName->setGeometry(QRect(30, 50, 331, 25));
        txtInstanceName = new QTextEdit(AddSequenceClassDialog);
        txtInstanceName->setObjectName(QString::fromUtf8("txtInstanceName"));
        txtInstanceName->setGeometry(QRect(30, 140, 331, 31));
        label = new QLabel(AddSequenceClassDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 181, 17));
        label_2 = new QLabel(AddSequenceClassDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 120, 181, 17));

        retranslateUi(AddSequenceClassDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddSequenceClassDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddSequenceClassDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddSequenceClassDialog);
    } // setupUi

    void retranslateUi(QDialog *AddSequenceClassDialog)
    {
        AddSequenceClassDialog->setWindowTitle(QCoreApplication::translate("AddSequenceClassDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddSequenceClassDialog", "Choose sequence class", nullptr));
        label_2->setText(QCoreApplication::translate("AddSequenceClassDialog", "Type instance name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSequenceClassDialog: public Ui_AddSequenceClassDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSEQUENCECLASSDIALOG_H
