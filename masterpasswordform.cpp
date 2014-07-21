#include "masterpasswordform.h"
#include "ui_masterpasswordform.h"

MasterPasswordForm::MasterPasswordForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MasterPasswordForm)
{
    ui->setupUi(this);
}

MasterPasswordForm::~MasterPasswordForm()
{
    delete ui;
}
