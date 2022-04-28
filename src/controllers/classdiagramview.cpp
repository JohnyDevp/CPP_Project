/** @file classdiagramview.cpp
 *  @author xholan11
 *  @brief Controller for view for class diagram
*/


#include "classdiagramview.h"
#include "src/cls/UMLClass.hpp"
#include "src/controllers/sequencediagramview.h"
#include "ui_classdiagramview.h"
#include <QGraphicsRectItem>

ClassDiagramView::ClassDiagramView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassDiagramView)
{
    ui->setupUi(this);


    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    //scene->setSceneRect(0,0, 800, 800); //FIXME
}

ClassDiagramView::~ClassDiagramView()
{
    delete ui;
}

/*functions for this class======================================================================================================================*/

void ClassDiagramView::init(std::string filePath, QPushButton * btn1, QPushButton * btn2, QTabWidget * tabPane){
    this->filePath = filePath;
    this->btnCreateNewDiagram = btn1;
    this->btnLoadExistingDiagram = btn2;
    this->tabPane = tabPane;

    //create diagraminterface - a public place and interface for storing classes, objects, relations,...
    DiagramInterface * diagramInterface = new DiagramInterface();
    this->diagramInterface = diagramInterface;

    //if the file path isnt empty then call file parser
    if (filePath != ""){
        parseFile();
    }
}

void ClassDiagramView::parseFile(){

}

/*event handlers======================================================================================================================*/

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



void ClassDiagramView::on_btnAddObject_clicked()
{
    //raise a dialog => choose name and whether it will be an interface or not

    //create umlclass
    UMLClass newCls("tmpname");

    //create new object - according to which has been specified in dialog
    ObjectGUI * newObj = new ObjectGUI(newCls);

    //add this object to the list of objects in public place (diagraminterface)
    //TODO

    //newObjj = new ObjectGUI();
    scene->addItem(newObj);

}



void ClassDiagramView::on_btnCreateNewSequenceDiagram_clicked()
{
    //create new ClassDiagramView controller, init it and ad it as view to the tab
    SequenceDiagramView * q = new SequenceDiagramView();

    //add class diagram canvas window -> in new tab
    this->tabPane->addTab(q, "Sequence diagram ");
}

