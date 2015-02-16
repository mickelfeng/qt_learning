/*************MainWindow.cpp****************/

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(0,0,300,300);
    pb=new QPushButton("AA",this);
    pb->setGeometry(0,0,30,30);
    thread=new MyThread(pb);
    thread->start();
}

MainWindow::~MainWindow()
{
    delete thread;
}
