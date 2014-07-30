#include "homescreen.h"
#include <QApplication>
#include"database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeScreen w;
    Database *database=new Database();
    database->connectionOpen();
    w.setDatabaseReference(database);
    w.show();

    return a.exec();
}
