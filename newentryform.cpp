#include "newentryform.h"
#include "ui_newentryform.h"
#include "password.h"
#include "serial.h"
#include <Qtsql>

NewEntryForm::NewEntryForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEntryForm)
{
    ui->setupUi(this);
    edit=false;
    keyEdit=false;
}

NewEntryForm::~NewEntryForm()
{
    delete ui;
}
void NewEntryForm::setDatabaseID(QString id)
{
    databaseID=id;
}
void NewEntryForm::setGroupID(QString name)
{
    QSqlQuery getID;
    getID.prepare("select groupID from groups where groupName='"+name+"' and dbID='"+databaseID+"'");
    if(getID.exec())
    {
        while(getID.next())
        {
            groupID=getID.value(0).toString();
        }
    }
    else
    {
        qDebug()<<getID.lastError().text();
    }
}


void NewEntryForm::setMainFormReference(HomeScreen * ref)
{
    main=ref;
}
void NewEntryForm::setEditFeatures(QString id)
{
    passID=id;
    ui->label_Heading->setText("Edit Entry");
    QSqlQuery fill;
    fill.prepare("select title,userName,password,notes,url from passwords where passID='"+passID+"'");
    if(fill.exec())
    {
        while(fill.next())
        {
            ui->lineEdit_notes->setText(fill.value(3).toString());
            ui->lineEdit_password->setText(fill.value(2).toString());
            ui->lineEdit_passwordTitle->setText(fill.value(0).toString());
            ui->lineEdit_url->setText(fill.value(4).toString());
            ui->lineEdit_userName->setText(fill.value(1).toString());
            ui->tabWidget->setCurrentIndex(0);
        }
        edit=true;
    }
    else
    {
        qDebug()<<fill.lastError().text();
    }
}
void NewEntryForm::setKeyEditFeatures(QString id)
{
    keyID=id;
    ui->label_Heading->setText("Edit Entry");
    QSqlQuery fill;
    fill.prepare("select title,serialKey,notes from serials where keyID='"+keyID+"'");
    if(fill.exec())
    {
        while(fill.next())
        {
           ui->lineEdit_keyTitle->setText(fill.value(0).toString());
           ui->lineEdit_key->setText(fill.value(1).toString());
           ui->plainTextEdit_keyNotes->setPlainText(fill.value(2).toString());

           ui->tabWidget->setCurrentIndex(1);
        }
        keyEdit=true;
    }
    else
    {
        qDebug()<<fill.lastError().text();
    }
}

void NewEntryForm::on_buttonBox_response_accepted()
{  
    if(edit)
    {
        Password editEntry;
        editEntry.editEntry(ui->lineEdit_passwordTitle->text(),ui->lineEdit_userName->text(),ui->lineEdit_password->text(),ui->lineEdit_notes->text(),ui->lineEdit_url->text(),passID);
        main->RefreshPasswords();
        this->close();

    }
    else
    {
        Password addEntry;
        addEntry.addNewEntry(ui->lineEdit_passwordTitle->text(),ui->lineEdit_userName->text(),ui->lineEdit_password->text(),ui->lineEdit_notes->text(),ui->lineEdit_url->text(),groupID,databaseID);
        main->RefreshPasswords();
        this->close();
    }


}

void NewEntryForm::on_buttonBox_keyResponse_accepted()
{
    if(keyEdit)
    {
        Serial editEntry;
        editEntry.editEntry(ui->lineEdit_keyTitle->text(),ui->lineEdit_key->text(),ui->plainTextEdit_keyNotes->toPlainText(),keyID);
        main->RefreshKeys();
        this->close();
    }
    else
    {
        Serial addEntry;
        addEntry.addEntry(ui->lineEdit_keyTitle->text(),ui->lineEdit_key->text(),ui->plainTextEdit_keyNotes->toPlainText(),groupID,databaseID);
        main->RefreshKeys();
        this->close();
    }
}

void NewEntryForm::on_buttonBox_response_rejected()
{
    this->close();
}

void NewEntryForm::on_buttonBox_keyResponse_rejected()
{
    this->close();
}
