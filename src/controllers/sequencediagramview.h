#ifndef SEQUENCEDIAGRAMVIEW_H
#define SEQUENCEDIAGRAMVIEW_H

#include "qtabwidget.h"
#include <QWidget>
#include "sequencediagraminterface.h"

namespace Ui
{
    class SequenceDiagramView;
}

class SequenceDiagramView : public QWidget
{
    Q_OBJECT

public:
    explicit SequenceDiagramView(QWidget *parent = nullptr);
    ~SequenceDiagramView();

    /**
     * @brief init - initialize this sequence diagram
     * @param tabPane
     * @param tabIndex
     * @param sequenceDiagramInterface
     */
    void init(QTabWidget *tabPane, int tabIndex, SequenceDiagramInterface * sequenceDiagramInterface);

private slots:
    void on_btnClose_clicked();

    void on_btnAddObject_clicked();

private:
    Ui::SequenceDiagramView *ui;

    QGraphicsScene * scene;

    /**
     * @brief tabPane
     */
    QTabWidget * tabPane;

    /**
     * @brief sequenceDiagramInterface
     */
    SequenceDiagramInterface * sequenceDiagramInterface;

    int tabIndex;
};

#endif // SEQUENCEDIAGRAMVIEW_H
