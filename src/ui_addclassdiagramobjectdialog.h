/********************************************************************************
** Form generated from reading UI file 'addclassdiagramobjectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCLASSDIAGRAMOBJECTDIALOG_H
#define UI_ADDCLASSDIAGRAMOBJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddClassDiagramObjectDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *txtObjectName;
    QCheckBox *checkBoxIsInterface;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddClassDiagramObjectDialog)
    {
        if (AddClassDiagramObjectDialog->objectName().isEmpty())
            AddClassDiagramObjectDialog->setObjectName(QString::fromUtf8("AddClassDiagramObjectDialog"));
        AddClassDiagramObjectDialog->resize(444, 166);
        verticalLayout_2 = new QVBoxLayout(AddClassDiagramObjectDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtObjectName = new QTextEdit(AddClassDiagramObjectDialog);
        txtObjectName->setObjectName(QString::fromUtf8("txtObjectName"));
        txtObjectName->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(txtObjectName);

        checkBoxIsInterface = new QCheckBox(AddClassDiagramObjectDialog);
        checkBoxIsInterface->setObjectName(QString::fromUtf8("checkBoxIsInterface"));

        verticalLayout->addWidget(checkBoxIsInterface);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(50, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(AddClassDiagramObjectDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(AddClassDiagramObjectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddClassDiagramObjectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddClassDiagramObjectDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddClassDiagramObjectDialog);
    } // setupUi

    void retranslateUi(QDialog *AddClassDiagramObjectDialog)
    {
        AddClassDiagramObjectDialog->setWindowTitle(QCoreApplication::translate("AddClassDiagramObjectDialog", "Dialog", nullptr));
        checkBoxIsInterface->setText(QCoreApplication::translate("AddClassDiagramObjectDialog", "Make this inteface", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddClassDiagramObjectDialog: public Ui_AddClassDiagramObjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLASSDIAGRAMOBJECTDIALOG_H
