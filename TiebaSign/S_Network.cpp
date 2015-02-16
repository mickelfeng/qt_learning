#include "H_Network.h"

bool MyNetwork::checkIsOnline(){
    QHostInfo::lookupHost(QString("www.baidu.com"), NULL, SLOT(lookedUp(QHostInfo)));
}


void MyNetwork::lookedUp(QHostInfo &host){
     qDebug() << host.addresses().first().toString();
}
