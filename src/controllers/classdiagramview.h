/** @file classdiagramview.h
 *  @author xholan11, xzimol04
 *  @brief Header file for controller of classdiagramview.cpp
 */

#ifndef CLASSDIAGRAMVIEW_H
#define CLASSDIAGRAMVIEW_H

#include "qgraphicsscene.h"
#include "qtabwidget.h"
#include <QTabWidget>
#include <QPushButton>
#include <iostream>

#include <QtCore>
#include <QtGui>
#include <QCursor>

// include the objects which will be drawn on canvas

#include "../diagraminterface.h"
#include "relationgui.h"

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

    /**
     * @brief parseFile - function parsing file of existing diagram (if set)
     */
    void parseFile();

    /**
     * @brief createSequenceDiagramTab
     * @param sequenceDiagram
     * @return pointer to the interface for newly created sequence diagram
     */
    SequenceDiagramInterface *createSequenceDiagramTab(SequenceDiagram &sequenceDiagram);

    explicit ClassDiagramView(QWidget *parent = nullptr);

    ~ClassDiagramView();

private slots:
    /**
     * @brief on_btnClose_clicked - handling all closing events
     * starting saving the class diagram
     */
    void on_btnClose_clicked();

    /**
     * @brief on_btnAddObject_clicked
     */
    void on_btnAddObject_clicked();

    /**
     * @brief on_btnCreateNewSequenceDiagram_clicked
     */
    void on_btnCreateNewSequenceDiagram_clicked();

    void on_btnSave_clicked();

    void on_btnUndo_clicked();

private:
    Ui::ClassDiagramView *ui;

    /**
     * @brief scene - on which objects and relations are drawing for the current class diagram
     */
    QGraphicsScene *scene;

    /**
     * @brief diagramInterface
     * pointer to all objects and information necessary for class diagram and sequence diagram
     * concerning their inner and gui representation
     */
    DiagramInterface *diagramInterface;

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
