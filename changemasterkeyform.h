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
    ~ChangeMasterKeyForm();

private:
    Ui::ChangeMasterKeyForm *ui;
};

#endif // CHANGEMASTERKEYFORM_H
