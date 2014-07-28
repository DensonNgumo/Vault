#ifndef NEWENTRYFORM_H
#define NEWENTRYFORM_H

#include <QDialog>

namespace Ui {
class NewEntryForm;
}

class NewEntryForm : public QDialog
{
    Q_OBJECT

public:
    explicit NewEntryForm(QWidget *parent = 0);
    void setDatabaseID(QString id);
    ~NewEntryForm();

private slots:

    void on_buttonBox_response_accepted();

private:
    Ui::NewEntryForm *ui;
    QString databaseID;
};

#endif // NEWENTRYFORM_H
