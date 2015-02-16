#include "ipinfo.h"
#include <QDebug>
ipInfo::ipInfo()
{

}
//返回字符串数组
QStringList ipInfo::ipAddr (const QString &ip)
{
    QStringList address = ip.split (".");
    return address;

}
//判断是否为IP格式
bool ipInfo::isIP (const QString &ip )
{

    QStringList address = ip.split (".");
    int num = 0;
    for(int i =0 ;i<address.length ();i++){
        if(address[i].toInt ()>0 && address[i].toInt ()<256)
            num++;
    }
    if(num == 4)
        return true;
    return false;
  //  qDebug ()<<num;
}
//获取端口号
QStringList ipInfo::ipPort (const QString &port)
{
    QStringList ipport = port.split (",");

    return ipport;
}
//判断IP前两段是否一致
bool ipInfo::isSame_2 (const QString &begin, const QString &end)
{
    QStringList one = begin.split (".");
    QStringList two = end.split (".");
    if(one[0] == two[0] &&  one[1] == two[1])
        return true;
    return false;
}

//判断IP前三段是否一致
bool ipInfo::isSame_3 (const QString &begin, const QString &end)
{
    QStringList one = begin.split (".");
    QStringList two = end.split (".");
    if(one[0] == two[0] &&  one[1] == two[1] && one[2] == two[2])
        return true;
    return false;
}
//IP地址比较大小
bool ipInfo::isLarge (const QString &begin, const QString &end)
{
    QStringList one = begin.split (".");
    QStringList two = end.split (".");
    int sum_1 = one[0].toInt ()*255*255*255 + one[1].toInt ()*255*255 +one[2].toInt ()*255 + one[3].toInt ();
    int sum_2 = two[0].toInt ()*255*255*255 + two[1].toInt ()*255*255 +two[2].toInt ()*255 + two[3].toInt ();
    if(sum_2 >= sum_1)
        return true;
    return false;

}
//从字典读取每一行文本内容
QStringList ipInfo::getFileContent (const QString &filePath)
{
    QFile file (filePath);
    if(!file.open (QIODevice::ReadOnly | QIODevice::Text))
//        QMessageBox::warning (this,"error","file open failed!");
        qDebug ()<<"file open failed!";
    file.seek (0);
    QString str;
    QStringList array ;
    str = file.readAll ();
    array = str.split ("\n");
    return array;

}
//遍历字典中每一行的IP段中所有的IP
QStringList ipInfo::getIP (const QString &begin,const QString &end)
{
    QStringList begin_ip = begin.split (".");
    QStringList end_ip = end.split (".");
    QStringList ipAddress;
    // 42.121.4.41 42.121.5.50
    for(int a = begin_ip[2].toInt ();a<=end_ip[2].toInt ();a++){
        for(int b= ( a == begin_ip[2].toInt ()? begin_ip[3].toInt (): 0);b<=( a == end_ip[2].toInt ()? end_ip[3].toInt ():255);b++){
            QString str_a = QString::number (a,10);
            QString str_b = QString::number (b,10);
            ipAddress << begin_ip[0]+"."+begin_ip[1]+"."+str_a+"."+str_b;
        }
    }
    return ipAddress;
}
//计算IP个数
int ipInfo::ipNum (QString begin_ip, QString end_ip)
{
    QStringList begin = begin_ip.split (".");
    QStringList end = end_ip.split (".");
    int num = 0;
    for(int a = begin[2].toInt ();a<=end[2].toInt ();a++){
        for(int b= ( a == begin[2].toInt ()? begin[3].toInt (): 0);b<=( a == end[2].toInt ()? end[3].toInt ():255);b++){
            num++;
        }
    }
    return num;
}


