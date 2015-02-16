//端口扫描类
#ifndef PORTSCAN_H
#define PORTSCAN_H
#include <QThread>
#include <QTcpSocket>
#include <QtNetwork>
#include "ipinfo.h"
class portScan : public QThread
{
    Q_OBJECT
public:
    explicit portScan(QObject *parent = 0);
    void stop();
    volatile bool stopped;
    void beginScan();
signals:
    void tooMuch();
    void notConform();
    void portScanChanged();  //端口扫描结束发射信号
    void addressPort(QStringList);
    void portOpen(QStringList);
    void isip();
public slots:

protected:
    void run();

private:

};

#endif // PORTSCAN_H
