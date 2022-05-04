#include "sequencediagramview.h"
#include "ui_sequencediagramview.h"
#include <iostream>

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
