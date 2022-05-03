#ifndef EDITRELATIONDIALOG_H
#define EDITRELATIONDIALOG_H

#include "cls/UMLRelation.hpp"
#include <QDialog>

namespace Ui {
class EditRelationDialog;
}

class EditRelationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditRelationDialog(QWidget *parent = nullptr);
    ~EditRelationDialog();

    void init(UMLRelation * umlRelation);
    UMLRelation * getUpdatedUmlRelation();

private slots:
    void on_btnSetRelationName_clicked();

    void on_btnSetCardinalityEnd_clicked();

    void on_btnSetCardinalityStart_clicked();

    void on_btnRemoveRelation_clicked();

private:
    Ui::EditRelationDialog *ui;

    UMLRelation * umlRelation;
};

#endif // EDITRELATIONDIALOG_H
