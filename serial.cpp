#include "serial.h"
#include <QtSql>

Serial::Serial()
{
}
void Serial::addEntry(QString newTitle, QString newKey, QString newNotes, QString id)
{
    //Validation Required!!!!

    title=newTitle;key=newKey;notes=newNotes;dbID=id;
    QSqlQuery entry;
    entry.prepare("insert into serials(title,key,dbID,notes) values('"+title+"','"+key+"','"+dbID+"','"+notes+"')");
    if(entry.exec())
    {
        qDebug()<<"Serial entry added...";

    }
    else
    {
        qDebug()<<"Serial entry not added"<<entry.lastError().text();
    }
}
