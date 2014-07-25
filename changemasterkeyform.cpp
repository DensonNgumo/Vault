#include "changemasterkeyform.h"
#include "ui_changemasterkeyform.h"

ChangeMasterKeyForm::ChangeMasterKeyForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeMasterKeyForm)
{
    ui->setupUi(this);
}

ChangeMasterKeyForm::~ChangeMasterKeyForm()
{
    delete ui;
}
