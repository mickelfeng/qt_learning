#ifndef AMENDPWDIALOG_H
#define AMENDPWDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class AmendPWDialog;
}

class AmendPWDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AmendPWDialog(QWidget *parent = 0);
    ~AmendPWDialog();

private slots:
    void on_amendOKButton_clicked();

    void on_amendCancleButton_clicked();

private:
    Ui::AmendPWDialog *ui;

//    QString user;
//    QString passWord;
//    QString newPassWord;
//    QString newPassWord2;
};

#endif // AMENDPWDIALOG_H
