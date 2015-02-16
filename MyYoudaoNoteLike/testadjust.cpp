#include "testadjust.h"
#include "ui_testadjust.h"

TestAdjust::TestAdjust(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestAdjust)
{
    ui->setupUi(this);
}

TestAdjust::~TestAdjust()
{
    delete ui;
}
