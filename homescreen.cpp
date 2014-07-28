#include "homescreen.h"
#include "ui_homescreen.h"
#include"masterpasswordform.h"
#include"opendatabaseform.h"
#include "newentryform.h"
#include "database.h"
#include "changemasterkeyform.h"
#include "groups.h"
#include <QMessageBox>
#include <QtSql>

HomeScreen::HomeScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeScreen)
{
    ui->setupUi(this);
    currentDbName="None";
    ui->treeWidget_groups->setColumnCount(1);
    ui->treeWidget_groups->setHeaderLabel("Groups");

}

HomeScreen::~HomeScreen()
{
    delete ui;
}
void HomeScreen::setDatabaseID(QString id)
{
  currentDbID=id;

}
void HomeScreen::setDatabaseName(QString name)
{
    currentDbName=name;

    AddRoot(currentDbName);


    qDebug()<<currentDbName;
}
void HomeScreen::AddRoot(QString name)
{
    QTreeWidgetItem *group=new QTreeWidgetItem(ui->treeWidget_groups);
    group->setText(0,name);
    QSqlQuery getGroups;
    getGroups.prepare("select groupName from groups where dbID='"+currentDbID+"'");
    if(getGroups.exec())
    {
        while(getGroups.next())
        {
            AddChild(group,getGroups.value(0).toString());
        }
    }
    root=group;

}


void HomeScreen::AddChild(QTreeWidgetItem *parent,QString name)
{
    QTreeWidgetItem *child=new QTreeWidgetItem();
    child->setText(0,name);
    parent->addChild(child);
}
void HomeScreen::RemoveRoot()
{
   // QTreeWidgetItem *group=new QTreeWidgetItem(ui->treeWidget_groups);
  //  group->removeChild(root);
    ui->treeWidget_groups->clear();
}

QString HomeScreen::getDatabaseID()
{
    return currentDbID;
}

void HomeScreen::loadPasswords(QString id)
{
    QSqlQuery loadPass;
    QSqlQueryModel *load=new QSqlQueryModel();
    loadPass.prepare("select title,userName,password,notes,url,creationTime from passwords where dbID='"+id+"'");
    loadPass.exec();
    load->setQuery(loadPass);
    load->setHeaderData(0,Qt::Horizontal,QObject::tr("Title"));
    load->setHeaderData(1,Qt::Horizontal,QObject::tr("User Name"));
    load->setHeaderData(2,Qt::Horizontal,QObject::tr("Password"));
    load->setHeaderData(3,Qt::Horizontal,QObject::tr("Notes"));
    load->setHeaderData(4,Qt::Horizontal,QObject::tr("URL"));
    load->setHeaderData(5,Qt::Horizontal,QObject::tr("Creation Time"));


    ui->tableView_info->setModel(load);

}
void HomeScreen::on_actionNew_Database_triggered()
{
    MasterPasswordForm masterForm;
    masterForm.setMainFormReference(this);
    masterForm.exec();
    masterForm.setModal(true);
}

void HomeScreen::on_actionOpen_Database_triggered()
{

    OpenDatabaseForm openDB;
    openDB.setMainFormReference(this);
    openDB.setModal(true);
    openDB.exec();

    loadPasswords(currentDbID);
}

void HomeScreen::on_actionEdit_View_Entry_triggered()
{

}

void HomeScreen::on_actionAdd_New_Entry_triggered()
{
    NewEntryForm entry;
    entry.setDatabaseID(currentDbID);
    entry.setModal(true);
    entry.exec();
}

void HomeScreen::on_actionExit_triggered()
{
    Database database;
    database.connectionClose();
    QMessageBox::information(this,tr("Vault"),tr("Thank you for using Vault Password Safe"));
    exit(0);
}

void HomeScreen::on_actionChange_Master_Key_triggered()
{
    if(currentDbName=="None")
    {
        QMessageBox::information(this,tr("Change Master Key"),tr("No database opened..."));
    }
    else
    {
        ChangeMasterKeyForm form;
        form.SetDbID(currentDbID);
        form.exec();
    }
}

void HomeScreen::on_actionAdd_Group_triggered()
{
    Groups newGroup;
    newGroup.setDbID(currentDbID);
    newGroup.exec();
}
