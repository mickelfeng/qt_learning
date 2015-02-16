#ifndef QCOMPORT_H
#define QCOMPORT_H
#include <QObject>
#include <QSettings>
#include <QStringList>

#include"win_qextserialport.h"

/*
  class QComPort
  ���༯���˶�ע����ڸ������������Դ��ڵ����õ�

 */
class QComPort : public QObject
{
    Q_OBJECT

public:

    Win_QextSerialPort myCom;
    PortSettings portcom;//�������ò���
    bool comStateflag;//�����ڵ�״̬

public:
    explicit QComPort(QObject *parent = 0);
    //��ȡע������еĴ��ڶˣ����������Դ�������
    QStringList readAllComToList(void);

    bool openComPort(const QString & name, const PortSettings& settings);
    void closeComPort(void);

    QString readAll(void);
    QString readAlltoHex(void);
    qint64 WriteString(QString str);
    qint64 WriteHex(QString str);

private:
    //��ȡ��Ӧindexλ�õĴ�������
    QString getComValue(int index,QString keyorvalue);

signals:
    
public slots:
    
};

#endif // QCOMPORT_H
