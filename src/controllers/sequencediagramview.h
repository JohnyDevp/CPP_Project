/**
 * @file sequencediagramview.h
 * @author xholan11
 * @brief Header file for sequencediagram.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SEQUENCEDIAGRAMVIEW_H
#define SEQUENCEDIAGRAMVIEW_H

#include "qtabwidget.h"
#include <QWidget>
#include "sequencediagraminterface.h"

namespace Ui
{
    class SequenceDiagramView;
}

/**
 * @brief The SequenceDiagramView class
 * controlling initializing of new sequence diagram
 */
class SequenceDiagramView : public QWidget
{
    Q_OBJECT

public:
    explicit SequenceDiagramView(QWidget *parent = nullptr);
    ~SequenceDiagramView();

    /**
     * @brief init - initialize this sequence diagram - set inside this class all these params
     * @param tabPane - stores all opened tabs - for possibility of closing current tab
     * @param tabIndex - index of the tab, where the current sequence diagram is stored
     * @param sequenceDiagramInterface interface for the current sequence diagram
     */
    void init(QTabWidget *tabPane, int tabIndex, SequenceDiagramInterface *sequenceDiagramInterface);

private slots:
    void on_btnClose_clicked();

    void on_btnAddObject_clicked();

private:
    Ui::SequenceDiagramView *ui;

    /**
     * @brief scene newly created scene for the new sequence diagram
     */
    QGraphicsScene *scene;

    /**
     * @brief tabPane - stores all opened tabs - for possibility of closing current tab
     */
    QTabWidget *tabPane;

    /**
     * @brief sequenceDiagramInterface interface for the current sequence diagram
     */
    SequenceDiagramInterface *sequenceDiagramInterface;

    /**
     * @brief tabIndex - index of the tab, where the current sequence diagram is stored
     */
    int tabIndex;
};

#endif // SEQUENCEDIAGRAMVIEW_H
