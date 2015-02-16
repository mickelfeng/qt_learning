#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractItemView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMaximumSize(255, 544);
    setMinimumSize(255, 544);
    handle=new Handle();
    handle->setWindow(this);
    udp=new UDPNet();
    port =udp->bindPort();
    sign.setHandle(handle);
    sign.setPort(port);
    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/img/SiseChat.png"));
    trayIcon->show();
    sign.show();
    myRoomwidget = new QTableWidget;
    connect(myRoomwidget,SIGNAL(cellDoubleClicked(int,int)), this, SLOT(showRoomting(int,int)));
    myfriendwidget = new QTableWidget;
    connect(myfriendwidget,SIGNAL(cellDoubleClicked(int,int)), this, SLOT(showChating(int,int)));
    //创建监听行为
        QAction *minimizeAction = new QAction("最小化 (&I)", this);
        connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));
        QAction *restoreAction = new QAction("还原 (&R)", this);
        connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));
        QAction *quitAction = new QAction("退出 (&Q)", this);
        connect(quitAction, SIGNAL(triggered()), this, SLOT(exitWindow()));

        //创建右键弹出菜单
        trayIconMenu = new QMenu(this);
        trayIconMenu->addAction(minimizeAction);
        trayIconMenu->addAction(restoreAction);
        trayIconMenu->addSeparator();
        trayIconMenu->addAction(quitAction);
        trayIcon->setContextMenu(trayIconMenu);
        setMyFriendBox();
        setMyGroupBox();
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(Maction(QSystemTrayIcon::ActivationReason)));
    if(sign.exec()==QDialog::Accepted)
    {
       connect(udp,SIGNAL(haveMessaeg(QString)),this,SLOT(messageHandle(QString)));
       userId=sign.getUserId();
       username=sign.getUserName();
       ui->user_name->setText(username);
       times=new QTimer (this);
       times->setSingleShot(false);//true 表示循环一次 表示循环无数次
       times->setInterval(650);
       connect(times,SIGNAL(timeout()),this,SLOT(changeico()));
       addMyFriend();
       addMyRoom();
       show();
       trayIcon->showMessage("欢迎！","欢迎"+username+"你回来！");
       handle->reactionCacheRequest(userId);
       handle->reactionCacheRoomRequest(userId);

    }
    else
    {
       exit(0);
    }

}

MainWindow::~MainWindow()
{
    handle->lamdownline(userId);
    delete ui;
}
void MainWindow::exitWindow()
{
    handle->lamdownline(userId);
    exit(0);
}
void MainWindow::timeico()

{

    m=0;

    times->start();

}
void MainWindow::changeico()

{
    m++;
        if(m%2==0)

        {

            trayIcon->setIcon(QIcon(":/img/SiseChat.png"));
        }

        else

        {
             trayIcon->setIcon( QIcon() );
        }

}
void MainWindow::Maction(QSystemTrayIcon::ActivationReason wch)

{

    switch(wch)

    {

            case QSystemTrayIcon::Trigger: times->stop();

                     trayIcon->setIcon( QIcon(":/img/SiseChat.png") );break;//当用户单击时 我们让图标停止闪烁
                     break;

        case QSystemTrayIcon::DoubleClick:
            //双击托盘图标
            this->showNormal();
            this->raise();
            break;
        default:
            break;

    }

}
QString MainWindow::getUserName()
{
    return username;
}

QString MainWindow::getUserId()
{
    return userId ;
}
void MainWindow::setHandle(Handle h)
{
    this->handle=&h;
}
void MainWindow::setUdp(UDPNet u)
{
    this->udp=&u;
}
QString MainWindow::findRoomName(QString id)
{
    for(int i=0;i<myroomlist.size();i++)
    {
        if(myroomlist[i]["talkroomid"]==id)
        {
            return myroomlist[i]["talkroomname"];
        }
    }
}
/**
 * @brief 回应申请进入聊天室
 * @param command
 * <addtalkroominvite><userid:>请求者id<name:>请求者名字<talkroomid:>群id<ip:>ip<port:>port
 * @return
 * <addtalkroominviteback><userid:>请求者id<talkroomid:>群id<talkroomname:>群名称<fromuserid:>被请求者id<type:>0拒绝1同意
 */
