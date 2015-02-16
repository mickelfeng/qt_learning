#ifndef UDPNET_H
#define UDPNET_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include <QEventLoop>
#include <QDebug>
#include "config.h"

class UDPNet : public QObject
{
    Q_OBJECT
public:
    explicit UDPNet(QObject *parent = 0);
    //发送消息
    void sendMessage(QString message, QString ip, int port);
    //发送消息
    void sendMessage(QString message);
    //绑定端口
    int bindPort();
public slots:
    //接受消息
    void acceptMessage();
signals:
    void haveMessaeg(QString);
private:
   QUdpSocket *udpAccepct;
   QUdpSocket *udpReaction;
   quint16 port;
   QEventLoop eventloop;
   QString message;
   Config config;
};

#endif // UDPNET_H
