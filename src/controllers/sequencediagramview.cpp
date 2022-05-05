#include "sequencediagramview.h"
#include "ui_sequencediagramview.h"
#include <iostream>
#include <QInputDialog>

SequenceDiagramView::SequenceDiagramView(QWidget *parent) : QWidget(parent),
                                                            ui(new Ui::SequenceDiagramView)
{
    ui->setupUi(this);

    //set up the scene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

void SequenceDiagramView::init(QTabWidget *tabPane, int tabIndex, SequenceDiagramInterface * sequenceDiagramInterface)
{
    this->tabPane = tabPane;
    this->tabIndex = tabIndex;
    this->sequenceDiagramInterface = sequenceDiagramInterface;

    //set scene for the seauence diagram interface
    this->sequenceDiagramInterface->scene = this->scene;

}

SequenceDiagramView::~SequenceDiagramView()
{
    delete ui;
}

void SequenceDiagramView::on_btnClose_clicked()
{
    this->tabPane->removeTab(this->tabIndex);
}

void SequenceDiagramView::on_btnAddObject_clicked()
{
    //collect name of all classes
    QStringList listOfClasses;
    foreach(UMLClass umlClass, this->sequenceDiagramInterface->diagramInterface->classDiagram.classList){
        listOfClasses << umlClass.name;
    }

    //raise a choice dialog for choose a class to create
    // create new dialog
    bool ok; // variable storing whether ok has been pressed
    QString item = QInputDialog::getItem(this,
                                         QDialog::tr("Choose relation type"),
                                         QDialog::tr("Relation type"),
                                         listOfClasses, 0, false, &ok);

    if (ok && !item.isEmpty()){
        //if the class has been chosen then find class according to the chosen name
        //and create umlseqclass and its gui
        UMLClass umlClass = this->sequenceDiagramInterface->diagramInterface->getUMLClass(item);
        UMLSeqClass umlSeqClass(umlClass.name, umlClass.name, 0);
        SequenceObjectGUI sequenceObjectGUI();


    }
}

