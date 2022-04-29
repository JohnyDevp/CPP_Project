#include <QDialog>
#include <QString>

class SimpleDialog : public QDialog
{
private:
    /* data */
public:
    QString title;
    QString decription;

    void accept();
    void reject();

    SimpleDialog(QString title, QString description);
    ~SimpleDialog();
};
