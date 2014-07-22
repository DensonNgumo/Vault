#include "newentryform.h"
#include "ui_newentryform.h"

NewEntryForm::NewEntryForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewEntryForm)
{
    ui->setupUi(this);
}

NewEntryForm::~NewEntryForm()
{
    delete ui;
}
