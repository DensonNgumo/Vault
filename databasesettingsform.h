#ifndef DATABASESETTINGSFORM_H
#define DATABASESETTINGSFORM_H

#include <QDialog>

namespace Ui {
class DatabaseSettingsForm;
}

class DatabaseSettingsForm : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseSettingsForm(QWidget *parent = 0);
    ~DatabaseSettingsForm();

private:
    Ui::DatabaseSettingsForm *ui;
};

#endif // DATABASESETTINGSFORM_H
