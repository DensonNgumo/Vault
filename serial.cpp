#include "serial.h"
#include <QtSql>

Serial::Serial()
{
}
void Serial::addEntry(QString newTitle, QString newKey, QString newNotes,QString gID, QString id)
{
    //Validation Required!!!!

    title=newTitle;key=newKey;notes=newNotes;dbID=id;groupID=gID;
    QSqlQuery entry;
    entry.prepare("insert into serials(title,serialKey,dbID,notes,groupID) values('"+title+"','"+key+"','"+dbID+"','"+notes+"','"+groupID+"')");
    if(entry.exec())
    {
        qDebug()<<"Serial entry added...";

    }
    else
    {
        qDebug()<<"Serial entry not added"<<entry.lastError().text();
    }
}
void Serial::editEntry(QString newTitle, QString newKey,QString newNotes, QString id)
{
    //validation required!!!!!!
    title=newTitle; key=newKey;notes=newNotes;keyID=id;
    QSqlQuery edit;
    edit.prepare("update serials set title='"+title+"',serialKey='"+key+"',notes='"+notes+"' where keyID='"+keyID+"'");
    if(edit.exec())
    {
        qDebug()<<"Serial Key Entry edited...";
    }
    else
    {
        qDebug()<<"Serial Key Entry not edited..."<<edit.lastError().text();
    }
}
