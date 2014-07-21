#ifndef MASTERPASSWORDFORM_H
#define MASTERPASSWORDFORM_H

#include <QDialog>

namespace Ui {
class MasterPasswordForm;
}

class MasterPasswordForm : public QDialog
{
    Q_OBJECT

public:
    explicit MasterPasswordForm(QWidget *parent = 0);
    ~MasterPasswordForm();

private:
    Ui::MasterPasswordForm *ui;
};

#endif // MASTERPASSWORDFORM_H
