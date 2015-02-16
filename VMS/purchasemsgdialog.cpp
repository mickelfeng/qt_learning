#include "purchasemsgdialog.h"
#include "ui_purchasemsgdialog.h"

purchaseMSGDialog::purchaseMSGDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::purchaseMSGDialog)
{


    ui->setupUi(this);
}

purchaseMSGDialog::~purchaseMSGDialog()
{
    delete ui;
}
void purchaseMSGDialog::purchaseSet(QModelIndex index, QSqlTableModel *model)
{
    QString pid = model->record(index.row()).value(0).toString();
    QString fid = model->record(index.row()).value(1).toString();
    QString pkind = model->record(index.row()).value(2).toString();
    QString pweight = model->record(index.row()).value(3).toString();
    QString pprice = model->record(index.row()).value(4).toString();
    QString ptime = model->record(index.row()).value(5).toString();
    double pay = pweight.toDouble() * pprice.toDouble();
    QString ppay;
    QString sql = "SELECT fname FROM farmer WHERE fid = " + fid;
    QSqlQuery query;
    query.first();
    ui->pMSGPIDLineEdit->setText(pid);
    ui->pMSGIDLineEdit->setText(fid);
    ui->pMSGNameLineEdit->setText(query.value(0).toString());
    ui->pMSGKindLineEdit->setText(pkind);
    ui->pMSGWeightLineEdit->setText(pweight);
    ui->pMSGPriceLineEdit->setText(pprice);
    ui->pMSGTimeLlineEdit->setText(ptime);
    ui->pMSGPayLineEdit->setText(ppay.setNum(pay));
}

void purchaseMSGDialog::on_pMSGOKButton_clicked()
{
    close();
}
