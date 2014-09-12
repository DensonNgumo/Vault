#ifndef PASSWORD_H
#define PASSWORD_H
#include <QtCore>
#include<QtGui>

class Password
{
public:
    Password();
     void addNewEntry(QString newTitle,QString newUserName,QString newPassword,QString newNotes,QString newURL,QString gID,QString id);
     void editEntry(QString newTitle,QString newUserName,QString newPassword,QString newNotes,QString newURL,QString id);
private:
     QString title;
     QString userName;
     QString password;
     QString notes;
     QString url;
     QString dbID;
     QString groupID;
     QString passID;
     QString characters;
};

#endif // PASSWORD_H
