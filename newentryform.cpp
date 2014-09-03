#include "newentryform.h"
#include "ui_newentryform.h"
#include "password.h"
#include "serial.h"
#include <Qtsql>
#include <QMessageBox>

NewEntryForm::NewEntryForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEntryForm),edit(false),keyEdit(false),passwordVisible(false)
{
    ui->setupUi(this);
}

NewEntryForm::~NewEntryForm()
{
    delete ui;
    main=0;
    delete main;
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
            ui->plainTextEdit_Notes->setPlainText(fill.value(3).toString());
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
    QString title,userName,pass,pass2,notes,url;
    pass=ui->lineEdit_password->text();
    pass2=ui->lineEdit_password2->text();
    if(pass.isEmpty())
    {
        QMessageBox::warning(this,tr("Entry"),tr("Please enter a passsword..."));
        return;
    }
    if(!passwordVisible)
    {
        if(pass!=pass2)
        {
            QMessageBox::warning(this,tr("Entry"),tr("Both passwords must match..."));
            return;
        }
    }
    title=ui->lineEdit_passwordTitle->text();
    userName=ui->lineEdit_userName->text();
    notes=ui->plainTextEdit_Notes->toPlainText();
    url=ui->lineEdit_url->text();
    if(edit)//editing a current password entry
    {
        Password editEntry;
        editEntry.editEntry(title,userName,pass,notes,url,passID);
        main->RefreshPasswords();
        this->close();

    }
    else//adding a new password entry
    {
        Password addEntry;
        addEntry.addNewEntry(title,userName,pass,notes,url,groupID,databaseID);
        main->RefreshPasswords();
        this->close();
    }
}

void NewEntryForm::on_buttonBox_keyResponse_accepted()
{
    QString title,key,notes;    
    key=ui->lineEdit_key->text();
    if(key.isEmpty())
    {
        QMessageBox::warning(this,tr("Entry"),tr("Please enter the key value"));
        return;
    }
    title=ui->lineEdit_keyTitle->text();
    notes=ui->plainTextEdit_keyNotes->toPlainText();

    if(keyEdit)//editing a key entry
    {
        Serial editEntry;
        editEntry.editEntry(title,key,notes,keyID);
        main->RefreshKeys();
        this->close();
    }
    else//adding a new key entry
    {
        Serial addEntry;
        addEntry.addEntry(title,key,notes,groupID,databaseID);
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

void NewEntryForm::on_toolButton_passwordVisible_clicked()
{
    if(passwordVisible)
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Password);
        ui->lineEdit_password2->setEnabled(true);
        passwordVisible=false;
    }
    else
    {
        ui->lineEdit_password->setEchoMode(QLineEdit::EchoMode::Normal);
        ui->lineEdit_password2->setEnabled(false);
        passwordVisible=true;
    }
}
