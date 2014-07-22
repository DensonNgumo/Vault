#ifndef OPENDATABASEFORM_H
#define OPENDATABASEFORM_H

#include <QDialog>

namespace Ui {
class OpenDatabaseForm;
}

class OpenDatabaseForm : public QDialog
{
    Q_OBJECT

public:
    explicit OpenDatabaseForm(QWidget *parent = 0);
    ~OpenDatabaseForm();

private:
    Ui::OpenDatabaseForm *ui;
};

#endif // OPENDATABASEFORM_H
