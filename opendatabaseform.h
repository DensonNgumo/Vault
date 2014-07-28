#ifndef OPENDATABASEFORM_H
#define OPENDATABASEFORM_H

#include <QDialog>
#include "homescreen.h"

namespace Ui {
class OpenDatabaseForm;
}

class OpenDatabaseForm : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDatabaseForm(QWidget *parent = 0);
    void setMainFormReference(HomeScreen* mainForm);
    ~OpenDatabaseForm();

private slots:
    void on_pushButton_open_clicked();

private:
    Ui::OpenDatabaseForm *ui;
    HomeScreen* main;
};

#endif // OPENDATABASEFORM_H
