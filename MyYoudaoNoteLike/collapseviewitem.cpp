#include "collapseviewitem.h"
#include "ui_collapseviewitem.h"

#include "litteriem.h"

#include <QDebug>

CollapseViewItem::CollapseViewItem(QString titleText, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CollapseViewItem)
{
    ui->setupUi(this);
    ui->label->setProperty("slected",!ui->item_con->isVisible());


    this->setTitleText(titleText);

    for(int i=0;i<5;i++){
        addSubItem(new LitterIem(this));
    }

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onCollapseButClick()));

}

CollapseViewItem::~CollapseViewItem()
{
    delete ui;
}

void CollapseViewItem::setTitleText(QString titleText)
{
    ui->pushButton->setText(titleText);
}

void CollapseViewItem::addSubItems(QList<QWidget *> widgets)
{
    foreach (QWidget *var, widgets) {
        addSubItem(var);
    }
}

void CollapseViewItem::addSubItem(QWidget *widget)
{
    ui->item_con->layout()->addWidget(widget);
}

void CollapseViewItem::onCollapseButClick()
{
   //设置为相反的显示状态
   ui->item_con->setVisible(!ui->item_con->isVisible());

   ui->label->setProperty("slected",ui->item_con->isVisible());

   ui->label->update();

   qDebug()<<ui->label->property("slected");

}
