/********************************************************************************
** Form generated from reading UI file 'editobjectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
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
    QFrame *line;
    QPushButton *btnRenameObject;
    QPushButton *btnRemoveObject;
    QTextEdit *txtObjectName;
    QFrame *line_2;
    QLabel *label;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *txtAttrForOperationName;
    QTextEdit *txtAttrForOperationType;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnAddAttributeToOperation;
    QPushButton *btnClearAllOperationAttributes;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *cmbAttributeModifier;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *txtAttrName;
    QTextEdit *txtAttrType;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnAddAttribute;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *cmbOperationModifier;
    QHBoxLayout *horizontalLayout;
    QTextEdit *txtOperationName;
    QTextEdit *txtOperationType;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnAddOperation;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *cmbOperations;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDeleteOperation;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *cmbAttributes;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnDeleteAttribute;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *EditObjectDialog)
    {
        if (EditObjectDialog->objectName().isEmpty())
            EditObjectDialog->setObjectName(QString::fromUtf8("EditObjectDialog"));
        EditObjectDialog->resize(1094, 755);
        line = new QFrame(EditObjectDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 310, 1041, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        btnRenameObject = new QPushButton(EditObjectDialog);
        btnRenameObject->setObjectName(QString::fromUtf8("btnRenameObject"));
        btnRenameObject->setGeometry(QRect(970, 40, 89, 25));
        btnRemoveObject = new QPushButton(EditObjectDialog);
        btnRemoveObject->setObjectName(QString::fromUtf8("btnRemoveObject"));
        btnRemoveObject->setGeometry(QRect(830, 40, 89, 25));
        txtObjectName = new QTextEdit(EditObjectDialog);
        txtObjectName->setObjectName(QString::fromUtf8("txtObjectName"));
        txtObjectName->setGeometry(QRect(20, 40, 311, 31));
        line_2 = new QFrame(EditObjectDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(20, 90, 1041, 31));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(EditObjectDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 67, 17));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        layoutWidget_2 = new QWidget(EditObjectDialog);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 630, 1041, 74));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        txtAttrForOperationName = new QTextEdit(layoutWidget_2);
        txtAttrForOperationName->setObjectName(QString::fromUtf8("txtAttrForOperationName"));

        horizontalLayout_5->addWidget(txtAttrForOperationName);

        txtAttrForOperationType = new QTextEdit(layoutWidget_2);
        txtAttrForOperationType->setObjectName(QString::fromUtf8("txtAttrForOperationType"));

        horizontalLayout_5->addWidget(txtAttrForOperationType);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        btnAddAttributeToOperation = new QPushButton(layoutWidget_2);
        btnAddAttributeToOperation->setObjectName(QString::fromUtf8("btnAddAttributeToOperation"));

        horizontalLayout_5->addWidget(btnAddAttributeToOperation);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        btnClearAllOperationAttributes = new QPushButton(EditObjectDialog);
        btnClearAllOperationAttributes->setObjectName(QString::fromUtf8("btnClearAllOperationAttributes"));
        btnClearAllOperationAttributes->setGeometry(QRect(960, 590, 104, 25));
        layoutWidget = new QWidget(EditObjectDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 218, 1041, 74));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        cmbAttributeModifier = new QComboBox(layoutWidget);
        cmbAttributeModifier->setObjectName(QString::fromUtf8("cmbAttributeModifier"));

        horizontalLayout_3->addWidget(cmbAttributeModifier);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        txtAttrName = new QTextEdit(layoutWidget);
        txtAttrName->setObjectName(QString::fromUtf8("txtAttrName"));

        horizontalLayout_2->addWidget(txtAttrName);

        txtAttrType = new QTextEdit(layoutWidget);
        txtAttrType->setObjectName(QString::fromUtf8("txtAttrType"));

        horizontalLayout_2->addWidget(txtAttrType);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        btnAddAttribute = new QPushButton(layoutWidget);
        btnAddAttribute->setObjectName(QString::fromUtf8("btnAddAttribute"));

        horizontalLayout_2->addWidget(btnAddAttribute);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(EditObjectDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 480, 1041, 74));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        cmbOperationModifier = new QComboBox(layoutWidget1);
        cmbOperationModifier->setObjectName(QString::fromUtf8("cmbOperationModifier"));

        horizontalLayout_6->addWidget(cmbOperationModifier);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        txtOperationName = new QTextEdit(layoutWidget1);
        txtOperationName->setObjectName(QString::fromUtf8("txtOperationName"));
        txtOperationName->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(txtOperationName);

        txtOperationType = new QTextEdit(layoutWidget1);
        txtOperationType->setObjectName(QString::fromUtf8("txtOperationType"));
        txtOperationType->setMinimumSize(QSize(156, 0));

        horizontalLayout->addWidget(txtOperationType);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        btnAddOperation = new QPushButton(layoutWidget1);
        btnAddOperation->setObjectName(QString::fromUtf8("btnAddOperation"));

        horizontalLayout_6->addWidget(btnAddOperation);

        layoutWidget2 = new QWidget(EditObjectDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 370, 1041, 76));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        cmbOperations = new QComboBox(layoutWidget2);
        cmbOperations->setObjectName(QString::fromUtf8("cmbOperations"));
        cmbOperations->setMinimumSize(QSize(600, 0));

        horizontalLayout_7->addWidget(cmbOperations);

        horizontalSpacer_5 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        btnDeleteOperation = new QPushButton(layoutWidget2);
        btnDeleteOperation->setObjectName(QString::fromUtf8("btnDeleteOperation"));

        horizontalLayout_7->addWidget(btnDeleteOperation);

        layoutWidget3 = new QWidget(EditObjectDialog);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 160, 1041, 28));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        cmbAttributes = new QComboBox(layoutWidget3);
        cmbAttributes->setObjectName(QString::fromUtf8("cmbAttributes"));
        cmbAttributes->setMinimumSize(QSize(600, 0));

        horizontalLayout_8->addWidget(cmbAttributes);

        horizontalSpacer_6 = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        btnDeleteAttribute = new QPushButton(layoutWidget3);
        btnDeleteAttribute->setObjectName(QString::fromUtf8("btnDeleteAttribute"));

        horizontalLayout_8->addWidget(btnDeleteAttribute);

        label_2 = new QLabel(EditObjectDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 111, 18));
        label_2->setFont(font);
        label_3 = new QLabel(EditObjectDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 340, 111, 18));
        label_3->setFont(font);
        label_4 = new QLabel(EditObjectDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 590, 201, 18));
        label_4->setFont(font);

        retranslateUi(EditObjectDialog);

        QMetaObject::connectSlotsByName(EditObjectDialog);
    } // setupUi

    void retranslateUi(QDialog *EditObjectDialog)
    {
        EditObjectDialog->setWindowTitle(QApplication::translate("EditObjectDialog", "Dialog", nullptr));
        btnRenameObject->setText(QApplication::translate("EditObjectDialog", "RENAME", nullptr));
        btnRemoveObject->setText(QApplication::translate("EditObjectDialog", "REMOVE", nullptr));
        label->setText(QApplication::translate("EditObjectDialog", "Name", nullptr));
        btnAddAttributeToOperation->setText(QApplication::translate("EditObjectDialog", "ADD ATTRIBUTE", nullptr));
        btnClearAllOperationAttributes->setText(QApplication::translate("EditObjectDialog", "CLEAR LIST", nullptr));
        btnAddAttribute->setText(QApplication::translate("EditObjectDialog", "ADD", nullptr));
        btnAddOperation->setText(QApplication::translate("EditObjectDialog", "ADD", nullptr));
        btnDeleteOperation->setText(QApplication::translate("EditObjectDialog", "DELETE", nullptr));
        btnDeleteAttribute->setText(QApplication::translate("EditObjectDialog", "DELETE", nullptr));
        label_2->setText(QApplication::translate("EditObjectDialog", "Attributes", nullptr));
        label_3->setText(QApplication::translate("EditObjectDialog", "Operations", nullptr));
        label_4->setText(QApplication::translate("EditObjectDialog", "Operation Attributes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditObjectDialog: public Ui_EditObjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOBJECTDIALOG_H
