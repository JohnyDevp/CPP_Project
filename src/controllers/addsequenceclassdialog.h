#ifndef ADDSEQUENCECLASSDIALOG_H
#define ADDSEQUENCECLASSDIALOG_H

#include "cls/UMLSeqClass.hpp"
#include "diagraminterface.h"
#include "sequencediagraminterface.h"
#include <QDialog>

namespace Ui {
class AddSequenceClassDialog;
}

/**
 * @brief The AddSequenceClassDialog class
 * handling creating dialog for choosing the name of instance and the uml class, from which is the instance created
 */
class AddSequenceClassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSequenceClassDialog(QWidget *parent = nullptr);
    ~AddSequenceClassDialog();

    /**
     * @brief dataValid - sets whether the created umlseqclass is valid or not
     */
    bool dataValid = false;

    /**
     * @brief init loads combobox with all possible classes to be added
     * @param seqDiagInterface
     */
    void init(SequenceDiagramInterface *seqDiagInterface);

    /**
     * @brief getUmlSeqClass
     * @return newly created umlSeqClass with the instance of the uml class
     */
    UMLSeqClass getUmlSeqClass();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddSequenceClassDialog *ui;

    SequenceDiagramInterface *seqDiagInterface;

    /**
     * @brief umlSeqClass - newly created umlseqClass
     */
    UMLSeqClass umlSeqClass;
};

#endif // ADDSEQUENCECLASSDIALOG_H
