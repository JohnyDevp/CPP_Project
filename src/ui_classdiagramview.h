/********************************************************************************
** Form generated from reading UI file 'classdiagramview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSDIAGRAMVIEW_H
#define UI_CLASSDIAGRAMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassDiagramView
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnUndo;
    QPushButton *btnClose;
    QPushButton *btnAddObject;
    QPushButton *btnAddRelation;
    QPushButton *btnEditObject;
    QPushButton *btnEditRelation;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *ClassDiagramView)
    {
        if (ClassDiagramView->objectName().isEmpty())
            ClassDiagramView->setObjectName(QString::fromUtf8("ClassDiagramView"));
        ClassDiagramView->resize(865, 308);
        verticalLayout_3 = new QVBoxLayout(ClassDiagramView);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_8 = new QPushButton(ClassDiagramView);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_2->addWidget(pushButton_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnSave = new QPushButton(ClassDiagramView);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnUndo = new QPushButton(ClassDiagramView);
        btnUndo->setObjectName(QString::fromUtf8("btnUndo"));

        horizontalLayout->addWidget(btnUndo);

        btnClose = new QPushButton(ClassDiagramView);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout->addWidget(btnClose);

        btnAddObject = new QPushButton(ClassDiagramView);
        btnAddObject->setObjectName(QString::fromUtf8("btnAddObject"));

        horizontalLayout->addWidget(btnAddObject);

        btnAddRelation = new QPushButton(ClassDiagramView);
        btnAddRelation->setObjectName(QString::fromUtf8("btnAddRelation"));

        horizontalLayout->addWidget(btnAddRelation);

        btnEditObject = new QPushButton(ClassDiagramView);
        btnEditObject->setObjectName(QString::fromUtf8("btnEditObject"));

        horizontalLayout->addWidget(btnEditObject);

        btnEditRelation = new QPushButton(ClassDiagramView);
        btnEditRelation->setObjectName(QString::fromUtf8("btnEditRelation"));

        horizontalLayout->addWidget(btnEditRelation);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(ClassDiagramView);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_2->addWidget(graphicsView);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(ClassDiagramView);

        QMetaObject::connectSlotsByName(ClassDiagramView);
    } // setupUi

    void retranslateUi(QWidget *ClassDiagramView)
    {
        ClassDiagramView->setWindowTitle(QCoreApplication::translate("ClassDiagramView", "Form", nullptr));
        pushButton_8->setText(QCoreApplication::translate("ClassDiagramView", "Create new sequence diagram", nullptr));
        btnSave->setText(QCoreApplication::translate("ClassDiagramView", "Save", nullptr));
        btnUndo->setText(QCoreApplication::translate("ClassDiagramView", "Undo", nullptr));
        btnClose->setText(QCoreApplication::translate("ClassDiagramView", "Close", nullptr));
        btnAddObject->setText(QCoreApplication::translate("ClassDiagramView", "ADD CLASS/INTERFACE", nullptr));
        btnAddRelation->setText(QCoreApplication::translate("ClassDiagramView", "ADD RELATION", nullptr));
        btnEditObject->setText(QCoreApplication::translate("ClassDiagramView", "EDIT CLASS/INTERFACE", nullptr));
        btnEditRelation->setText(QCoreApplication::translate("ClassDiagramView", "EDIT RELATION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClassDiagramView: public Ui_ClassDiagramView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSDIAGRAMVIEW_H
