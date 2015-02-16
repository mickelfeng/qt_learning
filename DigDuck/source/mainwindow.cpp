#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置软件名字
    setWindowTitle (tr("挖掘鸭 Ver:0.2"));
    setMaximumSize (695,435);
    setMinimumSize (695,435);
    //载入样式表
//    QFile file(":/style/style.qss");
//    file.open(QFile::ReadOnly);
//    QString StyleSheet = tr(file.readAll ());
//    qApp->setStyleSheet (StyleSheet);
    //状态栏

    //初始化扫描线程
    portscan = new portScan(this);

    ui->textEdit_port->setEnabled (false);

    //时钟
    usedtime = 0;
    timer = new QTimer(this);
    la = new QLabel(this);
    la ->setAlignment (Qt::AlignRight);
    ui->statusBar->addPermanentWidget (la);

    connect (timer,SIGNAL(timeout()),this,SLOT(usedTime()));
    //2222222222222222
    getInterfaceInfo ();



}

MainWindow::~MainWindow()
{
    delete ui;
}

/*************************工具栏按钮**********************/

//端口扫描按钮
void MainWindow::on_action_portScan_triggered()
{
    ui->stackedWidget->setCurrentIndex (0);
    ui->statusBar->showMessage (tr("端口扫描:基于TCP SOCKET扫描主机开放端口"));
    la->clear ();


}
//网卡信息
void MainWindow::on_action_host_triggered()
{
   ui->stackedWidget->setCurrentIndex (1);
   getInterfaceInfo();

}


//关于信息
void MainWindow::on_action_about_triggered()
{
    QDialog *dlg = new QDialog();
    QGridLayout *layout = new QGridLayout();
    QLabel *label = new QLabel();
    label->setText("更新日志:\n\n1、端口扫描速度比上一个版本提升5倍以上.\n\n2、程序暂时不支持多线程扫描");
    layout->addWidget (label);
    dlg->setWindowTitle (tr("关于"));
    dlg->resize (200,70);
    dlg->setLayout (layout);
    dlg->show ();
  //  QMessageBox::information (this,tr("关于"),tr("目前只把端口扫描的部分功能写完,其他功能暂未实现."));
}


/********************************端口扫描算法********************************/


//开始端口扫描
void MainWindow::on_pushButton_portBegin_clicked()
{

    ui->textEdit_port->clear ();  //清空

    ui->pushButton_portBegin->setEnabled (false);
    ui->pushButton_portBegin->setText (tr("正在扫描..."));
    usedtime = 0;   //已用时间归零
    timer->start (1000);  //开启时钟
    portscan->start ();
    connect(portscan,SIGNAL(isip()),
            this,SLOT(isipSlot()));  //IP格式不正确

    connect (portscan,SIGNAL(tooMuch()),
             this,SLOT(tooMuchSlot())); //IP太多

    connect (portscan,SIGNAL(portScanChanged()),
             this,SLOT(portScanEnd()));  //扫描完成

    connect (portscan,SIGNAL(addressPort(QStringList)),
             this,SLOT(addressPortSlot(QStringList)));  //扫描进程

    connect (portscan,SIGNAL(portOpen(QStringList)),
             this,SLOT(portOpenSlot(QStringList)));  //开放端口


}

//结束端口扫描
void MainWindow::on_pushButton_portEnd_clicked()
{
    ui->pushButton_portBegin->setEnabled (true);
    ui->pushButton_portBegin->setText (tr("开始"));
    if(portscan->isRunning ())
    {
       portscan->stop ();
    }
    timer->stop();

}
            /*******************槽函数********************/
//IP格式不正确
void MainWindow::isipSlot ()
{
    QMessageBox::warning (this,tr("警告"),tr("IP格式不正确"));
}

//扫描结束后执行的函数
void MainWindow::portScanEnd ()
{
    timer->stop();
    ui->pushButton_portBegin->setEnabled (true);
    ui->pushButton_portBegin->setText (tr("开始"));
    QMessageBox::information (this,tr("提示"),tr("端口扫描完成!"));

    ui->statusBar->showMessage (tr("扫描完成!"));

}
//取出IP和端口，并存到string字符串里
QStringList MainWindow::returnIpInfo ()
{

    QString str_begin = ui->lineEdit_begin->text ();
    QString str_end = ui->lineEdit_end->text ();
    QString str_port = ui ->lineEdit_port->text ();
    QStringList list;
    list <<str_begin<<str_end<<str_port;
    return list;
}

