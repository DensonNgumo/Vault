#include "opendatabaseform.h"
#include "ui_opendatabaseform.h"
#include <QtSql>

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
}

OpenDatabaseForm::~OpenDatabaseForm()
{
    delete ui;
}
void OpenDatabaseForm::setMainFormReference(HomeScreen *mainForm)
{
    main=mainForm;
}
void OpenDatabaseForm::on_pushButton_open_clicked()
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
         }
          this->hide();
      }
     else
      {
         qDebug()<<open.lastError().text();
      }
}
