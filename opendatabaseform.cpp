#include "opendatabaseform.h"
#include "ui_opendatabaseform.h"
#include <QtSql>
#include <QMessageBox>

OpenDatabaseForm::OpenDatabaseForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDatabaseForm),locked(false),passwordVisible(false)
{
    ui->setupUi(this);
    QSqlQuery load;
    QSqlQueryModel *dbCombo=new QSqlQueryModel();
    load.prepare("select dbName from databases");//load all database names to the combobox
    load.exec();
    dbCombo->setQuery(load);
    ui->comboBox_dbNames->setModel(dbCombo);
}

OpenDatabaseForm::~OpenDatabaseForm()
{
    delete ui;
    main=0;
    delete main;
}
void OpenDatabaseForm::setMainFormReference(HomeScreen *mainForm)
{
    main=mainForm;
}
void OpenDatabaseForm::setLockFeatures(QString id)
{
    locked=true;
    ui->label_heading->setText("Unlock Database");
    ui->label_dbName->setHidden(true);
    ui->comboBox_dbNames->setHidden(true);
    dbID=id;
}

void OpenDatabaseForm::on_pushButton_open_clicked()
{
    QString masterKey=ui->lineEdit_masterPass->text();
    if(masterKey.isEmpty())
    {
        QMessageBox::warning(this,tr("Open Database"),tr("Please enter the master password..."));
        return;
    }
    if(locked)//Opening a currently locked database
    {
        int count;
        QSqlQuery open;
        open.prepare("select count(*) from databases where dbID='"+dbID+"' and masterKey=HASHBYTES('sha1','"+masterKey+"')");
        if(open.exec())
          {
             while(open.next())
             {
                 count=open.value(0).toInt();
                 qDebug()<<QString::number(count)<<dbID;

             }
             if(count==1)//if password is correct
             {
                 main->UnlockWorkspace();
                 this->close();
             }
             else
             {
                 QMessageBox::information(this,tr("Lock"),tr("Check password entered..."));
             }

          }
         else
          {
             qDebug()<<open.lastError().text();
          }
    }
    else//opening a new database
    {
        main->RemoveRoot();
        QSqlQuery open;
        QString dbName=ui->comboBox_dbNames->currentText();
        open.prepare("select dbID from databases where dbName='"+dbName+"' and masterKey=HASHBYTES('sha1','"+masterKey+"')");
        if(open.exec())
          {
            int count=0;
             while(open.next())
             {
                count++;
                dbID=open.value(0).toString();

             }
             if(count==1)//if correct password entered
             {
                 main->setDatabaseID(dbID);
                 main->setDatabaseName(dbName);
                 main->UnlockWorkspace();
                 this->close();
             }
             else
             {
                 QMessageBox::warning(this,tr("Open Database"),tr("Check password entered..."));
                 return;
             }

          }
         else
          {
             qDebug()<<open.lastError().text();
          }
    }

}

void OpenDatabaseForm::on_toolButton_passwordVisible_clicked()
{
    if(passwordVisible)
    {
        ui->lineEdit_masterPass->setEchoMode(QLineEdit::EchoMode::Password);
        passwordVisible=false;
    }
    else
    {
        ui->lineEdit_masterPass->setEchoMode(QLineEdit::EchoMode::Normal);
        passwordVisible=true;
    }
}
