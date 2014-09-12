#include "groups.h"
#include "ui_groups.h"
#include "homescreen.h"
#include <QMessageBox>

Groups::Groups(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Groups),edit(false)
{
    ui->setupUi(this);
}

Groups::~Groups()
{
    delete ui;
    main=0;
    delete main;
}
void Groups::setGroupID(QString id)
{
    groupID=id;
}
void Groups::setDbID(QString id)
{
    dbID=id;
}

void Groups::setMainFormReference(HomeScreen * ref)
{
    main=ref;
}
void Groups::setEditFeatures(QString name, QString id)
{
    dbID=id;
    ui->label_Heading->setText("\t\t Edit Group");
    edit=true;
    QString notes;
    QSqlQuery getGroupID;
    getGroupID.prepare("select groupID,Notes from groups where groupName='"+name+"' and dbID='"+dbID+"'");
    if(getGroupID.exec())
    {
        while(getGroupID.next())
        {
            groupID=getGroupID.value(0).toString();
            notes=getGroupID.value(1).toString();
        }
    }
    else
    {
        qDebug()<<getGroupID.lastError().text();
    }
    ui->lineEdit_Name->setText(name);
    ui->plainTextEdit_Notes->setPlainText(notes);
}

void Groups::on_buttonBox_Response_accepted()
{
    QString groupName=ui->lineEdit_Name->text();
    if(groupName.isEmpty())
    {
        QMessageBox::warning(this,tr("Groups"),tr("Please enter the name of the group..."));
        return;
    }
    QString notes=ui->plainTextEdit_Notes->toPlainText();
    QSqlQuery save;
    if(edit)//if editing an existent group
    {
        save.prepare("update groups set groupName='"+groupName+"',Notes='"+notes+"' where groupID='"+groupID+"'");
        if(save.exec())
        {                 
                qDebug()<<"Group Edited...";
                main->RefreshTree();
                this->close();
        }
        else
        {
            qDebug()<<save.lastError().text();
        }
    }
    else//creating a new group
    {
        QSqlQuery check;//check if there is already a group with a similar name in that database
        check.prepare("select count(*) from groups where groupName='"+groupName+"' and dbID='"+dbID+"'");
        if(check.exec())
        {
            int count;
            while(check.next())
            {
               count=check.value(0).toInt();
            }
            if(count>0)
            {
                QMessageBox::warning(this,tr("Groups"),tr("A Group with that name already exists..."));
                return;
            }

        }
        else
           { qDebug()<<check.lastError().text(); return;}
        save.prepare("insert into groups(groupName,dbID,Notes)values('"+groupName+"','"+dbID+"','"+notes+"')");
        if(save.exec())
        {
            qDebug()<<"Group Added...";
            main->RefreshTree();
            this->close();
        }
        else
        {
            qDebug()<<save.lastError().text();
        }
        qDebug()<<notes;
    }

}

void Groups::on_buttonBox_Response_rejected()
{
    this->close();
}
