#include "password.h"
#include <QtSql>

Password::Password()
{
}
void Password::addNewEntry(QString newTitle, QString newUserName, QString newPassword, QString newNotes, QString newURL, QString id)
{
    //validation required!!!!!!
    title=newTitle; userName=newUserName; password=newPassword; notes=newNotes; url=newURL;dbID=id;


    QSqlQuery add;
    add.prepare("insert into passwords(title,userName,password,notes,url,dbID) values('"+title+"','"+userName+"','"+password+"','"+notes+"','"+url+"','"+dbID+"')");
    if(add.exec())
        qDebug()<<"Password Entry added...";
    else
        qDebug()<<"Password Entry not added..."<<add.lastError().text();
}
