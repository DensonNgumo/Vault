#include "opendatabaseform.h"
#include "ui_opendatabaseform.h"

OpenDatabaseForm::OpenDatabaseForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OpenDatabaseForm)
{
    ui->setupUi(this);
}

OpenDatabaseForm::~OpenDatabaseForm()
{
    delete ui;
}
