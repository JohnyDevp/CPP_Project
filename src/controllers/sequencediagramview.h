#ifndef SEQUENCEDIAGRAMVIEW_H
#define SEQUENCEDIAGRAMVIEW_H

#include "qtabwidget.h"
#include <QWidget>

namespace Ui {
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
     */
    void init(QTabWidget *tabPane);

private slots:
    void on_btnClose_clicked();

private:
    Ui::SequenceDiagramView *ui;
};

#endif // SEQUENCEDIAGRAMVIEW_H
