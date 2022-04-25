/** @file mainwindow.cpp
 *  @author xholan11
 *  @brief Controlling the main window
 *  Creating new or loading existing diagram
 *  Adding tab to tabpane
*/


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

