#include "addinfo.h"
#include "ui_addinfo.h"
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QCursor>
#include <QTableWidgetSelectionRange>
#include <qdebug.h>

AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo)
{
    ui->setupUi(this);

    setMinimumWidth(500);
    setMaximumWidth(500);

    ui->friend_id->setText(NULL);
    ui->friend_name->setText(NULL);
    ui->group_id->setText(NULL);
    setConnection();
    ui->friend_table->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->group_table->setContextMenuPolicy(Qt::CustomContextMenu);
    fmenu = new QMenu(ui->friend_table);
    gmenu = new QMenu(ui->group_table);
    addfriend = new QAction("添加好友", this);
    addgroup = new QAction("添加聊天室", this);
    connect(addfriend, SIGNAL(triggered()), this, SLOT(addFriendAction()));
    connect(addgroup, SIGNAL(triggered()), this, SLOT(addGroupAction()));
}

AddInfo::~AddInfo()
{
    delete ui;
}

// 设置用户昵称
void AddInfo::setUserName(QString name)
{
    username = name;
}

// 设置用户帐号（ID）
void AddInfo::setUserId(QString id)
{
    userid = id ;
}

// 好友查找按钮点击槽函数
void AddInfo::on_friend_searchbtn_clicked()
{
    adduserid = ui->friend_id->text() ;    // 获取用户输入的帐号
    username = ui->friend_name->text() ;    // 获取用户输入的昵称
    printFriendInfo(username, adduserid);
}

// 聊天室（群）查找点击槽函数
void AddInfo::on_group_searchbtn_clicked()
{
    groupid = ui->group_id->text();
    groupname=ui->group_name->text();
    printGroupInfo(groupid,groupname);
}

void AddInfo::addFriendAction()
{
    QList<QTableWidgetItem*> items=ui->friend_table->selectedItems();
    QTableWidgetItem *item=items.at(0);
    QString adduserid=item->text();//获取内容
    QMap<QString,QString>map= handle.addFriend(userid,adduserid);
    if(map["command"]=="adduserfriendback")
    {
        if(map["type"]=="1")
        {
            QMessageBox::warning(this,"添加好友","好友添加成功");
        }else{
            QMessageBox::warning(this,"添加好友","对方拒绝添加你为好友");
        }
    }else{
        QMessageBox::warning(this,"添加好友","好友不在线,请等待好友确认!");
    }
}

void AddInfo::addGroupAction()
{
    QList<QTableWidgetItem*> items=ui->group_table->selectedItems();
    QTableWidgetItem *item=items.at(0);
    QString roomid=item->text();//获取内容
    QMap<QString,QString>map=handle.addRoom(userid,roomid);
    qDebug()<<map;
    if(map["command"].isNull())
    {
        QMessageBox::warning(this,"群添加通知","正在等待群主确认");
    }
}


// 设置对话框中各部的大小
void AddInfo::setSize()
{
    float height = this->height();
    ui->tabWidget->resize(500, height);
    // 设置好友添加表格
    setFriendTable();
    ui->friend_table->resize(495, height-84);
    // 设置群添加表格
    setGroupTable();

}

/**
 * @brief AddInfo::setFriendTable
 * 方法描述：设置好友添加表格的相关属性
 */
void AddInfo::setFriendTable()
{
    // 设置好友添加表格各列的宽度
    ui->friend_table->setColumnWidth(0, 90);
    ui->friend_table->setColumnWidth(1, 100);
    ui->friend_table->setColumnWidth(2, 40);
    ui->friend_table->setColumnWidth(3, 110);
    ui->friend_table->setColumnWidth(4, 100);
    ui->friend_table->setColumnWidth(5, 50);

    // 设置单元格不能被修改
    ui->friend_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 设置表格整行选择
    ui->friend_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置表格中只能选中一个目标
    ui->friend_table->setSelectionMode(QAbstractItemView::SingleSelection);
}

/**
 * @brief AddInfo::setGroupTable
 * 方法描述：设置聊天室（群）添加表格的相关属性
 */
void AddInfo::setGroupTable()
{
    // 设置群添加表格各列的宽度
    ui->group_table->setColumnWidth(0, 200);
    ui->group_table->setColumnWidth(1,243);
    ui->group_table->setColumnWidth(2,50);

    // 设置单元格不能被修改
    ui->group_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 设置表格整行选择
    ui->group_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 设置表格中只能选中一个目标
    ui->group_table->setSelectionMode(QAbstractItemView::SingleSelection);
}

