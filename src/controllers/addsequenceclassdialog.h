#ifndef ADDSEQUENCECLASSDIALOG_H
#define ADDSEQUENCECLASSDIALOG_H

#include "cls/UMLSeqClass.hpp"
#include "diagraminterface.h"
#include "sequencediagraminterface.h"
#include <QDialog>

namespace Ui {
class AddSequenceClassDialog;
}

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

    void init(SequenceDiagramInterface *seqDiagInterface);
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
