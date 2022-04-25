/** @file mainwindow.h
 *  @author xholan11
 *  @brief Header file for controller of mainwindow.cpp
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

private:
    /**
     * @brief diagramTabConstructor - for adding new tab with class diagram
     * @param isLoadingFile pass whether the diagram is giong to be load from file or not (just create new one)
     */
    void diagramTabConstructor(bool isLoadingFile);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
