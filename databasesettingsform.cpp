#include "databasesettingsform.h"
#include "ui_databasesettingsform.h"

DatabaseSettingsForm::DatabaseSettingsForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseSettingsForm)
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

void DatabaseSettingsForm::on_buttonBox_Response_accepted()
{
    newDatabase.SetDbName(ui->lineEdit_dbName->text());
    newDatabase.SetDescription(ui->lineEdit_description->text());
    newDatabase.SetUserName(ui->lineEdit_userName->text());
    newDatabase.SaveSettings();
    main->setDatabaseID(newDatabase.getDbID());
    main->setDatabaseName(newDatabase.getDbName());

}
