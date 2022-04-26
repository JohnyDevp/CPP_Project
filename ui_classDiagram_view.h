/********************************************************************************
** Form generated from reading UI file 'classDiagram_view.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSDIAGRAM_VIEW_H
#define UI_CLASSDIAGRAM_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_classDiagramForm
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton_6;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *classDiagramForm)
    {
        if (classDiagramForm->objectName().isEmpty())
            classDiagramForm->setObjectName(QString::fromUtf8("classDiagramForm"));
        classDiagramForm->resize(1074, 457);
        verticalLayout_3 = new QVBoxLayout(classDiagramForm);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_8 = new QPushButton(classDiagramForm);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_2->addWidget(pushButton_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(classDiagramForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(classDiagramForm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(classDiagramForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(classDiagramForm);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(classDiagramForm);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(classDiagramForm);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_6 = new QPushButton(classDiagramForm);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout->addWidget(pushButton_6);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(classDiagramForm);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_2->addWidget(graphicsView);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(classDiagramForm);

        QMetaObject::connectSlotsByName(classDiagramForm);
    } // setupUi

    void retranslateUi(QWidget *classDiagramForm)
    {
        classDiagramForm->setWindowTitle(QApplication::translate("classDiagramForm", "Form", nullptr));
        pushButton_8->setText(QApplication::translate("classDiagramForm", "Create new sequence diagram", nullptr));
        pushButton->setText(QApplication::translate("classDiagramForm", "Save", nullptr));
        pushButton_2->setText(QApplication::translate("classDiagramForm", "Undo", nullptr));
        pushButton_3->setText(QApplication::translate("classDiagramForm", "Close", nullptr));
        pushButton_4->setText(QApplication::translate("classDiagramForm", "ADD CLASS/INTERFACE", nullptr));
        pushButton_5->setText(QApplication::translate("classDiagramForm", "ADD RELATION", nullptr));
        pushButton_7->setText(QApplication::translate("classDiagramForm", "EDIT CLASS/INTERFACE", nullptr));
        pushButton_6->setText(QApplication::translate("classDiagramForm", "EDIT RELATION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class classDiagramForm: public Ui_classDiagramForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSDIAGRAM_VIEW_H
