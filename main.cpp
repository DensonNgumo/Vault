#include "homescreen.h"
#include <QApplication>
#include"database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeScreen w;
    w.dbPtr->connectionOpen();//connect to database
    w.show();//display MainForm
    return a.exec();

}
