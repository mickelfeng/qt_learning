#include "litteriem.h"
#include "ui_litteriem.h"

LitterIem::LitterIem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LitterIem)
{
    ui->setupUi(this);
}

LitterIem::~LitterIem()
{
    delete ui;
}
