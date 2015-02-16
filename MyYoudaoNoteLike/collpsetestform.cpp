#include "collpsetestform.h"
#include "ui_collpsetestform.h"

#include "collapseview.h"

CollpseTestForm::CollpseTestForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollpseTestForm)
{
    ui->setupUi(this);

    for(int i=0;i<6;i++){

        ui->widget->layout()->addWidget(new CollapseView(this));

    }
}

CollpseTestForm::~CollpseTestForm()
{
    delete ui;
}