/**
 * @brief AddInfo::printFriendInfo
 * @param name
 * @param id
 * 方法描述：将搜索用户得到的信息放进表格中，通过特定的用户名或帐号想找相应的用户信息并打印到表格中
 */
void AddInfo::printFriendInfo(QString name, QString id)
{
    ui->friend_table->setRowCount(0);
    ui->friend_table->clearContents();
    int i,j;
    friendlist = handle.getUserList(userid) ;
    QString temp[]={"userid","name","sex", "department", "major"};
    // 插入一行
    int row = ui->friend_table->rowCount(); // 必须有此行代码才能新添一行表格
    if (name == NULL || name == " " || id == NULL || id == " ")
    {   // 当用户即不输入用户名也不输入帐号，或者输入的帐号和用户名都为空时运行此区域的代码
        // 遍历所有用户信息，并将用户信息输出到表格中
        for (i=0; i < friendlist.size(); i++)
        {
            ui->friend_table->insertRow(ui->friend_table->rowCount());
            for (j=0; j<5; j++)
            {
                // 将用户信息输出到第 i 行，第 j 列单元格中
                if (temp[j] == "sex")
                {
                    if (friendlist[i][temp[j]] == "0")
                    {
                        ui->friend_table->setItem(i, j, new QTableWidgetItem("保密")) ;
                    }else if(friendlist[i][temp[j]] == "1"){
                        ui->friend_table->setItem(i, j, new QTableWidgetItem("男")) ;
                    }else if (friendlist[i][temp[j]] == "2") {
                         ui->friend_table->setItem(i, j, new QTableWidgetItem("女")) ;
                    }
                }else{
                    ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
                }

            }
        }
    }else if(name != NULL && name != "" && (id == NULL || id == "")){
        // 当用户只输入用户名时则运行此条件内的代码
        int count = 0;  // 用于统计人数
        // 遍历查找好友
        for (i=0; i < friendlist.size(); i++)
        {
             ui->friend_table->insertRow(ui->friend_table->rowCount());
            if (name == friendlist[i][temp[1]])
            {
                ui->friend_table->insertRow(row);
                for(j=0; j<5; j++)
                {
                    // 将用户信息输出到第 i 行，第 j 列单元格中
                    if (temp[j] == "sex")
                    {
                        if (friendlist[i][temp[j]] == "0")
                        {
                            ui->friend_table->setItem(i, j, new QTableWidgetItem("保密")) ;
                        }else if(friendlist[i][temp[j]] == "1"){
                            ui->friend_table->setItem(i, j, new QTableWidgetItem("男")) ;
                        }else if (friendlist[i][temp[j]] == "2") {
                             ui->friend_table->setItem(i, j, new QTableWidgetItem("女")) ;
                        }
                    }else{
                        ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
                    }
                    count++;

                }
            }
        }
        // 当查找的用户不存在时，弹出一个消息框
        if (0 == count)
        {
            QMessageBox::about(this, "消息", "对不起，您所要查找的用户不存在！");
        }
    }else if(id != NULL && id == "" && (name == NULL | name == "")){
        // 当用户只输入帐号时则运行此条件内的代码
        int count=0;
        // 遍历查找好友
        for (i=0; i <friendlist.size(); i++)
        {
             ui->friend_table->insertRow(ui->friend_table->rowCount());
            if (id == friendlist[i][temp[0]])
            {
                ui->friend_table->insertRow(row);
                for(j=0; j<5; j++)
                {
                    // 将用户信息输出到第 i 行，第 j 列单元格中
                    if (temp[j] == "sex")
                    {
                        if (friendlist[i][temp[j]] == "0")
                        {
                            ui->friend_table->setItem(i, j, new QTableWidgetItem("保密")) ;
                        }else if(friendlist[i][temp[j]] == "1"){
                            ui->friend_table->setItem(i, j, new QTableWidgetItem("男")) ;
                        }else if (friendlist[i][temp[j]] == "2") {
                             ui->friend_table->setItem(i, j, new QTableWidgetItem("女")) ;
                        }
                    }else{
                        ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
                    }
                    count++;
                }
            }
        }
        // 当查找的用户不存在时，弹出一个消息框
        if (0 == count)
        {
            QMessageBox::about(this, "消息", "对不起，您所要查找的用户不存在！");
        }
    }else if (name != NULL && name != "" && id == NULL && id == ""){
        // 当用户同时输入用户名和帐号时则运行此条件内的代码
        int count=0;
        for(i=0; i <friendlist.size(); i++)
        {
            ui->friend_table->insertRow(ui->friend_table->rowCount());
            if(friendlist[i][temp[0]] == id && friendlist[i][temp[1]] == name)
            {
                ui->friend_table->insertRow(row);
                for(j=0; j<5; j++)
                {
                    // 将用户信息输出到第 i 行，第 j 列单元格中
                    if (temp[j] == "sex")
                    {
                        if (friendlist[i][temp[j]] == "0")
                        {
                            ui->friend_table->setItem(i, j, new QTableWidgetItem("保密")) ;
                        }else if(friendlist[i][temp[j]] == "1"){
                            ui->friend_table->setItem(i, j, new QTableWidgetItem("男")) ;
                        }else if (friendlist[i][temp[j]] == "2") {
                             ui->friend_table->setItem(i, j, new QTableWidgetItem("女")) ;
                        }
                    }else{
                        ui->friend_table->setItem(i, j, new QTableWidgetItem(friendlist[i][temp[j]]));
                    }
                    count++;
                }
            }
        }
        // 当查找的用户不存在时，弹出一个消息框
        if (0 == count)
        {
            QMessageBox::about(this, "消息", "对不起，您所要查找的用户不存在！");
        }
    }
}

