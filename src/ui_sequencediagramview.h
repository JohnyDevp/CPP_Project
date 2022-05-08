/********************************************************************************
** Form generated from reading UI file 'sequencediagramview.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEQUENCEDIAGRAMVIEW_H
#define UI_SEQUENCEDIAGRAMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SequenceDiagramView
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnSave;
    QPushButton *btnUndo;
    QPushButton *btnClose;
    QPushButton *btnAddObject;
    QPushButton *btnAddRelation;
    QPushButton *btnEditObject;
    QPushButton *btnEditRelation;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *SequenceDiagramView)
    {
        if (SequenceDiagramView->objectName().isEmpty())
            SequenceDiagramView->setObjectName(QString::fromUtf8("SequenceDiagramView"));
        SequenceDiagramView->resize(967, 559);
        verticalLayout_3 = new QVBoxLayout(SequenceDiagramView);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnSave = new QPushButton(SequenceDiagramView);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        btnUndo = new QPushButton(SequenceDiagramView);
        btnUndo->setObjectName(QString::fromUtf8("btnUndo"));

        horizontalLayout->addWidget(btnUndo);

        btnClose = new QPushButton(SequenceDiagramView);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout->addWidget(btnClose);

        btnAddObject = new QPushButton(SequenceDiagramView);
        btnAddObject->setObjectName(QString::fromUtf8("btnAddObject"));

        horizontalLayout->addWidget(btnAddObject);

        btnAddRelation = new QPushButton(SequenceDiagramView);
        btnAddRelation->setObjectName(QString::fromUtf8("btnAddRelation"));

        horizontalLayout->addWidget(btnAddRelation);

        btnEditObject = new QPushButton(SequenceDiagramView);
        btnEditObject->setObjectName(QString::fromUtf8("btnEditObject"));

        horizontalLayout->addWidget(btnEditObject);

        btnEditRelation = new QPushButton(SequenceDiagramView);
        btnEditRelation->setObjectName(QString::fromUtf8("btnEditRelation"));

        horizontalLayout->addWidget(btnEditRelation);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        graphicsView = new QGraphicsView(SequenceDiagramView);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setSceneRect(QRectF(0, 0, 400, 400));

        verticalLayout_2->addWidget(graphicsView);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(SequenceDiagramView);

        QMetaObject::connectSlotsByName(SequenceDiagramView);
    } // setupUi

    void retranslateUi(QWidget *SequenceDiagramView)
    {
        SequenceDiagramView->setWindowTitle(QCoreApplication::translate("SequenceDiagramView", "Form", nullptr));
        btnSave->setText(QCoreApplication::translate("SequenceDiagramView", "Save", nullptr));
        btnUndo->setText(QCoreApplication::translate("SequenceDiagramView", "Undo", nullptr));
        btnClose->setText(QCoreApplication::translate("SequenceDiagramView", "Close", nullptr));
        btnAddObject->setText(QCoreApplication::translate("SequenceDiagramView", "ADD CLASS", nullptr));
        btnAddRelation->setText(QCoreApplication::translate("SequenceDiagramView", "ADD RELATION", nullptr));
        btnEditObject->setText(QCoreApplication::translate("SequenceDiagramView", "EDIT CLASS/INTERFACE", nullptr));
        btnEditRelation->setText(QCoreApplication::translate("SequenceDiagramView", "EDIT RELATION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SequenceDiagramView: public Ui_SequenceDiagramView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEQUENCEDIAGRAMVIEW_H
