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
#include "controllers/addsequenceclassdialog.h"
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

    //load the gui of sequence diagram, if exists
    this->sequenceDiagramInterface->load();
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
    //create new dialog for adding new sequence class
    AddSequenceClassDialog * seqClassDlg = new AddSequenceClassDialog();
    seqClassDlg->init(this->sequenceDiagramInterface);
    seqClassDlg->exec();

    //if the data get are valid
    if (seqClassDlg->dataValid){
        UMLSeqClass umlSeqClass = seqClassDlg->getUmlSeqClass();
        SequenceObjectGUI *sequenceObjectGUI = new SequenceObjectGUI(umlSeqClass, this->sequenceDiagramInterface);

        this->sequenceDiagramInterface->addSeqClas(umlSeqClass);
        // this method also add the gui to the scene
        this->sequenceDiagramInterface->addNewSequenceObjectGUI(sequenceObjectGUI);
    }
}