// ip太多时候弹出警告
void MainWindow::tooMuchSlot ()
{
    QMessageBox::warning (this,tr("警告"),tr("扫那么多干吗?"));
}
//ip不符合规则
void MainWindow::notConformSlot ()
{
    QMessageBox::warning (this,tr("警告"),tr("结束IP不符合规则!"));
}
//扫描进度
void MainWindow::addressPortSlot(QStringList sb)
{

    if(ui->stackedWidget->currentIndex () == 0)
        ui->statusBar->showMessage ("正在扫描"+sb[0]+":"+sb[1]);
    ui->progressBar->setMaximum (sb[2].toInt ());
    ui->progressBar->setValue (sb[2].toInt ()- sb[3].toInt ()+1);

}
//开放的端口
void MainWindow::portOpenSlot (QStringList sb)
{
    ui->textEdit_port->append (sb[0]+":"+sb[1]+"端口开放");
}


/********************主机信息*******************/
//刷新接口信息
void MainWindow::on_pushButton_interface_clicked()
{
    getInterfaceInfo ();
    QMessageBox::information (this,tr("提示"),tr("接口信息已更新...."));
}


//获取所有网卡信息
void MainWindow::getInterfaceInfo ()
{
    QNetworkRequest request;
    manager = new QNetworkAccessManager(this);
    request.setUrl(QUrl("http://www.123cha.com/"));
    request.setRawHeader("User-Agent", "caonimei");
    reply = manager->get(request);
    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));

    QStandardItemModel *interfaceModel = new QStandardItemModel();
    interfaceModel->clear ();
    interfaceModel->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("接口")));
    interfaceModel->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("IP")));
    interfaceModel->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("子网掩码")));
    interfaceModel->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("MAC地址")));

    ui->tableView->setModel (interfaceModel);
    ui->tableView->setColumnWidth (0,150);
    ui->tableView->setColumnWidth (1,110);
    ui->tableView->setColumnWidth (2,110);
    ui->tableView->setColumnWidth (3,140);
    ui->tableView->setSelectionBehavior (QAbstractItemView::SelectRows);

    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    // 遍历每一个网络接口
    int i = 0;
    foreach (QNetworkInterface interface, list)
    {

        // 接口名称
        QString name,mac,ip,netMask;
        name = interface.name();
        // 硬件地址
        mac = interface.hardwareAddress();
        // 获取IP地址条目列表，每个条目中包含一个IP地址，一个子网掩码和一个广播地址
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        // 遍历每一个IP地址条目
        foreach (QNetworkAddressEntry entry, entryList)
        {
            // IP地址
            ip = entry.ip().toString();
            // 子网掩码
            netMask = entry.netmask().toString();

        }
        QStringList list;

        QRegExp rx("^[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}$");
        list<<name<<ip<<netMask<<mac;
        if(rx.exactMatch (list[1]))
        {
            for(int sb=0 ;sb<list.length ();sb++)
                 interfaceModel->setItem(i, sb, new QStandardItem(list[sb]));
            i ++;

        }
    }

}
//获取本机当前IP和主机名
QStringList MainWindow::hostInfo ()
{
    QStringList list;
    QString localHostName = QHostInfo::localHostName ();
    list<<localHostName;
    QHostInfo info = QHostInfo::fromName (localHostName);
    foreach (QHostAddress addr, info.addresses ()) {
        if(addr.protocol () == QAbstractSocket::IPv4Protocol){

            list<< addr.toString ();
        }
    }

    return list;
}



/************************其他自定义槽函数*******************************/
//已用时间
void MainWindow::usedTime ()
{
    usedtime = usedtime + 1;
    la->setText ("已用时间"+QString::number (usedtime,10)+"sec");
}

void MainWindow::slotReadyRead()
{
    QStringList list = hostInfo ();
    ui->statusBar->showMessage ("主机信息:");
    la->clear ();
    QRegExp rx("(((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?))");
    QString all = reply->readAll ();
    rx.indexIn (all);
    if(ui->stackedWidget->currentIndex () == 1)
        la->setText ("主机名:"+list[0]+"  内网IP:"+list[1]+" 外网IP:"+rx.cap (0));
}












void MainWindow::on_pushButton_clicked()
{
    QString ip = ui->lineEdit->text ();
    QString url = "http://www.ip138.com/ips138.asp?ip="+ip;
    manager2 = new QNetworkAccessManager(this);
    reply2 =  manager2->get(QNetworkRequest(QUrl(url)));
    connect(reply2, SIGNAL(readyRead()), this, SLOT(slotReadyRead_2()));
}
void MainWindow::slotReadyRead_2 ()
{
    QTextCodec *codec = QTextCodec::codecForName("gb2312");
    QString all = codec->toUnicode((reply2->readAll()));
    int a = all.indexOf ("本站主数据");
    int b = all.indexOf ("参考数据一:");
    QString str1 = all.mid (a,b);
    int c = str1.indexOf ("本站主数据");
    int d = str1.indexOf ("参考数据一");

    //"本站主数据：上海市 阿里巴巴软件（上海）有限公司</li><li>"
    QString str2 =str1.mid (c,d);
    int len = str2.length ();
    QString addr = str2.mid (0,len-9);
    ui->label_3->setText (addr);





}
