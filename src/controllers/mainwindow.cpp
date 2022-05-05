/** @file mainwindow.cpp
 *  @author xholan11
 *  @brief Controlling the main window
 *  Creating new or loading existing diagram
 *  Adding tab to tabpane
 */

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // remove default tab of QTabWidget -> maybe //FIXME
    ui->tabWidget->removeTab(0);

    // add actions to buttons -> early version - now replaced - rather again this????
    //    QPushButton * b_cnd = ui->btnCreateNewDiagram;
    //    QPushButton * b_led = ui->btnLoadExistingDiagram;
    //    connect(b_cnd, SIGNAL(clicked()),this, SLOT(btnCreateNewDiagram_click()));
    //    connect(b_led, SIGNAL(clicked()),this, SLOT(btnLoadExistingDiagram_click()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete q;
}

void MainWindow::on_btnCreateNewDiagram_clicked()
{
    std::cout << "creating new diagram\n";
    diagramTabConstructor(false);
}

void MainWindow::on_btnLoadExistingDiagram_clicked()
{
    std::cout << "loading existing diagram\n";
    diagramTabConstructor(true);
}

// TODO
void MainWindow::diagramTabConstructor(bool isLoadingFile)
{
    // load file if it should be loaded
    QString fileName;
    if (isLoadingFile)
    {
        fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath(), "JSON (*.json)");
        // nothing has been selected -> prompt and return
        if (fileName == "")
        {
            std::cout << "nothing has been selected!" << std::endl;
            return;
        }
    }

    // create new ClassDiagramView controller, init it and ad it as view to the tab
    q = new ClassDiagramView();
    q->init(fileName, ui->btnCreateNewDiagram, ui->btnLoadExistingDiagram, ui->tabWidget);

    // add class diagram canvas window -> in new tab
    ui->tabWidget->addTab(q, "Class diagram ");

    // disable buttons for creating diagram
    ui->btnCreateNewDiagram->setEnabled(false);
    ui->btnLoadExistingDiagram->setEnabled(false);
}
