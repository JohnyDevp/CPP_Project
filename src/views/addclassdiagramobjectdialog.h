/**
 * @file addclassdiagramobjectdialog.h
 * @author xholan11
 * @brief Header file for addclassdiagramobjectdialog.cpp
 * @date 2022-05-02
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ADDCLASSDIAGRAMOBJECTDIALOG_H
#define ADDCLASSDIAGRAMOBJECTDIALOG_H

#include <QDialog>

namespace Ui
{
    class AddClassDiagramObjectDialog;
}

class AddClassDiagramObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClassDiagramObjectDialog(QWidget *parent = nullptr);
    ~AddClassDiagramObjectDialog();

    QString getObjectName();
    bool getIsInterface();
    bool isValid = false;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddClassDiagramObjectDialog *ui;
};

#endif // ADDCLASSDIAGRAMOBJECTDIALOG_H
