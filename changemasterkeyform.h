#ifndef CHANGEMASTERKEYFORM_H
#define CHANGEMASTERKEYFORM_H

#include <QDialog>

namespace Ui {
class ChangeMasterKeyForm;
}

class ChangeMasterKeyForm : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeMasterKeyForm(QWidget *parent = 0);
    void SetDbID(QString);
    ~ChangeMasterKeyForm();

private slots:
    void on_buttonBox_Response_accepted();

    void on_buttonBox_Response_rejected();

private:
    Ui::ChangeMasterKeyForm *ui;
    QString dbID;
};

#endif // CHANGEMASTERKEYFORM_H
