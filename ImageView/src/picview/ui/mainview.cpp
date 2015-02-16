#include "mainview.h"
#include "ui_mainview.h"

#include "controlview.h"
#include "imageview.h"


#include <QStackedLayout>

MainView::MainView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    ui->verticalLayout->addWidget(new ImageView(this));

}

MainView::~MainView()
{
    delete ui;
}
