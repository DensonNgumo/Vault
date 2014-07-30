#include "database.h"
#include <QDebug>

Database::Database()
{
}
void Database::connectionOpen()
{
    servername="BRANIAC\\BRANIAC";
    databaseName="vault";
    db= QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();

    dsn=QString("DRIVER={SQL Server}; SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(databaseName);
    db.setDatabaseName(dsn);
          if(db.open())
          {
              qDebug()<<"Opened...";



          }
          else
          {
             qDebug()<<"Error="<<db.lastError().text();
          }
}
void Database::connectionClose()
{
    db.close();
   // db.removeDatabase(QSqlDatabase::defaultConnection);
    qDebug()<<"Database closed...";
}
void Database::SetDbID(QString id)
{
    dbID=id;
}

void Database::SetMasterKey(QString key)
{
    masterKey=key;
}
void Database::SetDbName(QString name)
{
    dbName=name;
}
void Database::SetDescription(QString text)
{
    description=text;
}
void Database::SetUserName(QString name)
{
    userName=name;
}
void Database::SaveSettings()
{
    QSqlQuery save;
    save.prepare("insert into databases (dbName,masterKey,description,userName) values('"+dbName+"',HASHBYTES('sha1','"+masterKey+"'),'"+description+"','"+userName+"')");
    if(save.exec())
    {
        qDebug()<<"Saved...";
        InsertDefaults();
    }
    else
    {
        qDebug()<<"Not Saved..."<<save.lastError().text();
    }

}
void Database::EditSettings()
{
    QSqlQuery edit;
    edit.prepare("update databases set dbName='"+dbName+"',description='"+description+"',userName='"+userName+"' where dbID='"+dbID+"'");
    if(edit.exec())
    {
        qDebug()<<"Edited...";

    }
    else
    {
        qDebug()<<"Not Edited..."<<edit.lastError().text();
    }
}

QString Database::getDbID()
{
    QSqlQuery id;
    id.prepare("select dbID from databases where dbName='"+dbName+"'");
    if(id.exec())
    {
        while(id.next())
        {
            dbID=id.value(0).toString();
        }
        return dbID;
    }
    else
        qDebug()<<id.lastError().text();
    return "error";
}
QString Database::getDbName()
{
    return dbName;
}
void Database::InsertDefaults()
{
    QString id=getDbID();
    QString groupID;
    QString defaultGroupName="Default",title="Example",password="12345",userName="User123",url="www.deenze.com",notes="Notes";
    QString defaultKeyTitle="Software Y",key="xxxx-xxxx-xxxx-xxxx-xxxx";
    QSqlQuery groupDefault,passwordDefault,getGroupID,keyDefault;
    groupDefault.prepare("insert into groups(groupName,dbID) values('"+defaultGroupName+"','"+id+"')");
    if(groupDefault.exec()){qDebug()<<"group inserted..";}
    getGroupID.prepare("select groupID from groups where groupName='"+defaultGroupName+"' and dbID='"+id+"'");
    if(getGroupID.exec())
    {
        while(getGroupID.next())
        {
            groupID=getGroupID.value(0).toString();
        }
    }
    else
    {
        qDebug()<<getGroupID.lastError().text();
    }
    passwordDefault.prepare("insert into passwords(dbID,groupID,title,userName,password,notes,url,creationTime,modificationTime)"
                            "values('"+id+"','"+groupID+"','"+title+"','"+userName+"','"+password+"','"+notes+"','"+url+"',GETDATE(),GETDATE())");
    if(passwordDefault.exec())
    {
        qDebug()<<"Password inserted...";
        keyDefault.prepare("insert into serials(dbID,title,serialKey,notes,groupID)values('"+id+"','"+defaultKeyTitle+"','"+key+"','"+notes+"','"+groupID+"')");
        if(keyDefault.exec())
        {
            qDebug()<<"Sample Key inserted...";
        }
        else
        {
            qDebug()<<"Sample Key not added..."<<keyDefault.lastError().text();
        }

    }
    else
    {
        qDebug()<<passwordDefault.lastError().text();
    }

}
