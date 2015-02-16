#include "slidewindow.h"
#include "ui_slidewindow.h"

#include "collapseview.h"

SlideWindow::SlideWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SlideWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->page->layout()->addWidget(new CollapseView());

   //ui->main_center->layout()->addWidget(new CollapseView());

   //tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
}

SlideWindow::~SlideWindow()
{
    delete ui;
}
