#include "homescreen.h"
#include <QApplication>
#include"database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeScreen w;
    Database database;
    database.connectionOpen();
    w.show();

    return a.exec();
}
