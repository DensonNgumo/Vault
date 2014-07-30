#include "groups.h"
#include "ui_groups.h"
#include "homescreen.h"

Groups::Groups(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Groups)
{
    ui->setupUi(this);
    edit=false;
}

Groups::~Groups()
{
    delete ui;
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
    //validate name and id
    dbID=id;
    ui->label_Heading->setText("Edit Group");
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
    //validate!!!!!!!!!
    QString groupName=ui->lineEdit_Name->text();
    QString notes=ui->plainTextEdit_Notes->toPlainText();
    QSqlQuery save;
    if(edit)
    {
        save.prepare("update groups set groupName='"+groupName+"' where groupID='"+groupID+"'");
        if(save.exec())
        {
            save.prepare("update groups set Notes='"+notes+"' where groupID='"+groupID+"'");
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
        else
        {
            qDebug()<<save.lastError().text();
        }

    }
    else
    {
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
