#include "addmessagedialog.h"
#include "errors.h"
#include "ui_addmessagedialog.h"

AddMessageDialog::AddMessageDialog(QWidget *parent) : QDialog(parent),
                                                      ui(new Ui::AddMessageDialog)
{
    ui->setupUi(this);
}
void AddMessageDialog::init(SequenceObjectGUI *seqObjGuiSender, SequenceDiagramInterface *seqDiagInterface)
{
    this->seqObjGuiSender = seqObjGuiSender;
    this->seqDiagInterface = seqDiagInterface;

    // load cmbReceiver with all possible classes
    foreach (SequenceObjectGUI *seqObjGui, seqDiagInterface->sequenceObjectGUIList)
    {
        ui->cmbMessageReceiver->addItem(seqObjGui->objectName);
    }

    // load message types to cmbbox
    QStringList typeList;
    typeList << "SYNC"
             << "ASYNC"
             << "CREATE"
             << "DESTROY"
             << "RETURN";
    ui->cmbMessageType->addItems(typeList);
}

AddMessageDialog::~AddMessageDialog()
{
    delete ui;
}

void AddMessageDialog::on_buttonBox_accepted()
{
    // build a message

    QString messageReceiver = ui->cmbMessageReceiver->currentText();
    QString messageOperation = ui->cmbMessageOperation->currentText();

    //check for input
    if (
        ((ui->cmbMessageType->currentText() == "SYNC" ||
         ui->cmbMessageType->currentText() == "ASYNC") &&
            !messageOperation.isEmpty())
            ||
        (ui->cmbMessageType->currentText() == "DESTROY" ||
            ui->cmbMessageType->currentText() == "CREATE" ||
            ui->cmbMessageType->currentText() == "RETURN")
            ) { }
    else {Errors().raiseError("Bad input!"); return;}

    //find the UMLOperation for the message
    UMLOperation umlOperation;
    QMapIterator<UMLOperation, QString> i(this->cmbOperationList);
    while (i.hasNext()) {
        i.next();
        if(i.value() == messageOperation){
            umlOperation = i.key();
        }
    }

    //get and transfer message type and get message paramy
    QString messageType = ui->cmbMessageType->currentText();
    QString messageParams = ui->txtMessageParams->toPlainText();

    Message::MessageType msgType;

    if (messageType == "SYNC")
        msgType = Message::SYNC;
    else if (messageType == "ASYNC")
        msgType = Message::ASYNC;
    else if (messageType == "DESTROY")
        msgType = Message::DESTROY;
    else if (messageType == "CREATE")
        msgType = Message::CREATE;
    if (messageType == "RETURN"){
        msgType = Message::RETURN;
    }

    // decide what will be created
    if (messageType == "DESTROY" || messageType == "CREATE" || messageType == "RETURN")
    {
        // create message just with text (empty operation)
        //DESTROY & CREATE & RETURN
        UMLOperation uo("");
        Message msg(
            -1,
            this->seqObjGuiSender->umlSeqClass.getUniqueName(),
            this->seqObjGuiReceiver->umlSeqClass.getUniqueName(),
            uo,
            msgType);
        msg.argumentText = messageParams;
        this->createdMessage = msg;
    }
    else
    {
        //otherwise create message with declared operation
        //SYNC & ASYNC
        Message msg(
            -1,
            this->seqObjGuiSender->umlSeqClass.getUniqueName(),
            this->seqObjGuiReceiver->umlSeqClass.getUniqueName(),
            umlOperation,
            msgType);
        msg.argumentText = messageParams;
        this->createdMessage = msg;
    }

    this->dataValid = true;
}

Message AddMessageDialog::getCreatedMessage()
{
    return this->createdMessage;
}

void AddMessageDialog::on_cmbMessageReceiver_currentTextChanged(const QString &arg1)
{
    QString chosenClass = arg1;

    // if nothing is chosen, then return
    if (chosenClass.isEmpty())
    {
        ui->buttonBox->setEnabled(false);
        return;
    }
    else
    {
        ui->buttonBox->setEnabled(true);
    }

    // find this class and its operation
    foreach (SequenceObjectGUI *seqObjGui, seqDiagInterface->sequenceObjectGUIList)
    {
        if (chosenClass == seqObjGui->objectName)
        {
            // set it as receiver
            this->seqObjGuiReceiver = seqObjGui;
            QString justforfun = seqObjGui->umlSeqClass.getUniqueName();
            // load operations
            // get class of object which receiving the message -> firstly check whether it exists
            if (!seqObjGui->umlClassExists)
                return;

            // now there is certainity of filling the combobox with new operations related to currently selected class
            ui->cmbMessageOperation->clear(); // clear the combobox
            this->cmbOperationList.clear();   // clear list with loaded operations

            UMLClass umlClass = seqDiagInterface->diagramInterface->getUMLClass(seqObjGui->umlSeqClass.className);
            foreach (UMLOperation umlOperation, umlClass.umlOperationsList)
            {
                //check whether the operation is public
                if (umlOperation.modifier != "+") return;

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

