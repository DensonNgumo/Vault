#ifndef SERIAL_H
#define SERIAL_H
#include<QtCore>
#include<QtGui>

class Serial
{
public:
    Serial();
    void addEntry(QString newTitle, QString newKey, QString newNotes, QString gID, QString id);
    void editEntry(QString newTitle, QString newKey, QString newNotes, QString id);
private:
    QString title;
    QString key;
    QString notes;
    QString dbID;
    QString groupID;
    QString keyID;

};

#endif // SERIAL_H
