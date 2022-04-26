/** @file mainwindow.cpp
 *  @author xholan11
 *  @brief Controlling the main window
 *  Creating new or loading existing diagram
 *  Adding tab to tabpane
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton * m_button = ui->btnCreateNewDiagram;
    connect(m_button, &QPushButton::clicked,this, [&] {ui->tabWidget->addTab(this, QString("hello there"));});
}

MainWindow::~MainWindow()
{
    delete ui;
}

