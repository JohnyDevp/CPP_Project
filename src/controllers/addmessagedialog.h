#ifndef ADDMESSAGEDIALOG_H
#define ADDMESSAGEDIALOG_H

#include "cls/UMLSeqClass.hpp"
#include "sequencediagraminterface.h"
#include <QDialog>

namespace Ui
{
    class AddMessageDialog;
}

/**
 * @brief The AddMessageDialog class
 * handles the dialog for editing message in sequence diagram class
 */
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

    /**
     * @brief init - initialize the data into comboboxes and lists
     * @param seqObjGuiSender the object, which has been aactivated
     * @param seqDiagInterface - for later possibility of check whether operation exists, etc.
     */
    void init(SequenceObjectGUI *seqObjGuiSender, SequenceDiagramInterface *seqDiagInterface);

    /**
     * @brief getCreatedMessage
     * @return newly created message object
     */
    Message getCreatedMessage();
private slots:
    void on_buttonBox_accepted();

    void on_cmbMessageReceiver_currentTextChanged(const QString &arg1);

private:
    Ui::AddMessageDialog *ui;

    /**
     * @brief createdMessage represents newly created message
     */
    Message createdMessage;

    /**
     * @brief seqObjGuiSender variables storing objects, which are related to the newly created message
     * for loading operations and getting neccessary information for build the message object
     */
    SequenceObjectGUI *seqObjGuiSender;
    SequenceObjectGUI *seqObjGuiReceiver;

    SequenceDiagramInterface *seqDiagInterface;

    /**
     * @brief cmbOperationList map storing umloperations of the currently chosen object, where the message could be send, and their
     * text representation, which is displayed in the combobox
     */
    QMap<UMLOperation, QString> cmbOperationList;
};

#endif // ADDMESSAGEDIALOG_H
