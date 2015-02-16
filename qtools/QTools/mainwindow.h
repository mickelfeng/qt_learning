#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <serialport/qcomport.h>
#include <QMessageBox>
#include <QEvent>
#include <QDateTime>
#include <QTimer>
#include <QFileDialog>
#include <QString>
#include <QDesktopServices>
#include <QList>
#include "painterdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    QComPort wincom;
    explicit MainWindow(QWidget *parent = 0);
    virtual bool eventFilter(QObject *, QEvent *);

    ~MainWindow();

protected :

private slots:
    void on_OpenButton_clicked();

    void on_searchbutton_clicked();

    void DisReiveData();

    void on_RecClrButton_clicked();

    void autoSend(void);

    void on_pushButton_clicked();

    void on_autosendBox_clicked();

    void on_sendmsBox_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_sendButton_clicked();

    void on_pushButton_3_clicked();

private:
    PainterDialog *PainterDis;
    Ui::MainWindow *ui;
    QDateTime nowTime;
    QTimer autosendtimer;
    QTimer distimer;
    void SendData(QString sbuf);

};

#endif // MAINWINDOW_H
