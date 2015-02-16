#include "painterdialog.h"
#include "ui_painterdialog.h"
#include "QPainter"

PainterDialog::PainterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PainterDialog)
{

    ui->setupUi(this);



}

PainterDialog::~PainterDialog()
{
    delete ui;
}

void PainterDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(Qt::blue,2,Qt::DashDotLine,Qt::RoundCap));
    painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
    painter.drawLine(10,10,100,100);
}
