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
    ~NewEntryForm();

private:
    Ui::NewEntryForm *ui;
};

#endif // NEWENTRYFORM_H
