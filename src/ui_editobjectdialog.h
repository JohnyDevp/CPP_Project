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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_EditObjectDialog
{
public:
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton_2;
    QFrame *line;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QTextEdit *textEdit_5;
    QFrame *line_2;
    QPushButton *pushButton;

    void setupUi(QDialog *EditObjectDialog)
    {
        if (EditObjectDialog->objectName().isEmpty())
            EditObjectDialog->setObjectName(QString::fromUtf8("EditObjectDialog"));
        EditObjectDialog->resize(993, 408);
        comboBox = new QComboBox(EditObjectDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(30, 100, 431, 25));
        comboBox_2 = new QComboBox(EditObjectDialog);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(40, 240, 261, 25));
        pushButton_2 = new QPushButton(EditObjectDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(790, 240, 89, 25));
        line = new QFrame(EditObjectDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 190, 1011, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        textEdit = new QTextEdit(EditObjectDialog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(122, 158, 256, 29));
        textEdit_2 = new QTextEdit(EditObjectDialog);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(384, 158, 256, 29));
        textEdit_3 = new QTextEdit(EditObjectDialog);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(90, 290, 201, 31));
        textEdit_4 = new QTextEdit(EditObjectDialog);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(350, 290, 201, 31));
        comboBox_3 = new QComboBox(EditObjectDialog);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(30, 160, 86, 25));
        comboBox_4 = new QComboBox(EditObjectDialog);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(10, 290, 51, 25));
        pushButton_3 = new QPushButton(EditObjectDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(780, 300, 89, 25));
        pushButton_4 = new QPushButton(EditObjectDialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(650, 300, 111, 71));
        pushButton_5 = new QPushButton(EditObjectDialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(831, 168, 80, 25));
        pushButton_6 = new QPushButton(EditObjectDialog);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(790, 20, 89, 25));
        pushButton_7 = new QPushButton(EditObjectDialog);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(690, 20, 89, 25));
        textEdit_5 = new QTextEdit(EditObjectDialog);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(70, 20, 201, 31));
        line_2 = new QFrame(EditObjectDialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 60, 1011, 31));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        pushButton = new QPushButton(EditObjectDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(820, 100, 80, 25));

        retranslateUi(EditObjectDialog);

        QMetaObject::connectSlotsByName(EditObjectDialog);
    } // setupUi

    void retranslateUi(QDialog *EditObjectDialog)
    {
        EditObjectDialog->setWindowTitle(QApplication::translate("EditObjectDialog", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("EditObjectDialog", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("EditObjectDialog", "ADD", nullptr));
        pushButton_4->setText(QApplication::translate("EditObjectDialog", "Add operation attribute", nullptr));
        pushButton_5->setText(QApplication::translate("EditObjectDialog", "ADD", nullptr));
        pushButton_6->setText(QApplication::translate("EditObjectDialog", "RENAME", nullptr));
        pushButton_7->setText(QApplication::translate("EditObjectDialog", "REMOVE", nullptr));
        pushButton->setText(QApplication::translate("EditObjectDialog", "DELETE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditObjectDialog: public Ui_EditObjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOBJECTDIALOG_H
