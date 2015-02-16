#ifndef REGDIALOG_H
#define REGDIALOG_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class RegDialog;
}

class RegDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegDialog(QWidget *parent = 0);
    ~RegDialog();

private slots:
    void on_regButton_clicked();

    void on_cancleButton_clicked();

private:
    Ui::RegDialog *ui;
};

#endif // REGDIALOG_H
