#include "addmessagedialog.h"
#include "ui_addmessagedialog.h"

AddMessageDialog::AddMessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMessageDialog)
{
    ui->setupUi(this);
}

void AddMessageDialog::init(UMLSeqClass * umlSeqClass, SequenceDiagramInterface * seqDiagInterface){
    this->umlSeqClassSender = umlSeqClass;
    this->seqDiagInterface = seqDiagInterface;

    //load cmbReceiver with all possible classes
    foreach(SequenceObjectGUI *seqObjGui, seqDiagInterface->sequenceObjectGUIList){
        ui->cmbMessageReceiver->addItem(seqObjGui->objectName);
    }
}

AddMessageDialog::~AddMessageDialog()
{
    delete ui;
}

void AddMessageDialog::on_buttonBox_accepted()
{
    this->dataValid = dataValid;
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
            //load operations
            //get class of object which receiving the message -> firstly check whether it exists
            if (!seqObjGui->umlClassExists) return;

            //no there is certainity of filling the combobox with new operations related to currently selected class
            ui->cmbMessageOperation->clear(); //clear the combobox

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

