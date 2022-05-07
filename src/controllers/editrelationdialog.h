/**
 * @file editrelationdialog.h
 * @author xholan11
 * @brief Header file for editrelationdialog.cpp
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef EDITRELATIONDIALOG_H
#define EDITRELATIONDIALOG_H

#include "cls/UMLRelation.hpp"
#include <QDialog>

namespace Ui
{
    class EditRelationDialog;
}

/**
 * @brief The EditRelationDialog class
 * handle edittig relation dialog - when relation is double-clicked
 */
class EditRelationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditRelationDialog(QWidget *parent = nullptr);
    ~EditRelationDialog();

    /**
     * @brief init initializes this function - only setting the currently edditing relation (its intern representation)
     * @param umlRelation
     */
    void init(UMLRelation *umlRelation);
    UMLRelation *getUpdatedUmlRelation();

private slots:
    void on_btnSetRelationName_clicked();

    void on_btnSetCardinalityEnd_clicked();

    void on_btnSetCardinalityStart_clicked();

    void on_btnRemoveRelation_clicked();

private:
    Ui::EditRelationDialog *ui;

    /**
     * @brief umlRelation currently editting relation (its inner representation)
     */
    UMLRelation *umlRelation;
};

#endif // EDITRELATIONDIALOG_H
