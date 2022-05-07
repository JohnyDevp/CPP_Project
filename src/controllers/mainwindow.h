/** @file mainwindow.h
 *  @author xholan11
 *  @brief Header file for controller of mainwindow.cpp
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFileDialog>
#include <QDir>

#include "classdiagramview.h"
#include "ui_mainwindow.h"
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The MainWindow class
 * handle start step for creating or loading class diagram and its sequence diagrams - according to
 * which button is pressed
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * @brief diagramTabConstructor - for adding new tab with class diagram
     * @param isLoadingFile pass whether the diagram is giong to be load from file or not (just create new one)
     */
    void diagramTabConstructor(bool isLoadingFile);

private slots:
    /**
     * @brief on_btnCreateNewDiagram_clicked
     */
    void on_btnCreateNewDiagram_clicked();

    /**
     * @brief on_btnLoadExistingDiagram_clicked
     */
    void on_btnLoadExistingDiagram_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ClassDiagramView *q;
};
#endif // MAINWINDOW_H
