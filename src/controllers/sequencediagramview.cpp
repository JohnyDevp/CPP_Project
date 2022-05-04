#include "sequencediagramview.h"
#include "ui_sequencediagramview.h"
#include <iostream>

SequenceDiagramView::SequenceDiagramView(QWidget *parent) : QWidget(parent),
                                                            ui(new Ui::SequenceDiagramView)
{
    ui->setupUi(this);
}

void SequenceDiagramView::init(QTabWidget *tabPane, int tabIndex)
{
    this->tabPane = tabPane;
    this->tabIndex = tabIndex;
}

SequenceDiagramView::~SequenceDiagramView()
{
    delete ui;
}

void SequenceDiagramView::on_btnClose_clicked()
{
    this->tabPane->removeTab(this->tabIndex);
}
