//获取IP信息的类
#ifndef IPINFO_H
#define IPINFO_H
#include <QString>
#include <QStringList>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

class ipInfo
{
public:
    ipInfo();
    QStringList ipAddr(const QString &ip);
    bool isIP(const QString &ip);
    QStringList ipPort(const QString &port);
    //写上判断是否符合规则时候的函数....
    bool isSame_2(const QString &begin ,const QString &end);
    bool isSame_3(const QString &begin ,const QString &end);
    bool isLarge(const QString &begin ,const QString &end);
    QStringList getFileContent(const QString &filePath) ;
    QStringList getIP(const QString &begin,  const QString &end);
    int ipNum(QString ,QString);


private slots:

private:


};



#endif // IPINFO_H
