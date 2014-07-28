#include "changemasterkeyform.h"
#include "ui_changemasterkeyform.h"
#include <QtSql>

ChangeMasterKeyForm::ChangeMasterKeyForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeMasterKeyForm)
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
    //Validation!!!!!!!!!
    QSqlQuery change;
    change.prepare("update databases set masterKey=HASHBYTES('sha1','"+ui->lineEdit_MasterPass->text()+"') where dbID='"+dbID+"'");
    if(change.exec())
    {
        qDebug()<<"Password changed...";
    }
    else
    {
        qDebug()<<change.lastError().text();
    }

}
