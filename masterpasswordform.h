#ifndef MASTERPASSWORDFORM_H
#define MASTERPASSWORDFORM_H

#include <QDialog>
#include "homescreen.h"

namespace Ui {
class MasterPasswordForm;
}

class MasterPasswordForm : public QDialog
{
    Q_OBJECT

public:
    explicit MasterPasswordForm(QWidget *parent = 0);
    HomeScreen* getMainFormReference();
    void setMainFormReference(HomeScreen* main);

    ~MasterPasswordForm();

private slots:
    void on_buttonBox_Response_accepted();

    void on_buttonBox_Response_rejected();

    void on_pushButton_passwordView_clicked();

private:
    Ui::MasterPasswordForm *ui;
    HomeScreen* mainForm;
    bool passwordVisible;
};

#endif // MASTERPASSWORDFORM_H
