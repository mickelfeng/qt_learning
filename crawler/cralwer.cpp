#include "cralwer.h"
#include "ui_cralwer.h"

Cralwer::Cralwer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cralwer)
{
    ui->setupUi(this);
}

Cralwer::~Cralwer()
{
    delete ui;
}
