/** @file classdiagramview.h
 *  @author xholan11
 *  @brief Header file for controller of classdiagramview.cpp
 */

#ifndef CLASSDIAGRAMVIEW_H
#define CLASSDIAGRAMVIEW_H

#include <QString>

#include "qtabwidget.h"
#include <QTabWidget>
#include <QPushButton>
#include <iostream>

namespace Ui
{
    class ClassDiagramView;
}

/**
 * @brief class handling all controlling actions of class diagram
 */
class ClassDiagramView : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief initializes the controller with path to file, if exists, link to tabcontainer,...
     * @param filePath
     * @param btn1
     * @param btn1
     * @param tabPane
     */
    void init(QString filePath, QPushButton *btn1, QPushButton *btn2, QTabWidget *tabPane);
    explicit ClassDiagramView(QWidget *parent = nullptr);
    ~ClassDiagramView();

private slots:
    /**
     * @brief on_btnClose_clicked - handling all closing events
     * starting saving the class diagram
     */
    void on_btnClose_clicked();

private:
    Ui::ClassDiagramView *ui;
    /**
     * @brief filePath - path to file, if was loaded
     * otherwise should be empty string literal
     */
    QString filePath;
    /**
     * @brief tabPane - storing pointer to tab widget from mainview ->
     * for make possible close the tab by itself
     */
    QTabWidget *tabPane;
    /**
     * @brief btnCreateNewDiagram - storing pointer for possibility of
     * enabling this button when closing diagrams
     */
    QPushButton *btnCreateNewDiagram;
    /**
     * @brief btnLoadExistingDiagram - storing pointer for possibility of
     * enabling this button when closing diagrams
     */
    QPushButton *btnLoadExistingDiagram;
};

#endif // CLASSDIAGRAMVIEW_H
