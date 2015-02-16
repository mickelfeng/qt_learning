#include "chat.h"

Chat::Chat(QWidget *parent):
    QDialog(parent)

{
    init();
    resize(500, 400);
    setMinimumSize(500, 400);   // 设置聊天窗口最小大小为500x400
    setWindowFlags(Qt::WindowMinimizeButtonHint);   // 设置窗口最小化按钮
    setWindowFlags(Qt::WindowMaximizeButtonHint);   // 设置窗口最大化按钮
    splitter->setOpaqueResize(false);   // 设置为不透明
    alltext->resize(1000,550);
    inputtext->resize(500, 50);
    setModal(false);
    setComponent();
    setSize();
    setConnect();
    setWindowOpacity(2);
    flag=true;
    setWindowIcon(*new QIcon(":/img/Person.png"));
    qDebug()<<"创建窗口";
}

Chat::~Chat()
{
   qDebug()<<"窗口被释放了";
}
void Chat::message(QString head,QString msg)
{
    alltext->append(head);
    alltext->append(msg);
    file.setFileName(userid+"_"+frienduserid+"_histroy.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    file.write(alltext->toPlainText().toAscii());
    file.close();
}
void Chat::setUdp(UDPNet *u)
{
    udp=u;
}
// 设置用户昵称
void Chat::setUserName(QString name)
{
    username = name ;
}
// 设置用户帐号(ID)
void Chat::setUserId(QString id)
{
    userid = id;
}

// 要与之聊天好友的id
void Chat::setFriendUserId(QString fuserid)
{
    frienduserid = fuserid ;
}

// 要与之聊天的好友的ip
void Chat::setFriendUserIp(QString fuserip)
{
    frienduserip = fuserip ;
}

// 要与之聊天的好友的端口
void Chat::setFriendUserPort(QString fuserport)
{
    frienduserport = fuserport ;
}

QString Chat::getFriend()
{
    return this->friendId;
}
// 组件初始化
void Chat::init()
{
    splitter = new QSplitter(Qt::Horizontal, this);     // 水平分割窗口，把窗口分成多列-->主分割
    Lsplitter = new QSplitter(Qt::Vertical, splitter) ; // 垂直分割左边部分窗口，把窗口分割成多行
    Rsplitter = new QSplitter(Qt::Vertical,splitter) ;  // 垂直分割右边部分窗口，把窗口分割成多行
    alltext = new QTextEdit ;     // 所有聊天信息显示区域
    inputtext = new QTextEdit ;   // 本地输入区域
    inputtext->setText(NULL);
    historytext = new QTextEdit ;   // 历史记录显示框
    Rsplitter->addWidget(historytext);
    Rsplitter->hide();
    center = new QDialog;   // 聊天对话框中间用于放置工具栏的 dialog 部件
    fontbtn = new QPushButton(center) ; // 改变字体按钮
    history = new QPushButton(center) ; // 查看历史记录按钮
    frame = new QFrame;
    send = new QPushButton(frame) ;     // 聊天消息发送按钮
}

// 将各部件布局到窗口的函数
void Chat::setComponent()
{
    alltext->setReadOnly(true); // 设置所有聊天信息显示区域为只读，不能写
    historytext->setReadOnly(true); // 设置历史记录区域文本只读属性
    fontbtn->setIcon(QPixmap(":/img/font.png"));
    fontbtn->move(0,0);
    history->setText("历史记录");
    send->setText("发送");
    send->resize(70,25);
    send->move(0,0);
    Lsplitter->addWidget(alltext);
    Lsplitter->addWidget(center);
    Lsplitter->addWidget(inputtext);
    Lsplitter->addWidget(frame);
}

// 设置组件大小
void Chat::setSize()
{
    float height, width;
    height = this->height();    // 获取窗口的高度
    width = this->width() ;     // 获取窗口的宽度
    fontbtn->resize(20, 20);    // 设置字体按钮的大小
    history->move(20, 0);
    // 设置聊天输入区域的大小,宽度随窗口的宽度大小的改变而改变，高度为当前高度
    inputtext->resize(splitter->width(), inputtext->height());
    // 设置聊天信息区域的的大小
    alltext->resize(width, (height-center->height()-inputtext->height()-frame->height()));
    // 固定中间部分的高度
    center->setMinimumHeight(22);
    center->setMaximumHeight(22);
    center->resize(splitter->width(),height);
    center->setContentsMargins(0,0,0,0);
    // 固定放置发送按钮的区域高度
    frame->setMaximumHeight(25);
    frame->setMinimumHeight(25);
    splitter->resize(width, height);    // 设置分割组件的大小
}

// 连接函数
void Chat::setConnect()
{
    connect(fontbtn, SIGNAL(clicked()), this, SLOT(setFont())) ;
    connect(history, SIGNAL(clicked()), this, SLOT(showHistory())) ;
    connect(send, SIGNAL(clicked()), this, SLOT(sendText()));
}

// 事件
// 大小改变事件
void Chat::resizeEvent(QResizeEvent *)
{
    setSize();
}

// 槽函数
// 设置字体
void Chat::setFont()
{
    bool ok ;
    font = QFontDialog::getFont(&ok) ;
    if (ok)
    {
        inputtext->setFont(font);
    }
}

// 显示历史记录
void Chat::showHistory()
{

    if (flag)
    {
        file.setFileName(userid+"_"+frienduserid+"_histroy.txt");
        file.open(QIODevice::ReadOnly|QIODevice::Text);
        QByteArray by=file.readAll();
        this->historytext->setText(by);
        file.close();
        flag=false;
        //Rsplitter->resize(200,400);
        Rsplitter->show();
        update();
    }else{
        //Rsplitter->resize(0,400);
        Rsplitter->hide();
        flag=true;
        update();
    }
}


/**
 * @brief Chat::sendText
 * 聊天信息发送按钮槽函数
 * 功能：获取用户输入的聊天信息，当用户点击发送按钮时将使用udp协议的方式发送出去
 */
void Chat::sendText()
{
    QString nameid = username + "(" + userid + ")" ;
    time = QDateTime::currentDateTime();    // 获取系统当前时间
    QString timestr = time.toString("yyyy-MM-dd hh:mm:ss") ;    // 设置当前系统时间格式并转换成字符串形式
    QString inputstr = inputtext->toPlainText() ;   // 获取输入框的聊天信息
    /**
     * @brief str
     * 封装聊天信息的样式
     * 思路：通过获取用户当前输入框的字体样式，将当前样式封装成样式字符串
     */
    QString str = "<font font-family="+font.family()+" size="+QString::number(font.pointSize())+">"+inputstr+"</font>" ;
    // 完整的聊天信息
    if (inputstr != NULL)
    {
        alltext->append(nameid+" "+timestr);
        alltext->append(str);
        inputtext->setText(NULL);
    }
    /**
     * 将聊天相关的信息都封装到字符串 sendstr 中
     * 在此字符串中，“｜”将做为分割符，用于接收方以此分割此字符串
     * 字符串内容为：发送方用户名和帐号 发送时间 ｜ 发送方输入内容的字体样式 ｜ 发送方的输入内容 ｜ 样式结束字符
     */
    QString sendstr = nameid + " " + timestr + "|"
            + "font font-family="+font.family()+" size="+QString::number(font.pointSize()) + "|"
            + inputstr + "|"
            + "/font" ;
    QString command="<chat><userid:>"+userid+"<username:>"+username+"<value:>"+sendstr;
    //     计算协议长度，添加协议头
        command="[length="+QString::number(command.size())+"]"+command;
    if ("_empty_" != frienduserip && "0" != frienduserport)
    {
        bool ok;
        port = frienduserport.toInt(&ok, 10) ;
        udp->sendMessage(command,frienduserip,port);
        file.setFileName(userid+"_"+frienduserid+"_histroy.txt");
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        file.write(alltext->toPlainText().toAscii());
        file.close();
    }



}
