#include "sequencediagramview.h"
#include "ui_sequencediagramview.h"

SequenceDiagramView::SequenceDiagramView(QWidget *parent) : QWidget(parent),
                                                            ui(new Ui::SequenceDiagramView)
{
    ui->setupUi(this);
}

void SequenceDiagramView::init(QTabWidget *tabPane)
{
}

SequenceDiagramView::~SequenceDiagramView()
{
    delete ui;
}

void SequenceDiagramView::on_btnClose_clicked()
{
}
