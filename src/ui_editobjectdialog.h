/********************************************************************************
** Form generated from reading UI file 'editobjectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOBJECTDIALOG_H
#define UI_EDITOBJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditObjectDialog
{
public:
    QComboBox *cmbAttributes;
    QComboBox *cmbOperations;
    QPushButton *btnDeleteOperation;
    QFrame *line;
    QTextEdit *txtAttributeName;
    QTextEdit *textEdit_2;
    QComboBox *cmbOperationModifier_2;
    QComboBox *cmbOperationModifier;
    QPushButton *btnAddOperation;
    QPushButton *btnAddAttributeToOperation;
    QPushButton *btnAddAttribute;
    QPushButton *btnRenameObject;
    QPushButton *btnRemoveObject;
    QTextEdit *txtObjectName;
    QFrame *line_2;
    QPushButton *btnDeleteAttribute;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *txtOperationName;
    QSpacerItem *horizontalSpacer;
    QTextEdit *txtOperationType;

    void setupUi(QDialog *EditObjectDialog)
    {
        if (EditObjectDialog->objectName().isEmpty())
            EditObjectDialog->setObjectName(QString::fromUtf8("EditObjectDialog"));
        EditObjectDialog->resize(1014, 488);
        cmbAttributes = new QComboBox(EditObjectDialog);
        cmbAttributes->setObjectName(QString::fromUtf8("cmbAttributes"));
        cmbAttributes->setGeometry(QRect(30, 100, 431, 25));
        cmbOperations = new QComboBox(EditObjectDialog);
        cmbOperations->setObjectName(QString::fromUtf8("cmbOperations"));
        cmbOperations->setGeometry(QRect(30, 260, 421, 25));
        btnDeleteOperation = new QPushButton(EditObjectDialog);
        btnDeleteOperation->setObjectName(QString::fromUtf8("btnDeleteOperation"));
        btnDeleteOperation->setGeometry(QRect(820, 250, 89, 25));
        line = new QFrame(EditObjectDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 190, 1011, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        txtAttributeName = new QTextEdit(EditObjectDialog);
        txtAttributeName->setObjectName(QString::fromUtf8("txtAttributeName"));
        txtAttributeName->setGeometry(QRect(122, 158, 256, 29));
        textEdit_2 = new QTextEdit(EditObjectDialog);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(384, 158, 256, 29));
        cmbOperationModifier_2 = new QComboBox(EditObjectDialog);
        cmbOperationModifier_2->setObjectName(QString::fromUtf8("cmbOperationModifier_2"));
        cmbOperationModifier_2->setGeometry(QRect(30, 160, 86, 25));
        cmbOperationModifier = new QComboBox(EditObjectDialog);
        cmbOperationModifier->setObjectName(QString::fromUtf8("cmbOperationModifier"));
        cmbOperationModifier->setGeometry(QRect(30, 330, 71, 25));
        btnAddOperation = new QPushButton(EditObjectDialog);
        btnAddOperation->setObjectName(QString::fromUtf8("btnAddOperation"));
        btnAddOperation->setGeometry(QRect(820, 340, 89, 25));
        btnAddAttributeToOperation = new QPushButton(EditObjectDialog);
        btnAddAttributeToOperation->setObjectName(QString::fromUtf8("btnAddAttributeToOperation"));
        btnAddAttributeToOperation->setGeometry(QRect(650, 300, 111, 71));
        btnAddAttribute = new QPushButton(EditObjectDialog);
        btnAddAttribute->setObjectName(QString::fromUtf8("btnAddAttribute"));
        btnAddAttribute->setGeometry(QRect(820, 170, 80, 25));
        btnRenameObject = new QPushButton(EditObjectDialog);
        btnRenameObject->setObjectName(QString::fromUtf8("btnRenameObject"));
        btnRenameObject->setGeometry(QRect(820, 20, 89, 25));
        btnRemoveObject = new QPushButton(EditObjectDialog);
        btnRemoveObject->setObjectName(QString::fromUtf8("btnRemoveObject"));
        btnRemoveObject->setGeometry(QRect(690, 20, 89, 25));
        txtObjectName = new QTextEdit(EditObjectDialog);
        txtObjectName->setObjectName(QString::fromUtf8("txtObjectName"));
        txtObjectName->setGeometry(QRect(70, 30, 201, 31));
        line_2 = new QFrame(EditObjectDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 60, 1011, 31));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        btnDeleteAttribute = new QPushButton(EditObjectDialog);
        btnDeleteAttribute->setObjectName(QString::fromUtf8("btnDeleteAttribute"));
        btnDeleteAttribute->setGeometry(QRect(820, 100, 80, 25));
        label = new QLabel(EditObjectDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 67, 17));
        widget = new QWidget(EditObjectDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 331, 520, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txtOperationName = new QTextEdit(widget);
        txtOperationName->setObjectName(QString::fromUtf8("txtOperationName"));
        txtOperationName->setMinimumSize(QSize(221, 29));

        horizontalLayout->addWidget(txtOperationName);

        horizontalSpacer = new QSpacerItem(150, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        txtOperationType = new QTextEdit(widget);
        txtOperationType->setObjectName(QString::fromUtf8("txtOperationType"));

        horizontalLayout->addWidget(txtOperationType);


        retranslateUi(EditObjectDialog);

        QMetaObject::connectSlotsByName(EditObjectDialog);
    } // setupUi

    void retranslateUi(QDialog *EditObjectDialog)
    {
        EditObjectDialog->setWindowTitle(QCoreApplication::translate("EditObjectDialog", "Dialog", nullptr));
        btnDeleteOperation->setText(QCoreApplication::translate("EditObjectDialog", "DELETE", nullptr));
        btnAddOperation->setText(QCoreApplication::translate("EditObjectDialog", "ADD", nullptr));
        btnAddAttributeToOperation->setText(QCoreApplication::translate("EditObjectDialog", "Add operation attribute", nullptr));
        btnAddAttribute->setText(QCoreApplication::translate("EditObjectDialog", "ADD", nullptr));
        btnRenameObject->setText(QCoreApplication::translate("EditObjectDialog", "RENAME", nullptr));
        btnRemoveObject->setText(QCoreApplication::translate("EditObjectDialog", "REMOVE", nullptr));
        btnDeleteAttribute->setText(QCoreApplication::translate("EditObjectDialog", "DELETE", nullptr));
        label->setText(QCoreApplication::translate("EditObjectDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditObjectDialog: public Ui_EditObjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOBJECTDIALOG_H
