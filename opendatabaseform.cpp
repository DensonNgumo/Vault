#include "opendatabaseform.h"
#include "ui_opendatabaseform.h"
#include <QtSql>
#include <QMessageBox>

OpenDatabaseForm::OpenDatabaseForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDatabaseForm)
{
    ui->setupUi(this);
    QSqlQuery load;
    QSqlQueryModel *dbCombo=new QSqlQueryModel();
    load.prepare("select dbName from databases");
    load.exec();
    dbCombo->setQuery(load);
    ui->comboBox_dbNames->setModel(dbCombo);
    locked=false;
}

OpenDatabaseForm::~OpenDatabaseForm()
{
    delete ui;
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
    if(locked)
    {
        int count;
        QSqlQuery open;
        open.prepare("select count(*) from databases where dbID='"+dbID+"' and masterKey=HASHBYTES('sha1','"+ui->lineEdit_masterPass->text()+"')");
        if(open.exec())
          {
             while(open.next())
             {
                 count=open.value(0).toInt();
                 qDebug()<<QString::number(count)<<dbID;

             }
             if(count==1)
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
    else
    {
        main->RemoveRoot();
        QSqlQuery open;
        open.prepare("select dbID from databases where dbName='"+ui->comboBox_dbNames->currentText()+"' and masterKey=HASHBYTES('sha1','"+ui->lineEdit_masterPass->text()+"')");
        if(open.exec())
          {
             while(open.next())
             {
                main->setDatabaseID(open.value(0).toString());
                main->setDatabaseName(ui->comboBox_dbNames->currentText());
                main->UnlockWorkspace();

             }
              this->close();
          }
         else
          {
             qDebug()<<open.lastError().text();
          }
    }

}
