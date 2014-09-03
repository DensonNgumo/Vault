#include "masterpasswordform.h"
#include "ui_masterpasswordform.h"
#include"databasesettingsform.h"
#include <QMessageBox>

MasterPasswordForm::MasterPasswordForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MasterPasswordForm),passwordVisible(false)
{
    ui->setupUi(this);
}

MasterPasswordForm::~MasterPasswordForm()
{
    delete ui;
    mainForm=0;
    delete mainForm;
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
     QString masterKey=ui->lineEdit_masterPass->text(),repeatKey=ui->lineEdit_repeatPass->text();
    //validation
    if(masterKey.isEmpty())
    {
        QMessageBox::warning(this,tr("Master Key"),tr("Please enter the master password..."));
        return;
    }
    if(!passwordVisible)
    {
        if(masterKey!=repeatKey)
        {
            QMessageBox::warning(this,tr("Master Key"),"Make sure both passwords match...");
            return;
        }
    }
    DatabaseSettingsForm settings;//open form for entering the new database's details
    settings.setMasterKey(masterKey);
    settings.setMainFormReference(getMainFormReference());
    this->hide();
    settings.exec();
}

void MasterPasswordForm::on_buttonBox_Response_rejected()
{
    this->close();
}

void MasterPasswordForm::on_pushButton_passwordView_clicked()
{
    if(passwordVisible)
    {
        ui->lineEdit_masterPass->setEchoMode(QLineEdit::EchoMode::Password);
        ui->lineEdit_repeatPass->setEnabled(true);
        passwordVisible=false;
    }
    else
    {
        ui->lineEdit_masterPass->setEchoMode(QLineEdit::EchoMode::Normal);
        ui->lineEdit_repeatPass->setEnabled(false);
        passwordVisible=true;

    }
}
