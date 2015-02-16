#ifndef QCOMPORT_H
#define QCOMPORT_H
#include <QObject>
#include <QSettings>
#include <QStringList>

#include"win_qextserialport.h"

/*
  class QComPort
  该类集成了对注册表串口个数的搜索，对串口的设置等

 */
class QComPort : public QObject
{
    Q_OBJECT

public:

    Win_QextSerialPort myCom;
    PortSettings portcom;//串口设置参数
    bool comStateflag;//代表串口的状态

public:
    explicit QComPort(QObject *parent = 0);
    //读取注册表所有的串口端，并返回所以串口数据
    QStringList readAllComToList(void);

    bool openComPort(const QString & name, const PortSettings& settings);
    void closeComPort(void);

    QString readAll(void);
    QString readAlltoHex(void);
    qint64 WriteString(QString str);
    qint64 WriteHex(QString str);

private:
    //读取对应index位置的串口名字
    QString getComValue(int index,QString keyorvalue);

signals:
    
public slots:
    
};

#endif // QCOMPORT_H
