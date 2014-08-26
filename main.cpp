#include "homescreen.h"
#include <QApplication>
#include"database.h"
#include <memory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeScreen w;
    w.dbPtr->connectionOpen();
    w.show();

    return a.exec();

}
