#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QFile>
#include <QTextStream>
#include <QtGui>
#include <QtCore>
#include <Qt>
#include <QSystemTrayIcon>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QProgressDialog>
#include <QDir>
#include <QTreeWidgetItem>
#include <QTime>

#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionQuit_triggered();

    void on_CloudTree_pressed(const QModelIndex &index);
    void on_LocalTree_pressed(const QModelIndex &index);

    void on_LocalTree_doubleClicked(const QModelIndex &index);
    void on_CloudTree_doubleClicked(const QModelIndex &index);

    void on_actionGithub_triggered();
    void callOpendss(const QString &fileName);
    void callGridlabd();

    void delFile();//right click
    void newFold();
    void newFile();
    void rename();

    void on_LocalTree_customContextMenuRequested(const QPoint &pos);
    void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
    void closeEvent(QCloseEvent *event);

    void on_actionGo_triggered();
    void on_actionPause_triggered();
    void on_actionInfo_triggered();

    void writeSettings();
    void loadSettings();

    void on_pushButton_clicked();
    void openFileOfItem(int,int);
    void findFiles(const QStringList &, const QString &);
    void showFiles(const QStringList &files);
    void on_lineEdit_textEdited(const QString &arg1);

    void on_CloudTree_customContextMenuRequested(const QPoint &pos);
    void MainWindow::deleteDirectory(QFileInfo);
    void setList(); //set the list of the tag
    QString firstFile();
    void on_actionDebugInfo_triggered();
    void on_actionLocalTree_triggered();
    void on_actionCloudTree_triggered();
    void on_actionAbout_triggered();

    void on_actionRefresh_triggered();
    void setTree();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *localmodel;
    QFileSystemModel *cloudmodel;
    QSystemTrayIcon *trayicon;
    QMenu *trayiconMenu;
    QTreeWidgetItem *imageItemWait;
    QTreeWidgetItem *imageItemRun;
    QTreeWidgetItem *imageItemDone;
    int timeElapse;
    int pause;
};

#endif // MAINWINDOW_H
