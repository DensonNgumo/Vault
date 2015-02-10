#ifndef NEWENTRYFORM_H
#define NEWENTRYFORM_H

#include <QDialog>
#include "homescreen.h"

namespace Ui {
class NewEntryForm;
}

class NewEntryForm : public QDialog
{
    Q_OBJECT

public:
    explicit NewEntryForm(QWidget *parent = 0);
    void setDatabaseID(QString id);
    void setGroupID(QString);
    void setMainFormReference(HomeScreen*);
    void setEditFeatures(QString id);
    void setKeyEditFeatures(QString id);
    void setTempPassword(QString);
    void setTempUserName(QString);


    ~NewEntryForm();

private slots:

    void on_buttonBox_response_accepted();

    void on_buttonBox_keyResponse_accepted();

    void on_buttonBox_response_rejected();

    void on_buttonBox_keyResponse_rejected();



    void on_toolButton_passwordVisible_clicked();

    void on_toolButton_generatePassword_clicked();

private:
    Ui::NewEntryForm *ui;
    QString databaseID;
    QString groupID;
    QString passID;
    QString keyID;
    HomeScreen* main;
    bool edit;
    bool keyEdit;
    bool passwordVisible;

};

#endif // NEWENTRYFORM_H
