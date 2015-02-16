/************MainWindow.h**************/

#ifndef MINWINDOW_H_
#define MINWINDOW_H_

#include <QtGui/QWidget>
#include "MyThread.h"
#include <QtGui/QPushButton>

class MainWindow : public QWidget
{
    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();
        MyThread *thread;
        QPushButton *pb;
};

#endif
