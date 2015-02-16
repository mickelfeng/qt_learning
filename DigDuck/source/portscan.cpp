#include "portscan.h"
#include <QDebug>
#include "mainwindow.h"

portScan::portScan(QObject *parent) :
    QThread(parent)
{
    stopped = false;
}

void portScan::run()
{


    beginScan ();

}


void portScan::stop ()
{
    stopped = true;

}


void portScan::beginScan()
{
    ipInfo ipinfo;
    QTcpSocket socket;
    MainWindow *ptr = (MainWindow *)  parent();
    QStringList list = ptr ->returnIpInfo ();  //获取mainwindow数据
    QString str_begin = list[0];
    QString str_end = list[1];
    QString str_port = list[2];
    //将IP和端口存到string数组
    QStringList begin = ipinfo.ipAddr (str_begin);
    QStringList end = ipinfo.ipAddr (str_end);
    QStringList port = ipinfo.ipPort (str_port);
    //进度条
    int scanNum = ipinfo.ipNum (str_begin,str_end) * port.length ();
    int temp = scanNum;
    //必须保持IP前两段一样，否则不能扫描
    if(! ipinfo.isIP (str_begin) || !ipinfo.isIP (str_end)){
        emit isip ();
    }else if(! ipinfo.isSame_2 (str_begin,str_end)){
       emit tooMuch ();  //IP太尼玛多了
    }else{
        //判断结束IP地址是否大于开始IP地址
        if( ! ipinfo.isLarge (str_begin,str_end)){
            emit notConform ();   //结束IP不符合规则
        }else{
          //  开始执行端口扫描
            int portNum = 80;
            QString ipAddress;

            //遍历IP

            for(int a = begin[2].toInt ();a<=end[2].toInt ();a++){
                for(int b= ( a == begin[2].toInt ()? begin[3].toInt (): 0);b<=( a == end[2].toInt ()? end[3].toInt ():255);b++){
                    QString str_a = QString::number (a,10);
                    QString str_b = QString::number (b,10);
                    ipAddress = begin[0]+"."+begin[1]+"."+str_a+"."+str_b;
                    //遍历端口并开始执行端口扫描
                    if(! stopped){ //判断是否结束扫描

                        for(int i=0;i<port.length ();i++){
                            portNum = port[i].toInt ();
                            socket.connectToHost(ipAddress,portNum);
                              QStringList sb;
                              sb<<ipAddress<<port[i]<<QString::number (scanNum,10)<<QString::number (temp,10);
                              emit addressPort(sb);//传递正在扫描地址和端口
                              temp --;
                            if(socket.waitForConnected(100)){
                                QStringList sb;
                                sb<<ipAddress<<port[i];
                                emit  portOpen(sb);//传递开放的端口
                                socket.close();
                            }
                        }
                        QThread::msleep (400);
                    }

                }
            }
          emit portScanChanged();  //扫描结束 发射信号
        }
    }

    stopped = false;
}



