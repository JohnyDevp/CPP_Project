/********************************************************************************
** Form generated from reading UI file 'addmessagedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMESSAGEDIALOG_H
#define UI_ADDMESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddMessageDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *txtMessageParams;
    QLabel *label;
    QComboBox *cmbMessageReceiver;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *cmbMessageOperation;
    QComboBox *cmbMessageType;
    QLabel *label_4;

    void setupUi(QDialog *AddMessageDialog)
    {
        if (AddMessageDialog->objectName().isEmpty())
            AddMessageDialog->setObjectName(QString::fromUtf8("AddMessageDialog"));
        AddMessageDialog->resize(533, 406);
        buttonBox = new QDialogButtonBox(AddMessageDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 330, 481, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        txtMessageParams = new QTextEdit(AddMessageDialog);
        txtMessageParams->setObjectName(QString::fromUtf8("txtMessageParams"));
        txtMessageParams->setGeometry(QRect(20, 200, 311, 31));
        label = new QLabel(AddMessageDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 180, 191, 17));
        cmbMessageReceiver = new QComboBox(AddMessageDialog);
        cmbMessageReceiver->setObjectName(QString::fromUtf8("cmbMessageReceiver"));
        cmbMessageReceiver->setGeometry(QRect(20, 40, 311, 25));
        label_2 = new QLabel(AddMessageDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 201, 17));
        label_3 = new QLabel(AddMessageDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 201, 17));
        cmbMessageOperation = new QComboBox(AddMessageDialog);
        cmbMessageOperation->setObjectName(QString::fromUtf8("cmbMessageOperation"));
        cmbMessageOperation->setGeometry(QRect(20, 140, 311, 25));
        cmbMessageType = new QComboBox(AddMessageDialog);
        cmbMessageType->setObjectName(QString::fromUtf8("cmbMessageType"));
        cmbMessageType->setGeometry(QRect(20, 260, 311, 25));
        label_4 = new QLabel(AddMessageDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 240, 201, 17));

        retranslateUi(AddMessageDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddMessageDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddMessageDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddMessageDialog);
    } // setupUi

    void retranslateUi(QDialog *AddMessageDialog)
    {
        AddMessageDialog->setWindowTitle(QCoreApplication::translate("AddMessageDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddMessageDialog", "Type message params", nullptr));
        label_2->setText(QCoreApplication::translate("AddMessageDialog", "Set message receiver class", nullptr));
        label_3->setText(QCoreApplication::translate("AddMessageDialog", "Choose operation", nullptr));
        label_4->setText(QCoreApplication::translate("AddMessageDialog", "Set message type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMessageDialog: public Ui_AddMessageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMESSAGEDIALOG_H
