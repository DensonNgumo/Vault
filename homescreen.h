#ifndef HOMESCREEN_H
#define HOMESCREEN_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QtGui>
#include "database.h"
#include <memory>


namespace Ui {
class HomeScreen;
}

class HomeScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeScreen(QWidget *parent = 0);
    void setDatabaseID(QString id);
    void setDatabaseName(QString name);
    void loadPasswords(QString id);
    void AddRoot(QString name);
    void AddChild(QTreeWidgetItem *parent,QString name);
    void RemoveRoot();
    void RefreshTree();
    void RefreshPasswords();
    void DeletePassword(QString);
    void loadKeys(QString);
    void RefreshKeys();
    void DeleteKey(QString id);
    void LockWorkspace();
    void UnlockWorkspace();
    void DeleteGroup(QString);
    void DuplicateEntry(QString,QString);


    std::tr1::shared_ptr<Database>dbPtr;
    QString getDatabaseID();
    QString getGroupID();



    ~HomeScreen();

private slots:
    void on_actionNew_Database_triggered();

    void on_actionOpen_Database_triggered();

    void on_actionEdit_View_Entry_triggered();

    void on_actionAdd_New_Entry_triggered();

    void on_actionExit_triggered();

    void on_actionChange_Master_Key_triggered();

    void on_actionAdd_Group_triggered();

    void on_treeWidget_groups_itemClicked(QTreeWidgetItem *item, int column);

    void on_actionEdit_Group_triggered();

    void on_tableView_info_doubleClicked(const QModelIndex &index);

    void on_actionDelete_Entry_triggered();

    void on_tableView_info_clicked(const QModelIndex &index);

    void on_tableView_keyInfo_doubleClicked(const QModelIndex &index);

    void on_tableView_keyInfo_clicked(const QModelIndex &index);

    void on_tabWidget_tabBarClicked(int index);

    void on_actionLock_Workspace_triggered();

    void on_actionDatabase_Settings_triggered();

    void on_actionDelete_Group_triggered();

    void on_actionAbout_Vault_triggered();

    void on_actionDuplicate_Entry_triggered();
    void showContextMenu(const QPoint &);
    void showGroupContextMenu(const QPoint& pos);
    void showKeyContextMenu(const QPoint&);


private:
    Ui::HomeScreen *ui;
    QString currentDbID;
    QString currentDbName;
    QString currentGroupName;
    QString currentPassID;
    QString currentKeyID;
    bool locked;



};

#endif // HOMESCREEN_H
