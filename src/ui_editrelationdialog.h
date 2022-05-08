/********************************************************************************
** Form generated from reading UI file 'editrelationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITRELATIONDIALOG_H
#define UI_EDITRELATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditRelationDialog
{
public:
    QPushButton *btnSetRelationName;
    QPushButton *btnSetCardinalityEnd;
    QPushButton *btnSetCardinalityStart;
    QPushButton *btnRemoveRelation;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *txtRelationName;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTextEdit *txtCardinalityStart;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTextEdit *txtCardinalityEnd;

    void setupUi(QDialog *EditRelationDialog)
    {
        if (EditRelationDialog->objectName().isEmpty())
            EditRelationDialog->setObjectName(QString::fromUtf8("EditRelationDialog"));
        EditRelationDialog->resize(511, 300);
        btnSetRelationName = new QPushButton(EditRelationDialog);
        btnSetRelationName->setObjectName(QString::fromUtf8("btnSetRelationName"));
        btnSetRelationName->setGeometry(QRect(320, 60, 89, 25));
        btnSetCardinalityEnd = new QPushButton(EditRelationDialog);
        btnSetCardinalityEnd->setObjectName(QString::fromUtf8("btnSetCardinalityEnd"));
        btnSetCardinalityEnd->setGeometry(QRect(320, 130, 89, 25));
        btnSetCardinalityStart = new QPushButton(EditRelationDialog);
        btnSetCardinalityStart->setObjectName(QString::fromUtf8("btnSetCardinalityStart"));
        btnSetCardinalityStart->setGeometry(QRect(320, 210, 89, 25));
        btnRemoveRelation = new QPushButton(EditRelationDialog);
        btnRemoveRelation->setObjectName(QString::fromUtf8("btnRemoveRelation"));
        btnRemoveRelation->setGeometry(QRect(140, 260, 241, 25));
        widget = new QWidget(EditRelationDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 30, 258, 51));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        txtRelationName = new QTextEdit(widget);
        txtRelationName->setObjectName(QString::fromUtf8("txtRelationName"));

        verticalLayout->addWidget(txtRelationName);

        widget1 = new QWidget(EditRelationDialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 190, 258, 51));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        txtCardinalityStart = new QTextEdit(widget1);
        txtCardinalityStart->setObjectName(QString::fromUtf8("txtCardinalityStart"));

        verticalLayout_2->addWidget(txtCardinalityStart);

        widget2 = new QWidget(EditRelationDialog);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(50, 110, 258, 51));
        verticalLayout_3 = new QVBoxLayout(widget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        txtCardinalityEnd = new QTextEdit(widget2);
        txtCardinalityEnd->setObjectName(QString::fromUtf8("txtCardinalityEnd"));

        verticalLayout_3->addWidget(txtCardinalityEnd);


        retranslateUi(EditRelationDialog);

        QMetaObject::connectSlotsByName(EditRelationDialog);
    } // setupUi

    void retranslateUi(QDialog *EditRelationDialog)
    {
        EditRelationDialog->setWindowTitle(QApplication::translate("EditRelationDialog", "Dialog", nullptr));
        btnSetRelationName->setText(QApplication::translate("EditRelationDialog", "SET", nullptr));
        btnSetCardinalityEnd->setText(QApplication::translate("EditRelationDialog", "SET", nullptr));
        btnSetCardinalityStart->setText(QApplication::translate("EditRelationDialog", "SET", nullptr));
        btnRemoveRelation->setText(QApplication::translate("EditRelationDialog", "REMOVE RELATION", nullptr));
        label->setText(QApplication::translate("EditRelationDialog", "Relation name", nullptr));
        label_2->setText(QApplication::translate("EditRelationDialog", "Cardinality by relation start object", nullptr));
        label_3->setText(QApplication::translate("EditRelationDialog", "Cardinality by relation end object", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditRelationDialog: public Ui_EditRelationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITRELATIONDIALOG_H