void MainWindow::reactionApplyTalkRoom(QMap<QString, QString> command)
{
    QString text="用户："+command["name"]+"申请加入聊天室："+findRoomName(command["talkroomid"])+",请问是否同意？";
    QString type="";
    if(QMessageBox::question(this,"进群申请",text,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
    {
            type="1";
    }else{
            type="0";
    }
    //     拼接服务器请求协议
             QString commands="<addtalkroominviteback><userid:>"+command["userid"]+"<talkroomid:>"+command["talkroomid"]+
                     "<talkroomname:>"+findRoomName(command["talkroomid"])+"<fromuserid:>"+userId+"<type:>"+type;
    //    计算协议长度，添加协议头
             commands="[length="+QString::number(commands.size())+"]"+commands;
    //    发送协议
             udp->sendMessage(commands);
//             后续处理
}
/**
 * @brief 回应邀请进入聊天室
 * @param command
 * <fromid:>id<fromname:>名称(A) <talkroomid:>聊天室ID<talkroomname:>聊天室
 * @return
 */
void MainWindow::reactionTalkRoom(QMap<QString, QString> command)
{
    QString text="你的好友："+command["fromname"]+"邀请你加入聊天室："+command["talkroomname"]+",请问是否同意？";
    QString type="";
    if(QMessageBox::question(this,"好友申请",text,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
    {
            type="1";
    }else{
            type="0";
    }
    //     拼接服务器请求协议
             QString commands="<addtalkroomfriendback><userid:>"+command["fromid"]+
"<fromuserid:>"+userId+"<type:>"+type+"<talkroomid:>"+command["talkroomid"];
    //    计算协议长度，添加协议头
             commands="[length="+QString::number(commands.size())+"]"+commands;
    //    发送协议
             udp->sendMessage(commands);
//             后续处理

}
/**
 * @brief 回应好友添加信息
 * @param command
 * <addyou><fromuserid:>用户名(A)<fromname:>名称(A)<ip:>ip<port:>port
 */
void MainWindow::reactionFriendRequest(QMap<QString,QString> command)
{
    QString text="用户："+command["fromname"]+"申请添加你为好友,请问是否同意？";
    QString type="";
    if(QMessageBox::question(this,"好友申请",text,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes)==QMessageBox::Yes)
    {
            type="1";
            addMyFriend();
    }else{
            type="0";
    }
    //     拼接服务器请求协议
             QString commands="<adduserfriendback><userId:>"+command["fromuserid"]+"<fromuserid:>"+userId+"<type:>"+type;;
    //    计算协议长度，添加协议头
             commands="[length="+QString::number(commands.size())+"]"+commands;
    //    发送协议
             udp->sendMessage(commands);
    //    后续处理
}
/**
 * @brief UDP接收处理函数
 * @param UDP接收到的Message
 */
void MainWindow::messageHandle(QString message)
{
    qDebug()<<message;
    QMap<QString,QString> result=handle->getCommand(handle->changeMessage(message));
    qDebug()<<result;
    QString command=result.value("command");
//        弹出系统窗口，询问是否进入聊天室
    if(command=="addtalkroomfriendyou")
    {
        reactionTalkRoom(result);
        addMyFriend();
    }
//    打开群聊窗口
    if(command=="roomchat")
    {


        QString value="";
        QStringList temp=result["value"].split('|');
        temp[1]="<"+temp[1]+">";
        temp[3]="<"+temp[3]+">";
        for(int i=1;i<temp.size();i++)
        {
            value+=temp[i];
        }
        if(roommap.contains(result["roomid"]))
        {
            roommap[result["roomid"]]->message(temp[0],value);
            qDebug()<<"message";
            roommap[result["roomid"]]->showNormal();
        }else{
            RoomChat *roomchat=new RoomChat();
            roomchat->setRoomFriendList(myroomfriendlist[result["roomid"]]);
            roomchat->setRoomId(result["roomid"]);
            roomchat->setRoomName(result["roomuser"]);
            roomchat->setUdp(udp);
            roomchat->message(temp[0],value);;
            roommap.insert(result["roomid"],roomchat);
            roomchat->setWindowTitle("聊天室:"+result["roomname"]+"("+result["roomid"]+")");
            roomchat->setUserId(userId);
            roomchat->setUserName(username);
            roomchat->showNormal();
        }
        //map.remove(result["userid"]);
}
//        打开聊天窗口
    if(command=="chat")
    {


        QString value="";
        QStringList temp=result["value"].split('|');
        temp[1]="<"+temp[1]+">";
        temp[3]="<"+temp[3]+">";
        for(int i=1;i<temp.size();i++)
        {
            value+=temp[i];
        }
        if(map.contains(result["userid"]))
        {
            map[result["userid"]]->message(temp[0],value);
            map[result["userid"]]->showNormal();
        }else{
            Chat *chat=new Chat();
            QMap<QString, QString> fipport = getFriendIp_Port(result["userid"]);
            chat->setFriendUserIp(fipport["ip"]);
            chat->setFriendUserPort(fipport["port"]);
            chat->setFriendUserId(result["userid"]);
            chat->setUserId(userId);
            chat->setUserName(username);
            chat->setUdp(udp);
            chat->message(temp[0],value);;
            map.insert(result["userid"],chat);
            chat->setWindowTitle("好友:"+result["username"]+"("+result["userid"]+")");
            chat->showNormal();
        }
        //map.remove(result["userid"]);
}
 //        弹出系统窗口，询问是否添加某人为好友
    if(command=="addyou")
    {
        reactionFriendRequest(result);
    }
//    弹出系统窗口，添加好友反馈信息
    if(command=="adduserfriendback")
    {
           /*<userId:>请求方id<fromuserid:>被请求方id<type:>1(同意)或者<type:>0(不同意)<ip:>ip<port:>端口*/
        if(result["type"]=="1")
        {
           trayIcon->showMessage("系统信息","成功添加好友:"+result["fromuserid"]);
        }else
        {
            trayIcon->showMessage("系统信息","用户:"+result["fromuserid"]+"拒绝添加你为好友");
        }
    }
//        弹出系统窗口，某人已下线，并把其项目置为enable（false）
    if(command=="youfrienddownline")
    {
        addMyFriend();
        trayIcon->showMessage("好友下线","你的好友："+result["name"]+"已下线");
    }
//        弹出系统窗口，某人已上线线，并把其项目置为enable（true）
    if(command=="youfriendsignin")
    {
        addMyFriend();
        trayIcon->showMessage("好友上线","你的好友："+result["name"]+"已上线");
    }
//        弹出系统窗口，某人进入群,并把其添加到群友列表
    if(command=="addtalkroomfriendback2")
    {
      /*<fromid:>id（B）<fromname:>名称(B)<ip:>ip<port:>port<talkroomid:>聊天室ID */
      trayIcon->showMessage("群消息","用户:"+result["fromname"]+"加入聊天室"+result["talkroomid"]);
    }
    if(command=="addtalkroominvite")
    {
        reactionApplyTalkRoom(result);
        myroomfriendlist[result["talkroomid"]]=handle->getRoomFriendList(userId,result["talkroomid"]);
        if(roommap.contains(result["talkroomid"])){
            roommap[result["talkroomid"]]->setRoomFriendList(myroomfriendlist[result["talkroomid"]]);
        }
    }
    if(command=="addtalkroominviteback")
    {
        if(result["type"]=="1")
        {
            trayIcon->showMessage("群消息","聊天室"+result["talkroomname"]+"("+result["talkroomid"]+")同意你的加入");
            addMyRoom();
        }
        else
        {
            trayIcon->showMessage("群消息","聊天室"+result["talkroomname"]+"("+result["talkroomid"]+")拒绝你的加入");
        }
    }
    if(command=="addtalkroomfriendback")
    {
//        <fromid:>id（B）<fromname:>名称(B) <type:>1(同意) <ip:>ip<port:>port<talkroomid:>聊天室ID
//        或者<type:>0(不同意) <talkroomid:>聊天室ID
        if(result["type"]=="1")
        {
            trayIcon->showMessage("群消息","用户:"+result["fromname"]+"加入聊天室"+result["talkroomid"]);
            myroomfriendlist[result["talkroomid"]]=handle->getRoomFriendList(userId,result["talkroomid"]);
            roommap[result["talkroomid"]]->setRoomFriendList(myroomfriendlist[result["talkroomid"]]);
        }else{
            trayIcon->showMessage("群消息","用户:"+result["fromname"]+"拒绝加入聊天室"+result["talkroomid"]);
        }

    }
    if(command=="yougfriendsignin")
    {
        myroomfriendlist[result["talkroomid"]]=handle->getRoomFriendList(userId,result["talkroomid"]);
        if(roommap.contains(result["talkroomid"])){
            roommap[result["talkroomid"]]->setRoomFriendList(myroomfriendlist[result["talkroomid"]]);
        }
    }
    if(command=="yougfrienddownline")
    {
        myroomfriendlist[result["talkroomid"]]=handle->getRoomFriendList(userId,result["talkroomid"]);
        if(roommap.contains(result["talkroomid"])){
            roommap[result["talkroomid"]]->setRoomFriendList(myroomfriendlist[result["talkroomid"]]);
        }
    }
}
/**
 * @brief 创建聊天室列表
 */
void MainWindow::setMyGroupBox()
{

    myRoomwidget->verticalHeader()->setVisible(false);  // 隐藏表头
    myRoomwidget->horizontalHeader()->setVisible(false);    // 隐藏行头

    myRoomwidget->insertColumn(myRoomwidget->columnCount());    // 增加一列单元格
    myRoomwidget->insertColumn(myRoomwidget->columnCount());    // 增加一列单元格
    myRoomwidget->insertColumn(myRoomwidget->columnCount());    // 增加一列单元格
    myRoomwidget->setColumnWidth(0, 252);     // 设置单元格的宽度为252
    myRoomwidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 设置表格不可编辑属性
    myRoomwidget->setSelectionBehavior(QAbstractItemView::SelectRows);    //设置表格每次选中一行
    myRoomwidget->hideColumn(1);  // 隐藏第二列
    myRoomwidget->hideColumn(2);  // 隐藏第三列
    roombox = new QVBoxLayout(ui->mygroup);
    roombox->setMargin(0);  // 设置边距为0
}

/**
 * @brief 创建好友列表
 */
void MainWindow::setMyFriendBox()
{

    myfriendwidget->verticalHeader()->setVisible(false);  // 隐藏表头
    myfriendwidget->horizontalHeader()->setVisible(false);    // 隐藏行头

    myfriendwidget->insertColumn(myfriendwidget->columnCount());    // 增加一列单元格
    myfriendwidget->insertColumn(myfriendwidget->columnCount());    // 增加一列单元格
    myfriendwidget->insertColumn(myfriendwidget->columnCount());    // 增加一列单元格
    myfriendwidget->insertColumn(myfriendwidget->columnCount());    // 增加一列单元格
    myfriendwidget->insertColumn(myfriendwidget->columnCount());    // 增加一列单元格
    myfriendwidget->setColumnWidth(0, 252);     // 设置单元格的宽度为252
    myfriendwidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 设置表格不可编辑属性
    myfriendwidget->setSelectionBehavior(QAbstractItemView::SelectRows);    //设置表格每次选中一行
    myfriendwidget->hideColumn(1);  // 隐藏第二列
    myfriendwidget->hideColumn(2);  // 隐藏第三列
    myfriendwidget->hideColumn(3);  // 隐藏第四列
    myfriendwidget->hideColumn(4);  // 隐藏第五列

    lay = new QVBoxLayout(ui->myfriend);
    lay->setMargin(0);  // 设置边距为0
}
/**
 * @brief 初始化聊天室列表
 */
void MainWindow::addMyRoom()
{
    //myfriendwidget->clear();
/*    for(int len=0; len<rowlen;len++)
    {
        myfriendwidget->setRowCount(0);
    }*/
    myRoomwidget->setRowCount(0);
    myRoomwidget->clearContents();
    myroomlist = handle->getMyRoomList(userId);  // 获取所有的聊天室列表
//    <talkroomid:>聊天室ID<talkroomname:>聊天室名
    QString temp[]={"talkroomid","talkroomname"} ;
    for (int i=0; i<myroomlist.size(); i++)
    {
        myRoomwidget->insertRow(myRoomwidget->rowCount()); // 插入一行单元格
        myRoomwidget->setRowHeight(i,50); // 设置单元格的高度为50
        QTableWidgetItem *nameiditem = new QTableWidgetItem(myroomlist[i][temp[0]]+"\n"+myroomlist[i][temp[1]]);
        QTableWidgetItem *iditem = new QTableWidgetItem(myroomlist[i][temp[0]]) ;
        QTableWidgetItem *nameitem = new QTableWidgetItem(myroomlist[i][temp[1]]) ;
        nameiditem->setIcon(QPixmap(":/img/Talkroom.png"));
        myRoomwidget->setItem(i, 0, nameiditem);
        myRoomwidget->setItem(i, 1, iditem);
        myRoomwidget->setItem(i, 2, nameitem);
        myRoomwidget->setIconSize(QSize(40,40));
        roombox->addWidget(myRoomwidget); // 将一个表格放进我的群抽屉中
        qDebug()<<"id"+myroomlist[i][temp[0]];
        myroomfriendlist.insert(myroomlist[i][temp[0]],handle->getRoomFriendList(userId,myroomlist[i][temp[0]]));
    }
}

/**
 * @brief 初始化好友列表
 */
void MainWindow::addMyFriend()
{
    //myfriendwidget->clear();
/*    for(int len=0; len<rowlen;len++)
    {
        myfriendwidget->setRowCount(0);
    }*/
    myfriendwidget->setRowCount(0);
    myfriendwidget->clearContents();
    addmyfriendlist = handle->getFriendList(userId);  // 获取所有的好友列表
    QString temp[]={"fuserId","fname","ip", "port"} ;
    for (int i=0; i<addmyfriendlist.size(); i++)
    {
        myfriendwidget->insertRow(myfriendwidget->rowCount()); // 插入一行单元格
        myfriendwidget->setRowHeight(i,50); // 设置单元格的高度为50
        QTableWidgetItem *nameiditem = new QTableWidgetItem(addmyfriendlist[i][temp[0]]+"\n"+addmyfriendlist[i][temp[1]]);
        QTableWidgetItem *iditem = new QTableWidgetItem(addmyfriendlist[i][temp[0]]) ;
        QTableWidgetItem *nameitem = new QTableWidgetItem(addmyfriendlist[i][temp[1]]) ;
        QTableWidgetItem *ipitem = new QTableWidgetItem(addmyfriendlist[i][temp[2]]) ;
        QTableWidgetItem *portitem = new QTableWidgetItem(addmyfriendlist[i][temp[3]]) ;
        if((addmyfriendlist[i][temp[2]]=="_empty_")||(addmyfriendlist[i][temp[3]]=="0"))
        {
            nameiditem->setIcon(QPixmap(":/img/Person_black.png"));
        }else
        {
            nameiditem->setIcon(QPixmap(":/img/Person.png"));
        }
        myfriendwidget->setItem(i, 0, nameiditem);
        myfriendwidget->setItem(i, 1, iditem);
        myfriendwidget->setItem(i, 2, ipitem);
        myfriendwidget->setItem(i, 3, portitem);
        myfriendwidget->setItem(i, 4, nameitem);
        myfriendwidget->setIconSize(QSize(40,40));
        lay->addWidget(myfriendwidget); // 将一个表格放进我的好友抽屉中
    }
}

void MainWindow::on_addfriend_clicked()
{
    AddInfo addinfo;
    setWindowTitle("N");
    addinfo.setUserId(userId);
    addinfo.exec();
    addMyFriend();
}
/**
 * @brief 打开群聊窗口
 * @param row
 * @param column
 */
void MainWindow::showRoomting(int row, int column)
{
    column=0;
    if(!map.contains("frienduserid"))
    {
        qDebug()<<myroomfriendlist;
        RoomChat *roomchat=new RoomChat;
        roomchat->setRoomId(myRoomwidget->item(row,1)->text());
        roomchat->setRoomName(myRoomwidget->item(row,2)->text());
        roomchat->setUdp(udp);
        roomchat->setUserId(userId);
        roomchat->setUserName(username);
        roomchat->setRoomFriendList(myroomfriendlist[myRoomwidget->item(row,1)->text()]);
        roommap.insert(myRoomwidget->item(row,1)->text(),roomchat);
        roomchat->setWindowTitle("聊天室:"+myRoomwidget->item(row,2)->text()+"("+myRoomwidget->item(row,1)->text()+")");
        roomchat->showNormal();
    }

}
/**
 * @brief 打开私聊窗口
 * @param row
 * @param column
 */
void MainWindow::showChating(int row, int column)
{
    column=0;
    if(!map.contains("frienduserid"))
    {

        QString frienduserid = myfriendwidget->item(row, 1)->text() ;
        QString frienduserip = myfriendwidget->item(row, 2)->text();
        QString frienduserport = myfriendwidget->item(row, 3)->text() ;
        QString friendusername= myfriendwidget->item(row,4)->text();
        Chat *chat=new Chat();
        chat->setUserName(username);
        chat->setUserId(userId);
        chat->setUdp(udp);
        chat->setFriendUserId(frienduserid);
        chat->setFriendUserIp(frienduserip);
        chat->setFriendUserPort(frienduserport);
        qDebug()<< frienduserid;
        qDebug()<< frienduserip;
        qDebug()<<frienduserport;
        map.insert(frienduserid,chat);
        chat->setWindowTitle("好友:"+friendusername+"("+frienduserid+")");
        chat->showNormal();
    }

}

/**
 * @brief MainWindow::getFriendIp_Port
 * @param friendid
 * @return QMap<QString, QString>
 * key:<ip>聊天好友的ip;<port>聊天好友的端口
 */
QMap<QString, QString> MainWindow::getFriendIp_Port(QString friendid)
{
    QMap<QString, QString> map;
    for (int i=0; i<addmyfriendlist.size(); i++)
    {
        if (friendid == addmyfriendlist[i]["fuserId"])
        {
            map.insert("ip", addmyfriendlist[i]["ip"]);
            map.insert("port", addmyfriendlist[i]["port"]) ;
        }
    }
    return map;
}
