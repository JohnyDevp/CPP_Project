#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

/**
 * @brief The InfoDialog class
 * handling the showing info about this app
 */
class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

private:
    Ui::InfoDialog *ui;
};

#endif // INFODIALOG_H
