#ifndef GROUPS_H
#define GROUPS_H

#include <QDialog>

namespace Ui {
class Groups;
}

class Groups : public QDialog
{
    Q_OBJECT

public:
    explicit Groups(QWidget *parent = 0);
    ~Groups();

private:
    Ui::Groups *ui;
};

#endif // GROUPS_H
