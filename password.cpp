#include "password.h"
#include <QtSql>

Password::Password():characters("*****")
{
}
void Password::addNewEntry(QString newTitle, QString newUserName, QString newPassword, QString newNotes, QString newURL,QString gID, QString id)
{
    //validation required!!!!!!
    title=newTitle; userName=newUserName; password=newPassword; notes=newNotes; url=newURL;dbID=id;groupID=gID;

    QSqlQuery add;
    add.prepare("insert into passwords(title,userName,password,notes,url,dbID,groupID,creationTime,modificationTime,hide)"
                "values('"+title+"','"+userName+"','"+password+"','"+notes+"','"+url+"','"+dbID+"','"+groupID+"',GETDATE(),GETDATE(),'"+characters+"')");
    if(add.exec())
        qDebug()<<"Password Entry added...";
    else
        qDebug()<<"Password Entry not added..."<<add.lastError().text();
}
void Password::editEntry(QString newTitle, QString newUserName, QString newPassword, QString newNotes, QString newURL, QString id)
{
    //validation required!!!!!!
    title=newTitle; userName=newUserName; password=newPassword; notes=newNotes; url=newURL;passID=id;
    QSqlQuery edit;
    edit.prepare("update passwords set title='"+title+"',userName='"+userName+"',password='"+password+"',notes='"+notes+"',url='"+url+"',modificationTime=GETDATE() where passID='"+id+"'");
    if(edit.exec())
    {
        qDebug()<<"Password Entry edited...";
    }
    else
    {
        qDebug()<<"Password Entry not edited..."<<edit.lastError().text();
    }
}
