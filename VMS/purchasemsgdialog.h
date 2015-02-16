#ifndef PURCHASEMSGDIALOG_H
#define PURCHASEMSGDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class purchaseMSGDialog;
}

class purchaseMSGDialog : public QDialog
{
    Q_OBJECT

public:
    explicit purchaseMSGDialog(QWidget *parent = 0);
    void purchaseSet(QModelIndex index, QSqlTableModel *model);
    ~purchaseMSGDialog();

private slots:
    void on_pMSGOKButton_clicked();

private:
    Ui::purchaseMSGDialog *ui;
};

#endif // PURCHASEMSGDIALOG_H
