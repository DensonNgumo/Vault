#include "groups.h"
#include "ui_groups.h"

Groups::Groups(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Groups)
{
    ui->setupUi(this);
}

Groups::~Groups()
{
    delete ui;
}
void Groups::setGroupID(QString id)
{
    groupID=id;
}
void Groups::setDbID(QString id)
{
    dbID=id;
}

void Groups::setMainFormReference(HomeScreen * ref)
{
    main=ref;
}

void Groups::on_buttonBox_Response_accepted()
{
    //validate!!!!!!!!!
    QString groupName=ui->lineEdit_Name->text();
    QString notes=ui->plainTextEdit_Notes->toPlainText();
    QSqlQuery save;
    save.prepare("insert into groups(groupName,dbID,Notes)values('"+groupName+"','"+dbID+"','"+notes+"')");
    if(save.exec())
    {
        qDebug()<<"Group Added...";
    }
    else
    {
        qDebug()<<save.lastError().text();
    }
    qDebug()<<notes;
}
