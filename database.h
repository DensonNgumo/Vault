#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>



class Database
{
public:
    Database();
    void connectionOpen();
    void connectionClose();
    void SetMasterKey(QString key);
    void SetDbName(QString name);
    void SetDbID(QString);
    void SetDescription(QString text);
    void SetUserName(QString name);
    void SaveSettings();
    void EditSettings();
    void InsertDefaults();
    QString getDbID();
    QString getDbName();
private:
    QSqlDatabase db;
    QString servername;
    QString databaseName;
    QString dsn;

    QString dbName;
    QString masterKey;
    QString description;
    QString userName;
    QString dbID;

};

#endif // DATABASE_H
