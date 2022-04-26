/** @file classdiagramview.cpp
 *  @author xholan11
 *  @brief Controller for view for class diagram
*/


#include "classdiagramview.h"
#include "ui_classdiagramview.h"

ClassDiagramView::ClassDiagramView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassDiagramView)
{
    ui->setupUi(this);
}

ClassDiagramView::~ClassDiagramView()
{
    delete ui;
}

void ClassDiagramView::init(std::string filePath, QPushButton * btn1, QPushButton * btn2, QTabWidget * tabPane){
    this->filePath = filePath;
    this->btnCreateNewDiagram = btn1;
    this->btnLoadExistingDiagram = btn2;
    this->tabPane = tabPane;
}



void ClassDiagramView::on_btnClose_clicked()
{
    //save all diagrams?? //TODO

    //enabling buttons
    this->btnCreateNewDiagram->setEnabled(true);
    this->btnLoadExistingDiagram->setEnabled(true);

    //remove all tabs
    //TODO call close() of all sequence diagrams
    this->tabPane->removeTab(0);
}

