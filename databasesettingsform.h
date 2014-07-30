#ifndef DATABASESETTINGSFORM_H
#define DATABASESETTINGSFORM_H

#include <QDialog>
#include"database.h"
#include"homescreen.h"

namespace Ui {
class DatabaseSettingsForm;
}

class DatabaseSettingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseSettingsForm(QWidget *parent = 0);
    void setMasterKey(QString key);
    void setMainFormReference(HomeScreen* mainForm);
    void setEdit(QString id);
    ~DatabaseSettingsForm();

private slots:
    void on_buttonBox_Response_accepted();

private:
    Ui::DatabaseSettingsForm *ui;
    Database newDatabase;
    HomeScreen* main;
    bool edit;
    QString dbID;
};

#endif // DATABASESETTINGSFORM_H