// 将搜索群得到的信息放进表格中
void AddInfo::printGroupInfo(QString id, QString name)
{
    ui->group_table->setRowCount(0);
    ui->group_table->clearContents();
    if(id.isEmpty()){
        if(name.isEmpty())
        {
             grouplist = handle.getRoomList();
        }else{
             grouplist = handle.getRoomList("_empty_",name);
        }
    }else{
        if(name.isEmpty())
        {
            grouplist =  handle.getRoomList(id);
        }else{
            grouplist = handle.getRoomList(id,name);
        }
    }
    qDebug()<<grouplist;
    int i,j ;
    QString temp[]={"talkroomid", "talkroomname"};
    // 插入一行
    if(id == NULL || id == "")
    {   // 当聊天室（群）帐号为空时，执行此分支
        for (i=0; i<grouplist.size(); i++)
        {
            ui->group_table->insertRow(ui->group_table->rowCount());
            for(j=0; j<2; j++)
            {
                // 将用户信息输出到第 i 行，第 j 列单元格中
                ui->group_table->setItem(i, j, new QTableWidgetItem(grouplist[i][temp[j]]));
            }
        }
    }else if(id != NULL && id != ""){
        // 当聊天室（群）帐号不为空时，执行此分支
        int count = 0 ;
        // 遍历所有的信息，找到对应 id 的聊天室（群）并输出到表格中
        for(i=0;  i<grouplist.size(); i++)
        {
            ui->group_table->insertRow(ui->group_table->rowCount());
            if(grouplist[i][temp[0]] == id)
            {
                for(j=0; j<2; j++)
                {
                    // 将用户信息输出到第 i 行，第 j 列单元格中
                    ui->group_table->setItem(i, j, new QTableWidgetItem(grouplist[i][temp[j]]));
                    count++ ;
                }
            }
        }
        // 当查找的聊天室（群）不存在时，弹出一个消息框
        if (0 == count)
        {
            QMessageBox::about(this, "消息", "对不起，您所要查找的聊天室不存在！");
        }
    }

}

void AddInfo::setConnection()
{

}

// 窗体大小改变事件
void AddInfo::resizeEvent(QResizeEvent *)
{
    setSize();
}

// 鼠标按下事件响应函数
void AddInfo::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::RightButton)
    {
        event = e ;
    }
}

// 鼠标松开事件响应函数
void AddInfo::mouseReleaseEvent(QMouseEvent *e)
{
    if(event->button() == e->button())
    {
        QMenuBar *menubar = new QMenuBar(this);
        QAction *addfriend = menubar->addAction("添加好友") ;
        QAction *getinfo = menubar->addAction("好友信息");
        menubar->show();
    }
}


void AddInfo::on_friend_table_customContextMenuRequested(const QPoint &pos)
{
    fmenu->addAction(addfriend);
    fmenu->exec(QCursor::pos());
}

void AddInfo::on_group_table_customContextMenuRequested(const QPoint &pos)
{
    gmenu->addAction(addgroup);
    gmenu->addAction("群信息");
    gmenu->exec(QCursor::pos());
}

void AddInfo::on_c_btn_clicked()
{
    QMap<QString,QString> result=handle.creatRoom(userid,ui->c_group_id->text(),ui->c_group_name->text());
    if(result["type"]=="1")
    {
         QMessageBox::about(this, "消息", "聊天室创建成功！");
    }else
    {
         QMessageBox::about(this, "消息", "聊天室创建失败！");
    }
}
