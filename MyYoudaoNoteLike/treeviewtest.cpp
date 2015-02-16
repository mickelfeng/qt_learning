#include "treeviewtest.h"
#include "ui_treeviewtest.h"

#include <QDebug>

TreeViewtest::TreeViewtest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeViewtest)
{
    ui->setupUi(this);

    ui->treeWidget->itemSelectionChanged();

    connect(ui->treeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(onItemChange()));

    floatWidget.setStyleSheet("background:red");
    floatWidget.setParent(ui->treeWidget);

    floatWidget.setVisible(false);

}

TreeViewtest::~TreeViewtest()
{
    delete ui;
}


void TreeViewtest::onItemChange()
{

}
