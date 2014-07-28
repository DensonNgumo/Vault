#ifndef SERIAL_H
#define SERIAL_H
#include<QtCore>
#include<QtGui>

class Serial
{
public:
    Serial();
    void addEntry(QString newTitle,QString newKey,QString newNotes,QString id);
private:
    QString title;
    QString key;
    QString notes;
    QString dbID;

};

#endif // SERIAL_H
