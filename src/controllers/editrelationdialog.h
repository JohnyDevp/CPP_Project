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

private:
    Ui::EditRelationDialog *ui;

    UMLRelation * umlRelation;
};

#endif // EDITRELATIONDIALOG_H
