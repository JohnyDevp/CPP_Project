/** @file classdiagramview.cpp
 *  @author xholan11
 *  @brief Controller for view for class diagram
 */

#include "classdiagramview.h"
#include "cls/UMLClass.hpp"
#include "controllers/sequencediagramview.h"
#include "qinputdialog.h"
#include "ui_classdiagramview.h"
#include <QGraphicsRectItem>
#include "diagraminterface.h"
#include "../objectgui.h"
#include "views/addclassdiagramobjectdialog.h"
#include "errors.h"

ClassDiagramView::ClassDiagramView(QWidget *parent) : QWidget(parent),
                                                      ui(new Ui::ClassDiagramView)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
}

ClassDiagramView::~ClassDiagramView()
{
    delete ui;
}

/*functions for this class======================================================================================================================*/

void ClassDiagramView::init(QString filePath, QPushButton *btn1, QPushButton *btn2, QTabWidget *tabPane)
{
    this->filePath = filePath;
    this->btnCreateNewDiagram = btn1;
    this->btnLoadExistingDiagram = btn2;
    this->tabPane = tabPane;

    // create diagraminterface - a public place and interface for storing classes, objects, relations,...
    DiagramInterface *diagramInterface = new DiagramInterface(scene);
    this->diagramInterface = diagramInterface;

    // if the file path isnt empty then call file parser
    if (!filePath.isEmpty())
    {
        parseFile();
    }
}

void ClassDiagramView::parseFile()
{
    if (!diagramInterface->load(filePath))
    {
        Errors().raiseError("Error occured while loading. Please try again.");

        return;
    }
    // Creating GUI Objects

    foreach (const UMLClass &cl, diagramInterface->classDiagram.classList)
    {
        // create new object - according to which has been specified in dialog
        ObjectGUI *newObj = new ObjectGUI(cl, this->diagramInterface);

        // add gui representation of this object to the list
        this->diagramInterface->addObjectToObjectGuiList(newObj);

        // newObjj = new ObjectGUI();
        scene->addItem(newObj);
    }
}

/*event handlers======================================================================================================================*/

void ClassDiagramView::on_btnClose_clicked()
{
    // save all diagrams?? //TODO

    // enabling buttons
    this->btnCreateNewDiagram->setEnabled(true);
    this->btnLoadExistingDiagram->setEnabled(true);

    // remove all tabs

    // TODO call close() of all sequence diagrams
    this->tabPane->removeTab(0);
}

void ClassDiagramView::on_btnAddObject_clicked()
{
    scene->removeItem(this->relation);
    scene->addItem(this->relation);
    relation->qpointStart.setX(relation->qpointStart.x() + 50);

    // raise a dialog => choose name and whether it will be an interface or not
    AddClassDiagramObjectDialog *addClassDlg = new AddClassDiagramObjectDialog();
    addClassDlg->exec();

    if (!addClassDlg->isValid)
    {
        // if dialog was canceled or close or the input is invalid
        return;
    }

    // create umlinterface or umlclass
    UMLClass newCls(addClassDlg->getObjectName());
    // set whether the uml object is interface or not
    newCls.isInterface = addClassDlg->getIsInterface();

    // when the class already exists
    //  and add this object to the list of objects in public place (diagraminterface)
    if (!diagramInterface->createUMLClass(newCls))
    {
        return;
    }

    // create new object - according to which has been specified in dialog
    ObjectGUI *newObj = new ObjectGUI(newCls, this->diagramInterface);

    // add gui representation of this object to the list
    this->diagramInterface->addObjectToObjectGuiList(newObj);

    // newObjj = new ObjectGUI();
    scene->addItem(newObj);
}

void ClassDiagramView::on_btnCreateNewSequenceDiagram_clicked()
{
    // create new ClassDiagramView controller, init it and ad it as view to the tab
    SequenceDiagramView *q = new SequenceDiagramView();

    // add class diagram canvas window -> in new tab
    this->tabPane->addTab(q, "Sequence diagram ");
}

void ClassDiagramView::on_btnSave_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), "JSON (*.json)");
    // nothing has been selected -> prompt and return
    if (fileName.isEmpty())
    {
        Errors().raiseError("File was not selected.");
    }

    if (!diagramInterface->save(fileName))
    {
        Errors().raiseError("Problem occured while saving. Please try again.");
    }
}
