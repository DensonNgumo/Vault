#include "masterpasswordform.h"
#include "ui_masterpasswordform.h"
#include"databasesettingsform.h"

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
HomeScreen* MasterPasswordForm::getMainFormReference()
{
    return mainForm;
}
void MasterPasswordForm::setMainFormReference(HomeScreen *main)
{
    mainForm=main;
}
void MasterPasswordForm::on_buttonBox_Response_accepted()
{
    DatabaseSettingsForm settings;
    settings.setMasterKey(ui->lineEdit_masterPass->text());
    settings.setMainFormReference(getMainFormReference());
    this->hide();
    settings.exec();
}
