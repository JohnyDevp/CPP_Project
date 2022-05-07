#ifndef ADDMESSAGEDIALOG_H
#define ADDMESSAGEDIALOG_H

#include "cls/UMLSeqClass.hpp"
#include "sequencediagraminterface.h"
#include <QDialog>

namespace Ui {
class AddMessageDialog;
}

class AddMessageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMessageDialog(QWidget *parent = nullptr);
    ~AddMessageDialog();

    /**
     * @brief dataValid determines whether the data, got from dialog, are valid or not
     */
    bool dataValid = false;

    void init(SequenceObjectGUI * seqObjGuiSender, SequenceDiagramInterface * seqDiagInterface);


    Message getCreatedMessage();
private slots:
    void on_buttonBox_accepted();

    void on_cmbMessageReceiver_currentTextChanged(const QString &arg1);

    void on_checkBoxReturnMessage_toggled(bool checked);

    void on_cmbMessageOperation_currentTextChanged(const QString &arg1);

private:
    Ui::AddMessageDialog *ui;

    Message createdMessage;

    SequenceObjectGUI * seqObjGuiSender;
    SequenceObjectGUI * seqObjGuiReceiver;

    SequenceDiagramInterface * seqDiagInterface;

    QMap<UMLOperation, QString> cmbOperationList;
};

#endif // ADDMESSAGEDIALOG_H
