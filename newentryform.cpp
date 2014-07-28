#include "newentryform.h"
#include "ui_newentryform.h"
#include "password.h"
#include "serial.h"

NewEntryForm::NewEntryForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEntryForm)
{
    ui->setupUi(this);
}

NewEntryForm::~NewEntryForm()
{
    delete ui;
}
void NewEntryForm::setDatabaseID(QString id)
{
    databaseID=id;
}


void NewEntryForm::on_buttonBox_response_accepted()
{
    qDebug()<<"Hello";
    //Validate!!!!!!!!!!
   // Password addEntry;
    //addEntry.addNewEntry(ui->lineEdit_passwordTitle->text(),ui->lineEdit_userName->text(),ui->lineEdit_password->text(),ui->lineEdit_notes->text(),ui->lineEdit_url->text(),databaseID);
}
