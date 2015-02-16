#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tabitem.h"
#include "treeviewtest.h"
#include "collpsetestform.h"


#include "collapseview.h"

#include <windows.h>
#include <QMouseEvent>
#include <QRect>
#include <QPoint>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    QLayout* l=ui->scrollAreaWidgetContents_2->layout();

    l->addWidget(new CollapseView(this));

    ui->splitter->setStretchFactor(0,0);
    ui->splitter->setStretchFactor(1,1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    if(!this->isFullScreen()&&!this->isMaximized()){
        //判断位置
        QRect rect=ui->top_widget->rect();
        QPoint pos=event->pos();
        bool shouldMove=pos.x()>=rect.left()&&pos.x()<=rect.right()&&pos.y()>=rect.top()&&pos.y()<=rect.bottom();
        if(shouldMove){
            if (ReleaseCapture()){
                SendMessage(HWND(this->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
            }
        }
        event->ignore();
    }

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_F1:
        this->showFullScreen();
        break;
    case Qt::Key_F2:
        this->showMaximized();
        break;
    case Qt::Key_F3:
        this->showNormal();
        break;
    case Qt::Key_F4:
        this->close();
        break;
    default:
        break;
    }
}

