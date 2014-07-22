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
