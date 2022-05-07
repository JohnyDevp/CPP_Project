#include "addmessagedialog.h"
#include "ui_addmessagedialog.h"

AddMessageDialog::AddMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMessageDialog)
{
    ui->setupUi(this);
}

void AddMessageDialog::init(SequenceObjectGUI * seqObjGuiSender, SequenceDiagramInterface * seqDiagInterface){
    this->seqObjGuiSender = seqObjGuiSender;
    this->seqDiagInterface = seqDiagInterface;

    //load cmbReceiver with all possible classes
    foreach(SequenceObjectGUI *seqObjGui, seqDiagInterface->sequenceObjectGUIList){
        ui->cmbMessageReceiver->addItem(seqObjGui->objectName);
    }

    //load message types to cmbbox
    QStringList typeList;
    typeList << "SYNC" << "ASYNC" << "CREATE" << "DESTROY";
    ui->cmbMessageType->addItems(typeList);

}

AddMessageDialog::~AddMessageDialog()
{
    delete ui;
}

void AddMessageDialog::on_buttonBox_accepted()
{
    //build a message

    QString messageReceiver = ui->cmbMessageReceiver->currentText();
    QString messageOperation = ui->cmbMessageOperation->currentText();
    bool messageIsOnlyReturn = ui->checkBoxReturnMessage->isChecked();
    //bool addReturnedMessage = ui->checkBoxAddReturnMessage->isChecked();
    QString messageType = ui->cmbMessageType->currentText();
    QString messageParams = ui->txtMessageParams->toPlainText();

    Message::MessageType msgType;

    if (messageType == "SYNC") msgType = Message::SYNC;
    if (messageType == "ASYNC") msgType = Message::ASYNC;
    if (messageType == "DESTROY") msgType = Message::DESTROY;
    if (messageType == "CREATE") msgType = Message::CREATE;

    //decide what will be created
    if (messageIsOnlyReturn){
        //create only return message
        Message msg(
                    -1,
                    this->seqObjGuiSender->umlSeqClass.getUniqueName(),
                    this->seqObjGuiReceiver->umlSeqClass.getUniqueName(),
                    "",
                    Message::RETURN
                    );
        msg.returnText = messageParams;
        this->createdMessage = msg;

    } else {
        //create only return message
        Message msg(
                    -1,
                    this->seqObjGuiSender->umlSeqClass.getUniqueName(),
                    this->seqObjGuiReceiver->umlSeqClass.getUniqueName(),
                    messageOperation,
                    msgType
                    );
        msg.argumentText = messageParams;
        this->createdMessage = msg;
    }

    this->dataValid = true;
}

Message AddMessageDialog::getCreatedMessage(){
    return this->createdMessage;
}

void AddMessageDialog::on_cmbMessageReceiver_currentTextChanged(const QString &arg1)
{
    QString chosenClass = arg1;

    //if nothing is chosen, then return
    if (chosenClass.isEmpty()) {
        ui->buttonBox->setEnabled(false);
        return;
    }
    else {ui->buttonBox->setEnabled(true); }

    //find this class and its operation
    foreach(SequenceObjectGUI *seqObjGui, seqDiagInterface->sequenceObjectGUIList){
        if (chosenClass == seqObjGui->objectName){
            //set it as receiver
            this->seqObjGuiReceiver = seqObjGui;
            QString justforfun = seqObjGui->umlSeqClass.getUniqueName();
            //load operations
            //get class of object which receiving the message -> firstly check whether it exists
            if (!seqObjGui->umlClassExists) return;

            //no there is certainity of filling the combobox with new operations related to currently selected class
            ui->cmbMessageOperation->clear(); //clear the combobox
            this->cmbOperationList.clear(); //clear list with loaded operations

            UMLClass umlClass = seqDiagInterface->diagramInterface->getUMLClass(seqObjGui->umlSeqClass.className);
            foreach (UMLOperation umlOperation, umlClass.umlOperationsList)
            {
                // build the operation text
                QString operationText = umlOperation.modifier + umlOperation.name + "(";
                foreach (UMLAttribute operationParam, umlOperation.parameterssOfOperationList)
                {
                    operationText += operationParam.name + ":" + operationParam.type;
                }
                operationText += ") : " + umlOperation.type;

                // add to the map and to the combobox
                this->cmbOperationList.insert(umlOperation, operationText);
                ui->cmbMessageOperation->addItem(operationText);
            }
            break;
        }
    }
}

void AddMessageDialog::on_checkBoxReturnMessage_toggled(bool checked)
{
    //if only RETURN message is added (according to the checkbox)
    // then there cant be other return message and also no operation can be chosen
    if (checked){
        //for adding another return message
        ui->checkBoxAddReturnMessage->setChecked(false);
        ui->checkBoxAddReturnMessage->setEnabled(false);

        ui->cmbMessageOperation->setEnabled(false);

        //for
    } else {
        //for adding another return message
        ui->checkBoxAddReturnMessage->setChecked(false);
        ui->checkBoxAddReturnMessage->setEnabled(true);

        ui->cmbMessageOperation->setEnabled(true);
    }
}


void AddMessageDialog::on_cmbMessageOperation_currentTextChanged(const QString &arg1)
{
    //check whether is there any operation to be choosed
    //if not and if checkbox, saying whether it is returned message or not, is unchecked
    // then disable OK button
    if (ui->cmbMessageOperation->count() == 0 && !ui->checkBoxReturnMessage->isChecked()){
        ui->buttonBox->setEnabled(false);
    }
}

