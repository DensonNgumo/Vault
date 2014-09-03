#include "changemasterkeyform.h"
#include "ui_changemasterkeyform.h"
#include <QtSql>
#include <QMessageBox>

ChangeMasterKeyForm::ChangeMasterKeyForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeMasterKeyForm),passwordVisible(false)
{
    ui->setupUi(this);
}

ChangeMasterKeyForm::~ChangeMasterKeyForm()
{
    delete ui;
}
void ChangeMasterKeyForm::SetDbID(QString id)
{
    dbID=id;
}

void ChangeMasterKeyForm::on_buttonBox_Response_accepted()
{
    QString masterPass=ui->lineEdit_MasterPass->text(),repeatPass=ui->lineEdit_Repeat->text();
    //Validate if the correct password has been entered
    if(!passwordVisible)
    {
        if(masterPass!=repeatPass)
        {
            QMessageBox::warning(this,tr("Change Master Key"),tr("Make sure that the two passwords match..."));
            return;
        }
    }
    QSqlQuery change;
    change.prepare("update databases set masterKey=HASHBYTES('sha1','"+masterPass+"') where dbID='"+dbID+"'");
    if(change.exec())
    {
        qDebug()<<"Password changed...";
        QMessageBox::information(this,tr("Change Master Key"),tr("Password has been successfully changed..."));
        //password changed
        this->close();
    }
    else
    {
        qDebug()<<change.lastError().text();
    }

}

void ChangeMasterKeyForm::on_buttonBox_Response_rejected()
{
    this->close();
}


void ChangeMasterKeyForm::on_toolButton_Visible_clicked()
{
    //when triggered will allow the user to see the characters being entered
    if(passwordVisible)
    {
        ui->lineEdit_MasterPass->setEchoMode(QLineEdit::EchoMode::Password);
        ui->lineEdit_Repeat->setEnabled(true);
        passwordVisible=false;
    }
    else//will hide the characters from the user
    {
        ui->lineEdit_Repeat->setEnabled(false);
        ui->lineEdit_MasterPass->setEchoMode(QLineEdit::EchoMode::Normal);
        passwordVisible=true;

    }
}
