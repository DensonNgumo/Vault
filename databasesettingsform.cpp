#include "databasesettingsform.h"
#include "ui_databasesettingsform.h"
#include <QMessageBox>

DatabaseSettingsForm::DatabaseSettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseSettingsForm),edit(false)
{
    ui->setupUi(this);
}

DatabaseSettingsForm::~DatabaseSettingsForm()
{
    delete ui;
}
void DatabaseSettingsForm::setMasterKey(QString key)
{
    newDatabase.SetMasterKey(key);
}
void DatabaseSettingsForm::setMainFormReference(HomeScreen *mainForm)
{
    main=mainForm;
}
void DatabaseSettingsForm::setEdit(QString id)
{
    edit=true;
    dbID=id;
}

void DatabaseSettingsForm::on_buttonBox_Response_accepted()
{
    QString dbName,dbDescription,dbUserName;
    dbName=ui->lineEdit_dbName->text();
    dbDescription=ui->lineEdit_description->text();
    dbUserName=ui->lineEdit_userName->text();
    if(edit)//changing details of currently open database
    {
        main->RemoveRoot();
        newDatabase.SetDbName(dbName);
        newDatabase.SetDescription(dbDescription);
        newDatabase.SetUserName(dbUserName);
        newDatabase.SetDbID(dbID);
        newDatabase.EditSettings();
        main->setDatabaseName(newDatabase.getDbName());
        this->close();
    }
    else//entering details for a new database
    {
       //Make sure the database has a unique name
        QSqlQuery check;
        check.exec("select count(*) from databases where dbName='"+dbName+"'");
        check.next();
        int count=check.value(0).toInt();
        if(count>0)
        {
            QMessageBox::warning(this,tr("Database Name"),tr("A database with that name already exists, would you please user another name"));
            return;
        }
        newDatabase.SetDbName(dbName);
        newDatabase.SetDescription(dbDescription);
        newDatabase.SetUserName(dbUserName);
        newDatabase.SaveSettings();
        main->setDatabaseID(newDatabase.getDbID());
        main->setDatabaseName(newDatabase.getDbName());
        main->UnlockWorkspace();
        this->close();
    }
}

void DatabaseSettingsForm::on_buttonBox_Response_rejected()
{
    this->close();
}
