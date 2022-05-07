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

/**
 * @brief The AddClassDiagramObjectDialog class
 * handles creating new name for new object and setting whether it will be interface or not
 */
class AddClassDiagramObjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddClassDiagramObjectDialog(QWidget *parent = nullptr);
    ~AddClassDiagramObjectDialog();

    /**
     * @brief getObjectName getter
     * @return the new object name for the creatign object
     */
    QString getObjectName();
    /**
     * @brief getIsInterface getter
     * @return true or false accoring to if the checkbox, saying whether the currently creating object is interface or not,
     * is checked or not
     */
    bool getIsInterface();
    /**
     * @brief isValid tells whether the data, which can be get by getters, are valid or not (for example when te window is closed,
     * they are invalid)
     */
    bool isValid = false;

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddClassDiagramObjectDialog *ui;
};

#endif // ADDCLASSDIAGRAMOBJECTDIALOG_H
