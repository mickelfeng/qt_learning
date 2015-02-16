#include "tabitem.h"
#include "ui_tabitem.h"

#include "qcustomplot.h"

#include "myrealtimeplot.h"
#include "mycolormapplot.h"

tabItem::tabItem(int type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tabItem)
{
    ui->setupUi(this);

    QCustomPlot*customPlot;
    if(type==0){
        // setup customPlot as central widget of window:
        customPlot=new MyRealTimePlot;


    }else{

        customPlot=new MyColorMapPlot;
    }


    ui->tab_con->layout()->addWidget(customPlot);

}

tabItem::~tabItem()
{
    delete ui;
}
