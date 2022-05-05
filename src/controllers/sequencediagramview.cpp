/**
 * @file sequencediagramview.cpp
 * @author xholan11
 * @brief Controller for view for sequence diagram
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "sequencediagramview.h"
#include "ui_sequencediagramview.h"
#include <iostream>
#include <QInputDialog>

SequenceDiagramView::SequenceDiagramView(QWidget *parent) : QWidget(parent),
                                                            ui(new Ui::SequenceDiagramView)
{
    ui->setupUi(this);

    // set up the scene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

void SequenceDiagramView::init(QTabWidget *tabPane, int tabIndex, SequenceDiagramInterface *sequenceDiagramInterface)
{
    this->tabPane = tabPane;
    this->tabIndex = tabIndex;
    this->sequenceDiagramInterface = sequenceDiagramInterface;

    // set scene for the seauence diagram interface
    this->sequenceDiagramInterface->setScene(this->scene);
}

SequenceDiagramView::~SequenceDiagramView()
{
    delete ui;
    delete scene;
}

void SequenceDiagramView::on_btnClose_clicked()
{
    this->tabPane->removeTab(this->tabIndex);
}

void SequenceDiagramView::on_btnAddObject_clicked()
{
    // collect name of all classes
    QStringList listOfClasses;
    foreach (UMLClass umlClass, this->sequenceDiagramInterface->diagramInterface->classDiagram.classList)
    {
        if (!umlClass.isInterface){
            listOfClasses << umlClass.name;
        }
    }

    // raise a choice dialog for choose a class to create
    //  create new dialog
    bool ok; // variable storing whether ok has been pressed
    QString item = QInputDialog::getItem(this,
                                         QDialog::tr("Choose relation type"),
                                         QDialog::tr("Relation type"),
                                         listOfClasses, 0, false, &ok);

    if (ok && !item.isEmpty())
    {
        // if the class has been chosen then find class according to the chosen name
        // and create umlseqclass and its gui
        UMLClass umlClass = this->sequenceDiagramInterface->diagramInterface->getUMLClass(item);
        UMLSeqClass umlSeqClass("", umlClass.name, 10);
        SequenceObjectGUI *sequenceObjectGUI = new SequenceObjectGUI(umlSeqClass, this->sequenceDiagramInterface);

        this->sequenceDiagramInterface->addSeqClas(umlSeqClass);
        // this method also add the gui to the scene
        this->sequenceDiagramInterface->addNewSequenceObjectGUI(sequenceObjectGUI);
    }
}
