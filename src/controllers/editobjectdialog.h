#ifndef EDITOBJECTDIALOG_H
#define EDITOBJECTDIALOG_H

#include "diagraminterface.h"
#include <QDialog>

namespace Ui {
class EditObjectDialog;
}

class EditObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditObjectDialog(QWidget *parent = nullptr);
    ~EditObjectDialog();

    void init(DiagramInterface * diagramInterface, UMLClass * umlObject);
    UMLClass * getUpdatedUmlObject();

private slots:
    void on_btnRenameObject_clicked();

    void on_btnRemoveObject_clicked();

private:
    Ui::EditObjectDialog *ui;

    /**
     * @brief diagramInterface
     */
    DiagramInterface * diagramInterface;

    /**
     * @brief umlClass
     */
    UMLClass * umlClass;
};

#endif // EDITOBJECTDIALOG_H
