#ifndef DIALOG_H
#define DIALOG_H
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <math.h>
#include <QByteArray>
#include <QRegExpValidator>
#include <QPushButton>
class Dialog : public QDialog
{
    Q_OBJECT
private:
    QLabel * binary;
    QLabel * dex;
    QLabel * hex;
    QLineEdit * ebinary;
    QLineEdit * edex;
    QLineEdit * ehex;
    QPushButton * exit;

    QHBoxLayout * hbinary;
    QHBoxLayout * hdex;
    QHBoxLayout * hhex;
    QVBoxLayout * total;
    QByteArray ba;
  //  long BitoEdx(long n);
  //  long HetoEdx(QString s);
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
public slots:
    void changeB();
    void changeD();
    void changeH();
};

#endif // DIALOG_H
